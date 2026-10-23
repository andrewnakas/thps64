#include "common.h"

extern u16 D_800DCAAC;
extern u8 D_800DD920[];

s32 func_8006F040(u8 *s) {
    s32 max;
    s32 cur;
    s32 w;
    u8 c;

    max = 0;
    cur = 0;
    while (1) {
        c = *s;
        if (c == 0) {
            break;
        }
        w = D_800DD920[c];
        if (w == 0xFE) {
            w = -1;
        }
        if (w == 0xFD) {
            w = -1;
        }
        if (w == 0xFC) {
            w = -1;
        }
        if (w == 0xFB) {
            w = -1;
        }
        if (w == 0xFA) {
            w = -1;
        }
        if (w == 0xFF) {
            w = -1;
        }
        if (w >= 0) {
            if (max < cur) {
                max = cur;
            }
        }
        s++;
    }
    return (max * D_800DCAAC) >> 8;
}
