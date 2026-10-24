#!/bin/bash
# Boot a ROM in mupen64plus with no input and save screenshots at the given frame (VI) counts, then quit.
#   tools/emu_shots.sh OUT_DIR ROM [FRAMES] [extra mupen64plus args, e.g. --set Core[DisableExtraMem]=True]
# FRAMES defaults to 600,1800,3000,4200,5400 (10..90 s at 60 VI/s). OUT_DIR must be under build/ (gitignored).
# MUPEN_ROOT: a mupen64plus tree (default ~/.local/mupen64plus/root: the Ubuntu 2.6.0 debs unpacked with
# `apt-get download` + `dpkg -x`, no root needed; libsdl2-net and libglu1-mesa unpacked there too).
# Headless: SDL's offscreen video driver (EGL), so no window opens and nothing the user types reaches the emulator
# (set SDL_VIDEODRIVER=x11 to watch). Runs without the speed limiter, with dummy audio and input (no buttons pressed).
set -e
OUT=$1; ROM=$2; FRAMES=${3:-600,1800,3000,4200,5400}; shift 3 2>/dev/null || shift $#
R=${MUPEN_ROOT:-$HOME/.local/mupen64plus/root}
LIB=$R/usr/lib/x86_64-linux-gnu
mkdir -p "$OUT/cfg"
export SDL_VIDEODRIVER=${SDL_VIDEODRIVER:-offscreen}
export LD_LIBRARY_PATH=$LIB${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}
timeout 900 "$R/usr/games/mupen64plus" --noosd --windowed --nosaveoptions --configdir "$OUT/cfg" \
  --datadir "$R/usr/share/games/mupen64plus" --plugindir "$LIB/mupen64plus" --corelib "$LIB/libmupen64plus.so.2" \
  --gfx mupen64plus-video-glide64mk2 --audio dummy --input dummy --rsp mupen64plus-rsp-hle --nospeedlimit \
  --sshotdir "$OUT" --testshots "$FRAMES" "$@" "$ROM" > "$OUT/log.txt" 2>&1 || echo "mupen64plus exited with $? (see $OUT/log.txt)"
grep -E "Captured screenshot|Error|error" "$OUT/log.txt" || true
