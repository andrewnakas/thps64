#!/usr/bin/env python3
"""Full build of the main segment: every function from its matched C (src/funcs) or else its splat asm, linked at
its address, and compared byte for byte with work/main.bin (the unpacked game code).

  python tools/build.py [-j N]      -> build/main.elf, build/main.bin; exit 0 only if identical

This is the whole-binary check behind tools/gate.py's per-function one: it also proves relocations, data and the
link order. Functions: asm/nonmatchings/game/*.s (splat), C: src/funcs/func_XXXXXXXX.c (KMC GCC 2.7.2 + gas 2.6),
asm and data: zig's LLVM assembler, link: ld.lld. Symbols splat could not place come from config/undefined_*.txt.
"""
import concurrent.futures as cf
import glob
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(__file__))
import match  # noqa: E402  (C compile pipeline)

ROOT = match.ROOT
ZIG = match.ZIG
VRAM = 0x80016AC0
OUT = os.path.join(ROOT, 'build')
OBJ = os.path.join(OUT, 'obj')
AS_FLAGS = ['cc', '-target', 'mips-freestanding-none', '-mcpu=mips3', '-mabi=32', '-fno-pic', '-mno-abicalls', '-modd-spreg',
            '-c', '-x', 'assembler-with-cpp',
            '-I', os.path.join(ROOT, 'include'), '-I', ROOT]


def func_list():
    out = []
    for p in glob.glob(os.path.join(ROOT, 'asm', 'nonmatchings', 'game', '*.s')):
        t = open(p).read()
        m = re.search(r'/\* [0-9A-F]+ ([0-9A-F]{8}) ', t)
        n = len(re.findall(r'^\s*/\* [0-9A-F]+ [0-9A-F]{8} [0-9A-F]{8} \*/', t, re.M))
        out.append((int(m.group(1), 16), 4 * n, os.path.basename(p)[:-2], p))
    # splat writes trivially empty functions (`jr $ra; nop`) straight into src/game.c and gives them no asm file
    have = {a for a, _, _, _ in out}
    game_c = os.path.join(ROOT, 'src', 'game.c')
    if os.path.exists(game_c):
        stub_dir = os.path.join(OUT, 'stubs')
        os.makedirs(stub_dir, exist_ok=True)
        for m in re.finditer(r'^void (func_([0-9A-F]{8}))\(void\) \{\s*\}', open(game_c).read(), re.M):
            a = int(m.group(2), 16)
            if a in have:
                continue
            p = os.path.join(stub_dir, m.group(1) + '.s')
            with open(p, 'w', newline='\n') as f:
                f.write(f'glabel {m.group(1)}\n    /* 0 {a:08X} 03E00008 */ jr $ra\n    /* 4 {a + 4:08X} 00000000 */ nop\n')
            out.append((a, 8, m.group(1), p))
    # constant-pool words between functions that no asm file covers: emit them as data, like a splat bin segment
    out.sort()
    main_bin = open(os.path.join(ROOT, 'work', 'main.bin'), 'rb').read()
    pos, gaps = VRAM + 0xB900, []
    for a, sz, _, _ in out:
        if a > pos:
            gaps.append((pos, a - pos))
        pos = max(pos, a + sz)
    for a, sz in gaps:
        name = f'pool_{a:08X}'
        p = os.path.join(OUT, 'stubs', name + '.s')
        os.makedirs(os.path.dirname(p), exist_ok=True)
        with open(p, 'w', newline='\n') as f:
            for k in range(0, sz, 4):
                w = main_bin[a - VRAM + k:a - VRAM + k + 4].hex().upper()
                f.write(f'    /* {k:X} {a + k:08X} {w} */ .word 0x{w}\n')
        out.append((a, sz, name, p))
    return sorted(out)


COP2 = re.compile(r'^(\s*/\* [0-9A-F]+ [0-9A-F]{8} ([0-9A-F]{8}) \*/\s*)(?:mtc2|mfc2|ctc2|cfc2|lwc2|swc2|ldc2|sdc2|c2|cop2)\b.*$',
                  re.M)


def raw_cop2(text):
    """LLVM's assembler has no COP2 (PSX GTE leftovers in THPS): emit those instructions as their raw words."""
    return COP2.sub(lambda m: m.group(1) + '.word 0x' + m.group(2), text)


def assemble(src_s, obj, wrap=True):
    if wrap:
        w = obj[:-2] + '.wrap.s'
        with open(w, 'w', newline='\n') as f:
            f.write('.include "macro.inc"\n.set noreorder\n.set noat\n.section .text\n' + raw_cop2(open(src_s).read()))
        src_s = w
    r = subprocess.run([ZIG, *AS_FLAGS, '-o', obj, src_s], capture_output=True, text=True, cwd=ROOT)
    if r.returncode:
        raise RuntimeError(f'{src_s}: {r.stderr.strip()[:500]}')
    return obj


def compile_c(c_file, obj, size):
    tmp = obj[:-2] + '.d'
    os.makedirs(tmp, exist_ok=True)
    o = match.build(c_file, tmp)
    os.replace(o, obj)
    trim_text(obj, size)
    return obj


def trim_text(obj, size):
    """gas 2.6 pads .text to 16 bytes with zeros; the game packs functions at 4. Shrink the section header to the
    function's real size and alignment (the padding lies past every relocation, so nothing is lost)."""
    import io
    import struct
    from elftools.elf.elffile import ELFFile
    data = bytearray(open(obj, 'rb').read())
    elf = ELFFile(io.BytesIO(bytes(data)))
    idx = elf.get_section_index('.text')
    sh = elf['e_shoff'] + idx * elf['e_shentsize']
    cur = struct.unpack_from('>I', data, sh + 20)[0]           # Elf32_Shdr.sh_size
    if cur < size or any(data[elf.get_section(idx)['sh_offset'] + size:elf.get_section(idx)['sh_offset'] + cur]):
        raise RuntimeError(f'{obj}: .text is {cur:#x} bytes, expected {size:#x} plus zero padding')
    struct.pack_into('>I', data, sh + 20, size)
    struct.pack_into('>I', data, sh + 32, 4)                    # sh_addralign
    open(obj, 'wb').write(data)


