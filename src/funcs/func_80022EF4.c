#include "common.h"

s32 func_80022EF4(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 a;
    f32 b;
    f32 f;

    a = (f32) arg0;
    a *= (f32) arg1 * 5.9604645e-08f;
    b = (f32) arg2;
    b *= (f32) arg3 * 5.9604645e-08f;
    f = a + b;
    if (f < 0.0f) {
        return -1;
    }
    if (f > 0.0f) {
        return 1;
    }
    return 0;
}
