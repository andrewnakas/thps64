#include "common.h"

s32 func_8005BF24(s32);
extern u32 D_800DC5D0;

void func_80069640(s32 arg0) {
    u32 x;
    u32 y;
    u32 z;
    s32 w;

    x = D_800DC5D0;
    x ^= arg0;
    y = x << 1;
    y ^= x >> 31;
    D_800DC5D0 = y * 0x209;
    w = func_8005BF24(D_800DC5D0);
    z = D_800DC5D0;
    D_800DC5D0 = z + w;
}
