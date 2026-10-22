# Rules (THPS N64 decomp, Decompathon pilot)
1. One function per file: `src/funcs/func_XXXXXXXX.c`, defining exactly that function.
2. It must compile with KMC GCC 2.7.2 (`-O2 -G0`, see tools/match.py) to the game's exact bytes: the `match` gate.
3. Zero-loss: nothing that already matches may break or disappear, and the whole main segment must still rebuild
   byte-identical (`build` gate). Both gates run on the judge box with the owner's ROM, never on GitHub.
4. No game files, ROM bytes, dumps or code from leaks or from projects that have not opted in.
5. Claimed by someone else? Ask them (`/claim`, `/status`). Touching someone's merged function: Steward asks them;
   7 days of silence = go ahead, original credit kept.
6. Up to 20 functions per PR. tools/, config/, steward.toml and these rules are maintainer-only (CODEOWNERS).
7. Say how AI was used in the PR template. Names and comments need a reason, not a guess.
8. Steward merges when the deterministic gates pass; its AI notes only explain. Appeals: open an issue labelled `appeal`.
