# Decompathon post-mortem: Tony Hawk's Pro Skater (N64)

THPS64 was the first Decompathon project. It went from an empty repository to a fully decompiled game in four days
(2026-10-21 to 2026-10-24). One owner directed the work. Claude Code agents did most of it, the owner's Codex agent
took a share, and Decompathon Steward checked and merged every PR. This document covers what worked, what didn't, and
what we would do the same way or differently on the next game. Engineering details are in [STATUS.md](../STATUS.md).

## Result

| Measure | Value |
|---|---|
| Functions in the game's code | 2,512 (0x9B21C bytes) |
| Byte-matching C (`src/funcs`) | 2,449 functions, **86.85%** of code bytes |
| Decompiled: matching + reviewed non-matching C | 2,511 functions, **99.78%** |
| Fuzzy match ([ByteMatch](https://bytematch.dev/andrewnakas/thps64)) | **97.5%** |
| Linked units (every function in the unit byte-matches) | 85 / 115 units, 40.5% of code |
| Kept as assembly | 1 (libgcc `__udivdi3`; GPL source, see [ASM_UNITS.md](ASM_UNITS.md)) |
| Merged PRs | 271: 261 from the owner's account (Claude agents' batches and maintainer tools PRs), 10 from Codex's |

- **Exact build:** the main segment rebuilds byte-identically on every merge.
- **Playable build:** a second build runs all 62 non-matching functions from C. In an emulator it boots through the
  title and the attract demo with the same screenshots as the original game. The owner has also played it with a
  controller.

### Matched functions over time

| Time (UTC) | Matched | What drove it |
|---|---|---|
| Day 1 end | 202 | ROM unpacked, splat split, toolchain identified, Steward live, first m2c matches |
| Day 2 end | 648 | Float-constant and FPU-hazard toolchain fixes, then mass m2c + agent lanes |
| Day 3, noon | 823 | Agent lanes on Windows |
| Day 3, 18:00 | 1,144 | Moved to Linux; batch script; more lanes |
| Day 4, 06:00 | 2,423 | Overnight: toolchain fixes #143/#179/#197/#233/#247 reopened whole families; up to ~10 parallel lanes |
| Day 4 end | 2,449 matched + 62 non-matching | Endgame: finisher lanes, NON_MATCHING convention, reviews, playable build |

The function table also grew from 1,393 to 2,512 entries as function discovery improved, so early percentages
aren't comparable with late ones.

## What worked

### 1. Fix the toolchain before grinding functions
The biggest jumps never came from someone being clever with C. They came from finding one more way the original
toolchain differed from ours, and each fix made a whole family of functions matchable at once:

- **Compiler identity.** We started on KMC GCC 2.7.2, the usual N64 choice. Every one of the game's 1,017 stores
  to globals goes through a compiler-chosen register, and 2.7.2 never does that. GCC 2.8.1 with
  `-O1 -msplit-addresses` (Paper Mario's compiler) does. Measuring idioms across the whole binary settled this in
  hours: 9,348 `addu` moves against 0 `or` moves, `j` against `b`, how stores to globals are built.
- **The assembler had its own rules.** Loads are never moved into delay slots. There are no coprocessor hazard
  nops. `mult` is never placed in a delay slot. We patched gas with opt-in rules (`toolchain/gas_patch.py`) and
  rewrote assembly between cc1 and gas (`tools/match.py`):
  - float literals become the game's `.rodata` loads;
  - `mult` is moved out of delay slots (#197).
  - Each fix was measured: it had to break 0 existing matches and fix N new ones.
- **The compiler binary itself.** Building cc1 with clang miscompiled GCC 2.8.1, which relies on signed
  wraparound; building it with `-fwrapv` fixed that (#233).
- **Parts of the game are C++.** Function-by-function evidence pointed to g++ 2.8.1: temporaries with their own
  stack slots, an inlined `operator new`, vtables. A per-file `/* compiler: cc1plus */` opt-in (#247) unlocked
  that family.
- **Splitting matters as much as compiling.** Varargs preambles before `addiu sp`, filler words, constant pools
  between functions, and RSP microcode read as a CPU function (#265) each blocked functions or broke the build.
  `tools/find_funcs.py` and `tools/split.py` were fixed many times. The rule is to re-split from scratch every
  time.

**Lesson:** when a class of functions resists, stop grinding them and find out what the original toolchain did
differently. Prove each tools change against every existing match before merging it.

### 2. Two hard gates, and Steward as the only path to main
- **match:** every `src/funcs` file compiles to the game's bytes.
- **build:** the whole main segment relinks byte-identically.
- Both run on a judge machine with the ROM. GitHub never sees it.

Steward merged by fixed rules only. AI wrote explanations, never verdicts. That made it safe to let about ten agents
open PRs concurrently: a wrong PR couldn't land, and a right one landed without waiting for a human. The build gate
caught bugs the per-function gate couldn't. For example, a local `j` that was relocated one word off matched as a
function but broke the link.

### 3. Agent lanes with a shared brief and a result-file protocol
A Claude session acted as coordinator and ran up to about 10 agent "lanes" at once. Each lane had:
- a disjoint list of functions, so no two agents ever touched the same file;
- **one brief, `work/AGENT_BRIEF.md`**, which ended up with about 60 one-line lessons ("top-tested loop with `j`
  back: `while (1) { if (i >= N) break; ... }`"). Every lane read it first and appended what it learned, so each
  new lane started from everything the earlier lanes had found;
- a results file with one line per function (`MATCH func_X flags` or `NO func_X reason`). A near-miss draft was
  saved with its flags on line 1 and a header saying exactly what still differed;
- `work/scripts/batch.sh`, which collected MATCH lines, re-ran the full gate and build on current main, opened
  ≤20-function PRs and merged them. Agents never pushed.

**Lesson:** the coordinator's job is to keep queues disjoint and the brief current. The brief compounding across
lanes is what made later lanes faster than earlier ones.

### 4. Diagnose with the compiler's own dumps, not blind variants
For near-misses, the reliable method was to dump cc1's RTL passes (cse, combine, local-alloc, global-alloc,
sched, reorg) and find the exact pass where our output diverged. One lane rebuilt cc1 with `fprintf`s in reorg.c
to show why a single `mult` stayed out of a delay slot. That diagnosis often pointed straight at a source shape:
- the address taken in the lvalue of the statement containing the call: `(p = &s->f)->x = a + f();`;
- a loop written with `goto` to hide it from loop.c;
- a callee that takes fewer arguments than we assumed.

### 5. NON_MATCHING as the finish line, with real review
Some functions can't be byte-matched with any compiler we have:
- register-allocation ties inside GCC;
- switch compare trees that our GCC (and the KMC-matching 2.7.2) builds with a different root;
- a libc assembled by another toolchain (the binary's only `bgez $zero`);
- PlayStation GTE leftovers.

Following mature N64 projects, those functions get readable, equivalent C in `src/nonmatching/`, while the exact
build keeps their assembly (#256, RULES.md rule 9). Each file has a `NON_MATCHING:` note naming what differs.

Every non-matching file was reviewed block by block against the asm by an agent that did not write it. That review
was not a formality: it found **five real behaviour bugs** in drafts that compiled fine and looked right:
- literals sign-extended instead of zero-extended in a script interpreter;
- an undefined-behaviour `pc` update;
- a sign error that made a clamp impossible;
- a dropped hit record on one path;
- a table indexed with a 10-byte stride where the game uses 8.

### 6. Run the decompiled C in an emulator
`tools/build.py --nonmatching` compiles each non-matching function into a small region carved from the start of
the heap. It patches a jump at the original address, so every other address stays put. `tools/pack_rom.py` writes
the result into a ROM copy (boot's loader accepts raw chunks, and the CIC-6102 checksum is fixed).
`tools/nm_bisect.py` then boots one ROM per function in headless mupen64plus and compares screenshots with the
original.

This caught a **sixth bug** that code review had missed: the glyph renderer drew with texture tile 0 instead of 1,
which turned every string into stripes. Without input it only covers boot and the attract demo, but it costs
minutes per function.

### 7. Cross-checking between agents of different vendors
- Codex fixed glue bugs in Claude's permuter setup.
- Claude's reviewer found two real bugs in Codex's non-matching PR (#258).

An independent reader with different habits catches different things. Treat every author's output as needing
review, whoever the author is.

### 8. A static-recompilation port on day one
An N64Recomp port (`port/`) was playable by day 1. It reached menus, gameplay, audio and a virtual Controller Pak.
It was a research tool for the decomp: tracing which functions run, confirming function boundaries, and spotting
mis-splits. A split varargs preamble emptied the main menu, and that pointed us to a splitter fix.

## What didn't work, or cost more than it returned

- **decomp-permuter late in the project.** Early on, the cheap version paid off: wrapping one statement in
  `do { } while (0)` fixed 4 of the first permuter lane's 6 matches. Late near-misses produced mostly
  behaviour-changing or noise variants, and every result needed a semantic review. Our glue was also wrong at
  first: it skipped our assembly rewrites and per-file flags, so early scores were unreliable. **Check baseline
  parity before trusting any permuter score** (`checked_setup.py`).
- **Hunting for the "real" compiler.** decompals' KMC-matching GCC 2.7.2 builds the same switch tree as our 2.8.1
  (root 0x8C, where the game has 0x8B). Real KMC `libkmc.a` contained none of the remaining library routines.
  Worth an hour, not a day.
- **Mechanical C++ conversion.** Recompiling a stubborn C draft as C++ unchanged almost never helped. C++ helped
  only where the asm showed C++ structure: temporaries, ctor/dtor shapes, `operator new`.
- **Blind variant sweeps on register-allocation ties.** Two near-equal allocation priorities rarely move under
  cosmetic changes. A budget of **two focused attempts per function**, then non-matching, saved many lane-hours in
  the endgame.
- **Positional instruction scores.** "45/54 instructions agree" is misleading once one instruction shifts. The
  endgame used a difflib ratio over masked disassembly, which also became the fuzzy score
  (`tools/nonmatching.py --scores`).
- **Aliases in `symbol_addrs.txt`.** A second name for one address broke the split (#164). Linker-only aliases go
  in `config/link_aliases.txt`.
- **Merging before review.** Two of Codex's non-matching PRs (#271, #272) were merged by Codex before the review
  finished. Both reviews came back clean, but the earlier #258 had real bugs. The non-matching gate only proves
  that the C compiles, not that it is right.
- **Progress labels.** The README badge said "decompiled" while showing the byte-matched share. Keep matched,
  decompiled, fuzzy and linked as separately named numbers.

## Smaller lessons

- **Re-run the full flag sweep after every structural fix.** A flag set that lost earlier can win later.
- **Save near-misses with flags on line 1** and a header naming what differs. Unlabelled drafts got re-measured
  wrongly by later lanes.
- **Mid-task interruptions strand agent state.** Have agents write results as they go, not at the end.
- **Don't put helper scripts in a shared directory with stdlib names.** A `dis.py` in a shared scratch folder
  shadowed Python's `dis` and broke other agents' tools.
- **Owner policy decisions unblock lanes.** These were decided once and written into the brief:
  - fixed hardware addresses may be integer constants;
  - `volatile` is allowed where the game reloads a value;
  - plausible unused locals that give the game's stack frame are allowed;
  - symbol-name asm labels are allowed;
  - inline asm, register pins and dead statements are never allowed.

## Checklist for the next Decompathon game

1. Get the ROM unpacked, a reproducible `main.bin`, a re-split-from-scratch script and a byte-identical full build
   on day 1, before any matching.
2. Identify the compiler from binary-wide idioms, and keep a list of every toolchain mismatch the agents report.
   Fix them as tools PRs that break 0 matches.
3. Stand up Steward (match + build gates, judge box) before inviting agents. Agents never merge.
4. Run agent lanes with disjoint queues, one shared brief and the results-file protocol. Batch through a script
   that re-verifies on current main.
5. Use RTL dumps for near-misses. Use the permuter only after checking baseline parity, and only for small regions.
6. Decide the NON_MATCHING policy early. Give every function a two-attempt budget, then route it to equivalent C.
7. Have a different agent review every non-matching file for equivalence, block by block against the asm. Then
   boot the C build in an emulator and bisect.
8. Report matched, decompiled, fuzzy and linked separately, from day 1.

## Still open

- **Matching the rest.** 62 functions in `src/nonmatching` are documented candidates for matching; each `NON_MATCHING:`
  note says where to start. Each new match also moves its unit toward "linked".
- **Gameplay coverage.** The emulator check covers boot and the attract demo only. Scripted-input runs (the port
  has `THPS_PRESS`) would extend it.
- **8 MB timing.** With the Expansion Pak, the non-matching build's animation phase drifts late in the attract
  demo. The game times frames from `osGetCount`, so this is expected, but it hasn't been formally ruled out as a
  behaviour difference.
