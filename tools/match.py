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
# a zig cache per workspace: the judge and a contributor's checkout must never share (or clear) each other's entries
os.environ.setdefault('ZIG_GLOBAL_CACHE_DIR', os.path.join(ROOT, 'build', 'zig-cache'))
os.environ.setdefault('ZIG_LOCAL_CACHE_DIR', os.path.join(ROOT, 'build', 'zig-cache'))
ZIG = os.environ.get('ZIG', 'C:/Users/andre/.local/zig-x86_64-windows-0.16.0/zig.exe')
MAIN_VRAM = 0x80016AC0
# GCC 2.8.1 (pmret/gcc-papermario) -O1 -msplit-addresses: the game loads every global address through a
# compiler-chosen register (1017/1017 stores), which GCC 2.7.2 never does; -O1 pinned on func_8005E6B4 (2026-10-21).
CC1 = os.environ.get('THPS_CC1', 'E:/thps64-tools/gcc-2.8.1-pm/cc1.exe')
# -mno-fix4300: this cc1 defaults to the early-VR4300 workaround (a nop after every mul.s/mul.d); the game has none
CFLAGS = ['-quiet', '-O1', '-mips3', '-mgp32', '-mfp32', '-G0', '-fno-builtin', '-msplit-addresses', '-mno-fix4300']
# the VR4300 interlocks HI/LO: -m4100 stops gas 2.6 padding mflo/mfhi hazards with nops (the game has none)
ASFLAGS = ['-EB', '-mips3', '-m4100', '-G0']
# the game's assembler never moved a load into a branch delay slot (`lw; jr ra; nop`), but did move other
# instructions (`jr ra; addiu sp`). gas 2.6 does that only for -mips1, which also adds load-delay nops the game
# lacks; toolchain/build.sh patches gas to apply just the no-load-swap rule when this is set (2026-10-22: 0 of 360
# matches change, 12 more functions match).
os.environ['THPS_AS_NO_LOAD_SWAP'] = '1'
# and no coprocessor load/move hazard nops (the VR4300 interlocks them; the game has `mtc1; cvt.s.w` and `mfc1 $a3; jal`),
# keeping the single nop between an FP compare and its branch (also at `.set noreorder`)
os.environ['THPS_AS_COP_INTERLOCKS'] = '1'
# stores are never moved into a delay slot either (`sw; jr ra; nop` after block copies; 2026-10-22: 0 of 505 matches
# change, func_8003A410 and the plain-C func_800790D4 match, func_800669CC 71 -> 154/157 instructions)
os.environ['THPS_AS_NO_STORE_SWAP'] = '1'
# and no multiply in a delay slot at all (VR4300 errata): 0 of the game's 2240 mult/multu/mul.s/mul.d sit in one, while
# other FP ops do (2026-10-23: 0 of 833 matches change; func_8002311C 6 -> 26/29, func_80023190 10 -> 30/33)
os.environ['THPS_AS_NO_MUL_SWAP'] = '1'
# the KMC mulmul emulation (a nop between a float multiply and a following mult/mul.s) also counted every column-0
# line as a float multiply: a label or the blank line after `.set reorder`, so a multiply at a branch target got a
# nop. The game has 36 multiplies at branch targets, 35 without one (2026-10-23)
os.environ['THPS_AS_MULMUL_CODE_ONLY'] = '1'
# with -no-m4100 (files whose mflo/mfhi -> mult/div hazards have nops), gas also padded mflo/mfhi before GCC's own
# `.set noreorder` branch + delay slot; the game never has a nop between mflo/mfhi and a branch (0 of 168)
os.environ['THPS_AS_NO_HILO_FLUSH'] = '1'
# a label right before an instruction that needs hazard nops stays before them, so branches to it run the nops too
# (the game's branch targets at `c.lt.s; nop; bc1t` are the nop: 2 of 2)
os.environ['THPS_AS_LABEL_BEFORE_NOPS'] = '1'
R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16 = 4, 5, 6


def symbol_addrs():
    out = {}
    p = os.path.join(ROOT, 'config', 'symbol_addrs.txt')
    for line in open(p):
        m = re.match(r'\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)', line)
        if m:
            out[m.group(1)] = int(m.group(2), 16)
    return out


class CompileError(Exception):
    pass


