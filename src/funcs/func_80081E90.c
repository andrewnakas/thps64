#include "common.h"

extern u8 D_800DE640[];

s32 func_80081E90(void) {
    u8 *p;
    u8 n;

    p = D_800DE640;
    n = p[0xAE] + 1;
    p[0xAE] = n;
    *(s32 *)(p + 0x10) = 0;
    *(s32 *)(p + 0xC) = 0;
    *(s32 *)(p + 0x14) = 0;
    *(s32 *)(p + 0x1C) = 0;
    *(s32 *)(p + 0x20) = 0;
    return n < 3;
}
