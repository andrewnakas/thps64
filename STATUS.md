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

## Compiler identification is incomplete (2026-10-21 evening)
- Every store to a global in the game (1017 of 1017) is `lui $vN,%hi(sym); sX ...,%lo(sym)($vN)` with a
  compiler-chosen register; none use `$at`. GCC 2.7.2 + gas never does that (gas expands `sw $4,sym` via `$at`),
  so stores to globals can never match with the current toolchain; only loads and pure code do (the 54 matches).
- **Solved: GCC 2.8.1 (pmret/gcc-papermario d97824f) `-O1 -msplit-addresses` + gas 2.6 `-m4100`.** Built natively
  with zig (toolchain/build.sh). It matches all 74 earlier matches plus the stores; -O1 was pinned by hand-matching
  func_8005E6B4 (0x80 bytes, two divides: -O2 gets 11/33). `-m4100` tells gas the CPU interlocks HI/LO, so it stops
  padding mflo with nops (the game has none). tools/match.py uses this toolchain (THPS_CC1 overrides the path).
- README/AGENTS.md: the compiler line is now settled; functions that write globals can match.

## Decomp tooling (2026-10-21)
- splat code subsegment is `c` -> one asm file per function in asm/nonmatchings/game (1930 + 88 empty ones splat
  writes into src/game.c, generated/ignored). FPU regs numeric (LLVM).
- `tools/build.py`: **full build byte-identical to the game** (C from src/funcs via KMC GCC 2.7.2 + gas 2.6, rest asm
  via zig's LLVM assembler, ld.lld, per-function placement). Handles: COP2 as raw words, gas 16-byte .text padding
  trimmed, undefined label/addr symbols defined from their names (two-pass link), uncovered pool words, empty funcs.
  Second Steward gate ("build"), runs in ~2-3 min.
- `tools/split.py`: re-split from scratch (find_funcs -> wipe asm/ -> splat -> config/functions.csv). Always use it:
  splat leaves .s files of functions that no longer exist and build.py links them all. find_funcs now walks varargs
  preambles (sw a0-a3 to home slots) back to the real start and drops prologues that real code runs into (div before
  `addiu sp`, prologue in a delay slot): 1834 functions, build still byte-identical (2026-10-21).
- `tools/new_func.py func_X`: m2c draft into src/funcs + match attempt. `tools/match.py`: readable compile errors.
- `tools/progress.py [--json]`: matched functions/bytes. m2c + decomp-permuter cloned in E:/thps64-tools.

## Steward live (2026-10-21)
- Private repo github.com/andrewnakas/thps64 (main), Steward App installed (App limited to this repo + the test repo).
- Judge workspace E:/thps64-judge: a dedicated clone (never work in it); rebuilt from a clean clone with
  build_main -> split -> gate 24/24 -> build identical. Steward runs where=judge gates there:
  `python -m steward.daemon --repo andrewnakas/thps64 --app decompathon-steward --judge-workspace E:/thps64-judge [--once] [--no-ai]`
- End to end: PR #2 (12 functions) judged (match 36/36, build identical) and merged by Steward; PR #3 (deliberately
  wrong) refused with the differing word in the report. Daemon is not left running for this repo (run it when wanted).
- 18 more m2c matches wait in work/drafts/pending (max 20 functions per PR).

## Next
1. Make `match` the Steward gate (artifact: per-function MATCH lines) and wire `steward.toml`.
2. Full build: assemble splat asm with a modern assembler (zig clang -target mips) + link -> byte-exact main.bin.
3. Name the rest of boot (big ultralib files, audio) -> N64Recomp's runtime needs every libultra entry point.
4. Recomp: N64Recomp (source in n64cleanrecomp/external/pilotwings-64-recomp/lib/N64ModernRuntime/N64Recomp),
   symbol-file mode over a ROM with main.bin stored raw; boot's own unpack then just writes data.

## Float constants block ~300 functions (2026-10-22)
- The game loads float constants from per-function .rodata literals through `$at` (`lui $at,%hi(D_x); lwc1 $fN,%lo(D_x)($at)`,
  even 1.0/2.0, duplicated per function); 990 such loads in asm/nonmatchings/game, ~306 files.
