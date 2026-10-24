#include "common.h"

s32 func_800B5B40(s32, s32);                /* extern */

void func_800B4930(void *arg0, s32 arg1) {
    void *var_s0;

    var_s0 = (*(void **)((u8 *)arg0 + 0x3C));
    if (var_s0 != NULL) {
        do {
            func_800B5B40((*(s32 *)((u8 *)var_s0 + 0x10)), arg1);
            var_s0 = (*(void **)((u8 *)var_s0 + 4));
        } while (var_s0 != NULL);
    }
}
