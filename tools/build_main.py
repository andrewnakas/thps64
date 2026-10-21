#!/usr/bin/env python3
"""Rebuild the game's RAM image the way boot (0x80000870) does, as an uncompressed "baserom" for splat/N64Recomp.

Boot: ROM 0x1000.. -> 0x80000400 (code+data to 0x80012F10, bss to 0x80016AC0).
Chunk table at ROM 0x13B14: u32 count, then count+1 offsets (relative to 0x13B14).
Each chunk is ERZ1/ERZ2 or raw, and lands at 0x80016AC0 + i*0x10000. Then boot jumps to 0x800C0480.

  python tools/build_main.py ROM work/   -> work/main.bin (RAM 0x80016AC0..), work/boot.bin, work/layout.txt
"""
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(__file__))
import erz  # noqa: E402

TABLE = 0x13B14
MAIN_VRAM = 0x80016AC0


def main():
    rom, out = sys.argv[1], sys.argv[2]
    d = open(rom, 'rb').read()
    os.makedirs(out, exist_ok=True)
    n = struct.unpack_from('>I', d, TABLE)[0]
    offs = struct.unpack_from(f'>{n + 1}I', d, TABLE + 4)
    img = bytearray()
    lines = [f'boot  rom 0x001000-0x013A10 vram 0x80000400-0x80012F10 (bss to {MAIN_VRAM:#x})']
    for i in range(n):
        o, size = TABLE + offs[i], offs[i + 1] - offs[i]
        kind = d[o:o + 4]
        if kind[:3] == b'ERZ':
            chunk, ok = erz.unpack(d, o)
            if not ok:
                sys.exit(f'chunk {i} at {o:#x}: CRC mismatch')
        else:
            chunk = d[o:o + size]
        lines.append(f'chunk {i:2d} rom {o:#08x} {kind[:3].decode("latin1")}{kind[3]} -> vram {MAIN_VRAM + len(img):#x} +{len(chunk):#x}')
        img += chunk
        if i < n - 1 and len(chunk) != 0x10000:
            sys.exit(f'chunk {i} is {len(chunk):#x} bytes, expected 0x10000')
    open(os.path.join(out, 'main.bin'), 'wb').write(img)
    open(os.path.join(out, 'boot.bin'), 'wb').write(d[0x1000:0x13A10])
    lines.append(f'main  vram {MAIN_VRAM:#x}-{MAIN_VRAM + len(img):#x} ({len(img):#x} bytes), entry 0x800C0480')
    lines.append(f'assets from rom {struct.unpack_from(">I", d, 0x13B10)[0] & 0x0FFFFFFF:#x}')
    open(os.path.join(out, 'layout.txt'), 'w').write('\n'.join(lines) + '\n')
    print('\n'.join(lines[-3:]))


if __name__ == '__main__':
    main()
