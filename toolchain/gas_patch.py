"""Patch gas 2.6 (gas/targ-cpu.c, configure's copy of tc-mips.c) with the two opt-in THPS rules.

  THPS_AS_NO_LOAD_SWAP   never move a load into a branch delay slot (gas does this only for -mips1)
  THPS_AS_COP_INTERLOCKS no coprocessor load/move hazard nops (VR4300 interlocks); keep the one nop between an FP
                         compare and the branch reading it, also when flushing delays at `.set noreorder`
Without the variables gas behaves exactly as before. Idempotent; fails loudly if the source differs.
Also (gas/as.h, always): bcopy is #defined to memcpy where the host has no bcopy (zig/MinGW). The KMC "mulmul"
fix in input-file.c shifts text forward with an overlapping bcopy, so memcpy garbled the line after every
mul.s/mul.d (`mul.smul.s`); memmove is the overlap-safe equivalent.
  python gas_patch.py gas/targ-cpu.c gas/as.h
"""
import sys

if len(sys.argv) > 2:
    h = sys.argv[2]
    t = open(h, newline='').read()
    old, new = '#define bcopy(src,dest,size)\tmemcpy(dest,src,size)', '#define bcopy(src,dest,size)\tmemmove(dest,src,size)'
    if new not in t:
        assert t.count(old) == 1, 'gas/as.h bcopy define not found'
        open(h, 'w', newline='').write(t.replace(old, new))

p = sys.argv[1]
s = open(p, newline='').read()
COP = '(getenv ("THPS_AS_COP_INTERLOCKS") == NULL)'
edits = [
    # delay-slot swap: loads never swapped
    ('\t      || (mips_isa < 2\n\t\t  && (prev_pinfo\n\t\t      & (INSN_LOAD_MEMORY_DELAY\n',
     '\t      || ((mips_isa < 2 || getenv ("THPS_AS_NO_LOAD_SWAP") != NULL)\n\t\t  && (prev_pinfo\n\t\t      & (INSN_LOAD_MEMORY_DELAY\n'),
    # append_insn: coprocessor load delay (mfc1, lwc1 on r3000)
    ('      if (mips_isa < 4\n\t  && ((prev_pinfo & INSN_LOAD_COPROC_DELAY)\n',
     f'      if (mips_isa < 4\n\t  && (({COP} && (prev_pinfo & INSN_LOAD_COPROC_DELAY))\n'),
    # append_insn: generic coprocessor move delay (mtc1, ctc1)
    ('      else if (mips_isa < 4\n\t       && ((prev_pinfo & INSN_COPROC_MOVE_DELAY)\n',
     f'      else if (mips_isa < 4\n\t       && (({COP} && (prev_pinfo & INSN_COPROC_MOVE_DELAY))\n'),
    # append_insn: two-instruction rule for ctc1 then condition-code read
    ('\t       && (prev_prev_insn.insn_mo->pinfo & INSN_COPROC_MOVE_DELAY)\n',
     f'\t       && {COP}\n\t       && (prev_prev_insn.insn_mo->pinfo & INSN_COPROC_MOVE_DELAY)\n'),
    # mips_emit_delays: coprocessor load/move delays need no nop
    ('      if ((mips_isa < 4\n\t   && (prev_insn.insn_mo->pinfo\n\t       & (INSN_LOAD_COPROC_DELAY\n\t\t  | INSN_COPROC_MOVE_DELAY\n\t\t  | INSN_WRITE_COND_CODE)))\n',
     f'      if ((mips_isa < 4\n\t   && (prev_insn.insn_mo->pinfo\n\t       & (({COP} ? (INSN_LOAD_COPROC_DELAY | INSN_COPROC_MOVE_DELAY) : 0)\n\t\t  | INSN_WRITE_COND_CODE)))\n'),
    # mips_emit_delays: one nop (not two) after an FP compare
    ('\t  if ((mips_isa < 4\n\t       && (prev_insn.insn_mo->pinfo & INSN_WRITE_COND_CODE))\n',
     f'\t  if ((mips_isa < 4 && {COP}\n\t       && (prev_insn.insn_mo->pinfo & INSN_WRITE_COND_CODE))\n'),
]
for old, new in edits:
    if new in s:
        continue
    assert s.count(old) == 1, f'gas source differs at: {old[:60]!r} ({s.count(old)} hits)'
    s = s.replace(old, new)
open(p, 'w', newline='').write(s)
print('gas patched')
