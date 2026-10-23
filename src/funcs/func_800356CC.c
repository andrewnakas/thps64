#include "common.h"

extern u8 D_800D36DC[];

void func_800356CC(s32 a, s32 b, s32 c) {
    u8 *p = D_800D36DC;
    p[0] = a;
    p[1] = b;
    p[2] = c;
}
