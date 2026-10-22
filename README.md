# Tony Hawk's Pro Skater (N64) decompilation

Matching decompilation of Tony Hawk's Pro Skater (N64, US V1.1), the pilot project of the Decompathon decomp jams.
Maintained with Steward (an automated maintainer: claims, gates, merges); see RULES.md.

**You need your own copy of the game.** Nothing from the ROM is in this repository.

- Game code was built with KMC GCC 2.7.2; libultra in the boot segment with IDO. `toolchain/build.sh` builds the
  compiler (cc1 + gas 2.6) natively.
- `tools/erz.py` unpacks the ROM's ERZ (RNC-style) blocks, `tools/build_main.py` produces the main segment,
  `tools/split.py` splits it with splat into per-function asm.
- Work on a function: `python tools/new_func.py func_XXXXXXXX`, iterate with `python tools/match.py src/funcs/<file> --show`.
- Gates: `python tools/gate.py` (every file matches), `python tools/build.py` (byte-identical rebuild).
- `port/`: a static recompilation (N64Recomp + N64ModernRuntime) that runs the game natively; useful for tracing.

Progress: `python tools/progress.py`.
