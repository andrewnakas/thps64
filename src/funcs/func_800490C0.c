#include "common.h"

f32 func_80001CA0(f32);

void func_800490C0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 s;
    s32 x;

    x = arg3;
    if (arg3 == 0) {
        s = 0;
    } else {
        arg3 = x - arg3 / 4096 * 4096;
        s = func_80001CA0((f32)(arg3 * 0.000244140625f * 6.283185)) * 4096.0f;
    }
    *arg0 = arg2 + (arg1 - arg2) * s / 4096 * s / 4096;
}
