"""Grab frames of the THPS64 window with Windows Graphics Capture (works when it is covered or off-screen; never
captures other windows). Usage: python capture_wgc.py OUTDIR COUNT INTERVAL_S"""
import os
import sys
import time

from windows_capture import WindowsCapture, Frame, InternalCaptureControl

out, count, interval = sys.argv[1], int(sys.argv[2]), float(sys.argv[3])
os.makedirs(out, exist_ok=True)
state = {'n': 0, 'next': time.time() + 0.5}
cap = WindowsCapture(cursor_capture=False, draw_border=False, window_name='THPS64 Recompiled')


@cap.event
def on_frame_arrived(frame: Frame, control: InternalCaptureControl):
    if time.time() >= state['next']:
        path = os.path.join(out, f'wgc_{state["n"]:03d}.png')
        frame.save_as_image(path)
        print(path, flush=True)
        state['n'] += 1
        state['next'] = time.time() + interval
        if state['n'] >= count:
            control.stop()


@cap.event
def on_closed():
    pass


cap.start()
