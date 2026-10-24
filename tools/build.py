#!/usr/bin/env python3
"""Full build of the main segment: every function from its matched C (src/funcs) or else its splat asm, linked at
its address, and compared byte for byte with work/main.bin (the unpacked game code).

  python tools/build.py [-j N] [--no-cache]   -> build/main.elf, build/main.bin; exit 0 only if identical
  python tools/build.py --nonmatching[=func_A,func_B] [--nonmatching-exclude=func_C,...]
      -> build/nm/main.bin: the game with src/nonmatching C in place of those functions' asm (see nm_* below;
         not byte-identical by design; tools/pack_rom.py turns it into a bootable ROM)
Unchanged objects come from build/objcache (keyed by source bytes + all shared inputs); --no-cache rebuilds all.

This is the whole-binary check behind tools/gate.py's per-function one: it also proves relocations, data and the
link order. Functions: asm/nonmatchings/game/*.s (splat), C: src/funcs/func_XXXXXXXX.c (KMC GCC 2.7.2 + gas 2.6),
asm and data: zig's LLVM assembler, link: ld.lld. Symbols splat could not place come from config/undefined_*.txt.
"""
import concurrent.futures as cf
import glob
import hashlib
import os
import re
import shutil
import subprocess
import sys

sys.path.insert(0, os.path.dirname(__file__))
import match  # noqa: E402  (C compile pipeline)

ROOT = match.ROOT
ZIG = match.ZIG
VRAM = 0x80016AC0
OUT = os.path.join(ROOT, 'build')
OBJ = os.path.join(OUT, 'obj')
CACHE = os.path.join(OUT, 'objcache')   # content-addressed objects reused across builds (see cached())
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


def cached(fn, kind, digest):
    """Wrap an object builder with a content-addressed cache (build/objcache). The key covers the source file's
    bytes, what kind of object it is, and `digest` (every shared input: tools, include, config, toolchain, the
    cc1/gas/zig binaries, main.bin), so an object is reused only when nothing it depends on changed. The link and
    the byte comparison below always run in full."""
    def run(src, o):
        h = hashlib.sha256(f'{digest}\0{kind}\0'.encode())
        h.update(open(src, 'rb').read())
        hit = os.path.join(CACHE, h.hexdigest() + '.o')
        if os.path.exists(hit):
            shutil.copyfile(hit, o)
            return o
        fn(src, o)
        tmp = hit + f'.{os.getpid()}.tmp'
        shutil.copyfile(o, tmp)
        os.replace(tmp, hit)
        return o
    return run


# --- non-matching build (--nonmatching) ------------------------------------------------------------------------
# Each selected src/nonmatching/func_X.c is compiled as `nmc_func_X` (renamed, so it never clashes with the asm
# unit that still defines func_X) and linked into a new region NM_REGION; the asm of func_X stays where it is and
# its first two words become `j nmc_func_X; nop`. Every other address in main is unchanged, and the C's references
# (functions, D_ data, jump tables, float literals, strings) resolve through the same link as the game's.
#
# Why NM_REGION = 0x800FC970 is free: the game owns all RAM from there to the end. Boot (boot.bin 0x80000890)
# clears main's bss 0x800F6460..0x800FC8C4; the last bss objects are D_800FC910 and the viewport D_800FC950
# (16 bytes, func_800BD740), ending at 0x800FC960. Main's start-up func_800C03CC then hands everything from
# D_800FC970 to 0x80000000 + osMemSize (D_80000318) to the heap: func_8009E3A0(D_800EA110, D_800FC970,
# osMemSize - (D_800FC970 - 0x80000000)). The frame and Z buffers are heap blocks taken at fixed addresses
# (func_800BDEA8 / func_800BE144 / func_800BDD9C via func_8009EAE0; lowest one 0x8016A000, the 640x480
# framebuffer), all far above. No code references 0x800FC970.. by any other symbol. So the region is carved from
# the front of the heap: the link moves D_800FC970 (the heap base, referenced only by func_800C03CC) to the end of
# the region, and the heap shrinks by the region's size (~0xC000 for all files: ~1.5% of a 4 MB heap). Boot's
# loader buffers (0x803C0000..0x80400000) are only used before the game starts. The loaded image now runs through
# bss (zeros, which boot has already cleared) up to the region's end.
NM_REGION = 0x800FC970
NM_HEAP_SYM = 'D_800FC970'
NM_LIMIT = 0x8016A000   # lowest fixed-address heap block (640x480 framebuffer): the region must end well below


