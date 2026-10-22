#include "common.h"

void func_80039E60(s32, s32, s32);   /* extern */

void func_80088B88(void *arg0, s32 arg1) {
    register s32 temp_a0 __asm__("$4");
    register s32 temp_v1 __asm__("$3");
    register s32 range_value __asm__("$2");
    void *temp_v1_2;
    void *temp_v1_3;

    temp_a0 = *(u8 *) ((u8 *) arg0 + 0x4F0);
    temp_v1 = *(s8 *) ((u8 *) arg0 + 0x4F0);
    __asm__("" : "+r" (temp_a0), "+r" (temp_v1));
    if (temp_v1 == 4) {
        (*(s32 *) ((u8 *) (arg0) + 0x550)) = (s32) ((*(s32 *) ((u8 *) (arg0) + 0x550)) == 0);
        goto block_4;
    }
    if (temp_v1 == 5) {
        (*(s32 *) ((u8 *) (arg0) + 0x554)) = (s32) ((*(s32 *) ((u8 *) (arg0) + 0x554)) == 0);
block_4:
        func_80039E60(0x91, 0x2710, 0);
        return;
    }
    range_value = temp_a0 - 6;
    __asm__("" : "+r" (range_value));
    temp_v1_2 = arg0 + temp_v1;
    if ((u32) (range_value & 0xFF) >= 2U) {
        (*(u8 *) ((u8 *) (temp_v1_2) + 0x535)) = (u8) ((*(u8 *) ((u8 *) (temp_v1_2) + 0x535)) + arg1);
        func_80039E60(0x91, 0x2710, 0);
        temp_v1_3 = arg0 + (s8) (*(u8 *) ((u8 *) (arg0) + 0x4F0));
        temp_a0 = (*(s8 *) ((u8 *) (temp_v1_3) + 0x535));
        if (temp_a0 >= 4) {
            (*(s8 *) ((u8 *) (temp_v1_3) + 0x535)) = 0;
            return;
        }
        if (temp_a0 < 0) {
            (*(s8 *) ((u8 *) (temp_v1_3) + 0x535)) = 3;
        }
    }
}
