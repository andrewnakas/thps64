#!/usr/bin/env python3
"""Bulk first pass: m2c-draft the smallest unmatched functions and keep only drafts that match as-is.

  python tools/auto_draft.py [N=50] [--max-size 0x40]
Drafts are compiled in work/drafts/; a matching one moves to src/funcs/. Prints one summary line.
"""
import csv
import os
import shutil
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
M2C = os.environ.get('M2C', 'E:/thps64-tools/m2c/m2c.py')


def main():
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    n = int(args[0]) if args else 50
    max_size = int(sys.argv[sys.argv.index('--max-size') + 1], 0) if '--max-size' in sys.argv else 0x40
    rows = list(csv.DictReader(open(os.path.join(ROOT, 'config', 'functions.csv'))))
    done = {f[:-2] for f in os.listdir(os.path.join(ROOT, 'src', 'funcs'))}
    tried_p = os.path.join(ROOT, 'work', 'drafts', 'tried.txt')
    os.makedirs(os.path.dirname(tried_p), exist_ok=True)
    tried = set(open(tried_p).read().split()) if os.path.exists(tried_p) else set()
    todo = sorted((int(r['size'], 16), r['name']) for r in rows
                  if r['name'] not in done and r['name'] not in tried and int(r['size'], 16) <= max_size)[:n]
    kept = []
    for _, name in todo:
        asm = os.path.join(ROOT, 'asm', 'nonmatchings', 'game', name + '.s')
        r = subprocess.run([sys.executable, M2C, '-t', 'mips-gcc-c', asm], capture_output=True, text=True)
        tried.add(name)
        if r.returncode != 0:
            continue
        draft = os.path.join(ROOT, 'work', 'drafts', name + '.c')
        with open(draft, 'w', newline='\n') as f:
            f.write('#include "common.h"\n\n' + r.stdout)
        m = subprocess.run([sys.executable, os.path.join(ROOT, 'tools', 'match.py'), draft], capture_output=True, text=True)
        if m.returncode == 0:
            shutil.move(draft, os.path.join(ROOT, 'src', 'funcs', name + '.c'))
            kept.append(name)
    open(tried_p, 'w').write('\n'.join(sorted(tried)) + '\n')
    print(f'{len(kept)}/{len(todo)} drafts matched as-is: {" ".join(kept)}')


if __name__ == '__main__':
    main()
