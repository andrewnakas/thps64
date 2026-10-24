#include "common.h"

void func_80097108(u8 *a0, s32 a1, u8 a2) {
    *(s32 *)(a0 + 0xA0) = a1;
    a0[0xB6] = a2;
}
