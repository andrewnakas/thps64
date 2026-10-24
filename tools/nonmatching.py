#!/usr/bin/env python3
"""NON_MATCHING gate: equivalent C for functions that cannot be byte-matched (yet).

  python tools/nonmatching.py            -> one line per file (instructions agreeing), then a summary; exit 0 only if
                                            every file is well-formed and compiles
A function that resisted matching may get a readable, behaviour-equivalent C version as
src/nonmatching/func_XXXXXXXX.c. The build keeps using its asm (asm/nonmatchings/game/), so the game stays
byte-identical; the file documents the function and is the starting point for whoever matches it later. Rules:
- same file conventions as src/funcs (one function, `/* compiler: ... */` and `/* cflags: ... */` first lines);
- a `NON_MATCHING:` comment in the first lines saying what still differs from the game;
- it must compile with the project toolchain;
- it must not also exist in src/funcs (once it matches, move it there and delete it here).
tools/progress.py reports these as decompiled, separately from matched.
"""
import contextlib
import csv
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


def check_one(path, funcs):
    """-> (ok, message) for one src/nonmatching file."""
    name = os.path.basename(path)[:-2]
    if not re.fullmatch(r'func_[0-9A-F]{8}', name) or name not in funcs:
        return False, 'not a function in config/functions.csv'
    if os.path.exists(os.path.join(ROOT, 'src', 'funcs', name + '.c')):
        return False, 'also matched in src/funcs: delete the non-matching copy'
    with open(path, encoding='utf-8', errors='replace') as f:
        head = ''.join(f.readline() for _ in range(8))
    if 'NON_MATCHING:' not in head:
        return False, 'needs a `NON_MATCHING:` comment in its first lines saying what differs'
    out = io.StringIO()
    with tempfile.TemporaryDirectory() as tmp:
        try:
            o_file = match.build(path, tmp)
            with contextlib.redirect_stdout(out):
                match.compare(o_file)
        except (match.CompileError, subprocess.CalledProcessError) as e:
            return False, 'COMPILE ERROR: ' + str(e)[-500:]
    lines = [x for x in out.getvalue().splitlines() if x.startswith(('MATCH', 'DIFF')) and name in x]
    if not lines:
        return False, f'does not define {name}'
    if lines[0].startswith('MATCH'):
        return True, 'MATCHES: move it to src/funcs'
    return True, lines[0][len('DIFF '):]


def main():
    funcs = {r['name'] for r in csv.DictReader(open(os.path.join(ROOT, 'config', 'functions.csv')))}
    files = sorted(glob.glob(os.path.join(ROOT, 'src', 'nonmatching', '*.c')))
    bad = 0
    for p in files:
        ok, msg = check_one(p, funcs)
        bad += not ok
        print(f'{"ok  " if ok else "FAIL"} {os.path.basename(p)}: {msg}')
    for f in glob.glob(os.path.join(ROOT, 'astemp_*')):
        os.remove(f)
    print(f'{len(files) - bad}/{len(files)} non-matching files ok')
    sys.exit(1 if bad else 0)


if __name__ == '__main__':
    main()
