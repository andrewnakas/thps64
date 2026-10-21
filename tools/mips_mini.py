"""Tiny MIPS interpreter: enough of the R4300 integer set to run the game's own leaf routines
(the ERZ method-2 unpacker at 0x80000CE8) on a flat RAM image. Not cycle- or exception-accurate."""
import struct

import rabbitizer

RAM_BASE = 0x80000000


class Cpu:
    def __init__(self, ram_size=0x800000):
        self.ram = bytearray(ram_size)
        self.r = [0] * 32
        self._dec = {}

    def load(self, addr, data):
        o = addr - RAM_BASE
        self.ram[o:o + len(data)] = data

    def read(self, addr, n):
        o = addr - RAM_BASE
        return bytes(self.ram[o:o + n])

    def _ins(self, pc):
        x = self._dec.get(pc)
        if x is None:
            w = struct.unpack_from('>I', self.ram, pc - RAM_BASE)[0]
            x = (rabbitizer.Instruction(w, pc).getOpcodeName(), 0, w)
            self._dec[pc] = x
        return x

    def call(self, pc, ret=0xDEAD0000, max_steps=200_000_000):
        r, ram = self.r, self.ram
        r[31] = ret
        steps = 0
        pending = None  # branch target to take after the delay slot
        while pc != ret:
            steps += 1
            if steps > max_steps:
                raise RuntimeError('step limit')
            name, _, w = self._ins(pc)
            rs, rt, rd = (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31
            imm = w & 0xFFFF
            simm = imm - 0x10000 if imm & 0x8000 else imm
            sa = (w >> 6) & 31
            nxt = pc + 4
            tgt = None
            if name == 'nop':
                pass
            elif name in ('addu', 'add'):
                r[rd] = (r[rs] + r[rt]) & 0xFFFFFFFF
            elif name in ('subu', 'sub'):
                r[rd] = (r[rs] - r[rt]) & 0xFFFFFFFF
            elif name in ('addiu', 'addi'):
                r[rt] = (r[rs] + simm) & 0xFFFFFFFF
            elif name == 'andi':
                r[rt] = r[rs] & imm
            elif name == 'ori':
                r[rt] = r[rs] | imm
            elif name == 'or':
                r[rd] = r[rs] | r[rt]
            elif name == 'and':
                r[rd] = r[rs] & r[rt]
            elif name == 'lui':
                r[rt] = (imm << 16) & 0xFFFFFFFF
            elif name == 'srl':
                r[rd] = r[rt] >> sa
            elif name == 'sll':
                r[rd] = (r[rt] << sa) & 0xFFFFFFFF
            elif name == 'lbu':
                r[rt] = ram[((r[rs] + simm) & 0xFFFFFFFF) - RAM_BASE]
            elif name == 'lhu':
                r[rt] = struct.unpack_from('>H', ram, ((r[rs] + simm) & 0xFFFFFFFF) - RAM_BASE)[0]
            elif name == 'lh':
                r[rt] = struct.unpack_from('>h', ram, ((r[rs] + simm) & 0xFFFFFFFF) - RAM_BASE)[0] & 0xFFFFFFFF
            elif name == 'lw':
                r[rt] = struct.unpack_from('>I', ram, ((r[rs] + simm) & 0xFFFFFFFF) - RAM_BASE)[0]
            elif name == 'sb':
                ram[((r[rs] + simm) & 0xFFFFFFFF) - RAM_BASE] = r[rt] & 0xFF
            elif name == 'sh':
                struct.pack_into('>H', ram, ((r[rs] + simm) & 0xFFFFFFFF) - RAM_BASE, r[rt] & 0xFFFF)
            elif name == 'sw':
                struct.pack_into('>I', ram, ((r[rs] + simm) & 0xFFFFFFFF) - RAM_BASE, r[rt])
            elif name == 'beq':
                if r[rs] == r[rt]:
                    tgt = (pc + 4 + (simm << 2)) & 0xFFFFFFFF
            elif name == 'bne':
                if r[rs] != r[rt]:
                    tgt = (pc + 4 + (simm << 2)) & 0xFFFFFFFF
            elif name == 'bgez':
                if not r[rs] & 0x80000000:
                    tgt = (pc + 4 + (simm << 2)) & 0xFFFFFFFF
            elif name == 'j':
                tgt = (pc & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
            elif name == 'jal':
                r[31] = pc + 8
                tgt = (pc & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
            elif name == 'jr':
                tgt = r[rs]
            elif name == 'jalr':
                r[rd or 31] = pc + 8
                tgt = r[rs]
            else:
                raise NotImplementedError(f'{name} at {pc:#x}')
            r[0] = 0
            if pending is not None:
                pc, pending = pending, None
            else:
                pc = nxt
            if tgt is not None:
                pending = tgt
        return r[2], steps
