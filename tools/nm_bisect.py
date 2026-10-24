#!/usr/bin/env python3
"""Find which src/nonmatching functions change what the game shows: build, pack and boot one ROM per function.

  python tools/nm_bisect.py [func_A,func_B,...] [--frames 600,4200] [--4mb]
For each function (default: every src/nonmatching file) this runs `tools/build.py --nonmatching=func_X`,
`tools/pack_rom.py build/bisect/func_X.z64`, and `tools/emu_shots.sh` (headless mupen64plus, no input) and compares
the screenshots with those of the repacked byte-identical game (build.py, then pack_rom.py). Emulation without
input is deterministic, so any differing frame means that function's C behaves differently from its asm (or the
emulator run was not reproducible: the reference is run twice to check). Prints one line per function.
Everything goes under build/bisect/ (gitignored).
"""
import argparse
import glob
import hashlib
import os
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OUT = os.path.join(ROOT, 'build', 'bisect')


def run(cmd):
    r = subprocess.run(cmd, cwd=ROOT, capture_output=True, text=True)
    if r.returncode:
        sys.exit(f'{" ".join(cmd)} failed:\n{(r.stdout + r.stderr)[-2000:]}')
    return r.stdout


def shots(name, rom, frames, extra):
    d = os.path.join(OUT, 'shots', name)
    subprocess.run(['rm', '-rf', d])
    run(['bash', os.path.join(ROOT, 'tools', 'emu_shots.sh'), d, rom, frames, *extra])
    pngs = sorted(glob.glob(os.path.join(d, '*.png')))
    if len(pngs) < len(frames.split(',')):
        sys.exit(f'{name}: only {len(pngs)} screenshot(s) in {d} (emulator stopped early?)')
    return [hashlib.md5(open(p, 'rb').read()).hexdigest() for p in pngs[:len(frames.split(','))]], d


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument('funcs', nargs='?', default='')
    ap.add_argument('--frames', default='600,4200')
    ap.add_argument('--4mb', dest='mb4', action='store_true', help='boot without the expansion pak')
    a = ap.parse_args()
    extra = ['--set', 'Core[DisableExtraMem]=True'] if a.mb4 else []
    names = [x for x in a.funcs.split(',') if x] or sorted(
        os.path.basename(p)[:-2] for p in glob.glob(os.path.join(ROOT, 'src', 'nonmatching', 'func_*.c')))
    os.makedirs(OUT, exist_ok=True)
    py = sys.executable
    run([py, 'tools/build.py'])
    run([py, 'tools/pack_rom.py', os.path.join(OUT, 'reference.z64')])
    ref, _ = shots('reference', os.path.join(OUT, 'reference.z64'), a.frames, extra)
    again, _ = shots('reference2', os.path.join(OUT, 'reference.z64'), a.frames, extra)
    if again != ref:
        sys.exit('the reference ROM does not give the same screenshots twice: emulation is not reproducible here')
    bad = []
    for name in names:
        run([py, 'tools/build.py', f'--nonmatching={name}'])
        rom = os.path.join(OUT, name + '.z64')
        run([py, 'tools/pack_rom.py', rom, '--main', os.path.join(ROOT, 'build', 'nm', 'main.bin')])
        got, d = shots(name, rom, a.frames, extra)
        diff = [f for f, x, y in zip(a.frames.split(','), got, ref) if x != y]
        print(f'{"DIFF" if diff else "same"} {name}' + (f': frame(s) {",".join(diff)} differ ({d})' if diff else ''),
              flush=True)
        if diff:
            bad.append(name)
    print(f'{len(bad)}/{len(names)} function(s) change the screenshots' + (': ' + ','.join(bad) if bad else ''))


if __name__ == '__main__':
    main()
