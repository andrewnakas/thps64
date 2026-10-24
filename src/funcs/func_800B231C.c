#include "common.h"

void func_800B231C(u8 *a0, u8 a1, u8 a2, u8 a3, u8 a4) {
    *(s32 *)(a0 + 8) = 1;
    a0[0xC] = a1;
    a0[0xD] = a2;
    a0[0xE] = a3;
    a0[0xF] = a4;
}
