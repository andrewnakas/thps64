#include "common.h"

s32 func_800B43F0(s32);
s32 func_800B4480(s32);
extern f32 D_800D0FF4;

s32 func_8003C648(s32 arg0, s32 arg1) {
    s32 ret;
    if (func_800B43F0(arg1) != 0) {
        D_800D0FF4 = 25.0f;
        ret = -1;
    } else if (func_800B4480(arg1) == 0) {
        ret = 0;
    } else {
        D_800D0FF4 = 25.0f;
        ret = 1;
    }
    return ret;
}
