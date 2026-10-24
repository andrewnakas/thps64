#!/usr/bin/env python3
"""Progress badge files for the README (written by .github/workflows/progress.yml to the `progress` branch).

  python tools/progress_badge.py OUTDIR
OUTDIR/progress.json  shields.io endpoint badge: decompiled (matched + src/nonmatching) share of code bytes
OUTDIR/matched.json   shields.io endpoint badge: byte-matched share of code bytes
OUTDIR/fuzzy.json     shields.io endpoint badge: fuzzy match (matched + non-matching similarity, as on ByteMatch)
OUTDIR/progress.svg   a progress bar: matched (bright) and decompiled (dark) bytes, plus the function count
Same numbers as tools/progress.py; needs no ROM.
"""
import json
import os
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def fuzzy_bytes(p):
    """Matched bytes plus each non-matching function's size times its similarity (src/nonmatching/scores.csv), the
    same fuzzy match the objdiff report gives ByteMatch."""
    import csv
    sizes = {r['name']: int(r['size'], 16) for r in csv.DictReader(open(os.path.join(ROOT, 'config', 'functions.csv')))}
    extra = 0.0
    path = os.path.join(ROOT, 'src', 'nonmatching', 'scores.csv')
    if os.path.exists(path):
        for r in csv.DictReader(open(path)):
            if r['name'] in sizes and not os.path.exists(os.path.join(ROOT, 'src', 'funcs', r['name'] + '.c')):
                extra += sizes[r['name']] * float(r['fuzzy_match_percent']) / 100.0
    return p['matched_bytes'] + extra


def color(pct):
    return 'red' if pct < 10 else 'orange' if pct < 30 else 'yellow' if pct < 60 else 'yellowgreen' if pct < 90 else 'brightgreen'


def main():
    out = sys.argv[1]
    os.makedirs(out, exist_ok=True)
    p = json.loads(subprocess.run([sys.executable, os.path.join(ROOT, 'tools', 'progress.py'), '--json'],
                                  capture_output=True, text=True, check=True).stdout)
    matched, decomp = p['percent_bytes'], p['percent_decompiled_bytes']
    fuzzy = 100.0 * fuzzy_bytes(p) / p['code_bytes']
    badges = {
        'progress.json': ('decompiled', decomp, f"{decomp:.1f}% ({p['decompiled_functions']}/{p['functions']} functions)"),
        'matched.json': ('matched', matched, f"{matched:.1f}% ({p['matched_functions']}/{p['functions']} functions)"),
        'fuzzy.json': ('fuzzy match', fuzzy, f"{fuzzy:.1f}%"),
    }
    for name, (label, pct, msg) in badges.items():
        with open(os.path.join(out, name), 'w', newline='\n') as f:
            json.dump({'schemaVersion': 1, 'label': label, 'color': color(pct), 'message': msg}, f)
    w, h = 520, 28
    fill_m, fill_d = round(w * matched / 100.0), round(w * decomp / 100.0)
    text = (f"{decomp:.1f}% decompiled · {matched:.1f}% byte-matched · "
            f"{p['matched_functions']} / {p['functions']} matched")
    svg = (f'<svg xmlns="http://www.w3.org/2000/svg" width="{w}" height="{h}" role="img" aria-label="{text}">'
           f'<title>{text}</title>'
           f'<rect width="{w}" height="{h}" rx="5" fill="#2b2f36"/>'
           f'<rect width="{fill_d}" height="{h}" rx="5" fill="#1f6f3a"/>'
           f'<rect width="{fill_m}" height="{h}" rx="5" fill="#3fb950"/>'
           f'<text x="{w // 2}" y="{h // 2 + 5}" text-anchor="middle" font-family="Verdana,DejaVu Sans,sans-serif" '
           f'font-size="13" fill="#ffffff">{text}</text></svg>\n')
    with open(os.path.join(out, 'progress.svg'), 'w', newline='\n', encoding='utf-8') as f:
        f.write(svg)
    print(text + f" · fuzzy {fuzzy:.1f}%")

if __name__ == '__main__':
    main()
