#include "common.h"

s32 func_80070C54(s32 arg0, s32 arg1) {
    s32 var_a1;

    var_a1 = arg1 - arg0;
    if (var_a1 < -0x800) {
        var_a1 += 0x1000;
    }
    if (var_a1 >= 0x800) {
        var_a1 -= 0x1000;
    }
    return var_a1;
}
