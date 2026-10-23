#!/usr/bin/env python3
"""Start work on one function: draft C from m2c into src/funcs/func_XXXXXXXX.c, then try to match it.

  python tools/new_func.py func_80024BA8          (refuses to overwrite an existing file; --force to redo)
m2c's draft usually needs editing (unkXX fields on void*, types); iterate with
  python tools/match.py src/funcs/func_XXXXXXXX.c --show
"""
import glob
import os
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
M2C = os.environ.get('M2C', 'E:/thps64-tools/m2c/m2c.py')


def jump_table_rodata(asm):
    """m2c cannot follow a `jr` through a jump table it has not seen: hand it the game's jtbl_ blocks the function
    uses (from the generated asm/data/*.rodata.s) as a .rodata file. -> [temp file] or []."""
    import re
    import tempfile
    names = set(re.findall(r'%hi\((jtbl_[0-9A-F]{8})\)', open(asm).read()))
    if not names:
        return []
    blocks = []
    for d in sorted(glob.glob(os.path.join(ROOT, 'asm', 'data', '*.rodata.s'))):
        cur = None
        for line in open(d):
            m = re.match(r'\s*dlabel\s+(\w+)', line)
            if m:
                cur = [line] if m.group(1) in names else None
                if cur is not None:
                    blocks.append(cur)
                continue
            if cur is not None:
                if re.match(r'\s*enddlabel', line):
                    cur = None
                else:
                    cur.append(line)
    if not blocks:
        return []
    fd, path = tempfile.mkstemp(suffix='.rodata.s')
    with os.fdopen(fd, 'w', newline='\n') as f:
        f.write('.section .rodata\n\n' + ''.join(''.join(b) + '\n' for b in blocks))
    return [path]


def main():
    name = sys.argv[1]
    if not name.startswith('func_'):
        name = 'func_' + name.upper().replace('0X', '')
    asm = os.path.join(ROOT, 'asm', 'nonmatchings', 'game', name + '.s')
    out = os.path.join(ROOT, 'src', 'funcs', name + '.c')
    if not os.path.exists(asm):
        sys.exit(f'no asm for {name} (run splat: python -m splat split config/main.yaml)')
    if os.path.exists(out) and '--force' not in sys.argv:
        sys.exit(f'{out} exists (use --force to overwrite)')
    extra = jump_table_rodata(asm)
    r = subprocess.run([sys.executable, M2C, '-t', 'mips-gcc-c', asm, *extra], capture_output=True, text=True)
    for e in extra:
        os.remove(e)
    draft = r.stdout if r.returncode == 0 else f'/* m2c failed:\n{r.stderr}\n*/\n'
    with open(out, 'w', newline='\n') as f:
        f.write('#include "common.h"\n\n' + draft)
    print(f'wrote {os.path.relpath(out, ROOT)} (m2c draft)')
    subprocess.run([sys.executable, os.path.join(ROOT, 'tools', 'match.py'), out, '--show'])


if __name__ == '__main__':
    main()
