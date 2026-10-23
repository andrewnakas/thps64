#include "common.h"

extern u16 D_800DCAAC;
extern u8 D_800DD920[];

s32 func_8006F0D8(u8 *arg0) {
    s32 n;
    s32 w;
    s32 c;
    s32 t;

    w = 0;
    n = 0;
    while (1) {
        c = *arg0;
        if (c == 0) break;
        c = D_800DD920[c];
        if (c == 0xFE) c = -1;
        if (c == 0xFD) c = -1;
        if (c == 0xFC) c = -1;
        if (c == 0xFB) c = -1;
        if (c == 0xFA) c = -1;
        if (c == 0xFF) c = -1;
        if (c >= 0) {
            n++;
        } else {
            w += 10;
        }
        arg0++;
    }
    t = w * D_800DCAAC;
    w = t >> 8;
    return w + n * 3;
}
