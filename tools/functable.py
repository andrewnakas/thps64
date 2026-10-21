#!/usr/bin/env python3
"""Function table for Steward (and progress): addr,size,name,source from splat's asm output.

  python tools/functable.py > config/functions.csv
A function counts as done when its asm file is gone from asm/nonmatchings (or src/ has it without INCLUDE_ASM).
"""
import glob
import re

rows = []
for path in glob.glob('asm/**/*.s', recursive=True):
    for m in re.finditer(r'^nonmatching (func_([0-9A-F]{8})), 0x([0-9A-F]+)', open(path).read(), re.M):
        rows.append((int(m.group(2), 16), int(m.group(3), 16), m.group(1)))
print('addr,size,name,source')
for a, s, n in sorted(rows):
    print(f'0x{a:08X},0x{s:X},{n},')
