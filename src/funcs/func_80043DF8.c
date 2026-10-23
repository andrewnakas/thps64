#include "common.h"

void func_80022E0C(void);
extern s32 D_800D49C4;

s32 func_80043DF8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 num;
    s32 den;
    s32 t;

    if (arg0 < arg1) {
        return -0x7F;
    }
    if (arg2 < arg0) {
        return 0x7F;
    }
    if (arg0 < arg3 - 0x20) {
        D_800D49C4 = 0;
        func_80022E0C();
        num = arg0 + 0x20;
        num = (arg3 - num) * -0x7F;
        den = arg1 + 0x20;
        den = arg3 - den;
    } else if (arg3 + 0x20 < arg0) {
        D_800D49C4 = 0;
        func_80022E0C();
        t = arg0 - 0x20;
        t = t - arg3;
        num = t * 0x7F;
        den = arg2 - 0x20;
        den = den - arg3;
    } else {
        return 0;
    }
    return num / den;
}
