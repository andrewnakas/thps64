#!/usr/bin/env python3
"""Re-split main from scratch: find_funcs seeds -> fresh asm/ (splat never deletes files of functions that no longer
exist, and build.py links every .s it finds) -> config/functions.csv.

  python tools/split.py
"""
import os
import shutil
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def run(*cmd):
    print('+', ' '.join(cmd), flush=True)
    subprocess.run(cmd, cwd=ROOT, check=True, stdout=subprocess.DEVNULL if 'splat' in cmd else None)


if __name__ == '__main__':
    run(sys.executable, 'tools/find_funcs.py')
    shutil.rmtree(os.path.join(ROOT, 'asm'), ignore_errors=True)   # generated (gitignored); boot lives in asm_boot/
    run(sys.executable, '-m', 'splat', 'split', 'config/main.yaml')
    with open(os.path.join(ROOT, 'config', 'functions.csv'), 'w') as f:
        subprocess.run([sys.executable, 'tools/functable.py'], cwd=ROOT, check=True, stdout=f)
    print('config/functions.csv rewritten')