def main():
    jobs = int(sys.argv[sys.argv.index('-j') + 1]) if '-j' in sys.argv else 6
    os.makedirs(OBJ, exist_ok=True)
    funcs = func_list()
    c_done = {os.path.basename(p)[:-2]: p for p in glob.glob(os.path.join(ROOT, 'src', 'funcs', 'func_*.c'))}
    tasks = []
    for a, sz, name, s_path in funcs:
        o = os.path.join(OBJ, name + '.o')
        if name in c_done:
            tasks.append((lambda c, o, sz=sz: compile_c(c, o, sz), c_done[name], o))
        else:
            tasks.append((assemble, s_path, o))
    data = []
    for s_path in sorted(glob.glob(os.path.join(ROOT, 'asm', 'data', '*.s'))):
        o = os.path.join(OBJ, os.path.basename(s_path)[:-2] + '.o')
        data.append(o)
        tasks.append((lambda s, o: assemble(s, o, wrap=False), s_path, o))
    errors = []
    with cf.ThreadPoolExecutor(jobs) as ex:
        futs = [ex.submit(fn, s, o) for fn, s, o in tasks]
        for f in futs:
            try:
                f.result()
            except Exception as e:  # report all, fail at the end
                errors.append(str(e))
    if errors:
        print(f'{len(errors)} object(s) failed:')
        for e in errors[:10]:
            print('  ' + e)
        sys.exit(1)

    rodata = [o for o in data if '.rodata' in o]
    datas = [o for o in data if '.data' in o and '.rodata' not in o]
    lines = ['ENTRY(0x800C0480)', 'SECTIONS', '{', f'  . = 0x{VRAM:08X};', '  .main : SUBALIGN(4) {']
    lines += [f'    "{o}"(.rodata*)' for o in rodata]
    for a, sz, name, _ in funcs:
        lines.append(f'    . = 0x{a:08X};')
        lines.append(f'    "{os.path.join(OBJ, name + ".o")}"(.text)')
    lines += [f'    "{o}"(.data*)' for o in datas]
    lines += ['  }', '  /DISCARD/ : { *(.reginfo) *(.MIPS.abiflags) *(.pdr) *(.mdebug*) *(.gnu.attributes) *(.comment) }', '}']
    for f in ('undefined_syms_auto.txt', 'undefined_funcs_auto.txt'):
        for line in open(os.path.join(ROOT, 'config', f)):
            if re.match(r'\s*\w+\s*=\s*0x[0-9A-Fa-f]+;', line):
                lines.append(line.strip())
    script = os.path.join(OUT, 'main.ld')
    open(script, 'w', newline='\n').write('\n'.join(lines).replace('\\', '/') + '\n')
    elf, binf = os.path.join(OUT, 'main.elf'), os.path.join(OUT, 'main.bin')
    rsp = os.path.join(OUT, 'objs.rsp')   # ~2000 objects: too long for a Windows command line
    all_objs = rodata + [os.path.join(OBJ, name + '.o') for _, _, name, _ in funcs] + datas
    open(rsp, 'w', newline='\n').write('\n'.join('"' + o.replace(os.sep, '/') + '"' for o in all_objs) + '\n')
    def link():
        return subprocess.run([ZIG, 'ld.lld', '-m', 'elf32btsmip', '--no-check-sections', '-T', script, '-o', elf,
                               '--noinhibit-exec', '@' + rsp], capture_output=True, text=True)
    r = link()
    # Labels that splat references by address (jump-table and pointer targets inside functions) but defines nowhere:
    # their names carry their addresses, so define them and link again.
    undefined = sorted(set(re.findall(r'undefined symbol: ((?:func_|D_|jtbl_|L_|jlabel_|\.L)([0-9A-F]{8}))\b', r.stderr)))
    if undefined:
        with open(script, 'a', newline='\n') as f:
            for name, addr in undefined:
                f.write(f'{name} = 0x{addr};\n')
        r = link()
    if r.returncode and not os.path.exists(elf):
        print('link failed:\n' + r.stderr[:2000])
        sys.exit(1)
    warn = [l for l in r.stderr.splitlines() if 'error' in l]
    r = subprocess.run([ZIG, 'objcopy', '-O', 'binary', '--only-section=.main', elf, binf], capture_output=True, text=True)
    if r.returncode:
        print('objcopy failed: ' + r.stderr[:500])
        sys.exit(1)
    mine, theirs = open(binf, 'rb').read(), open(os.path.join(ROOT, 'work', 'main.bin'), 'rb').read()
    n_c = sum(1 for _, _, name, _ in funcs if name in c_done)
    if mine == theirs:
        print(f'OK: build/main.bin is identical to the game ({len(mine):#x} bytes; {n_c} C functions, '
              f'{len(funcs) - n_c} asm)')
        return
    diffs = [i for i in range(0, min(len(mine), len(theirs)), 4) if mine[i:i + 4] != theirs[i:i + 4]]
    print(f'MISMATCH: size {len(mine):#x} vs {len(theirs):#x}, {len(diffs)} differing words')
    for i in diffs[:8]:
        print(f'  0x{VRAM + i:08X}: built {mine[i:i + 4].hex()} game {theirs[i:i + 4].hex()}')
    for l in warn[:5]:
        print('  link: ' + l)
    sys.exit(1)


if __name__ == '__main__':
    main()
