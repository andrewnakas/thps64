# THPS N64 decomp + recomp: status

Pilot game for Decompathon Steward (E:/decompathon-steward). Private, local only. No ROM or derived data in git.

## ROM
- `E:\Tony Hawk's Pro Skater (U) (V1.1) [!].z64`, 12 MiB, sha1 4900b6c92fb8df1765e91e891dccc525bb102fe1
- Header: NTFE "TONY HAWK PRO SKATER", entry 0x80000400, libultra rev 0x1444

## Findings (2026-10-21)
- Only ROM 0x1000-~0x13B00 is plain code: boot + libultra + the unpackers (loaded at 0x80000400).
- Everything else is **ERZ** blocks = Edge of Reality's renamed RNC ProPack (18-byte RNC header, magic `ERZ\x01`/`ERZ\x02`).
  1109 blocks with valid header CRC: ~1094 method 1, 15 method 2; ~18.5 MB unpacked.
- `tools/erz.py`: method 1 = dernc port, method 2 = the game's own routine 0x80000CE8 run in `tools/mips_mini.py`.
  Both verified by the header's unpacked CRC-16.
- Plain-segment idioms: `or` moves 634, `addu` moves 104, `daddu` 25, `sd ra` 76 -> mixed (libultra + hand asm); compiler of game code TBD.

## Next
1. Find which ERZ blocks are code (main game segment + overlays), and their RAM addresses (look for the loader table in boot).
2. Identify compiler (IDO 5.3/7.1 vs GCC 2.7.2 / KMC) from game-code prologues; match one function.
3. splat yaml over a "decompressed ROM" layout (or per-segment), objdiff config, function table for Steward.
4. Recomp harness: N64Recomp over the unpacked code segments (needs symbol/segment TOML).
