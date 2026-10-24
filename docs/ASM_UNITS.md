# Functions kept as asm

Every game function is either matched C (`src/funcs`), equivalent non-matching C (`src/nonmatching`), or listed
here with the reason it stays as asm (`asm/nonmatchings/game/`).

| function | what it is | why asm |
|---|---|---|
| func_800C0770 | libgcc `__udivdi3` (64-bit unsigned divide; `config/link_aliases.txt`) | Not game code. It is byte-identical to GCC 2.8.1's `libgcc2.c` (`-DL_udivdi3`, `-O2 -Wa,-no-m4100`, `__clz_tab` = D_800221A0, `umul_ppmm` from longlong.h's MIPS inline asm), verified 2026-10-24. That source is GPL and this repo is CC0, so it is not copied in (owner decision). |

Functions with coprocessor instructions have non-matching C in src/nonmatching with small named inline-asm
helpers (documentation only; inline asm is never allowed in matched C): func_8005D0B0 (GTE `mfc2` MAC1-3) and
func_8006F574 (GTE `ctc2` TRX/TRY/TRZ) are PSX GTE code left over from the PlayStation original.

func_80097B78 is a 50-instruction C++ destructor (0x80097B78-0x80097C3C, non-matching C in src/nonmatching);
the words after it, from 0x80097C40 (IMEM 0x1080) through func_80097D34, are RSP microcode text that the
splitter currently reads as part of that unit.

Data that the splitter once read as functions (RSP microcode / `.word` tables at 0x80097D34, 0x800998CC,
0x8009AC5C) is not in `config/functions.csv` and is not counted.
