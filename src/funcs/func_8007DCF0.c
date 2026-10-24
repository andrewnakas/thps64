#include "common.h"

void func_8007DCF0(u8 *arg0, s32 arg1, s32 arg2, u8 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8) {
    *(s32 *)(arg0 + 0xA0) = (arg1 << 16) | (arg4 << 8) | arg3;
    *(s32 *)(arg0 + 0xA4) = (arg2 << 16) | (arg6 << 8) | arg5;
    *(s16 *)(arg0 + 0xA8) = (arg8 << 8) | arg7;
}
