#!/usr/bin/env python3
"""Progress badge files for the README (written by .github/workflows/progress.yml to the `progress` branch).

  python tools/progress_badge.py OUTDIR
OUTDIR/progress.json  shields.io endpoint badge ("decompiled 7.8%")
OUTDIR/progress.svg   a plain progress bar (bytes of game code matched, plus the function count)
Same numbers as tools/progress.py; needs no ROM.
"""
import json
import os
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def main():
    out = sys.argv[1]
    os.makedirs(out, exist_ok=True)
    p = json.loads(subprocess.run([sys.executable, os.path.join(ROOT, 'tools', 'progress.py'), '--json'],
                                  capture_output=True, text=True, check=True).stdout)
    pct = p['percent_bytes']
    color = 'red' if pct < 10 else 'orange' if pct < 30 else 'yellow' if pct < 60 else 'yellowgreen' if pct < 90 else 'brightgreen'
    with open(os.path.join(out, 'progress.json'), 'w', newline='\n') as f:
        json.dump({'schemaVersion': 1, 'label': 'decompiled', 'color': color,
                   'message': f"{pct:.1f}% ({p['matched_functions']}/{p['functions']} functions)"}, f)
    w, h = 400, 28
    fill = round(w * pct / 100.0)
    text = f"{pct:.1f}% of game code · {p['matched_functions']} / {p['functions']} functions"
    svg = (f'<svg xmlns="http://www.w3.org/2000/svg" width="{w}" height="{h}" role="img" aria-label="{text}">'
           f'<title>{text}</title>'
           f'<rect width="{w}" height="{h}" rx="5" fill="#2b2f36"/>'
           f'<rect width="{fill}" height="{h}" rx="5" fill="#3fb950"/>'
           f'<text x="{w // 2}" y="{h // 2 + 5}" text-anchor="middle" font-family="Verdana,DejaVu Sans,sans-serif" '
           f'font-size="13" fill="#ffffff">{text}</text></svg>\n')
    with open(os.path.join(out, 'progress.svg'), 'w', newline='\n', encoding='utf-8') as f:
        f.write(svg)
    print(text)


if __name__ == '__main__':
    main()
