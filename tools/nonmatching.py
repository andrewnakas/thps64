#!/usr/bin/env python3
"""NON_MATCHING gate: equivalent C for functions that cannot be byte-matched (yet).

  python tools/nonmatching.py            -> one line per file (instructions agreeing), then a summary; exit 0 only if
                                            every file is well-formed and compiles
  python tools/nonmatching.py --scores   -> also write src/nonmatching/scores.csv: each function's similarity to the
                                            game in percent (for the progress report's fuzzy match; numbers only)
A function that resisted matching may get a readable, behaviour-equivalent C version as
src/nonmatching/func_XXXXXXXX.c. The build keeps using its asm (asm/nonmatchings/game/), so the game stays
byte-identical; the file documents the function and is the starting point for whoever matches it later. Rules:
- same file conventions as src/funcs (one function, `/* compiler: ... */` and `/* cflags: ... */` first lines);
- a `NON_MATCHING:` comment in the first lines saying what still differs from the game;
- it must compile with the project toolchain;
- it must not also exist in src/funcs (once it matches, move it there and delete it here).
tools/progress.py reports these as decompiled, separately from matched.
"""
import contextlib
import csv
import difflib
import glob
import io
import os
import re
import subprocess
import sys
import tempfile

sys.path.insert(0, os.path.dirname(__file__))
import match  # noqa: E402

ROOT = match.ROOT
SCORES = os.path.join(ROOT, 'src', 'nonmatching', 'scores.csv')


def _norm(words):
    """Disassembly with relocated fields (immediates, branch/jump targets) masked, so only the instruction shape
    and registers are compared."""
    import rabbitizer
    out = []
    for w in words:
        t = rabbitizer.Instruction(w).disassemble()
        t = re.sub(r'\. \+ 4 \+ \(.*?\)', 'B', t)
        out.append(re.sub(r'func_\w+|-?0x[0-9A-Fa-f]+\b', 'X', t))
    return out


def similarity(o_file, name, addr, size):
    """Percent similarity (difflib ratio over masked disassembly) of our function against the game's bytes."""
    import struct
    from elftools.elf.elffile import ELFFile
    elf = ELFFile(io.BytesIO(open(o_file, 'rb').read()))
    text = elf.get_section_by_name('.text')
    sym = next(s for s in elf.get_section_by_name('.symtab').iter_symbols() if s.name == name)
    ends = sorted(s['st_value'] for s in elf.get_section_by_name('.symtab').iter_symbols()
                  if s['st_info']['type'] == 'STT_FUNC' and s['st_value'] > sym['st_value'])
    data = text.data()[sym['st_value']:ends[0] if ends else len(text.data())]
    ours = [struct.unpack_from('>I', data, i)[0] for i in range(0, len(data) - 3, 4)]
    main = open(match.MAIN, 'rb').read()[addr - match.MAIN_VRAM:addr - match.MAIN_VRAM + size]
    game = [struct.unpack_from('>I', main, i)[0] for i in range(0, len(main) - 3, 4)]
    return 100.0 * difflib.SequenceMatcher(None, _norm(ours), _norm(game), autojunk=False).ratio()


def check_one(path, funcs, score=None):
    """-> (ok, message) for one src/nonmatching file. `score`: {} to receive {name: similarity percent}; needs
    `funcs` as {name: (addr, size)}."""
    name = os.path.basename(path)[:-2]
    if not re.fullmatch(r'func_[0-9A-F]{8}', name) or name not in funcs:
        return False, 'not a function in config/functions.csv'
    if os.path.exists(os.path.join(ROOT, 'src', 'funcs', name + '.c')):
        return False, 'also matched in src/funcs: delete the non-matching copy'
    with open(path, encoding='utf-8', errors='replace') as f:
        head = ''.join(f.readline() for _ in range(8))
    if 'NON_MATCHING:' not in head:
        return False, 'needs a `NON_MATCHING:` comment in its first lines saying what differs'
    out = io.StringIO()
    with tempfile.TemporaryDirectory() as tmp:
        try:
            o_file = match.build(path, tmp)
            with contextlib.redirect_stdout(out):
                match.compare(o_file)
            if score is not None:
                score[name] = similarity(o_file, name, *funcs[name])
        except (match.CompileError, subprocess.CalledProcessError) as e:
            return False, 'COMPILE ERROR: ' + str(e)[-500:]
    lines = [x for x in out.getvalue().splitlines() if x.startswith(('MATCH', 'DIFF')) and name in x]
    if not lines:
        return False, f'does not define {name}'
    if lines[0].startswith('MATCH'):
        return True, 'MATCHES: move it to src/funcs'
    return True, lines[0][len('DIFF '):]


def main():
    funcs = {r['name']: (int(r['addr'], 16), int(r['size'], 16))
             for r in csv.DictReader(open(os.path.join(ROOT, 'config', 'functions.csv')))}
    files = sorted(glob.glob(os.path.join(ROOT, 'src', 'nonmatching', '*.c')))
    scores = {} if '--scores' in sys.argv else None
    bad = 0
    for p in files:
        ok, msg = check_one(p, funcs, scores)
        bad += not ok
        print(f'{"ok  " if ok else "FAIL"} {os.path.basename(p)}: {msg}')
    for f in glob.glob(os.path.join(ROOT, 'astemp_*')):
        os.remove(f)
    print(f'{len(files) - bad}/{len(files)} non-matching files ok')
    if scores is not None:
        with open(SCORES, 'w', newline='\n') as f:
            f.write('name,fuzzy_match_percent\n')
            for n in sorted(scores):
                f.write(f'{n},{scores[n]:.1f}\n')
        print(f'{SCORES}: {len(scores)} scores')
    sys.exit(1 if bad else 0)


if __name__ == '__main__':
    main()
