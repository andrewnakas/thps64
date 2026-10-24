# Non-matching C

Readable, behaviour-equivalent C for functions that could not be byte-matched (yet). The build does **not** use
these files: the game is still linked from `asm/nonmatchings/game/*.s` for these functions, so it stays
byte-identical. They count as *decompiled* but not *matched* in `tools/progress.py`.

Each `func_XXXXXXXX.c` follows the `src/funcs` conventions (optional `/* compiler: ... */` and `/* cflags: ... */`
first lines) and carries a `NON_MATCHING:` comment near the top with the best score and what still differs.
`python tools/nonmatching.py` checks that every file compiles and reports how many instructions agree.

Matched it? Move the file to `src/funcs/` (drop the NON_MATCHING comment) and open a normal PR.
