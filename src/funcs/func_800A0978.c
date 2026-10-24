/* cflags: -O2 */
/* D3: u8 c with explicit range tests (extra zero-extends at loop time make loop.c hoist only 0x34-0x3D, like the game). */
#include "common.h"

void func_8009E0F0(s8 *, s32, s32);

void func_800A0978(s32 arg0, u8 *src, s8 *dst, s32 n) {
    s32 i;
    u8 c;
    u8 ch;

    func_8009E0F0(dst, 0, n);
    i = 0;
    while ((c = *src) != 0) {
        if (i >= n) break;
        if (c >= 0x41 && c <= 0x5A) {
            *dst = c - 0x27;
        } else if (c >= 0x61 && c <= 0x7A) {
            *dst = c - 0x47;
        } else if (c >= 0x30 && c <= 0x39) {
            *dst = c - 0x20;
        } else {
            ch = *src;
            switch (ch) {
            case 0x21: *dst = 0x34; break;
            case 0x22: *dst = 0x35; break;
            case 0x23: *dst = 0x36; break;
            case 0x27: *dst = 0x37; break;
            case 0x2A: *dst = 0x38; break;
            case 0x2B: *dst = 0x39; break;
            case 0x2C: *dst = 0x3A; break;
            case 0x2D: *dst = 0x3B; break;
            case 0x2E: *dst = 0x3C; break;
            case 0x2F: *dst = 0x3D; break;
            case 0x3A: *dst = 0x3E; break;
            case 0x3D: *dst = 0x3F; break;
            case 0x3F: *dst = 0x40; break;
            case 0x40: *dst = 0x41; break;
            case 0x20: *dst = 0xF; break;
            default: *dst = 0x38; break;
            }
        }
        src++;
        dst++;
        i++;
    }
}
