#include "common.h"

s32 func_800B4240(s32, s32);
extern u8 D_800D0FC0[];

s32 func_80095810(void) {
    s32 r = 0;
    u8 *p = D_800D0FC0;

    if (func_800B4240(p[3], 0x2000) || func_800B4240(p[2], 0x2000)) {
        r = 1;
    }
    return r;
}
