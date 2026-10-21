#!/usr/bin/env python3
"""Name the libultra functions inside THPS by compiling decompals/ultralib (libgultra_rom) with our
KMC GCC 2.7.2 toolchain and searching boot.bin + main.bin for each function (relocations masked).

  python tools/ultralib_scan.py ULTRALIB_DIR [VERSIONS=L,K,J,I]
-> per-version hit counts, and work/ultralib_<V>.txt (name = 0xADDR, one per unique hit).
Needs the game image from tools/build_main.py. Read-only on the game; writes only under work/.
"""
import concurrent.futures as cf
import io
import os
import struct
import subprocess
import sys
import tempfile

from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TOOLS = os.environ.get('THPS_TOOLS', 'E:/thps64-tools/bin')
ZIG = os.environ.get('ZIG', 'C:/Users/andre/.local/zig-x86_64-windows-0.16.0/zig.exe')
IMAGES = [('boot', os.path.join(ROOT, 'work', 'boot.bin'), 0x80000400),
          ('main', os.path.join(ROOT, 'work', 'main.bin'), 0x80016AC0)]
OPT_OVERRIDE = {'os/initialize_isv.c': '-O2', 'os/assert.c': '-O0', 'os/seterrorhandler.c': '-O0'}


IDO = os.environ.get('IDO', 'E:/thps64-tools/ido53')
IDO_O1_DIRS = ('debug/', 'host/', 'os/', 'rmon/', 'log/')
IDO_O1_FILES = ('libc/ll.c', 'libc/llbit.c', 'libc/llcvt.c')


def compile_ido(ul, rel, version):
    """Nintendo's libultra.a / libultra_rom.a: IDO 5.3, -O1 for 2.0I and older, else -O2 (os/ etc. always -O1)."""
    src = os.path.join(ul, 'src', rel)
    opt = '-O1' if (version in 'DEFGHI' or rel.startswith(IDO_O1_DIRS) or rel in IDO_O1_FILES) else '-O2'

    def rp(sub):
        return os.path.relpath(os.path.join(ul, sub), os.path.dirname(src)).replace(os.sep, '/')

    with tempfile.TemporaryDirectory(dir=os.path.join(ul, 'build_tmp')) as tmp:
        # IDO's cc does not take drive-letter paths: run in the source dir with relative names
        o = os.path.relpath(os.path.join(tmp, 'x.o'), os.path.dirname(src)).replace(os.sep, '/')
        defs = ['-D_MIPS_SZLONG=32', '-DF3DEX_GBI', f'-DBUILD_VERSION=VERSION_{version}', '-DNDEBUG', '-D_FINALROM',
                '-I', '.', '-I', rp('include'), '-I', rp('include/compiler/ido'), '-I', rp('include/PR'), '-I', rp('src')]
        # (no quoted -D values: cc.exe re-splits its command line)
        pre = subprocess.run([f'{IDO}/cc.exe', '-E', '-nostdinc', '-Xcpluscomm', '-mips2', '-o32', *defs, os.path.basename(src)],
                             capture_output=True, cwd=os.path.dirname(src))
        if pre.returncode:
            return None
        # the Windows IDO 5.3 cfe fails on inputs over ~32 KB: drop line markers, blank lines, extra spaces
        text = pre.stdout.decode('latin1').replace('\r', '')
        lines = []
        for line in text.split('\n'):
            line = ' '.join(line.split())
            if line and not line.startswith('#'):
                lines.append(line)
        small = os.path.join(tmp, 'x.i')
        open(small, 'w', encoding='latin1', newline='\n').write('\n'.join(lines) + '\n')
        if os.path.getsize(small) > 32000:
            # drop prototypes of functions the file never mentions again (headers declare all of libultra)
            import re as _re
            body = '\n'.join(lines)
            kept = []
            for line in lines:
                m = _re.match(r'^(?:extern\s+)?[\w\s\*]+?\b(\w+)\s*\([^{;]*\)\s*;$', line)
                if m and len(_re.findall(r'\b' + m.group(1) + r'\b', body)) == 1:
                    continue
                kept.append(line)
            open(small, 'w', encoding='latin1', newline='\n').write('\n'.join(kept) + '\n')
        if os.path.getsize(small) > 32000:
            return 'big'
        r = subprocess.run([f'{IDO}/cc.exe', '-c', '-Wab,-r4300_mul', '-G', '0', '-Xcpluscomm', '-w', '-mips2', '-o32',
                            '-non_shared', opt, 'x.i', '-o', 'x.o'], capture_output=True, cwd=tmp)
        full = os.path.join(tmp, 'x.o')
        if r.returncode or not os.path.exists(full):
            return None
        return funcs(open(full, 'rb').read())


