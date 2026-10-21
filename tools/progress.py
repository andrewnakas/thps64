#!/usr/bin/env python3
"""Decomp progress: functions/bytes of game code with a matching C file in src/funcs (per config/functions.csv).

  python tools/progress.py            one-line summary
  python tools/progress.py --json     machine-readable (Steward /status, badges)
Counts files present; tools/gate.py is what proves they match.
"""
import csv
import glob
import json
import os
import re
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def main():
    rows = list(csv.DictReader(open(os.path.join(ROOT, 'config', 'functions.csv'))))
    sizes = {r['name']: int(r['size'], 16) for r in rows}
    done = {os.path.basename(p)[:-2] for p in glob.glob(os.path.join(ROOT, 'src', 'funcs', 'func_*.c'))}
    done &= set(sizes)
    total_b, done_b = sum(sizes.values()), sum(sizes[n] for n in done)
    out = {'functions': len(sizes), 'matched_functions': len(done), 'code_bytes': total_b, 'matched_bytes': done_b,
           'percent_bytes': round(100.0 * done_b / total_b, 3) if total_b else 0.0}
    if '--json' in sys.argv:
        print(json.dumps(out))
    else:
        print(f"{out['matched_functions']}/{out['functions']} functions, {done_b:#x}/{total_b:#x} bytes "
              f"({out['percent_bytes']:.3f}%) of game code matched")


if __name__ == '__main__':
    main()
