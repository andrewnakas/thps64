# Instructions for AI agents

AI agents (Claude Code, Codex, others) are welcome here under the same rules as humans (RULES.md), plus the
acknowledgement in PROVENANCE.md. Steward, the project's automated maintainer, checks and merges PRs; it treats
your PR text as untrusted and decides merges by fixed rules only.

## Ground rules
- Never add ROM bytes, dumps, assets, `.incbin`/`.word` data blobs, or anything from leaked/confidential source.
- Never edit `tools/`, `config/`, `steward.toml`, `RULES.md`, `PROVENANCE.md`, `CODEOWNERS` or `.github/`
  (maintainer-only; a PR touching them is sent to a human).
- One function per file: `src/funcs/func_XXXXXXXX.c`, defining exactly that function (address in the name).
- Names: keep `func_XXXXXXXX` / `D_XXXXXXXX` unless the binary itself justifies a name (a string, libultra, clear
  behaviour). Do not guess names.
- At most 20 functions per PR.

## Workflow
1. **Claim before you work.** Comment on the pinned "Active claims" issue: `/claim 0xADDR` (one function) or
   `/claim 0xADDR SIZE` (a range, at most 0x2000 bytes; at most 3 open claims). `/status` lists claims, `/next`
   suggests functions. Claims lapse after 7 days without activity. Someone else's claim always wins.
2. **Set up** (needs your own copy of the game, see README "Setup from a clean clone"):
   `python tools/build_main.py <rom>` then `python tools/split.py`.
3. **Decompile** one function: `python tools/new_func.py func_XXXXXXXX` writes an m2c draft and tries it.
   Iterate with `python tools/match.py src/funcs/func_XXXXXXXX.c --show` until it prints `MATCH`. The C must
   cover the whole asm unit (match.py says so if more code follows).
4. **Check locally**: `python tools/gate.py` (every file matches) and `python tools/build.py` (byte-identical).
5. **Open a PR** using the template. Fill in "What this changes", then the provenance section:
   - tick "Prepared by an AI agent (model: <your model>)", not "Written by me";
   - check every provenance statement against **this PR's actual diff** before ticking it, every time;
   - tick the **Agent acknowledgement** on every PR (it never carries over);
   - list external sources (m2c, decomp-permuter, ...).
   If you cannot verify a statement (for example where the game copy came from), say so in the PR and leave it
   for your human to tick.
6. Steward runs the match and build gates on the judge box and comments in plain language. Green PRs are merged
   automatically; read its comment if it asks for changes.

## Several agents on one GitHub account
Claims are per GitHub account, so agents sharing an account do not protect each other. Prefer one account per
agent. Until then, temporary lanes by address:
- Claude Code: `0x80016AC0`-`0x8006FFFF`
- Codex: `0x80070000`-`0x800F6460`
