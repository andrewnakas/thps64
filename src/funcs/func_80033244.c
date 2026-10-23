#include "common.h"

void func_80033244(s32 arg0, s16 *arg1, u8 *arg2, u8 *arg3, s32 arg4, u8 *arg5, u8 *arg6, s16 *arg7, s16 *arg8, s16 *arg9, s16 *arg10) {
    s32 dir;

    if (*arg7 == 0x8D) {
        *arg2 = *arg3;
    } else if (*arg1 == 1) {
        *arg8 -= 0x1A;
        *arg7 -= 0x1A;
    } else if (*arg1 == -1) {
        *arg8 += 0x1A;
        *arg7 += 0x1A;
    }
    if (*arg9 == 0xDF) {
        *arg5 = *arg6;
        return;
    }
    dir = *arg1;
    if (dir == 1) {
        *arg10 -= 0xA;
        *arg9 -= 0xA;
    } else if (dir == -1) {
        *arg10 += 0xA;
        *arg9 += 0xA;
    }
}
