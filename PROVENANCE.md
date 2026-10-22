# Provenance

This project only accepts work that anyone could reproduce from a legally owned copy of the game and lawful tools.
Every pull request carries the provenance checklist from `.github/pull_request_template.md`, and Steward will not
merge a PR until every box is ticked.

## What the boxes mean

- **Own work.** You wrote it, or an AI agent you run wrote it under your direction, or you have permission from
  whoever did.
- **No leaked material.** Nothing from leaked or confidential Activision, Neversoft or Edge of Reality source code,
  debug symbols, linker maps, internal builds or internal documents. That includes names: a function or variable
  name must come from the binary itself (strings, behaviour, libultra signatures) or from your own judgement.
- **No game data.** No ROM images or ROM bytes, no game assets, no proprietary Nintendo SDK files. The repo only
  holds our C, tools and configuration; the game is read from your own copy at build time.
- **Lawful decompilation.** You worked from a copy of the game you legally own, with tools you are legally allowed
  to use (the open-source tools in this repo, m2c, splat, decomp-permuter, your own scripts, and the like).
- **Sources listed.** Anything you relied on beyond the repo's own tools is named in the PR.

## Humans and AI agents

Tick exactly one "who made this" box.

AI agents may prepare and submit PRs. An agent has to tick the boxes itself **on every PR**, after checking each
statement against that PR's actual changes, and must also tick the agent acknowledgement. The acknowledgement says
that the human who runs the agent is responsible for the contribution. An earlier PR's ticks never carry over.

If you are unsure about any box, leave it unticked and ask in the PR or on Discord.
