#!/usr/bin/env python3
"""Steward "match" gate: every src/funcs/func_XXXXXXXX.c must compile to its function in work/main.bin.

  python tools/gate.py            -> one line per file, then a summary line; exit 0 only if all match
A file must define exactly the function its name says (so claims and progress stay per address).
Re-checking every file on every PR is the zero-loss rule: nothing already matched may break or disappear
(files tracked on the base branch must still exist).
"""
import contextlib
import glob
import io
import os
import re
import subprocess
import sys
import tempfile

sys.path.insert(0, os.path.dirname(__file__))
import match  # noqa: E402

ROOT = match.ROOT


def main():
    files = sorted(glob.glob(os.path.join(ROOT, 'src', 'funcs', 'func_*.c')))
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
    sys.exit(0 if not bad else 1)


if __name__ == '__main__':
    main()
