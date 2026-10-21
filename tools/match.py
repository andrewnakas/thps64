#!/usr/bin/env python3
"""Compile a C file with KMC GCC 2.7.2 + gas 2.6 and compare every function in it against work/main.bin.

  python tools/match.py src/foo.c [--show]

Functions must be named func_XXXXXXXX (or listed in config/symbol_addrs.txt). Relocated fields
(jal targets, %hi/%lo halves) are masked, so this checks code shape, not symbol addresses;
the full build (later) checks those. Prints one line per function: MATCH / DIFF n/m.
Exit code 0 only if every function matches.
"""
import glob
import os
import re
import struct
import subprocess
import sys
import tempfile

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TOOLS = os.environ.get('THPS_TOOLS', 'E:/thps64-tools/bin')
MAIN = os.path.join(ROOT, 'work', 'main.bin')
ZIG = os.environ.get('ZIG', 'C:/Users/andre/.local/zig-x86_64-windows-0.16.0/zig.exe')
MAIN_VRAM = 0x80016AC0
CFLAGS = ['-quiet', '-O2', '-mips3', '-mgp32', '-mfp32', '-G0', '-fno-builtin']
R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16 = 4, 5, 6


def symbol_addrs():
    out = {}
    p = os.path.join(ROOT, 'config', 'symbol_addrs.txt')
    for line in open(p):
        m = re.match(r'\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)', line)
        if m:
            out[m.group(1)] = int(m.group(2), 16)
    return out


def build(src, tmp):
    i_file, s_file, o_file = (os.path.join(tmp, 'x' + e) for e in ('.i', '.s', '.o'))
    # clang's preprocessor (old cccp crashes on Windows)
    subprocess.run([ZIG, 'cc', '-E', '-P', '-x', 'c', '-nostdinc', '-undef', '-D__GNUC__=2', '-D_MIPS_SZLONG=32',
                    '-I', os.path.join(ROOT, 'include'), '-I', os.path.join(ROOT, 'src'),
                    '-D_LANGUAGE_C', '-DF3DEX_GBI', src, '-o', i_file], check=True)
    subprocess.run([f'{TOOLS}/cc1.exe', *CFLAGS, i_file, '-o', s_file], check=True)
    subprocess.run([f'{TOOLS}/mips-as.exe', '-EB', '-mips3', '-G0', s_file, '-o', o_file], check=True, cwd=tmp)
    return o_file


def compare(o_file, show=False):
    main = open(MAIN, 'rb').read()
    known = symbol_addrs()
    import io
    elf = ELFFile(io.BytesIO(open(o_file, 'rb').read()))
    text = elf.get_section_by_name('.text')
    tdata = text.data()
    tidx = elf.get_section_index('.text')
    masks = {}
    for sec in elf.iter_sections():
        if isinstance(sec, RelocationSection) and sec.name in ('.rel.text', '.rela.text'):
            for r in sec.iter_relocations():
                t = r['r_info_type']
                masks[r['r_offset']] = 0xFC000000 if t == R_MIPS_26 else 0xFFFF0000 if t in (R_MIPS_HI16, R_MIPS_LO16) else 0xFFFFFFFF
    syms = sorted((s['st_value'], s.name) for s in elf.get_section_by_name('.symtab').iter_symbols()
                  if s['st_shndx'] == tidx and s['st_info']['type'] == 'STT_FUNC')
    ok_all = True
    for k, (start, name) in enumerate(syms):
        end = syms[k + 1][0] if k + 1 < len(syms) else len(tdata)
        m = re.fullmatch(r'func_([0-9A-F]{8})', name)
        addr = int(m.group(1), 16) if m else known.get(name)
        if addr is None:
            print(f'SKIP  {name}: no address')
            continue
        mine = tdata[start:end]
        # trailing alignment nops in our object are not part of the function
        while len(mine) >= 4 and mine[-4:] == b'\0\0\0\0' and end - start > 4:
            mine, end = mine[:-4], end - 4
        theirs = main[addr - MAIN_VRAM:addr - MAIN_VRAM + len(mine)]
        bad = []
        for i in range(0, len(mine), 4):
            mk = masks.get(start + i, 0xFFFFFFFF)
            a, b = struct.unpack_from('>I', mine, i)[0], struct.unpack_from('>I', theirs, i)[0]
            if (a & mk) != (b & mk):
                bad.append(i)
        n = len(mine) // 4
        if bad:
            ok_all = False
            print(f'DIFF  {name}: {n - len(bad)}/{n} instructions agree (first diff at +{bad[0]:#x})')
            if show:
                import rabbitizer
                for i in range(0, len(mine), 4):
                    a, b = struct.unpack_from('>I', mine, i)[0], struct.unpack_from('>I', theirs, i)[0]
                    flag = '!!' if i in bad else '  '
                    print(f'   {flag} {rabbitizer.Instruction(a).disassemble():40s} | {rabbitizer.Instruction(b).disassemble()}')
        else:
            print(f'MATCH {name} ({len(mine):#x} bytes)')
    return ok_all


def main():
    src = sys.argv[1]
    show = '--show' in sys.argv
    with tempfile.TemporaryDirectory() as tmp:
        ok = compare(build(src, tmp), show)
    for f in glob.glob(os.path.join(ROOT, 'astemp_*')):
        os.remove(f)
    sys.exit(0 if ok else 1)


if __name__ == '__main__':
    main()
