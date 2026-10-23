#include "common.h"

s32 func_8006DA28(u8 *);
s32 func_8006DB34(u8 *);
extern u16 D_800DCAAC;
extern u8 D_800DCC1E;
extern u8 D_800DD920[];

s32 func_8006ED38(u8 *arg0) {
    s32 max;
    s32 cur;
    s32 w;
    s32 r;
    u8 *p;

    if (D_800DCC1E == 0) {
        p = arg0;
        max = 0;
        cur = max;
        while (1) {
            if (*p == 0) {
                break;
            }
            w = D_800DD920[*p];
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
            p++;
        }
        return (max * D_800DCAAC) >> 8;
    }
    r = func_8006DB34(arg0);
    return r + func_8006DA28(arg0);
}
