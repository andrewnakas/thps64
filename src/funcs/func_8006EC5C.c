#include "common.h"

void func_8006EC5C(u16 *arg0) {
    s32 var_v1;
    u16 *var_a0;

    var_a0 = arg0;
    var_v1 = 0;
    do {
        *var_a0 -= 1;
        var_v1 += 1;
        var_a0 += 1;
    } while (var_v1 < 0x20);
}
