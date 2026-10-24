#!/usr/bin/env python3
"""Pack a rebuilt main segment into a copy of the owner's ROM, so it can be booted in an emulator.

  python tools/pack_rom.py build/OUT.z64 [--main build/main.bin] [--rom ROM]   (ROM defaults to $THPS_ROM)

The main segment is stored as raw (uncompressed) chunks: boot's loader (0x80000870, see tools/build_main.py) reads
the chunk table at ROM 0x13B14 (u32 count, count+1 offsets relative to 0x13B14), PIO-reads each chunk into its
0x803E0000 buffer and, when the chunk does not start with "ERZ", copies it as is to 0x80016AC0 + i*0x10000; then it
jumps to 0x800C0480. So every chunk but the last is 0x10000 bytes, any count works (the table is read into
0x803C0000 by its own count), and raw chunk sizes must be multiples of 4 (the PIO reads whole words).
The raw chunks do not fit where the ERZ chunks were (0x13B54..0x61E26, followed by the assets, whose ROM base
0x13B10 points at), so they go after the end of the ROM; the table stays at 0x13B14 and grows over the old,
now unused, compressed chunks. Then the header checksum is recomputed (the CIC is identified from the IPL3
bootcode; this ROM uses CIC-NUS-6102).
Output must go under build/ (gitignored): ROM bytes are never committed.
"""
import argparse
import hashlib
import os
import struct
import subprocess
import sys
import zlib

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TABLE = 0x13B14
ASSET_BASE = 0x13B10          # u32: ROM address of the assets; the chunk table must stay below it
CHUNK = 0x10000
MAIN_VRAM = 0x80016AC0
# CRC32 of the IPL3 bootcode (ROM 0x40..0x1000) -> CIC, and that CIC's checksum seed
CICS = {0x6170A4A1: ('6101', 0xF8CA4DDC), 0x90BB6CB5: ('6102', 0xF8CA4DDC)}


def n64_crc(rom, seed):
    """The CIC-NUS-6101/6102 header checksum over ROM 0x1000..0x101000 -> (crc1, crc2)."""
    m = 0xFFFFFFFF
    t1 = t2 = t3 = t4 = t5 = t6 = seed
    words = struct.unpack_from('>262144I', rom, 0x1000)
    for d in words:
        k = (t6 + d) & m
        if k < t6:
            t4 = (t4 + 1) & m
        t6 = k
        t3 ^= d
        s = d & 0x1F
        r = ((d << s) | (d >> (32 - s))) & m if s else d
        t5 = (t5 + r) & m
        t2 ^= r if t2 > d else t6 ^ d
        t1 = (t1 + (t5 ^ d)) & m
    return t6 ^ t4 ^ t3, t5 ^ t2 ^ t1


def unpack(rom):
    """The main image as boot's loader would build it (raw chunks only)."""
    n = struct.unpack_from('>I', rom, TABLE)[0]
    offs = struct.unpack_from(f'>{n + 1}I', rom, TABLE + 4)
    img = bytearray()
    for i in range(n):
        o, size = TABLE + offs[i], offs[i + 1] - offs[i]
        if rom[o:o + 3] == b'ERZ':
            raise ValueError(f'chunk {i} is compressed')
        if len(img) != CHUNK * i or size % 4 or size > CHUNK:
            raise ValueError(f'chunk {i}: {size:#x} bytes would not land at 0x{MAIN_VRAM + CHUNK * i:08X}')
        img += rom[o:o + size]
    return bytes(img)


def main():
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('out')
    ap.add_argument('--main', default=os.path.join(ROOT, 'build', 'main.bin'))
    ap.add_argument('--rom', default=os.environ.get('THPS_ROM'))
    a = ap.parse_args()
    out = os.path.abspath(a.out)
    build = os.path.join(ROOT, 'build')
    if os.path.commonpath([out, build]) != build:
        sys.exit(f'refusing to write {out}: ROM output goes under {build}/ only')
    r = subprocess.run(['git', 'check-ignore', '-q', os.path.relpath(out, ROOT)], cwd=ROOT)
    if r.returncode != 0:
        sys.exit(f'{out} is not gitignored: refusing to write ROM bytes there')
    if not a.rom or not os.path.isfile(a.rom):
        sys.exit('no ROM: pass --rom or set THPS_ROM')
    rom = bytearray(open(a.rom, 'rb').read())
    main_img = open(a.main, 'rb').read()

    cic = zlib.crc32(rom[0x40:0x1000])
    if cic not in CICS:
        sys.exit(f'unknown CIC (bootcode crc32 {cic:#010x}): only 6101/6102 checksums are implemented')
    name, seed = CICS[cic]
    if n64_crc(rom, seed) != struct.unpack_from('>II', rom, 0x10):
        sys.exit('the input ROM\'s own header checksum does not verify: wrong byte order or a modified ROM?')
    boot_sha1 = hashlib.sha1(rom[0x1000:0x13A10]).hexdigest()
    want = None
    for line in open(os.path.join(ROOT, 'config', 'boot.yaml')):
        if line.startswith('sha1:'):
            want = line.split()[1]
    if want and boot_sha1 != want:
        sys.exit(f'boot segment sha1 {boot_sha1} is not the one config/boot.yaml expects')

    if len(main_img) % 4:
        main_img += bytes(4 - len(main_img) % 4)
    chunks = [main_img[i:i + CHUNK] for i in range(0, len(main_img), CHUNK)]
    for i, c in enumerate(chunks):
        if c[:3] == b'ERZ':
            sys.exit(f'raw chunk {i} starts with "ERZ": boot would take it for a compressed one')
    n = len(chunks)
    asset_base = struct.unpack_from('>I', rom, ASSET_BASE)[0] & 0x0FFFFFFF
    if TABLE + 4 * (n + 2) > asset_base:
        sys.exit(f'{n} chunks: the table would run into the assets at {asset_base:#x}')
    base = (len(rom) + 0xF) & ~0xF
    rom += bytes(base - len(rom))
    offs = []
    for c in chunks:
        offs.append(len(rom) - TABLE)
        rom += c
    offs.append(len(rom) - TABLE)
    struct.pack_into(f'>I{n + 1}I', rom, TABLE, n, *offs)
    struct.pack_into('>II', rom, 0x10, *n64_crc(rom, seed))

    if unpack(rom) != main_img:
        sys.exit('internal error: the packed ROM does not unpack to the main image')
    os.makedirs(os.path.dirname(out), exist_ok=True)
    open(out, 'wb').write(rom)
    end = MAIN_VRAM + len(main_img)
    print(f'{os.path.relpath(out, ROOT)}: {len(rom):#x} bytes, CIC-NUS-{name}; main {len(main_img):#x} bytes '
          f'(0x{MAIN_VRAM:08X}-0x{end:08X}) as {n} raw chunks at ROM {base:#x}')


if __name__ == '__main__':
    main()
