# Tony Hawk's Pro Skater (N64) — decompilation

This project is rebuilding the C source code of **Tony Hawk's Pro Skater for the Nintendo 64** (US, V1.1),
one function at a time, so that it compiles back into **exactly the same machine code** as the original game.
It is the pilot project of **Decompathon**, a series of community decomp jams.

**Nothing from the game is in this repository.** You need your own legally obtained copy of the ROM; every tool
here reads it locally and never uploads anything.

- Discord: **https://discord.gg/mf4fp7VKZ8** (help, claims, progress feed)
- Rules: [RULES.md](RULES.md) · Provenance: [PROVENANCE.md](PROVENANCE.md) · AI agents: [AGENTS.md](AGENTS.md)
- Licence: [CC0-1.0](LICENSE) for this project's own code and docs; `port/` also contains MIT-licensed code from the Pilotwings 64 recomp, which keeps its licence (`port/LICENSE.pilotwings64-recomp`)
- Progress (updated on every merge; locally: `python tools/progress.py`):

  ![Decompilation progress](https://raw.githubusercontent.com/andrewnakas/thps64/progress/progress.svg)
  [![decompiled](https://img.shields.io/endpoint?url=https://raw.githubusercontent.com/andrewnakas/thps64/progress/progress.json)](tools/progress.py)
  [![matched](https://img.shields.io/endpoint?url=https://raw.githubusercontent.com/andrewnakas/thps64/progress/matched.json)](tools/progress.py)
  [![fuzzy match](https://img.shields.io/endpoint?url=https://raw.githubusercontent.com/andrewnakas/thps64/progress/fuzzy.json)](https://bytematch.dev/andrewnakas/thps64)

## Status: fully decompiled (October 2026)

**Every function of the game's code has been decompiled to C, except one library routine.**

| | functions | share of code bytes |
|---|---|---|
| **Matching** C: compiles to the original bytes (`src/funcs/`) | **2,449 / 2,512** | **86.85%** |
| **Decompiled** in total: matching + non-matching C (`src/nonmatching/`) | **2,511 / 2,512** | **99.78%** |
| Kept as assembly: libgcc `__udivdi3` (not game code; see [docs/ASM_UNITS.md](docs/ASM_UNITS.md)) | 1 | 0.22% |

On ByteMatch / objdiff terms: **fuzzy match 97.5%** (matched code at 100%, each non-matching function at its
instruction similarity to the game), and **85 of 115 units linked** (40.5% of code). A unit counts as linked only
when every function in it is byte-matching C inside the byte-identical build. Units holding a non-matching
function still link that function's original assembly, so the project is not 100% linked yet.

- **Non-matching functions.** The last 62 functions resisted a byte-for-byte match. Each one has readable,
  behaviour-equivalent C in `src/nonmatching/`, checked block by block against the original assembly. Each file
  starts with a `NON_MATCHING:` note that names what still differs. Usually that is a register-allocation or
  scheduling choice inside GCC 2.8.1. A few are switch statements that our compiler lays out differently, a libc
  built by another toolchain, or GTE code left over from the PlayStation original.
- **The matching build is still exact.** `python tools/build.py` rebuilds the game code byte-identical. It uses
  the original assembly for the 62 non-matching functions.
- **A playable decompiled build.** `python tools/build.py --nonmatching` builds the game with all 62 non-matching
  functions running from their C, and `python tools/pack_rom.py build/rom/thps_decomp.z64` packs that into a copy
  of your ROM. In mupen64plus it boots through the title screen and the attract demo. Its screenshots are
  identical to the original game's from 10 to 90 seconds (headless, 4 MB, no input). The game is also playable
  with a controller. `tools/nm_bisect.py` boots one ROM per function to find any function whose C misbehaves.
- **What is left:** turning non-matching functions into matching ones. Once a function matches, move its file to
  `src/funcs/` and delete the copy in `src/nonmatching/`. The full engineering log is in [STATUS.md](STATUS.md).
- **Post-mortem:** what worked and what didn't, with a checklist for the next game, in
  [docs/POSTMORTEM.md](docs/POSTMORTEM.md).

---

## Contents
1. [What is a matching decompilation?](#what-is-a-matching-decompilation)
2. [How this game is built (what we found)](#how-this-game-is-built-what-we-found)
3. [Set up on your machine](#set-up-on-your-machine)
4. [Decompile your first function](#decompile-your-first-function)
5. [How contributions get checked and merged (Steward)](#how-contributions-get-checked-and-merged-steward)
6. [Provenance and AI agents](#provenance-and-ai-agents)
7. [Non-matching C and the playable decompiled build](#non-matching-c-and-the-playable-decompiled-build)
8. [Repository map](#repository-map)
9. [The native port (static recompilation)](#the-native-port-static-recompilation)
10. [FAQ](#faq)

---

## What is a matching decompilation?

Game cartridges contain compiled MIPS machine code, not source. A *matching* decompilation writes C that, when fed
to the same compiler the developers used with the same flags, produces the **identical bytes**. Because every
function is proven byte-identical, the C is known to behave exactly like the original, which is what makes it
useful for preservation, documentation, modding and native ports.

The work is split per function. For each one you:
1. look at its assembly (split out of your ROM by our tools),
2. write C for it (a decompiler, m2c, gives a rough first draft),
3. compile and compare, and adjust until every instruction is the same.

When a function matches, it is merged, and the project's "functions matched" counter goes up.

## How this game is built (what we found)

Everything below was worked out from the ROM itself (see [STATUS.md](STATUS.md) for the full log).

- **ERZ compression.** Almost all of the ROM is packed in "ERZ" blocks: Edge of Reality's renamed variant of the
  RNC ProPack format (methods 1 and 2). `tools/erz.py` unpacks all 1,109 blocks and verifies each CRC.
- **Two code segments.**
  - *boot* (RAM 0x80000400–0x80012F10): Nintendo's libultra, built with IDO.
  - *main* (RAM 0x80016AC0, 0xDF9A0 bytes): the game itself, 14 compressed chunks that boot unpacks at start-up.
    `tools/build_main.py` rebuilds the same RAM image (`work/main.bin`) from your ROM.
- **The compiler.** The game code was built with a late-1990s GCC. We started with KMC GCC 2.7.2, which
  reproduces pure code and loads from globals. But every one of the game's 1,017 *stores* to globals loads the
  address through a compiler-chosen register (`lui $v0,%hi(x); sw $a0,%lo(x)($v0)`), which GCC 2.7.2 never does.
  **GCC 2.8.1 with `-O1 -msplit-addresses`** (Paper Mario's compiler) reproduces both, assembled by gas 2.6 with
  `-m4100` (the N64's CPU needs no padding after `mflo`). That is the project toolchain.
- **splat** splits *main* into one assembly file per function (`asm/nonmatchings/game/`, generated locally).
  `tools/find_funcs.py` seeds the function starts (jal targets, prologues after returns, vtable entries,
  varargs preambles that sit before the stack setup).
- **Function table.** `config/functions.csv` lists every function (address, size). Matched functions live in
  `src/funcs/func_XXXXXXXX.c`, one per file, named by address.

## Set up on your machine

You need: your own ROM (US V1.1, `.z64`), Python 3.12+, git, and the toolchain. Windows is the reference platform
(everything builds natively, no WSL); Linux and macOS work with the same steps where the tools exist.

### 1. Python packages
```
pip install splat64 rabbitizer pyelftools
```
Plus [m2c](https://github.com/matt-kempster/m2c) (clone it; set `M2C=path/to/m2c.py` if it is not in
`E:/thps64-tools/m2c`).

### 2. The compiler and assembler
`toolchain/build.sh` builds GCC 2.8.1 (`cc1`, the project compiler) and gas 2.6 natively, with
[zig](https://ziglang.org/) as the host C compiler (no MSYS2/WSL):
```
sh toolchain/build.sh E:/thps64-tools   # -> E:/thps64-tools/gcc-2.8.1-pm/cc1.exe, E:/thps64-tools/bin/mips-as.exe
```
The build patches gas with two opt-in rules the game's original assembler followed (`toolchain/gas_patch.py`: no load
moved into a delay slot, no coprocessor hazard nops); `tools/match.py` turns them on and refuses an unpatched gas.
**If you built the tools before 2026-10-22, run `toolchain/build.sh` again.**

Point the tools at them with `THPS_CC1` (the GCC 2.8.1 cc1), `THPS_TOOLS` (folder with mips-as.exe) and `ZIG`. zig is also
the assembler and linker for the full build.

### 3. Build the inputs from your ROM
```
python tools/build_main.py "path/to/Tony Hawk's Pro Skater (U) (V1.1) [!].z64"   # or set THPS_ROM
python tools/split.py       # find_funcs -> splat -> asm/ + config/functions.csv
```
`work/`, `asm/` and `build/` are generated and git-ignored; they never leave your machine.

### 4. Check everything works
```
python tools/gate.py        # every src/funcs file must match:      "N/N files match"
python tools/build.py       # full rebuild must be byte-identical:  "OK: build/main.bin is identical to the game"
```
If both pass, you have exactly the setup Steward uses to judge PRs.

## Decompile your first function

1. **Pick and claim.** On Discord or on the pinned "Active claims" issue: `/next` suggests functions, and
   `/claim 0xADDR` claims one so nobody else works on it. Claims lapse after 7 days without activity.
2. **Draft it.**
   ```
   python tools/new_func.py func_8006F274
   ```
   This writes an m2c draft to `src/funcs/func_8006F274.c` and immediately compares it.
3. **Iterate until it matches.**
   ```
   python tools/match.py src/funcs/func_8006F274.c --show
   ```
   `--show` prints your instructions next to the game's, with `!!` on every difference. Typical fixes: the right
   types (`u8` vs `s32`), statement order, a temporary variable, signedness of comparisons. It prints `MATCH` when
   every instruction agrees **and** your C covers the whole function (if more code follows, it tells you).
4. **Run both gates** (`tools/gate.py`, `tools/build.py`), then open a PR with the template filled in.

Useful extras: `tools/auto_draft.py` bulk-tries m2c drafts and keeps the ones that match as-is;
[decomp-permuter](https://github.com/simonlindholm/decomp-permuter) helps with stubborn register allocation.

## How contributions get checked and merged (Steward)

PRs are handled by **Steward**, Decompathon's automated maintainer. When you open a PR:

1. Steward checks the PR description (provenance boxes), the files you changed (only `src/funcs/` is open to
   contributors) and claims.
2. On the **judge box** (a machine with a ROM; GitHub's servers never see it) it runs two gates from the main
   branch's own scripts, with only your function files copied in:
   - **match**: every function file compiles to the original bytes, and nothing that matched before is lost;
   - **build**: the whole game code still rebuilds byte-for-byte identical.
3. It posts one comment in plain language: what it checked, what happens next, and how far the PR moves the
   project (for example "from 54 / 1,924 to 74 / 1,924 functions matched").
4. If everything is green it **merges automatically** and announces it in Discord's #progress.

Merges follow fixed rules, never AI judgement; AI only explains results in more words. A human maintainer
reviews changes to tools, config or rules, anything Steward is unsure about, and appeals (open an issue with the
`appeal` label).

**First-time contributors:** the judge runs your code on the maintainer's machine, so a maintainer adds the
`judge-ok` label before your first PR is checked. After your first merge, your PRs are checked and merged
automatically.

## Provenance and AI agents

Every PR ticks the provenance boxes in the template ([PROVENANCE.md](PROVENANCE.md) explains each one): your own
work, no leaked material, no game data, decompiled lawfully from a copy you own with tools you may legally use,
and sources listed. Steward does not merge a PR with an unticked box.

**AI agents are welcome** (Claude Code, Codex, ...). They tick "Prepared by an AI agent (model: ...)", must check
every statement against that PR's actual changes, and tick the agent acknowledgement **on every PR**. See
[AGENTS.md](AGENTS.md) for the full agent workflow.

## Non-matching C and the playable decompiled build

Some functions cannot be byte-matched with our toolchain, even when their C is known to be right. Mature N64
decomps keep such functions as "NON_MATCHING" C, and this project does the same ([RULES.md](RULES.md) rule 9):

- `src/nonmatching/func_XXXXXXXX.c` uses the same conventions as `src/funcs`, plus a `NON_MATCHING:` comment
  saying what still differs. Maintainers review each one for equivalence before it is merged.
- `python tools/nonmatching.py` checks that every such file compiles and is not also matched, and reports how
  many instructions agree. `python tools/progress.py` reports *matched* and *decompiled* separately.
- **Playable build:** `python tools/build.py --nonmatching` compiles every non-matching function into a small
  code region taken from the start of the heap, and patches a jump to it at the original address. Every other
  address stays the same. `--nonmatching=func_A,func_B` and `--nonmatching-exclude=...` select which functions
  use C. `python tools/pack_rom.py build/rom/OUT.z64 --main build/nm/main.bin` writes the result into a copy of
  your ROM as uncompressed chunks and fixes the checksum. The output goes under the git-ignored `build/` folder.
- **Checking behaviour:** `tools/emu_shots.sh` boots a ROM headless in mupen64plus and takes screenshots.
  `tools/nm_bisect.py` does that once per non-matching function and compares each run with the original. This is
  how a text-rendering bug in one function's C was found and fixed.

## Repository map

| Path | What it is |
|---|---|
| `src/funcs/func_XXXXXXXX.c` | matched functions, one per file |
| `src/nonmatching/func_XXXXXXXX.c` | equivalent C for the functions that do not byte-match (not used by the exact build) |
| `docs/ASM_UNITS.md` | what stays assembly, and why |
| `include/` | `common.h` (types), assembler macros for the full build |
| `config/main.yaml`, `boot.yaml` | splat configuration for the two segments |
| `config/functions.csv` | every function: address and size (progress is counted against it) |
| `config/symbol_addrs.txt` | known symbols; the generated part comes from `tools/find_funcs.py` |
| `tools/erz.py` | ERZ (RNC) unpacker with CRC checks |
| `tools/build_main.py` | rebuilds the main segment's RAM image from your ROM |
| `tools/split.py` | clean re-split: find_funcs, splat, function table |
| `tools/new_func.py`, `match.py` | draft a function; compare it instruction by instruction |
| `tools/gate.py`, `build.py` | the two Steward gates |
| `tools/nonmatching.py` | checks `src/nonmatching` (compiles, `NON_MATCHING:` note, not also matched) |
| `tools/build.py --nonmatching`, `pack_rom.py` | the playable decompiled build: C for every function, packed into a ROM copy |
| `tools/emu_shots.sh`, `nm_bisect.py` | headless emulator screenshots; per-function behaviour check |
| `tools/auto_draft.py`, `progress.py` | bulk m2c pass; progress counter |
| `tools/recomp_*.py`, `recomp/`, `port/` | static recompilation (below) |
| `toolchain/` | native Windows build of the compiler and assembler |
| `steward.toml` | Steward's configuration for this project (gates, policy, Discord) |
| `STATUS.md` | the detailed engineering log: every finding, in order |

## The native port (static recompilation)

`port/` runs the game natively on Windows by statically recompiling its MIPS code to C++ with
[N64Recomp](https://github.com/N64Recomp/N64Recomp) on N64ModernRuntime and RT64 (the setup is derived from the
MIT-licensed Pilotwings 64 recomp, see `port/LICENSE.pilotwings64-recomp`). It boots through the menus into
gameplay, with music, a virtual Controller Pak and controller support. It is a research tool for the decomp
(tracing which functions run, testing behaviour) and also needs your own ROM. Build notes are in STATUS.md;
`port/third_party/rsp-hle` is GPL-2.0-or-later and only used for audio diagnosis.

## FAQ

**Can I download the game here?** No. Nothing from the ROM is in the repository and nobody will share it.

**Is this legal?** The repository holds only original code written by contributors, plus tools; everything reads
your own copy of the game locally. Contributions must not contain leaked or confidential material
([PROVENANCE.md](PROVENANCE.md)).

**How do I get help?** Ask in Discord's #decomp-help forum (one post per question; include the function, your C
and the `--show` diff).

**Why does a function "match" on its own but the build fails?** Sometimes splat keeps two functions in one
assembly file, and your C has to cover the whole unit. `tools/match.py` says so explicitly.

**What do "matched" and "decompiled" mean?** *Matched* is the share of game functions (or of code bytes) whose C
is merged and proven byte-identical. *Decompiled* also counts the reviewed, equivalent C in `src/nonmatching/`.
The game is 99.78% decompiled and 86.85% matched.

**Is the game fully decompiled?** Yes, except libgcc's 64-bit divide (`__udivdi3`). That function is not game code:
it is byte-identical to GCC 2.8.1's own `libgcc2.c`, which is GPL. Since this repository is CC0, it stays as
assembly ([docs/ASM_UNITS.md](docs/ASM_UNITS.md)).
