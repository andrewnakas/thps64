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
- **Port (`port/`, from the MIT Pilotwings 64 recomp; reuses its lib/ checkout):** `port/build.cmd` (clang-cl +
  Ninja, run detached) builds `port/build/THPS64Recomp.exe`; `--identify` accepts the V1.1 dump. src/boot.cpp
  replaces boot main (ignored in thps.toml): libultra setup, C++ ERZ1 unpack of main into RDRAM, then 0x800C0480.
  Audio tasks reported complete (silent). 8 libultra internals stubbed in src/glue.cpp. **Not launched yet**
  (owner rule: launch only on request).
- Open: first run (when the owner says), then name the remaining boot libultra so the runtime replaces it, and a
  runtime (N64ModernRuntime + RT64, as the PW64 port does) and boot with a custom entry that skips the ERZ loader.

## Port bring-up (2026-10-21, owner said "get it all working")
- **Runs:** boot -> 7 game threads -> game loop, display lists reach RT64 every frame, stable over 60 s (hidden test
  runs: `port/run.ps1 [seconds]`, env THPS_HIDDEN/THPS_WATCH/THPS_TRACE_FN/THPS_SAMPLE). Not yet looked at the image.
- Fixes on the way (each was a hang or crash):
  - boot.cpp also copies the asset base (ROM 0x13B10 -> 0x80011C2C) and chunk table (-> 0x803C0000) like boot main.
  - game uses its own PI DMA thread (OS_EVENT_PI + osPiRawStartDma): port owns thps_osSetEventMesg/thps_osPiRawStartDma.
  - boot's ERZ unpackers are recompiled whole (game unpacks files through 0x80000B08); no longer stubbed.
  - osMemSize reported as 4 MB (THPS_8MB=1 for 8 MB).
  - function starts: vtable {ptr,0} targets, gap scan, preamble before `addiu sp` (lui/lw), sizes to next start.
  - ~30 libultra functions named by hand from the call graph (controller, motor, VI, MI/AI, interrupts) in
    config/boot_symbols.txt, so the runtime replaces them; a few internals stubbed in port/src/glue.cpp.
- Debug kit: N64Recomp trace_mode -> per-thread last function + call ring + waited-on queue (watchdog), queue dumps,
  native stack walk of stalled threads, per-function argument logging.
- **Renders correctly** (Windows Graphics Capture, port/capture_wgc.py, no desktop grabs; run.ps1 with THPS_CAPTURE=1
  puts the window off-screen): Controller Pak notice -> copyright -> Activision/Neversoft/EoR logos -> 3D attract demo
  (Tony Hawk in the Warehouse). Scripted input: THPS_PRESS="A@4,START@12".
- **Audio works** (2026-10-21): menu music plays through the RSPRecomp'd n_aspMain (recomp/aspMain.thps.toml; data+0x10 =
  0x0000127C "naudio"; table entry 0x02B0 = IMEM 0x12B0). The long "silence" was the inherited mute-when-unfocused
  (test windows are never focused): now opt-in, THPS_MUTE_UNFOCUSED=1. The intro itself has no music; MusStartSong
  (libmus) fires on the front end. Latency fix: port-owned thps_osAiGetStatus reports FIFO-full while >3000 frames
  are queued (the runtime always said idle, THPS loops on it), queue went 20 s -> ~170 ms.
  - THPS_AUDIO_HLE=1 switches to mupen64plus-rsp-hle's naudio interpreter (port/third_party/rsp-hle, **GPL-2.0+**,
    vendored for diagnosis; decide before any release whether to drop it). THPS_AUDIO_OPS/_DUMP/_DUMP_TASK/_STATS.
- Names: shygoo/n64sym v0.9a (-s -t on a boot+main RAM image) -> config/n64sym.txt (+ n64sym_boot.txt for splat);
  it corrected 4 of my hand guesses and named 230 more (n_audio, libmus, libc). Game-segment names reach only the
  recompiler (recomp_syms), never osVoice*/rspboot look-alikes (osVoiceInit at 0x800A78E4 broke file loading).
  Missing runtime internals get generated no-op stubs (port/src/auto_stubs.cpp).
- Research digest (2026-10-21): Rush 2 Recompiled (n64sym naming, inflate+load_overlays, virtual Controller Pak in
  src/pak.cpp against a 32 KB .mpk), VPW64Recomp (widescreen/interpolation, virtual pak + rumble), wpj2-recomp.
  ModernRuntime osPfs* are NOPACK stubs.
- **Virtual Controller Pak works** (port/src/pak.cpp, own code from the libultra pfs layout): the game's osPfs* filesystem
  is recompiled under thps_ names (recomp_syms RECOMPILE_AS); the port supplies __osContRamRead/Write, __osPfsGetStatus,
  osPfsIsPlug against <settings>/thps64.mpk (THPS_MPK=path), created formatted. "No Controller Pak" notice gone.
- **8 MB is the default again** ("Expansion Pak found"; the old 7.5 MB failure was the truncated-function bug).
  THPS_4MB=1 for a stock console.
- **Playable to gameplay** (2026-10-21): notices -> logos -> intro -> title -> main menu (all six items, D-pad moves,
  A accepts) -> rumble notice -> Select Player -> Select Board -> Select Course -> loading tip -> Warehouse free skate
  with HUD. Scripted path: THPS_PRESS="A@4,START@25,START@28.5,DDOWN@33,DDOWN@34,DDOWN@35,A@37,A@42,A@47,A@52,A@57,A@66"
  (times depend on load speed; title shows around 22-25 s).
  - The empty, input-dead main menu was a function split: the menu builder func_8003C1A4 is varargs and GCC puts
    `sw a1-a3, 4..C(sp)` before `addiu sp`; that preamble had become its own 12-byte function, so the recompiled call
    stored its args and returned with zero items. recomp_syms `merge_fallthrough` merges any function that runs off
    its end into the next (5 in main: two varargs preambles, a div scheduled before the prologue, a mid-split).
    Lesson: check for functions that do not end in jr/j before chasing runtime causes.

## Decomp tooling (2026-10-21)
- splat code subsegment is `c` -> one asm file per function in asm/nonmatchings/game (1930 + 88 empty ones splat
  writes into src/game.c, generated/ignored). FPU regs numeric (LLVM).
- `tools/build.py`: **full build byte-identical to the game** (C from src/funcs via KMC GCC 2.7.2 + gas 2.6, rest asm
  via zig's LLVM assembler, ld.lld, per-function placement). Handles: COP2 as raw words, gas 16-byte .text padding
  trimmed, undefined label/addr symbols defined from their names (two-pass link), uncovered pool words, empty funcs.
  Second Steward gate ("build"), runs in ~2-3 min.
- `tools/new_func.py func_X`: m2c draft into src/funcs + match attempt. `tools/match.py`: readable compile errors.
- `tools/progress.py [--json]`: matched functions/bytes. m2c + decomp-permuter cloned in E:/thps64-tools.

## Blocked on the owner
- GitHub repo for this project (private) + Steward App install: after the passkey step.

## Next
1. Make `match` the Steward gate (artifact: per-function MATCH lines) and wire `steward.toml`.
2. Full build: assemble splat asm with a modern assembler (zig clang -target mips) + link -> byte-exact main.bin.
3. Name the rest of boot (big ultralib files, audio) -> N64Recomp's runtime needs every libultra entry point.
4. Recomp: N64Recomp (source in n64cleanrecomp/external/pilotwings-64-recomp/lib/N64ModernRuntime/N64Recomp),
   symbol-file mode over a ROM with main.bin stored raw; boot's own unpack then just writes data.