- GCC 2.8.1 (and 2.7.2) emit `li.s $fN,value` (mips_const_double_ok); KMC gas 2.6 expands that to lui/ori/mtc1, never a memory
  load. An `extern f32 D_x` instead gets split through `$v0` by -msplit-addresses (mips_check_split only skips SYMBOL_REF_FLAG).
- The game never uses lui $at + mtc1 at all, so the original compiler never emitted li.s (constants forced to memory,
  as when mips_const_double_ok returns false). Earlier guess: the original assembler put li.s values in .rodata (modern GNU as does that with -G0 for values lui alone can't make; it still
  uses lui+mtc1 for 1.0, which THPS does not). Next: (1) find the assembler/flag that always uses memory, or rewrite li.s ->
  .rodata literal + `l.s` before gas; (2) rodata migration: C files own their .rodata and build.py places it at the game's
  address. Until then skip functions with `lwc1 ...($at)`.
- Bad splits found while matching: func_8003B95C (3 junk words after jr ra at 0x8003B9F4), func_8003BD38 (1 word at 0x8003BDBC);
  the C for both matches the real function (work/retry). Needs a re-split.
- More toolchain gaps found by the matching agents (2026-10-22), each blocks a class of functions:
  - **Solved (2026-10-22):** loads are never moved into delay slots, other instructions are. gas 2.6 has exactly that
    rule for -mips1 only (`mips_isa < 2 && INSN_LOAD_MEMORY_DELAY`); -mips1 itself breaks 123 matches (load-delay nops),
    gas -O00 (no swapping) breaks 3. toolchain/build.sh now patches gas so THPS_AS_NO_LOAD_SWAP=1 (set by match.py)
    applies just that rule: 0 of 360 matches change, 12 more match. The 5 `.set noreorder` files may not need it now.
  - (Before the fix) Empty delay slots: the game has `lw ...; jr ra; nop` and `jr/j; nop` where our gas 2.6 (reorder mode) fills the slot.
    5 files in src/funcs work around it with `__asm__(".set noreorder")`. Suggests the original assembler did not reorder
    (or GCC filled slots itself) — e.g. func_800261A8, func_800391EC, func_80049E2C, func_800246EC, func_8006A148.
  - `mflo` then `mult` with a nop between (func_800430F0): gas pads that only without -m4100, other functions need -m4100.
  - Hazard nop after `mfc1 $a2,$f20` before jal (func_8003A410): our gas inserts it, the game has none.
  - Loop-invariant %hi register copied into an s-register (36 functions, e.g. func_80033A58): GCC reloads it in the loop.
  - Register allocation order for args with different live ranges (func_8006EBB0).
  Together with the float literal pools these point at a different assembler/compiler build than ours; worth a
  dedicated toolchain session (try GCC's own delay-slot filling + `.set noreorder` output, other KMC/SN builds).

## Float constants and FPU hazards solved (2026-10-22, tools PR after #33)
- `tools/match.py float_literals()`: between cc1 and gas, the k-th `li.s/li.d` in a function becomes `l.s/l.d $fN,D_x` where
  D_x is the k-th float literal the game's own asm for that function loads through $at, only if main.bin holds exactly the
  compiled bits. gas then emits the game's `lui $at; lwc1` and the link resolves D_x. C keeps plain literals (`1.0f`).
- `-mno-fix4300`: this cc1 defaults to the early-VR4300 multiply workaround (nop after every mul.s/mul.d; 209 game
  functions use mul.s/mul.d, none has that nop).
- gas rule THPS_AS_COP_INTERLOCKS (toolchain/gas_patch.py): no coprocessor load/move hazard nops (`mtc1; cvt.s.w`,
  `mfc1 $a3; jal`), one nop (not two) between an FP compare and its branch at `.set noreorder`.
- Measured: 0 of 379 matches change, func_8002A904 + func_80041EC0 match as-is, 7 more float functions matched by hand;
  full build byte-identical with all of them. C files must not contain string literals (they add .rodata and game text;
  reference the game's strings as `extern char D_x[]`).