def float_literals(s_text):
    """Point GCC's li.s/li.d at the game's own float literals before gas runs.

    The game loads every float constant from .rodata through $at (`lui $at,%hi(D_x); lwc1 $fN,%lo(D_x)($at)`, never
    lui+mtc1); GCC 2.8.1 emits `li.s $fN,value`, which gas 2.6 builds with lui/ori/mtc1. The k-th li.s/li.d in a
    function becomes `l.s/l.d $fN,D_x`, D_x being the k-th float literal the game's asm for that function loads,
    only when the bytes at D_x in main.bin equal the compiled value (so the C must hold the exact constant).
    gas then emits lui $at + lwc1 and the link resolves D_x like any other game symbol."""
    main = None
    out, queue = [], []
    for line in s_text.split('\n'):
        m = re.match(r'\s*\.ent\s+(\w+)', line)
        if m:
            asm = os.path.join(ROOT, 'asm', 'nonmatchings', 'game', m.group(1) + '.s')
            queue = []
            if os.path.exists(asm):
                queue = [('d' if op == 'ldc1' else 's', sym) for op, sym in re.findall(
                    r'\b(lwc1|ldc1)\s+\$f\d+, %lo\((D_[0-9A-F]{8})\)\(\$at\)', open(asm).read())]
        m = re.match(r'(\s*)li\.([sd])\s+(\$f\d+),\s*(\S+)\s*$', line)
        if m and queue and queue[0][0] == m.group(2):
            if main is None:
                main = open(MAIN, 'rb').read()
            kind, sym = queue[0]
            bits = struct.pack('>f' if kind == 's' else '>d', float(m.group(4)))
            o = int(sym[2:], 16) - MAIN_VRAM
            if main[o:o + len(bits)] == bits:
                queue.pop(0)
                out.append(f'{m.group(1)}l.{kind}\t{m.group(3)},{sym}')
                continue
        out.append(line)
    return '\n'.join(out)


def _tables(s_text):
    """GCC's switch jump tables in a .s file: [(function, label, [target labels], alignment)], in order. GCC puts
    `.align 3` (8 bytes) before each table, so a table after one with an odd entry count starts 4 bytes later."""
    out, func, block, cur, align = [], None, False, None, 4
    for line in s_text.split('\n'):
        t = line.strip()
        m = re.match(r'\.ent\s+(\w+)', t)
        if m:
            func = m.group(1)
        if t.startswith('.section') and '.rodata' in t:
            block = True
            continue
        if block and t == '.text':
            block, cur = False, None
            continue
        if block:
            m = re.match(r'\.align\s+(\d+)$', t)
            if m:
                align = max(align, 1 << int(m.group(1)))   # `.align 3` then `.align 2`: still 8
            m = re.match(r'(\.L\w+):$', t)
            if m:
                cur = (func, m.group(1), [], max(align, 4))
                out.append(cur)
                align = 4
            m = re.match(r'\.word\s+(\.L\w+)$', t)
            if m and cur is not None:
                cur[2].append(m.group(1))
    return out


def jump_tables(s_text, tmp):
    """Point GCC's switch jump tables at the game's own (jtbl_XXXXXXXX in .rodata) and drop GCC's copy.

    GCC emits each table into the file's own .rodata, which the build cannot place (the game's tables already sit in
    the game's rodata). The k-th table in a function becomes the k-th jtbl_ symbol the game's asm for that function
    uses, but only after checking every entry: the original .s is assembled once and each table word (a label offset
    within the function) must equal the game's table word minus the function's address. Any mismatch leaves the
    table in place, so the gate reports the file's own .rodata instead of hiding a wrong case mapping."""
    tables = _tables(s_text)
    if not tables:
        return s_text
    o_file = os.path.join(tmp, 'jt.o')
    with open(os.path.join(tmp, 'jt.s'), 'w', newline='\n') as f:
        f.write(s_text)
    r = subprocess.run([f'{TOOLS}/mips-as.exe', *ASFLAGS, 'jt.s', '-o', 'jt.o'], capture_output=True, text=True, cwd=tmp)
    if r.returncode:
        return s_text   # the real assembly step reports the error
    with open(o_file, 'rb') as fh:
        sec = ELFFile(fh).get_section_by_name('.rodata')
        ours = sec.data() if sec is not None else b''
    main = open(MAIN, 'rb').read()
    mapping, pos, used = {}, 0, {}
    for func, label, targets, align in tables:
        asm = os.path.join(ROOT, 'asm', 'nonmatchings', 'game', f'{func}.s')
        game = list(dict.fromkeys(re.findall(r'%hi\((jtbl_[0-9A-F]{8})\)', open(asm).read()))) if os.path.exists(asm) else []
        k = used.get(func, 0)
        used[func] = k + 1
        pos = (pos + align - 1) & ~(align - 1)
        words = [struct.unpack('>I', ours[pos + 4 * i:pos + 4 * i + 4])[0] for i in range(len(targets))]
        pos += 4 * len(targets)
        if k >= len(game) or not re.fullmatch(r'func_[0-9A-F]{8}', func or ''):
            return s_text
        sym, fva = game[k], int(func[5:], 16)
        o = int(sym[5:], 16) - MAIN_VRAM
        theirs = [struct.unpack('>I', main[o + 4 * i:o + 4 * i + 4])[0] for i in range(len(targets))]
        if theirs != [fva + w for w in words]:
            return s_text
        mapping[label] = sym
    # only drop .rodata that holds nothing but these tables (strings or other data stay, and the gate reports them)
    block = False
    for line in s_text.split('\n'):
        t = line.strip()
        if t.startswith('.section') and '.rodata' in t:
            block = True
        elif block and t == '.text':
            block = False
        elif block and t and not (t.startswith('.align') or re.fullmatch(r'\.word\s+\.L\w+', t)
                                  or (t.endswith(':') and t[:-1] in mapping)):
            return s_text
    out, block = [], False
    for line in s_text.split('\n'):
        t = line.strip()
        if t.startswith('.section') and '.rodata' in t:
            block = True
            continue
        if block:
            if t == '.text':
                block = False
            continue
        for label, sym in mapping.items():
            line = re.sub(r'(?<![\w.$])' + re.escape(label) + r'(?!\w)', sym, line)
        out.append(line)
    return '\n'.join(out)


