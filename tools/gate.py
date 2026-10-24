#!/usr/bin/env python3
"""Steward "match" gate: every src/funcs/func_XXXXXXXX.c must compile to its function in work/main.bin.

  python tools/gate.py            -> one line per checked file, then a summary line; exit 0 only if all match
  python tools/gate.py --all      -> check every file
A file must define exactly the function its name says (so claims and progress stay per address).
Zero-loss rule: nothing already matched may break or disappear (files tracked on the base branch must still
exist). A function file only depends on itself and the shared inputs (SHARED: tools, headers, config, toolchain),
so by default only files that differ from the base branch are compiled; whenever the shared inputs differ from
the last full pass (a tools PR merged, a new toolchain), every file is checked again. tools/build.py still
links the whole game and requires it byte-identical.
"""
import concurrent.futures
import contextlib
import glob
import hashlib
import io
import os
import re
import subprocess
import sys
import tempfile

sys.path.insert(0, os.path.dirname(__file__))
import match  # noqa: E402

ROOT = match.ROOT
SHARED = ['tools', 'include', 'config', 'toolchain']
FULL_STAMP = os.path.join(ROOT, 'work', 'gate_full.ok')


def git(*args):
    return subprocess.run(['git', '-c', 'safe.directory=*', *args], cwd=ROOT, capture_output=True, text=True)


def shared_digest():
    """Everything a function file's result depends on besides the file itself, incl. the compiler binaries."""
    h = hashlib.sha256()
    paths = sorted(p for d in SHARED for p in glob.glob(os.path.join(ROOT, d, '**', '*'), recursive=True)
                   if os.path.isfile(p) and '__pycache__' not in p)
    for p in paths + [match.CC1, match.CC1PLUS, f'{match.TOOLS}/mips-as.exe', match.MAIN]:
        if os.path.isfile(p):
            h.update(os.path.relpath(p, ROOT).encode() + open(p, 'rb').read().replace(b'\r\n', b'\n'))
    return h.hexdigest()


def changed_files():
    """Function files that differ from the base: the working tree vs HEAD (the judge stages a PR's files
    uncommitted on top of the base), plus commits since origin/main when that ref exists (a contributor's
    branch). A superset is harmless: it only costs time. -> None if git cannot answer (not a checkout, git
    missing or failing): the caller then checks every file, so the gate fails closed, never silently empty."""
    try:
        if git('rev-parse', '--is-inside-work-tree').stdout.strip() != 'true':
            return None
        mb = git('merge-base', 'HEAD', 'origin/main')
        base = mb.stdout.strip() if mb.returncode == 0 and mb.stdout.strip() else 'HEAD'
        diff = git('diff', '--name-only', base, '--', 'src/funcs')
        new = git('ls-files', '--others', '--exclude-standard', 'src/funcs')
    except OSError:
        return None
    if diff.returncode or new.returncode:
        return None
    out = set(diff.stdout.split()) | set(new.stdout.split())
    return {os.path.join(ROOT, *p.split('/')) for p in out if p.endswith('.c')}


def check_one(f):
    """-> (name, [(function, matches?)], compare output, compile error or None). Runs in a worker process."""
    want = os.path.basename(f)[:-2]
    with tempfile.TemporaryDirectory() as tmp:
        try:
            o = match.build(f, tmp)
        except Exception as e:
            return want, [], '', ' '.join(str(e).split())[:300]
        own = own_data(o)
        if own:   # the build links only the game's own data: a function file cannot bring rodata/data with it
            return want, [], '', OWN + ', '.join(own) + (' (a string literal, a switch jump table or initialized '
                                                         'data); use the game\'s symbols (extern char D_xxx[])')
        res = match.check(o)
        buf = io.StringIO()
        with contextlib.redirect_stdout(buf):
            match.compare(o, show=True)
    return want, res, buf.getvalue(), None


OWN = 'has its own '


