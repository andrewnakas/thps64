#include "common.h"

void func_80043FB0(s8 *arg0) {
    s32 var_a1;
    s8 *var_a0;
    void *var_v1;

    var_a0 = arg0;
    var_a1 = 0;
    var_v1 = var_a0 + 0xC;
    do {
        *var_a0 = 0;
        (*(s8 *)((u8 *)(var_v1) + -0xB)) = 0;
        (*(s32 *)((u8 *)(var_v1) + -8)) = 0;
        (*(s32 *)((u8 *)(var_v1) + -4)) = 0;
        (*(s32 *)((u8 *)(var_v1) + 0)) = 0;
        var_v1 += 0x10;
        var_a1 += 1;
        var_a0 += 0x10;
    } while (var_a1 < 0x14);
}
