/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

s32 func_800B4264(u8, s32);
extern u8 D_800D0FC0[];
extern s32 D_800DE7A0;
extern s32 D_800DE7C8;
extern s32 D_800DE964;
extern s32 D_800DE968;
extern s32 D_800DE9A8;
extern s32 D_800DE9C4;

s32 func_80091320(s32 arg0) {
    s32 a;
    s32 b;
    s32 r;
    s32 res;

    a = func_800B4264(D_800D0FC0[2], arg0);
    b = func_800B4264(D_800D0FC0[3], arg0);
    if (D_800DE9A8 == 1) {
        return a;
    }
    if (D_800DE7A0 == 7 && D_800DE7C8 == 0) {
        r = a;
        if (D_800DE9C4 != 0) {
            r = b;
        }
        return r;
    }
    if (D_800DE964 != 0) {
        return b;
    }
    if (D_800DE968 != 0) {
        return a;
    }
    if (D_800DE9A8 != 2) {
        return 2;
    }
    res = 0;
    if (a != 0 || b != 0) {
        res = 1;
    }
    return res;
}