def nm_select(argv):
    """-> None (default build), or the sorted names of the src/nonmatching functions to build from C."""
    sel = [a for a in argv if a == '--nonmatching' or a.startswith(('--nonmatching=', '--nonmatching-exclude='))]
    if not sel:
        return None
    avail = sorted(os.path.basename(p)[:-2] for p in glob.glob(os.path.join(ROOT, 'src', 'nonmatching', 'func_*.c')))
    names = set(avail)
    for a in sel:
        if a.startswith('--nonmatching='):
            want = [x for x in a.split('=', 1)[1].split(',') if x]
            want = [x if x.startswith('func_') else 'func_' + x.upper().removeprefix('0X') for x in want]
            bad = [x for x in want if x not in avail]
            if bad:
                sys.exit(f'--nonmatching: no src/nonmatching file for {", ".join(bad)}')
            names &= set(want)
    for a in sel:
        if a.startswith('--nonmatching-exclude='):
            names -= {x if x.startswith('func_') else 'func_' + x.upper().removeprefix('0X')
                      for x in a.split('=', 1)[1].split(',') if x}
    return sorted(names)


def compile_nm(c_file, obj):
    """Compile a src/nonmatching file with its function renamed to nmc_func_X (a #define after the compiler/cflags
    comment lines, which match.build reads from the top). The rename also keeps match.float_literals and
    match.jump_tables from pointing the C at the game's literal/jump-table slots for the asm version: the C keeps
    its own literals and jump tables (in its .rodata, linked into the region)."""
    name = os.path.basename(c_file)[:-2]
    lines = open(c_file, encoding='utf-8', errors='replace').read().split('\n')
    k = 0
    while k < min(2, len(lines)) and re.match(r'\s*/\*\s*(compiler|cflags):', lines[k]):
        k += 1
    lines.insert(k, f'#define {name} nmc_{name}')
    lines = [l.replace(f'"{name}"', f'"nmc_{name}"') for l in lines]   # C++ `__asm__("func_X")` symbol names
    src_dir = os.path.join(os.path.dirname(obj), 'src')
    os.makedirs(src_dir, exist_ok=True)
    renamed = os.path.join(src_dir, name + '.c')
    with open(renamed, 'w', newline='\n') as f:
        f.write('\n'.join(lines))
    tmp = obj[:-2] + '.d'
    os.makedirs(tmp, exist_ok=True)
    os.replace(match.build(renamed, tmp), obj)
    from elftools.elf.elffile import ELFFile
    with open(obj, 'rb') as fh:
        elf = ELFFile(fh)
        defined = [s.name for s in elf.get_section_by_name('.symtab').iter_symbols()
                   if s['st_info']['bind'] == 'STB_GLOBAL' and s['st_shndx'] != 'SHN_UNDEF']
    if f'nmc_{name}' not in defined:
        raise RuntimeError(f'{c_file}: does not define {name}')
    other = [d for d in defined if d != f'nmc_{name}']
    if other:   # a global the game already has would be defined twice (or silently split from the game's copy)
        raise RuntimeError(f'{c_file}: defines globals besides {name}: {" ".join(other)} (make them static/extern)')
    return obj


