#include "common.h"

s32 func_800635D8();                                /* extern */
extern void *D_800DC5E0;

s32 func_8006A16C(void) {
    s32 temp_a0;
    s32 var_v0;
    void *var_v1;

    temp_a0 = func_800635D8();
    var_v1 = D_800DC5E0;
    if (var_v1 != NULL) {
loop_1:
        if ((*(s32 *)((u8 *)(var_v1) + 0)) != temp_a0) {
            var_v1 = (*(void **)((u8 *)(var_v1) + 0xC));
            if (var_v1 != NULL) {
                goto loop_1;
            }
        }
    }
    var_v0 = 1;
    if (var_v1 != NULL) {
        var_v0 = 2;
    }
    return var_v0;
}