def compile_one(ul, rel, version):
    if os.environ.get('ULTRA_CC') == 'ido':
        return compile_ido(ul, rel, version)
    src = os.path.join(ul, 'src', rel)
    opt = '-O0' if rel.startswith('rmon/') else OPT_OVERRIDE.get(rel, '-O3')
    inc = ['-I', os.path.dirname(src), '-I', os.path.join(ul, 'include'), '-I', os.path.join(ul, 'include', 'compiler', 'gcc'),
           '-I', os.path.join(ul, 'include', 'PR'), '-I', os.path.join(ul, 'src')]
    defs = ['-D_MIPS_SZLONG=32', '-D__USE_ISOC99', '-DF3DEX_GBI', f'-DBUILD_VERSION=VERSION_{version}',
            f'-DBUILD_VERSION_STRING="2.0{version}"', '-DNDEBUG', '-D_FINALROM', '-D_LANGUAGE_C', '-D__GNUC__=2',
            '-D__mips__', '-D_MIPS_SIM=1', '-D_ULTRA64']
    with tempfile.TemporaryDirectory() as tmp:
        i, s, o = (os.path.join(tmp, 'x' + e) for e in ('.i', '.s', '.o'))
        try:
            subprocess.run([ZIG, 'cc', '-E', '-P', '-x', 'c', '-nostdinc', '-undef', *defs, *inc, src, '-o', i],
                           check=True, capture_output=True)
            subprocess.run([f'{TOOLS}/cc1.exe', '-quiet', opt, '-mips3', '-mgp32', '-mfp32', '-G0', '-funsigned-char',
                            '-w', i, '-o', s], check=True, capture_output=True)
            subprocess.run([f'{TOOLS}/mips-as.exe', '-EB', '-mips3', '-G0', s, '-o', o], check=True,
                           capture_output=True, cwd=tmp)
            return funcs(open(o, 'rb').read())
        except subprocess.CalledProcessError:
            return None


def funcs(obj):
    elf = ELFFile(io.BytesIO(obj))
    text = elf.get_section_by_name('.text')
    if text is None:
        return []
    data, tidx = text.data(), elf.get_section_index('.text')
    masks = {}
    for sec in elf.iter_sections():
        if isinstance(sec, RelocationSection) and sec.name == '.rel.text':
            for r in sec.iter_relocations():
                t = r['r_info_type']
                masks[r['r_offset']] = 0xFC000000 if t == 4 else 0xFFFF0000 if t in (5, 6) else 0
    syms = sorted((s['st_value'], s.name) for s in elf.get_section_by_name('.symtab').iter_symbols()
                  if s['st_shndx'] == tidx and s['st_info']['type'] == 'STT_FUNC')
    out = []
    for k, (start, name) in enumerate(syms):
        end = syms[k + 1][0] if k + 1 < len(syms) else len(data)
        body = data[start:end]
        while len(body) > 8 and body[-4:] == b'\0\0\0\0':
            body = body[:-4]
        words = [struct.unpack_from('>I', body, j)[0] for j in range(0, len(body), 4)]
        mk = [masks.get(start + j, 0xFFFFFFFF) for j in range(0, len(body), 4)]
        out.append((name, words, mk))
    return out


def search(images, words, mk):
    if len(words) < 4:
        return []   # too short to name reliably
    anchor = next((j for j, m in enumerate(mk) if m == 0xFFFFFFFF and words[j] not in (0, 0x03E00008)), None)
    if anchor is None:
        return []
    key = struct.pack('>I', words[anchor])
    hits = []
    for tag, img, vram in images:
        pos = img.find(key)
        while pos >= 0:
            st = pos - anchor * 4
            if st >= 0 and st % 4 == 0 and st + 4 * len(words) <= len(img):
                if all((struct.unpack_from('>I', img, st + 4 * j)[0] & m) == (w & m) for j, (w, m) in enumerate(zip(words, mk))):
                    hits.append(vram + st)
            pos = img.find(key, pos + 1)
    return hits


def main():
    ul = sys.argv[1]
    versions = (sys.argv[2] if len(sys.argv) > 2 else 'L,K,J,I').split(',')
    images = [(t, open(p, 'rb').read(), v) for t, p, v in IMAGES]
    rels = sorted(os.path.relpath(os.path.join(dp, f), os.path.join(ul, 'src')).replace('\\', '/')
                  for dp, _, fs in os.walk(os.path.join(ul, 'src')) for f in fs if f.endswith('.c'))
    for v in versions:
        found, failed, total, big = {}, 0, 0, 0
        with cf.ThreadPoolExecutor(8) as ex:
            for rel, fl in zip(rels, ex.map(lambda r: compile_one(ul, r, v), rels)):
                if fl is None or fl == 'big':
                    failed += 1
                    big += fl == 'big'
                    continue
                for name, words, mk in fl:
                    total += 1
                    h = search(images, words, mk)
                    if len(h) == 1:
                        found[name] = h[0]
        with open(os.path.join(ROOT, 'work', f'ultralib_{os.environ.get("ULTRA_CC", "gcc")}_{v}.txt'), 'w') as f:
            for name, a in sorted(found.items(), key=lambda x: x[1]):
                f.write(f'{name} = 0x{a:08X}; // type:func\n')
        print(f'2.0{v}: {len(found)} of {total} compiled functions found once ({failed} files did not compile, {big} of them over the 32 KB IDO limit)', flush=True)


if __name__ == '__main__':
    main()