def own_data(o):
    """Non-empty data sections in a function's object, e.g. ['.rodata (0x100 bytes)']."""
    from elftools.elf.elffile import ELFFile
    with open(o, 'rb') as fh:
        return [f'{s.name} ({s["sh_size"]:#x} bytes)' for s in ELFFile(fh).iter_sections()
                if s.name.startswith(('.rodata', '.rdata', '.data', '.sdata', '.bss', '.sbss')) and s['sh_size']]


def main():
    import fresh
    fresh.ensure()
    every = sorted(glob.glob(os.path.join(ROOT, 'src', 'funcs', 'func_*.c')))
    digest = shared_digest()
    full = '--all' in sys.argv or not os.path.exists(FULL_STAMP) or open(FULL_STAMP).read().strip() != digest
    why = '' if not full or '--all' in sys.argv else ' (shared inputs changed since the last full pass)'
    changed = None if full else changed_files()
    if changed is None and not full:   # fail closed: no reliable change list means check everything
        full, why = True, ' (could not list changed files with git)'
    files = every if full else sorted(f for f in changed if os.path.exists(f))
    print(f'checking {"all" if full else "changed"} files: {len(files)} of {len(every)}' + why)
    good, bad, difflines = 0, [], []
    named = [f for f in files if re.fullmatch(r'func_[0-9A-F]{8}', os.path.basename(f)[:-2])]
    bad += [f'{os.path.basename(f)[:-2]}: file name must be func_XXXXXXXX.c' for f in files if f not in named]
    jobs = int(os.environ.get('GATE_JOBS', 0)) or max(1, (os.cpu_count() or 2) - 1)
    if len(named) > 1 and jobs > 1:   # each file is independent: compile them side by side
        with concurrent.futures.ProcessPoolExecutor(jobs) as pool:
            results = list(pool.map(check_one, named))
    else:
        results = [check_one(f) for f in named]
    for want, res, out, err in results:
        if err is not None and err.startswith(OWN):
            bad.append(f'{want}: {err}')
            print(f'FAIL  {want}: has its own data')
            continue
        if err is not None:
            # the compiler's own message, so the author can fix it without running the tools
            bad.append(f'{want}: does not compile: {err}')
            print(f'FAIL  {want}: does not compile')
            continue
        names = {n for n, _ in res}
        if want not in names:
            bad.append(f'{want}: file does not define {want}')
        elif not dict(res)[want]:
            lines = out.splitlines()
            why = next((l.split(': ', 1)[1] for l in lines if l.startswith(f'DIFF {want}:')), 'does not match')
            bad.append(f'{want}: {why}')
            # first differing instructions, yours | the game's (Steward shows them in the PR comment)
            for l in [l for l in lines if l.lstrip().startswith('!!')][:8]:
                difflines.append(f'DIFFLINE {want}: {l.strip()[2:].strip()}')
        else:
            good += 1
        for n, ok in res:
            print(f'{"MATCH" if ok else "DIFF "} {n}' + ('' if n == want else '  (extra function in file)'))
    # zero-loss across PRs: a function matched on the base branch (tracked in git) may not disappear
    tracked = subprocess.run(['git', '-c', 'safe.directory=*', 'ls-files', 'src/funcs'], cwd=ROOT,
                             capture_output=True, text=True).stdout.split()
    for t in tracked:
        if t.endswith('.c') and not os.path.exists(os.path.join(ROOT, t)):
            bad.append(f'{os.path.basename(t)[:-2]}: matched on the base branch, removed by this change (LOST)')
    for d in difflines:   # last, next to the PROBLEM lines, so they survive output truncation
        print(d)
    for b in bad:
        print('PROBLEM ' + b)
    print(f'{good}/{len(files)} files match' + ('' if not bad else f', {len(bad)} problem(s)'))
    if full and not bad:   # later runs with the same shared inputs only need to check changed files
        os.makedirs(os.path.dirname(FULL_STAMP), exist_ok=True)
        with open(FULL_STAMP, 'w') as f:
            f.write(digest + '\n')
    sys.exit(0 if not bad else 1)


if __name__ == '__main__':
    main()
