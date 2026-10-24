/* cflags: -O2 */
#include "common.h"
typedef struct { s32 a; s32 b; f32 c; } Arg3750;
extern s32 D_800EA550;
void func_800A3750(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, Arg3750 arg4) {
    s32 a, b;
    f32 c;
    *(s32 *)(arg0 + 0x494) = arg1;
    *(s32 *)(arg0 + 0x434) = arg2;
    *(s32 *)(arg0 + 0x430) = arg3;
    *(s32 *)(arg0 + 0x468) = 0;
    *(f32 *)(arg0 + 0x4F0) = 0.0f;
    a = arg4.a; b = arg4.b; c = arg4.c;
    D_800EA550 = 2;
    *(s32 *)(arg0 + 0x42C) = b;
    *(s32 *)(arg0 + 0x18) = a;
    *(f32 *)(arg0 + 0x4F4) = c;
}
