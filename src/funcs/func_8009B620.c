#include "common.h"

void func_8009B620(u8 *a0, u8 a1, u8 a2, u8 a3, u8 a4) {
    a0[0x511] = a1;
    a0[0x512] = a2;
    a0[0x513] = a3;
    *(f32 *)(a0 + 0x514) = a4;
}
