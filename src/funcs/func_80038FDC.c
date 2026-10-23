#include "common.h"

void func_80038FDC(void *arg0, f32 arg1, f32 arg2, s32 *arg3, s32 *arg4) {
    f32 temp_f2;
    f32 temp_f2_2;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_v1;
    s32 temp_v1_2;
    f32 zero;

    temp_f2 = (*(f32 *)((u8 *)(arg0) + 0x44));
    zero = 0.0f;
    if (temp_f2 != zero) {
        *arg3 = (s32) ((arg1 - (*(f32 *)((u8 *)(arg0) + 0x34))) / temp_f2);
    }
    temp_f2_2 = (*(f32 *)((u8 *)(arg0) + 0x48));
    if (temp_f2_2 != zero) {
        *arg4 = (s32) ((arg2 - (*(f32 *)((u8 *)(arg0) + 0x3C))) / temp_f2_2);
    }
    temp_a1 = *arg3;
    temp_v1 = (*(s32 *)((u8 *)(arg0) + 0x4C));
    if (temp_a1 >= temp_v1) {
        *arg3 = temp_v1 - 1;
    } else if (temp_a1 < 0) {
        *arg3 = 0;
    }
    temp_v1_2 = *arg4;
    temp_a0 = (*(s32 *)((u8 *)(arg0) + 0x50));
    if (temp_v1_2 >= temp_a0) {
        *arg4 = temp_a0 - 1;
        return;
    }
    if (temp_v1_2 < 0) {
        *arg4 = 0;
    }
}
