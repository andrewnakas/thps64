#include "common.h"

void func_80087B8C(void *arg0) {
    register s32 var_v0 __asm__("$2");
    register s32 var_v1 __asm__("$3");
    register s32 one __asm__("$5");
    register s32 temp_v1 __asm__("$3") = *(s8 *) ((u8 *) arg0 + 0x4F0);

    __asm__("" : "+r" (temp_v1));
    if (temp_v1 == 0) {
        *(s16 *) ((u8 *) arg0 + 0x52C) = 0x159;
        *(s16 *) ((u8 *) arg0 + 0x52E) = 0x44;
        *(s16 *) ((u8 *) arg0 + 0x530) = 0x23C;
        *(s16 *) ((u8 *) arg0 + 0x532) = 0x44;
        *(s32 *) ((u8 *) arg0 + 0x524) = 1;
        return;
    }
    one = 1;
    __asm__("" : "+r" (one));
    if (temp_v1 == one) {
        *(s16 *) ((u8 *) arg0 + 0x52C) = 0x6F;
        var_v1 = 0x65;
        *(s16 *) ((u8 *) arg0 + 0x52E) = var_v1;
        var_v0 = 0x14D;
        goto block_23;
    }
    if (temp_v1 == 2) {
        *(s16 *) ((u8 *) arg0 + 0x52C) = 0x160;
        var_v1 = 0xD3;
        *(s16 *) ((u8 *) arg0 + 0x52E) = var_v1;
        var_v0 = 0x244;
        goto block_23;
    }
    if (temp_v1 == 3) {
        *(s16 *) ((u8 *) arg0 + 0x52C) = 0x89;
        var_v1 = 0xF3;
        *(s16 *) ((u8 *) arg0 + 0x52E) = var_v1;
        var_v0 = 0x16E;
        goto block_23;
    }
    if (temp_v1 == 4) {
        *(s16 *) ((u8 *) arg0 + 0x52C) = 0xB8;
        var_v1 = 0x127;
        goto block_22;
    }
    if (temp_v1 == 5) {
        *(s16 *) ((u8 *) arg0 + 0x52C) = 0xC8;
        var_v1 = 0x148;
        goto block_22;
    }
    if (temp_v1 == 6) {
        *(s16 *) ((u8 *) arg0 + 0x52C) = 0xA0;
        var_v1 = 0x164;
        goto block_22;
    }
    if (temp_v1 != 7) {
        return;
    }
    *(s16 *) ((u8 *) arg0 + 0x52C) = 0xA3;
    var_v1 = 0x184;
block_22:
    *(s16 *) ((u8 *) arg0 + 0x52E) = var_v1;
    var_v0 = 0x1E8;
block_23:
    __asm__("" : "+r" (var_v0), "+r" (var_v1));
    *(s16 *) ((u8 *) arg0 + 0x530) = var_v0;
    *(s16 *) ((u8 *) arg0 + 0x532) = var_v1;
    *(s32 *) ((u8 *) arg0 + 0x524) = one;
}
