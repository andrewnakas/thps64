#include "common.h"

f32 func_800018C0(f32);
f32 func_80001CA0(f32);

s32 *func_800677F8(s32 *arg0, s16 arg1) {
    s32 a;
    s32 x;
    s32 y;
    s32 b;
    s32 c;
    s32 s;

    a = arg1 >> 1;
    b = a;
    if (a == 0) {
        c = 0x1000;
    } else {
        b = a - (b / 4096) * 4096;
        c = func_800018C0(b * 0.000244140625f * 6.283185) * 4096.0f;
    }
    x = arg1 >> 1;
    y = x;
    if (x == 0) {
        s = 0;
    } else {
        y = x - (y / 4096) * 4096;
        s = func_80001CA0(y * 0.000244140625f * 6.283185) * 4096.0f;
    }
    arg0[0] = 0;
    arg0[1] = s;
    arg0[2] = 0;
    arg0[3] = c;
    return arg0;
}