def _check_gas():
    exe = f'{TOOLS}/mips-as.exe'
    data = open(exe, 'rb').read() if os.path.exists(exe) else b''
    if data and not all(k in data for k in (b'THPS_AS_NO_LOAD_SWAP', b'THPS_AS_COP_INTERLOCKS', b'THPS_AS_NO_STORE_SWAP', b'THPS_AS_NO_MUL_SWAP',
                                                    b'THPS_AS_MULMUL_CODE_ONLY', b'THPS_AS_NO_HILO_FLUSH',
                                                    b'THPS_AS_O0_AS_O2',
                                                    b'THPS_AS_LABEL_BEFORE_NOPS')):
        raise CompileError(f'{exe} predates the THPS gas patches: rerun toolchain/build.sh')


# Per-file optimisation flags: the game was not built with one flag set. Functions next to each other match only at -O1
# or only with -O2's CSE passes (2026-10-23: 7 given-up functions match with `-O2 -fno-schedule-insns
# -fno-schedule-insns2`, which breaks 30 of 821 -O1 matches). A file opts in with a first-line comment
#   /* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
# Only these flags are accepted, so a file cannot change anything else about the compiler.
# `-Wa,-no-m4100` is for the assembler: such files were assembled without -m4100, so gas pads mflo/mfhi -> mult/div
# hazards with nops the way the game does in those files (func_80042E78, func_80042F58, func_800673B0 match only so).
# `-Wa,-O0`: such files were assembled without delay-slot filling: gas leaves every slot GCC did not fill itself as a
# nop (the game has both `addiu $sp,-N; addiu $sp,N; jr $ra; nop` (11) and `addiu $sp,-N; jr $ra; addiu $sp,N` (9)).
FILE_CFLAGS = {'-O2', '-fno-schedule-insns', '-fno-schedule-insns2', '-fcse-follow-jumps', '-fcse-skip-blocks',
               '-frerun-cse-after-loop', '-fexpensive-optimizations', '-fno-strength-reduce', '-ffast-math',
               '-Wa,-no-m4100', '-Wa,-O0'}


def file_cflags(src):
    """The extra flags a C file asks for in its first-line `/* cflags: ... */` comment (whitelisted)."""
    with open(src, encoding='utf-8', errors='replace') as f:
        first = f.readline()
    m = re.match(r'\s*/\*\s*cflags:(.*?)\*/', first)
    if not m:
        return []
    flags = m.group(1).split()
    bad = [x for x in flags if x not in FILE_CFLAGS]
    if bad:
        raise CompileError(f'cflags comment: not allowed: {" ".join(bad)} (allowed: {" ".join(sorted(FILE_CFLAGS))})')
    return flags


