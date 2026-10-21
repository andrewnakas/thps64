#!/usr/bin/env python3
"""Run N64Recomp until it succeeds, stubbing boot functions it cannot translate (libultra internals the
runtime replaces: cop0, cache, exception code; the hand-written ERZ unpacker). Stops on any game (main) function.

  python tools/recomp_loop.py [N64Recomp.exe]
"""
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
N64R = sys.argv[1] if len(sys.argv) > 1 else os.environ.get('N64RECOMP',
    'C:/Users/andre/OneDrive/Documents/n64cleanrecomp/external/pilotwings-64-recomp/lib/N64ModernRuntime/N64Recomp/build-win/N64Recomp.exe')
RD = os.path.join(ROOT, 'recomp')


def main():
    syms = open(os.path.join(RD, 'thps.syms.toml')).read()
    addr = {m.group(1): int(m.group(2), 16) for m in re.finditer(r'name = "(\w+)", vram = 0x([0-9A-F]{8})', syms)}
    for it in range(200):
        cfg_p = os.path.join(RD, 'thps.toml')
        cfg = open(cfg_p).read()
        stubs = re.search(r'stubs = \[(.*?)\]', cfg, re.S).group(1)
        r = subprocess.run([N64R, 'thps.toml'], cwd=RD, capture_output=True, text=True)
        out = r.stdout + r.stderr
        if r.returncode == 0:
            print(f'N64Recomp OK ({it} new stubs this run)')
            return 0
        m = re.search(r'Error recompiling (\w+)', out)
        if not m:
            print('N64Recomp failed:', out[-800:])
            return 1
        name = m.group(1)
        a = addr.get(name, 0)
        why = [l for l in out.splitlines() if l.strip() and not l.startswith(('[Info]', 'Function count', 'Working dir'))
               and 'Error' not in l]
        why = why[-1] if why else ''
        if a >= 0x80016AC0 and not re.search(r'cop0|instruction: cache', why):
            print(f'STOP: game function {name} ({a:#x}): {why[:200]}')
            return 1
        # boot libultra internals, and game functions that only poke cop0 (TLB/debug leftovers), become stubs
        open(cfg_p, 'w').write(cfg.replace('stubs = [' + stubs + ']', 'stubs = [' + stubs + f', "{name}"]'))
        print(f'stubbed {name} {a:#x}: {why[:100]}')
    return 1


if __name__ == '__main__':
    sys.exit(main())