def nm_finish(elf_path, bin_path, nm_names, funcs):
    """Patch the trampolines into the linked image, check that nothing else in main moved, and report."""
    import struct
    from elftools.elf.elffile import ELFFile
    with open(elf_path, 'rb') as fh:
        elf = ELFFile(fh)
        syms = {s.name: s['st_value'] for s in elf.get_section_by_name('.symtab').iter_symbols()}
    img = bytearray(open(bin_path, 'rb').read())
    game = open(os.path.join(ROOT, 'work', 'main.bin'), 'rb').read()
    end, heap = syms['__nm_end'], syms[NM_HEAP_SYM]
    if len(img) < NM_REGION - VRAM:   # an empty .nm section
        img += bytes(NM_REGION - VRAM - len(img))
    if NM_REGION - VRAM + (end - NM_REGION) != len(img):
        sys.exit(f'nm: image is {len(img):#x} bytes, expected to end at the region end {end:#010x}')
    if end > NM_LIMIT - 0x40000:
        sys.exit(f'nm: region 0x{NM_REGION:08X}-0x{end:08X} is too large (heap would lose too much)')
    addr = {name: a for a, _, name, _ in funcs}
    size = {name: sz for _, sz, name, _ in funcs}
    tramp = {}
    lines = []
    for name in nm_names:
        a, t = addr[name], syms[f'nmc_{name}']
        if (a ^ t) & 0xF0000000:
            sys.exit(f'nm: {name} -> {t:#x} is out of j range')
        o = a - VRAM
        struct.pack_into('>II', img, o, 0x08000000 | ((t >> 2) & 0x3FFFFFF), 0)
        tramp[o], tramp[o + 4] = name, name
        lines.append(f'{name} 0x{a:08X} -> nmc_{name} 0x{t:08X}')
    # Only the trampolines and the heap-base %hi/%lo in func_800C03CC may differ from the game in the old range;
    # past it the image is the zeroed bss (boot clears it anyway), then the region.
    diffs = [i for i in range(0, len(game), 4) if img[i:i + 4] != game[i:i + 4] and i not in tramp]
    h0 = addr['func_800C03CC'] - VRAM
    heap_refs = [i for i in diffs if h0 <= i < h0 + size['func_800C03CC']]
    stray = [i for i in diffs if i not in heap_refs]
    if stray or any(img[len(game):NM_REGION - VRAM]):
        for i in stray[:8]:
            print(f'  0x{VRAM + i:08X}: built {img[i:i + 4].hex()} game {game[i:i + 4].hex()}')
        sys.exit(f'nm: {len(stray)} word(s) outside the trampolines differ from the game (or bss is not zero)')
    open(bin_path, 'wb').write(img)
    open(os.path.join(os.path.dirname(bin_path), 'trampolines.txt'), 'w', newline='\n').write('\n'.join(lines) + '\n')
    print(f'NONMATCHING: {os.path.relpath(bin_path, ROOT)} ({len(img):#x} bytes): {len(nm_names)} function(s) from C '
          f'in 0x{NM_REGION:08X}-0x{end:08X} ({end - NM_REGION:#x} bytes), heap base {heap:#010x}; '
          f'{len(heap_refs)} heap-base word(s) changed, everything else in main identical')


