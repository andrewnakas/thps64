#include "common.h"

s32 func_800B4240(s32, s32);
extern u8 D_800D0FC0[];
extern f32 D_800F5668;

s32 func_800245A4(u8 *arg0) {
    f32 temp_f0;
    s32 var_s0;
    s32 var_s2;
    u8 *p;

    var_s2 = 0;
    p = D_800D0FC0;
    if (func_800B4240(p[2], 0x2000) != 0) {
        var_s2 = func_800B4240(p[2], 0x1000) != 0;
    }
    var_s0 = 0;
    if (func_800B4240(p[3], 0x2000) != 0) {
        var_s0 = func_800B4240(p[3], 0x1000) != 0;
    }
    if ((var_s2 == 0) && (var_s0 == 0)) {
        *(f32 *)(arg0 + 0x1E8) = 0.0f;
    } else {
        temp_f0 = *(f32 *)(arg0 + 0x1E8) + D_800F5668;
        *(f32 *)(arg0 + 0x1E8) = temp_f0;
        if (temp_f0 > 3.0) {
            return 1;
        }
    }
    return 0;
}
