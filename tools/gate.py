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
    for p in paths + [match.CC1, f'{match.TOOLS}/mips-as.exe', match.MAIN]:
        if os.path.isfile(p):
            h.update(os.path.relpath(p, ROOT).encode() + open(p, 'rb').read().replace(b'\r\n', b'\n'))
    return h.hexdigest()


def changed_files():
    """Function files that differ from the base: the working tree vs HEAD (the judge stages a PR's files
    uncommitted on top of the base), plus commits since origin/main when that ref exists (a contributor's
    branch). A superset is harmless: it only costs time."""
    base = git('merge-base', 'HEAD', 'origin/main').stdout.strip() or 'HEAD'
    out = set(git('diff', '--name-only', base, '--', 'src/funcs').stdout.split())
    out |= set(git('ls-files', '--others', '--exclude-standard', 'src/funcs').stdout.split())
    return {os.path.join(ROOT, *p.split('/')) for p in out if p.endswith('.c')}


def main():
    import fresh
    fresh.ensure()
    every = sorted(glob.glob(os.path.join(ROOT, 'src', 'funcs', 'func_*.c')))
    digest = shared_digest()
    full = '--all' in sys.argv or not os.path.exists(FULL_STAMP) or open(FULL_STAMP).read().strip() != digest
    files = every if full else sorted(f for f in changed_files() if os.path.exists(f))
    print(f'checking {"all" if full else "changed"} files: {len(files)} of {len(every)}'
          + ('' if not full or '--all' in sys.argv else ' (shared inputs changed since the last full pass)'))
    good, bad, difflines = 0, [], []
    for f in files:
        want = os.path.basename(f)[:-2]
        if not re.fullmatch(r'func_[0-9A-F]{8}', want):
            bad.append(f'{want}: file name must be func_XXXXXXXX.c')
            continue
        with tempfile.TemporaryDirectory() as tmp:
            try:
                o = match.build(f, tmp)
            except Exception as e:
                # the compiler's own message, so the author can fix it without running the tools
                msg = ' '.join(str(e).split())[:300]
                bad.append(f'{want}: does not compile: {msg}')
                print(f'FAIL  {want}: does not compile')
                continue
            res = match.check(o)
            buf = io.StringIO()
            with contextlib.redirect_stdout(buf):
                match.compare(o, show=True)
        names = {n for n, _ in res}
        if want not in names:
            bad.append(f'{want}: file does not define {want}')
        elif not dict(res)[want]:
            lines = buf.getvalue().splitlines()
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
