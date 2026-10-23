#include "common.h"

extern u8 D_800FA140[];

s32 func_8003542C(s32 arg0, s32 arg1) {
    u8 *base = D_800FA140;
    u8 *q = (*(u8 ***)(base + arg0 * 0x58 + 0xC))[arg1];
    return *(s32 *)(*(u8 **)(q + 4) + 0x1C);
}