def build(src, tmp):
    _check_gas()
    extra = file_cflags(src)
    asflags = [a for a in ASFLAGS if a != '-m4100'] if '-Wa,-no-m4100' in extra else ASFLAGS
    asflags = asflags + ['-O0'] if '-Wa,-O0' in extra else asflags
    extra = [x for x in extra if not x.startswith('-Wa,')]
    i_file, s_file, o_file = (os.path.join(tmp, 'x' + e) for e in ('.i', '.s', '.o'))
    # clang's preprocessor (old cccp crashes on Windows)
    r = subprocess.run([ZIG, 'cc', '-E', '-x', 'c', '-nostdinc', '-undef', '-D__GNUC__=2', '-D_MIPS_SZLONG=32',
                    '-I', os.path.join(ROOT, 'include'), '-I', os.path.join(ROOT, 'src'),
                    '-D_LANGUAGE_C', '-DF3DEX_GBI', src, '-o', i_file], capture_output=True, text=True)
    if r.returncode:   # the preprocessor's own message (missing include, bad #define), not a command dump
        raise CompileError((r.stderr or r.stdout).replace(src, os.path.basename(src)).strip())
    for cmd, cwd in (([CC1, *CFLAGS, *extra, i_file, '-o', s_file], None),
                     ([f'{TOOLS}/mips-as.exe', *asflags, s_file, '-o', o_file], tmp)):
        if cmd[0] != CC1:
            with open(s_file) as f:
                text = f.read()
            with open(s_file, 'w', newline='\n') as f:
                f.write(jump_tables(float_literals(text), tmp))
        r = subprocess.run(cmd, capture_output=True, text=True, cwd=cwd)
        if r.returncode:
            raise CompileError((r.stderr or r.stdout).replace(i_file, os.path.basename(src)).strip())
    return o_file


def check(o_file):
    """[(function name, matches?)] for every function in the object, without printing."""
    import contextlib, io as _io
    res = []
    with contextlib.redirect_stdout(_io.StringIO()) as buf:
        compare(o_file)
    for line in buf.getvalue().splitlines():
        m = re.match(r'(MATCH|DIFF)\s+(\w+)', line)
        if m:
            res.append((m.group(2), m.group(1) == 'MATCH'))
    return res


def unit_sizes():
    import csv
    p = os.path.join(ROOT, 'config', 'functions.csv')
    if not os.path.exists(p):
        return {}
    return {int(r['addr'], 16): int(r['size'], 16) for r in csv.DictReader(open(p))}


def compare(o_file, show=False):
    main = open(MAIN, 'rb').read()
    known = symbol_addrs()
    import io
    elf = ELFFile(io.BytesIO(open(o_file, 'rb').read()))
    text = elf.get_section_by_name('.text')
    tdata = text.data()
    tidx = elf.get_section_index('.text')
    masks = {}
    # `j .Lx` inside the function is relocated against .text itself (gas 2.6 REL: the field holds the target), so
    # masking it like a call would hide a jump to the wrong instruction (func_80034AA4: `j .L80034C10` built one
    # word later, caught only by the build gate). Such jumps are compared by their target relative to the function.
    local_jumps = {}
    symtab = elf.get_section_by_name('.symtab')
    for sec in elf.iter_sections():
        if isinstance(sec, RelocationSection) and sec.name in ('.rel.text', '.rela.text'):
            for r in sec.iter_relocations():
                t = r['r_info_type']
                masks[r['r_offset']] = 0xFC000000 if t == R_MIPS_26 else 0xFFFF0000 if t in (R_MIPS_HI16, R_MIPS_LO16) else 0xFFFFFFFF
                s = symtab.get_symbol(r['r_info_sym'])
                if t == R_MIPS_26 and s['st_shndx'] == tidx and s['st_info']['type'] != 'STT_FUNC':
                    field = struct.unpack_from('>I', text.data(), r['r_offset'])[0] & 0x3FFFFFF
                    local_jumps[r['r_offset']] = s['st_value'] + (field << 2) + (r['r_addend'] if r.is_RELA() else 0)
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
            elif start + i in local_jumps:
                game_target = ((addr + i) & 0xF0000000) | ((b & 0x3FFFFFF) << 2)
                if local_jumps[start + i] - start != game_target - addr:
                    bad.append(i)
        n = len(mine) // 4
        # the C must cover the whole unit: splat sometimes keeps two functions in one asm file, and matching only the
        # first leaves the rest unbuilt (the build gate then sees zeros). Trailing alignment nops count as covered.
        want = unit_sizes().get(addr)
        rest = main[addr - MAIN_VRAM + len(mine):addr - MAIN_VRAM + want] if want else b''
        if not bad and want and len(mine) < want and any(rest):
            ok_all = False
            print(f'DIFF {name}: matches its first {len(mine):#x} bytes, but the unit is {want:#x} bytes '
                  f'(more code follows at 0x{addr + len(mine):08X}: decompile it too, or split the unit)')
            continue
        if bad:
            ok_all = False
            print(f'DIFF {name}: {n - len(bad)}/{n} instructions agree (first diff at +{bad[0]:#x})')
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
        try:
            ok = compare(build(src, tmp), show)
        except (CompileError, subprocess.CalledProcessError) as e:
            print(f'COMPILE ERROR in {os.path.basename(src)}:')
            print(str(e)[-3000:])
            ok = False
    for f in glob.glob(os.path.join(ROOT, 'astemp_*')):
        os.remove(f)
    sys.exit(0 if ok else 1)


if __name__ == '__main__':
    main()
