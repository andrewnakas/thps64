"""Patch gas 2.6 (gas/targ-cpu.c, configure's copy of tc-mips.c) with the two opt-in THPS rules.

  THPS_AS_NO_LOAD_SWAP   never move a load into a branch delay slot (gas does this only for -mips1)
  THPS_AS_NO_STORE_SWAP  never move a store into a branch delay slot either (the game's `sw; jr ra; nop`)
  THPS_AS_NO_MUL_SWAP    never move mult/multu/dmult/dmultu/mul.s/mul.d into a delay slot (VR4300 errata)
  THPS_AS_COP_INTERLOCKS no coprocessor load/move hazard nops (VR4300 interlocks); keep the one nop between an FP
                         compare and the branch reading it, also when flushing delays at `.set noreorder`
  THPS_AS_NO_HILO_FLUSH  (only matters with -no-m4100) no HI/LO hazard nops when gas flushes delays at a `.set
                         noreorder` directive (GCC's own branch + delay slot; macros like div still get them): the game never has `mflo/mfhi; nop; branch`
                         (0 of 168 mflo/mfhi followed by a branch within two words), while -no-m4100 files do
                         have `mflo; nop; nop; mult` (67)
  THPS_AS_MULMUL_CODE_ONLY  (gas/input-file.c, the KMC "mulmul" fix) a line starting in column 0 (a label, or the
                         blank line GCC prints after `.set reorder`) does not count as a float multiply, so a
                         mult/mul.s right after a branch target gets no nop: the game has 36 multiplies at branch
                         targets, 35 without a nop before them
Without the variables gas behaves exactly as before. Idempotent; fails loudly if the source differs.
Also (gas/as.h, always): bcopy is #defined to memcpy where the host has no bcopy (zig/MinGW). The KMC "mulmul"
fix in input-file.c shifts text forward with an overlapping bcopy, so memcpy garbled the line after every
mul.s/mul.d (`mul.smul.s`); memmove is the overlap-safe equivalent.
Also (gas/input-file.c, next to gas/as.h) THPS_AS_MULMUL_CODE_ONLY above.
  python gas_patch.py gas/targ-cpu.c gas/as.h
"""
import os
import sys

if len(sys.argv) > 2:
    h = sys.argv[2]
    t = open(h, newline='').read()
    old, new = '#define bcopy(src,dest,size)\tmemcpy(dest,src,size)', '#define bcopy(src,dest,size)\tmemmove(dest,src,size)'
    if new not in t:
        assert t.count(old) == 1, 'gas/as.h bcopy define not found'
        open(h, 'w', newline='').write(t.replace(old, new))
    # gas/input-file.c (next to as.h): the mulmul emulation counts any column-0 line as a float multiply
    i = os.path.join(os.path.dirname(h), 'input-file.c')
    t = open(i, newline='').read()
    old = '                            if ((local_28 == cur_insn) ||\n'
    new = '                            if ((local_28 == cur_insn && getenv ("THPS_AS_MULMUL_CODE_ONLY") == NULL) ||\n'
    if new not in t:
        assert t.count(old) == 1, 'gas/input-file.c mulmul column-0 test not found'
        open(i, 'w', newline='').write(t.replace(old, new))

p = sys.argv[1]
s = open(p, newline='').read()
COP = '(getenv ("THPS_AS_COP_INTERLOCKS") == NULL)'
HILO = '(! thps_set_noreorder || getenv ("THPS_AS_NO_HILO_FLUSH") == NULL)'
edits = [
    # delay-slot swap: loads never swapped
    ('\t      || (mips_isa < 2\n\t\t  && (prev_pinfo\n\t\t      & (INSN_LOAD_MEMORY_DELAY\n',
     '\t      || ((mips_isa < 2 || getenv ("THPS_AS_NO_LOAD_SWAP") != NULL)\n\t\t  && (prev_pinfo\n\t\t      & (INSN_LOAD_MEMORY_DELAY\n'),
    # delay-slot swap: stores never swapped
    ('\t\t\t | INSN_COPROC_MEMORY_DELAY)))\n\t      /* We can not swap with a branch instruction.  */\n',
     '\t\t\t | INSN_COPROC_MEMORY_DELAY)))\n\t      || (getenv ("THPS_AS_NO_STORE_SWAP") != NULL\n'
     '\t\t  && (prev_pinfo & INSN_STORE_MEMORY))\n\t      /* We can not swap with a branch instruction.  */\n'),
    # delay-slot swap: multiplies never swapped (VR4300 multiply-in-delay-slot errata: none of the game's 2240
    # mult/multu/mul.s/mul.d sits in a delay slot, while other FP ops do)
    ('\t\t  && (prev_pinfo & INSN_STORE_MEMORY))\n\t      /* We can not swap with a branch instruction.  */\n',
     '\t\t  && (prev_pinfo & INSN_STORE_MEMORY))\n\t      || (getenv ("THPS_AS_NO_MUL_SWAP") != NULL\n'
     '\t\t  && ((prev_insn.insn_opcode & 0xfc00fffe) == 0x00000018\n'
     '\t\t      || (prev_insn.insn_opcode & 0xfc00fffe) == 0x0000001c\n'
     '\t\t      || (prev_insn.insn_opcode & 0xffc0003f) == 0x46000002))\n'
     '\t      /* We can not swap with a branch instruction.  */\n'),
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
    # mips_emit_delays: no HI/LO hazard nops at `.set noreorder` (macros such as div still flush them)
    ('   kept for the previous instructions.  */\n\nstatic void\nmips_emit_delays ()\n',
     '   kept for the previous instructions.  */\n\nstatic int thps_set_noreorder;\n\nstatic void\nmips_emit_delays ()\n'),
    ('  else if (strcmp (name, "noreorder") == 0)\n    {\n      mips_emit_delays ();\n',
     '  else if (strcmp (name, "noreorder") == 0)\n    {\n      thps_set_noreorder = 1;\n      mips_emit_delays ();\n'
     '      thps_set_noreorder = 0;\n'),
    ('(! interlocks\n\t      && (prev_insn.insn_mo->pinfo\n\t\t  & (INSN_READ_LO',
     f'(! interlocks && {HILO}\n\t      && (prev_insn.insn_mo->pinfo\n\t\t  & (INSN_READ_LO'),
    ('(! interlocks\n\t\t  && ((prev_insn.insn_mo->pinfo & INSN_READ_HI)',
     f'(! interlocks && {HILO}\n\t\t  && ((prev_insn.insn_mo->pinfo & INSN_READ_HI)'),
    ('(! interlocks\n\t\t   && ((prev_prev_insn.insn_mo->pinfo & INSN_READ_HI)',
     f'(! interlocks && {HILO}\n\t\t   && ((prev_prev_insn.insn_mo->pinfo & INSN_READ_HI)'),
]
for old, new in edits:
    if new in s:
        continue
    assert s.count(old) == 1, f'gas source differs at: {old[:60]!r} ({s.count(old)} hits)'
    s = s.replace(old, new)
open(p, 'w', newline='').write(s)
print('gas patched')