def main():
    import fresh
    import gate
    fresh.ensure()
    jobs = int(sys.argv[sys.argv.index('-j') + 1]) if '-j' in sys.argv else max(1, (os.cpu_count() or 2) - 1)
    os.makedirs(OBJ, exist_ok=True)
    os.makedirs(CACHE, exist_ok=True)
    digest = 'off' if '--no-cache' in sys.argv else (
        gate.shared_digest() + f'\0{ZIG}\0{os.path.getsize(ZIG)}\0{AS_FLAGS}\0{match.CFLAGS}\0{match.ASFLAGS}')
    wrap = (lambda fn, kind: fn) if digest == 'off' else (lambda fn, kind: cached(fn, kind, digest))
    funcs = func_list()
    nm = nm_select(sys.argv)
    out = OUT if nm is None else os.path.join(OUT, 'nm')
    os.makedirs(out, exist_ok=True)
    c_done = {os.path.basename(p)[:-2]: p for p in glob.glob(os.path.join(ROOT, 'src', 'funcs', 'func_*.c'))}
    tasks = []
    for a, sz, name, s_path in funcs:
        o = os.path.join(OBJ, name + '.o')
        if name in c_done:
            tasks.append((wrap(lambda c, o, sz=sz: compile_c(c, o, sz), f'c:{sz:#x}'), c_done[name], o))
        else:
            tasks.append((wrap(assemble, 'asm:wrap'), s_path, o))
    nm_objs = []
    for name in nm or []:
        o = os.path.join(OBJ, 'nm', name + '.o')
        os.makedirs(os.path.dirname(o), exist_ok=True)
        nm_objs.append(o)
        tasks.append((wrap(compile_nm, 'nm-c'), os.path.join(ROOT, 'src', 'nonmatching', name + '.c'), o))
    data = []
    for s_path in sorted(glob.glob(os.path.join(ROOT, 'asm', 'data', '*.s'))):
        o = os.path.join(OBJ, os.path.basename(s_path)[:-2] + '.o')
        data.append(o)
        tasks.append((wrap(lambda s, o: assemble(s, o, wrap=False), 'asm:data'), s_path, o))
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
        first = errors[0].split(':', 1)
        name = os.path.basename(first[0]).split('.')[0]
        detail = ' '.join(first[1].split())[:160] if len(first) > 1 else ''
        print(f'BUILD FAIL: {len(errors)} object(s) failed; first: {name}: {detail}')
        sys.exit(1)

    rodata = [o for o in data if '.rodata' in o]
    datas = [o for o in data if '.data' in o and '.rodata' not in o]
    lines = ['ENTRY(0x800C0480)', 'SECTIONS', '{', f'  . = 0x{VRAM:08X};', '  .main : SUBALIGN(4) {']
    lines += [f'    "{o}"(.rodata*)' for o in rodata]
    for a, sz, name, _ in funcs:
        lines.append(f'    . = 0x{a:08X};')
        lines.append(f'    "{os.path.join(OBJ, name + ".o")}"(.text)')
    lines += [f'    "{o}"(.data*)' for o in datas]
    lines += ['  }']
    if nm is not None:
        lines += [f'  .nm 0x{NM_REGION:08X} : {{']
        lines += [f'    "{o}"(.text .rodata* .data* .sdata* .sbss* .bss* COMMON)' for o in nm_objs]
        lines += ['    . = ALIGN(16);', '    __nm_end = .;', '  }']
    lines += ['  /DISCARD/ : { *(.reginfo) *(.MIPS.abiflags) *(.pdr) *(.mdebug*) *(.gnu.attributes) *(.comment) }', '}']
    for f in ('undefined_syms_auto.txt', 'undefined_funcs_auto.txt'):
        for line in open(os.path.join(ROOT, 'config', f)):
            if re.match(r'\s*\w+\s*=\s*0x[0-9A-Fa-f]+;', line):
                if nm is not None and line.split('=')[0].strip() == NM_HEAP_SYM:
                    line = f'{NM_HEAP_SYM} = __nm_end;   /* heap base, moved past the non-matching region */'
                lines.append(line.strip())
    # symbols outside main that C calls by another name (splat leaves `absolute:True` ones out of the files above)
    for line in open(os.path.join(ROOT, 'config', 'symbol_addrs.txt')):
        m = re.match(r'\s*(\w+\s*=\s*0x[0-9A-Fa-f]+;).*absolute:True', line)
        if m:
            lines.append(m.group(1))
    # names C calls for code that is already a func_XXXXXXXX in main (libgcc helpers); kept out of symbol_addrs.txt
    # because find_funcs/splat would stop treating those addresses as functions
    aliases = os.path.join(ROOT, 'config', 'link_aliases.txt')
    if os.path.exists(aliases):
        with open(aliases) as f:
            for line in f:
                m = re.match(r'\s*(\w+\s*=\s*0x[0-9A-Fa-f]+;)', line)
                if m:
                    lines.append(m.group(1))
    if nm is not None and not any(l.startswith(NM_HEAP_SYM + ' = __nm_end') for l in lines):
        sys.exit(f'nm: {NM_HEAP_SYM} (heap base) not in config/undefined_syms_auto.txt')
    script = os.path.join(out, 'main.ld')
    open(script, 'w', newline='\n').write('\n'.join(lines).replace('\\', '/') + '\n')
    elf, binf = os.path.join(out, 'main.elf'), os.path.join(out, 'main.bin')
    rsp = os.path.join(out, 'objs.rsp')   # ~2000 objects: too long for a Windows command line
    all_objs = rodata + [os.path.join(OBJ, name + '.o') for _, _, name, _ in funcs] + datas + nm_objs
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
    if nm is not None:
        # zig objcopy keeps only the last --only-section: copy the region on its own and join them (bss gap = zeros)
        r = subprocess.run([ZIG, 'objcopy', '-O', 'binary', '--only-section=.nm', elf, binf + '.nm'], capture_output=True, text=True)
        if r.returncode:
            print('objcopy failed: ' + r.stderr[:500])
            sys.exit(1)
        with open(binf, 'r+b') as f:
            f.seek(NM_REGION - VRAM)
            f.write(open(binf + '.nm', 'rb').read())
        os.remove(binf + '.nm')
        for l in warn[:5]:
            print('  link: ' + l)
        nm_finish(elf, binf, nm, funcs)
        return
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
