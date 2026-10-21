# THPS N64 decomp + recomp: status

Pilot game for Decompathon Steward (E:/decompathon-steward). Private, local only. No ROM or derived data in git.

## ROM
- `E:\Tony Hawk's Pro Skater (U) (V1.1) [!].z64`, 12 MiB, sha1 4900b6c92fb8df1765e91e891dccc525bb102fe1
- Header: NTFE "TONY HAWK PRO SKATER", entry 0x80000400, libultra rev 0x1444

## Findings (2026-10-21)
- Plain ROM 0x1000-0x13A10 = boot (vram 0x80000400-0x80012F10, bss to 0x80016AC0): libultra-ish + ERZ unpackers.
- **ERZ** = Edge of Reality's renamed RNC ProPack (18-byte RNC header, magic `ERZ`/`ERZ`).
  1109 blocks, all unpack with matching CRC (`tools/erz.py`; method 1 = dernc port, method 2 = the game's own
  routine 0x80000CE8 run in `tools/mips_mini.py`).
- Boot (0x80000870) reads the chunk table at ROM 0x13B14 (14 chunks of 64 KB), unpacks them back to back at
  0x80016AC0, clears bss 0x800F6460-0x800FC8C5, jumps to 0x800C0480. `tools/build_main.py` rebuilds that image:
  `work/main.bin` (0xDF9A0 bytes). Assets start at ROM 0x61E26 (all ERZ).
- main.bin layout: rodata 0x0-0xB900, text 0xB900-0xAA35C (vram 0x800223C0-0x800C0E1C), data after.
- **Compiler: GCC** (KMC 2.7.2 most likely, SN64 possible): 9348 `addu` moves vs 0 `or` moves, 3206 `j` vs 1 `b`,
  2504 branch-likely. Boot C has the same idioms.
- splat (`config/main.yaml`) -> 1393 functions, median 184 B, 828 <= 0x100. `tools/functable.py` -> `config/functions.csv`.
- `steward.toml` passes `python -m steward check-config` (1393 units).

## Toolchain (2026-10-21, owner OK'd downloads)
- No Windows releases exist, so `toolchain/build.sh` builds them natively with zig (32-bit MinGW target):
  decompals/mips-gcc-2.7.2 `cc1` + decompals/mips-binutils-2.6 KMC gas. Small patches (temp files, CRLF/binary)
  + `toolchain/{posix,compat}.c` shims. Output in E:/thps64-tools/bin. Preprocessor = zig clang -E (cccp crashes).
- `tools/match.py src/X.c [--show]`: compile, mask relocations, compare each func_XXXXXXXX with work/main.bin.
- **First matches:** func_80024BA8, func_8002C0C0 (src/try1.c). Flags: -O2 -mips3 -mgp32 -mfp32 -G0.
  Near misses noted: func_800246EC (load placed before jr, nop in slot -> maybe different -O or source shape),
  func_8002EA7C (v0/v1 allocation order).

## libultra (2026-10-21)
- libultra lives in **boot** (0x80000400-0x80012F10) and was built with **IDO** (Nintendo's libultra.a); main is all game
  code (GCC). `tools/ultralib_scan.py` compiles decompals/ultralib and byte-matches: best fit 2.0I (or older) with IDO 5.3
  -O1 -> 65 boot functions named in `config/boot_symbols.txt`. ULTRA_CC=ido uses ido-static-recomp 5.3 (Windows).
- Windows IDO 5.3 trap: cfe fails ("Unexpected End-of-file") on preprocessed input over ~32 KB; the scanner squeezes
  whitespace, but 64 ultralib files are still too big -> those functions are not named yet. Also no quoted -D values,
  and no drive-letter paths (run cc.exe in the source dir).

## Recomp (2026-10-21)
- `tools/recomp_syms.py` -> `work/recomp.z64` (ROM + main.bin raw at 0xC00000) + `recomp/thps.syms.toml`;
  `tools/recomp_loop.py` runs N64Recomp (PW64 tree's build-win/N64Recomp.exe) with `recomp/thps.toml`.
  **N64Recomp now translates everything: 262 boot + 2503 main functions -> recomp/RecompiledFuncs (58 files).**
- Function discovery: `tools/find_funcs.py` seeds splat (jal targets, data pointers to prologues, prologues after
  returns) -> splat finds 1880 functions. recomp_syms then splits leaf runs, drops constant pools (KMC GCC puts
  small pools between functions; data that decodes as code is rejected: wild jumps, non-R4300 ops), trims tails.
- 21 boot functions stubbed (ERZ unpacker, cop0/cache/exception libultra internals the runtime replaces).
- **COP2 / GTE:** THPS N64 is a PSX port; the GTE is emulated in C (e.g. func_80042D1C, regs around 0x800D48A4), but
  6 leftover COP2 instructions sit in functions (mfc2 $25-27 at 0x8005D264...). In the recomp input they become
  `break 0x3F2` (recomp/cop2_sites.txt), so the runtime stops there if the game ever reaches one.
- Over-splits merged (`merge_outside`). `tools/gen_reimplemented_decls.py` declares the runtime's <name>_recomp
  libultra (440 names); **`tools/recomp_compile.sh`: all 55 generated C files compile with clang, 0 errors.**
- Open: link RecompiledFuncs with a
  runtime (N64ModernRuntime + RT64, as the PW64 port does) and boot with a custom entry that skips the ERZ loader.

## Blocked on the owner
- GitHub repo for this project (private) + Steward App install: after the passkey step.

## Next
1. Make `match` the Steward gate (artifact: per-function MATCH lines) and wire `steward.toml`.
2. Full build: assemble splat asm with a modern assembler (zig clang -target mips) + link -> byte-exact main.bin.
3. Name the rest of boot (big ultralib files, audio) -> N64Recomp's runtime needs every libultra entry point.
4. Recomp: N64Recomp (source in n64cleanrecomp/external/pilotwings-64-recomp/lib/N64ModernRuntime/N64Recomp),
   symbol-file mode over a ROM with main.bin stored raw; boot's own unpack then just writes data.
