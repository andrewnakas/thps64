# Functions kept as asm

Every game function is either matched C (`src/funcs`), equivalent non-matching C (`src/nonmatching`), or listed
here with the reason it stays as asm (`asm/nonmatchings/game/`).

| function | what it is | why asm |
|---|---|---|
| func_800C0770 | libgcc `__udivdi3` (64-bit unsigned divide; `config/link_aliases.txt`) | Not game code. It is byte-identical to GCC 2.8.1's `libgcc2.c` (`-DL_udivdi3`, `-O2 -Wa,-no-m4100`, `__clz_tab` = D_800221A0, `umul_ppmm` from longlong.h's MIPS inline asm), verified 2026-10-24. That source is GPL and this repo is CC0, so it is not copied in (owner decision). |
| func_80097B78 | game C with inline CP0 access (`mfc0`/`mtc0` ×15) around calls to func_8008BB50 / func_800A73EC / func_8008B490 | The original used inline-asm macros; RULES forbid inline asm in matched C. |
| func_8005D0B0 | game C with PSX GTE instructions (`mfc2` ×3), called from func_8005CF38 / func_8005DE04 | GTE (cop2) macros left over from the PlayStation original; not expressible in C without inline asm. |
| func_8006F574 | game C with PSX GTE instructions (`ctc2` ×3) | As above. |

Data that the splitter once read as functions (RSP microcode / `.word` tables at 0x80097D34, 0x800998CC,
0x8009AC5C) is not in `config/functions.csv` and is not counted.
