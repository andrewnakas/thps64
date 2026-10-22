#include "common.h"

s32 func_800847E8(void *, s32);                                /* extern */
s32 func_800849FC(void *, s32);                     /* extern */
void func_80084A14(void *, s32, s32);                     /* extern */
s32 func_8009B7D8(void *, void *, s32, s32);               /* extern */
s32 func_8009B898(void *, s32, s32);                  /* extern */
void func_8009ECF8(void *, s32);                          /* extern */
extern s32 D_800EA110[];

s32 func_8008486C(void *arg0, s32 arg1) {
    s32 sp10[2];
    s32 temp_s0;
    s32 temp_a2;
    s32 temp_v0_3;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 var_v0;

    temp_v0 = func_800847E8(arg0, arg1);
    temp_v0_2 = func_8009B898(arg0, temp_v0, 4);
    if ((temp_v0_2 == 0) || (func_80084A14(sp10, temp_v0_2, (temp_v0_3 = func_800849FC(arg0, temp_v0), temp_a2 = *(s32 *) ((u8 *) arg0 + 4), temp_a2 += temp_v0_3)), temp_s0 = func_8009B7D8(arg0, sp10, 2, 8), func_8009ECF8(&D_800EA110, temp_v0_2), var_v0 = temp_s0, (var_v0 == 0))) {
        var_v0 = 0;
    }
    return var_v0;
}
