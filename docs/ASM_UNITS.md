# Functions kept as asm

Every game function is either matched C (`src/funcs`), equivalent non-matching C (`src/nonmatching`), or listed
here with the reason it stays as asm (`asm/nonmatchings/game/`).

| function | what it is | why asm |
|---|---|---|
| func_800C0770 | libgcc `__udivdi3` (64-bit unsigned divide; `config/link_aliases.txt`) | Not game code. It is byte-identical to GCC 2.8.1's `libgcc2.c` (`-DL_udivdi3`, `-O2 -Wa,-no-m4100`, `__clz_tab` = D_800221A0, `umul_ppmm` from longlong.h's MIPS inline asm), verified 2026-10-24. That source is GPL and this repo is CC0, so it is not copied in (owner decision). |

Functions with coprocessor instructions have non-matching C in src/nonmatching with small named inline-asm
helpers (documentation only; inline asm is never allowed in matched C): func_8005D0B0 (GTE `mfc2` MAC1-3) and
func_8006F574 (GTE `ctc2` TRX/TRY/TRZ) are PSX GTE code left over from the PlayStation original.

func_80097B78 is a 50-instruction C++ destructor (0x80097B78-0x80097C3C, a 0xC8-byte unit: `size:0xC8` in
`config/symbol_addrs.txt`). The words after it, 0x80097C40 up to func_8009B0A0 (where CPU code resumes), are RSP
microcode text (n_aspMain at 0x80097C40, rspboot 0x800988A0, gspF3DEX2_NoN_fifo 0x80098970, _xbus 0x80099D00):
splat emits them as `.word` data units (D_80097C40, func_800998CC, func_8009AC5C) with no size.

Data that the splitter once read as functions (RSP microcode / `.word` tables at 0x80097C40, 0x80097D34,
0x800998CC, 0x8009AC5C) is not in `config/functions.csv` and is not counted.
