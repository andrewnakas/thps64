"""Keep the generated split in step with its inputs: if splat's inputs changed since the last split (a pull, a
config change), re-split before a gate runs. Without this a workspace pairs a new function table with old asm."""
import hashlib
import os
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
INPUTS = ['config/main.yaml', 'config/symbol_addrs.txt', 'tools/find_funcs.py', 'tools/split.py', 'work/main.bin']
STAMP = os.path.join(ROOT, 'asm', '.inputs')


def digest():
    h = hashlib.sha256()
    for p in INPUTS:
        full = os.path.join(ROOT, p)
        if os.path.exists(full):
            h.update(p.encode() + open(full, 'rb').read().replace(b'\r\n', b'\n'))
    return h.hexdigest()


def ensure():
    want = digest()
    if os.path.exists(STAMP) and open(STAMP).read().strip() == want:
        return
    print('split inputs changed: re-splitting (tools/split.py)', flush=True)
    subprocess.run([sys.executable, os.path.join(ROOT, 'tools', 'split.py')], cwd=ROOT, check=True,
                   stdout=subprocess.DEVNULL)
    want = digest()   # split.py rewrites symbol_addrs.txt
    with open(STAMP, 'w') as f:
        f.write(want + '\n')
