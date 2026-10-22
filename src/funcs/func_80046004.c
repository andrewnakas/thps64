#include "common.h"

s32 func_80046004(void *arg0) {
    s32 temp_a2;
    s32 var_a1;
    s32 var_v1;
    void *var_a0;

    var_a0 = arg0;
    var_v1 = 0;
    temp_a2 = (*(s32 *)((u8 *)(var_a0) + 0x388));
    var_a1 = 0;
    if (temp_a2 > 0) {
        do {
            var_a1 += (*(s32 *)((u8 *)(var_a0) + 0x1FC));
            var_v1 += 1;
            var_a0 += 0x14;
        } while (var_v1 < temp_a2);
    }
    return var_a1;
}
