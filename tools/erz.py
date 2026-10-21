#!/usr/bin/env python3
"""ERZ = Edge of Reality's renamed RNC ProPack blocks (magic b'ERZ\\x01' / b'ERZ\\x02').

Header (18 bytes, big-endian): magic[4] unpacked[4] packed[4] crc_unpacked[2] crc_packed[2] leftover[1] chunks[1].
Method 1 follows Simon Tatham's dernc; method 2 runs the game's own MIPS routine (0x80000CE8).
Every unpack is checked against the header CRC-16 (poly 0xA001).

  python tools/erz.py scan  ROM            list blocks
  python tools/erz.py dump  ROM OUTDIR     unpack every block to OUTDIR/<romoffset>.bin (+ index.csv)
"""
import csv
import os
import struct
import sys

MAGICS = (b'ERZ\x01', b'ERZ\x02')

_CRC = []
for _i in range(256):
    _c = _i
    for _ in range(8):
        _c = (_c >> 1) ^ 0xA001 if _c & 1 else _c >> 1
    _CRC.append(_c)


def crc16(data):
    c = 0
    for b in data:
        c = _CRC[(c ^ b) & 0xFF] ^ (c >> 8)
    return c


class Bits1:
    """dernc bit reader: little-endian 16-bit words, LSB first; p points at the last loaded word."""

    def __init__(self, d, p):
        self.d, self.p = d, p
        self.buf, self.cnt = self.word(p), 16

    def word(self, p):
        d = self.d
        return (d[p] if p < len(d) else 0) | ((d[p + 1] if p + 1 < len(d) else 0) << 8)

    def peek(self, mask):
        return self.buf & mask

    def advance(self, n):
        self.buf >>= n
        self.cnt -= n
        if self.cnt < 16:
            self.p += 2
            self.buf |= self.word(self.p) << self.cnt
            self.cnt += 16

    def read(self, n):
        v = self.buf & ((1 << n) - 1)
        self.advance(n)
        return v

    def fix(self):
        self.cnt -= 16
        self.buf &= (1 << self.cnt) - 1
        self.buf |= self.word(self.p) << self.cnt
        self.cnt += 16


def _mirror(x, n):
    r = 0
    for _ in range(n):
        r = (r << 1) | (x & 1)
        x >>= 1
    return r


def _table(bs):
    num = bs.read(5)
    if not num:
        return []
    lens = [bs.read(4) for _ in range(num)]
    out, code = [], 0
    for k in range(1, 17):
        for i, ln in enumerate(lens):
            if ln == k:
                out.append((_mirror(code, k), k, i))
                code += 1
        code <<= 1
    return out


def _huf(tab, bs):
    for code, ln, val in tab:
        if bs.peek((1 << ln) - 1) == code:
            bs.advance(ln)
            if val >= 2:
                val = (1 << (val - 1)) | bs.read(val - 1)
            return val
    raise ValueError('bad huffman code')


def unpack1(d, off, usz, psz):
    out = bytearray()
    bs = Bits1(d, off + 18)
    bs.advance(2)
    while len(out) < usz:
        raw, dist, ln = _table(bs), _table(bs), _table(bs)
        chunks = bs.read(16)
        while True:
            n = _huf(raw, bs)
            if n:
                out += d[bs.p:bs.p + n]
                bs.p += n
                bs.fix()
            chunks -= 1
            if chunks <= 0:
                break
            posn = _huf(dist, bs) + 1
            n = _huf(ln, bs) + 2
            for _ in range(n):
                out.append(out[-posn])
    return bytes(out[:usz])


def unpack2(d, off, usz, psz):
    """RNC method 2, run through the game's own routine at 0x80000CE8 (tools/mips_mini.py)."""
    from mips_mini import Cpu
    cpu = Cpu()
    cpu.load(0x80000400, d[0x1000:0x101000])     # boot segment, as IPL3 loads it
    src, dst = 0x80200000, 0x80400000
    cpu.load(src, d[off:off + 18 + psz])
    cpu.r[4], cpu.r[5], cpu.r[29] = src, dst, 0x801FFF00
    cpu.call(0x80000CE8)
    return cpu.read(dst, usz)


def header(d, o):
    usz, psz, cu, cp = struct.unpack_from('>IIHH', d, o + 4)
    return usz, psz, cu, cp


def scan(d):
    hits = []
    for m in MAGICS:
        i = d.find(m)
        while i >= 0:
            usz, psz, cu, cp = header(d, i)
            if 0 < psz < usz < 0x1000000 and i + 18 + psz <= len(d) and crc16(d[i + 18:i + 18 + psz]) == cp:
                hits.append((i, m[3], usz, psz, cu))
            i = d.find(m, i + 1)
    return sorted(hits)


def unpack(d, o):
    usz, psz, cu, _ = header(d, o)
    fn = unpack1 if d[o + 3] == 1 else unpack2
    out = fn(d, o, usz, psz)
    return out, crc16(out) == cu


def main():
    cmd, rom = sys.argv[1], sys.argv[2]
    d = open(rom, 'rb').read()
    blocks = scan(d)
    if cmd == 'scan':
        m1 = sum(1 for b in blocks if b[1] == 1)
        print(f'{len(blocks)} blocks ({m1} method 1, {len(blocks) - m1} method 2), '
              f'unpacked {sum(b[2] for b in blocks):#x}, packed {sum(b[3] for b in blocks):#x}')
        return
    outdir = sys.argv[3]
    os.makedirs(outdir, exist_ok=True)
    bad = []
    with open(os.path.join(outdir, 'index.csv'), 'w', newline='') as f:
        w = csv.writer(f)
        w.writerow(['rom', 'method', 'unpacked', 'packed', 'crc_ok'])
        for o, meth, usz, psz, _ in blocks:
            try:
                out, ok = unpack(d, o)
            except Exception as e:
                out, ok = b'', False
            if ok:
                open(os.path.join(outdir, f'{o:07X}.bin'), 'wb').write(out)
            else:
                bad.append((o, meth))
            w.writerow([f'{o:#x}', meth, usz, psz, int(ok)])
    print(f'{len(blocks) - len(bad)}/{len(blocks)} blocks unpacked with matching CRC')
    for o, meth in bad[:10]:
        print(f'  failed: {o:#x} method {meth}')


if __name__ == '__main__':
    main()
