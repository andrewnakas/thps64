#include "common.h"

s32 func_80039E60(s32, s32, s32);
s32 func_800B4510(s32);
s32 func_800B45A0(s32);
extern f32 D_800D0FF4;

s32 func_8003C5BC(s32 arg0, s32 arg1) {
    if (func_800B4510(arg1) != 0) {
        D_800D0FF4 = 25.0f;
        func_80039E60(0x90, 0x2710, 0);
        return -1;
    }
    if (func_800B45A0(arg1) != 0) {
        D_800D0FF4 = 25.0f;
        func_80039E60(0x90, 0x2710, 0);
        return 1;
    }
    return 0;
}
