/* cflags: -O2 */
/* D4: sibling of func_800A0978 (inverse mapping): u8 c with explicit range tests. */
#include "common.h"

void func_800A0B0C(s32 arg0, u8 *src, s8 *dst, s32 n) {
    s32 i;
    u8 c;
    u8 ch;

    i = 0;
    while ((c = *src) != 0) {
        if (i >= n) break;
        if (c >= 0x1A && c <= 0x33) {
            *dst = c + 0x47;
        } else if (c >= 0x10 && c <= 0x1F) {
            *dst = c + 0x20;
        } else {
            ch = *src;
            switch (ch) {
            case 0x34: *dst = 0x21; break;
            case 0x35: *dst = 0x22; break;
            case 0x36: *dst = 0x23; break;
            case 0x37: *dst = 0x27; break;
            case 0x38: *dst = 0x2A; break;
            case 0x39: *dst = 0x2B; break;
            case 0x3A: *dst = 0x2C; break;
            case 0x3B: *dst = 0x2D; break;
            case 0x3C: *dst = 0x2E; break;
            case 0x3D: *dst = 0x2F; break;
            case 0x3E: *dst = 0x3A; break;
            case 0x3F: *dst = 0x3D; break;
            case 0x40: *dst = 0x3F; break;
            case 0x41: *dst = 0x40; break;
            case 0xF: *dst = 0x20; break;
            default: *dst = 0x2A; break;
            }
        }
        src++;
        dst++;
        i++;
    }
    *dst = 0;
}
