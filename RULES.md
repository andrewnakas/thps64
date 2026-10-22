# Rules (THPS N64 decomp, Decompathon pilot)
1. One function per file: `src/funcs/func_XXXXXXXX.c`, defining exactly that function.
2. It must compile with KMC GCC 2.7.2 (`-O2 -G0`, see tools/match.py) to the game's exact bytes: the `match` gate.
3. Zero-loss: nothing that already matches may break or disappear, and the whole main segment must still rebuild
   byte-identical (`build` gate). Both gates run on the judge box with the owner's ROM, never on GitHub.
4. Provenance (PROVENANCE.md): every PR ticks every box: own work, no leaked material, no game data, decompiled
   lawfully from a copy you own with tools you may use, sources listed. Code from projects that have not opted in
   is not allowed either.
5. Claimed by someone else? Ask them (`/claim`, `/status`). Claims lapse after 7 days without activity (reminder
   after 5). Touching someone's merged function: Steward asks them; 7 days of silence = go ahead, credit kept.
6. Up to 20 functions per PR. tools/, config/, steward.toml and these rules are maintainer-only (CODEOWNERS).
7. Tick who made the PR. AI agents may contribute, but must tick every box themselves on every PR, after checking
   it against the PR's actual changes, plus the agent acknowledgement. Names and comments need a reason, not a guess.
8. Steward merges when the deterministic gates pass; its AI notes only explain. Appeals: open an issue labelled `appeal`.
