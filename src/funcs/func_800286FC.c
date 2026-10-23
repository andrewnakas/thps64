#include "common.h"

extern f32 D_800F5668;

void func_800286FC(void *arg0) {
    f32 temp_f0;
    f64 temp_f0_2;
    s16 var_v0;
    s16 var_v1;
    s32 temp_v1;

    temp_f0 = (*(f32 *)((u8 *)(arg0) + 0x2F0)) + D_800F5668;
    (*(f32 *)((u8 *)(arg0) + 0x2F0)) = temp_f0;
    temp_f0_2 = (f64) temp_f0;
    if (0.5 < temp_f0_2) {
        (*(f32 *)((u8 *)(arg0) + 0x2F0)) = (f32) (temp_f0_2 - 0.5);
        (*(s32 *)((u8 *)(arg0) + 0x2F4)) = (s32) ((*(s32 *)((u8 *)(arg0) + 0x2F4)) == 0);
    }
    temp_v1 = (*(u16 *)((u8 *)(arg0) + 0x48));
    if (temp_v1 == 0x65) {
        (*(s16 *)((u8 *)(arg0) + 0x2FC)) = 0xCD;
        var_v1 = 0xDA;
        (*(s16 *)((u8 *)(arg0) + 0x2FE)) = var_v1;
        var_v0 = 0x1DB;
    } else if (temp_v1 == 0x66) {
        (*(s16 *)((u8 *)(arg0) + 0x2FC)) = 0xB5;
        var_v1 = 0x12B;
        (*(s16 *)((u8 *)(arg0) + 0x2FE)) = var_v1;
        var_v0 = 0x1F0;
    } else if (temp_v1 == 0x67) {
        (*(s16 *)((u8 *)(arg0) + 0x2FC)) = 0x98;
        var_v1 = 0x14E;
        (*(s16 *)((u8 *)(arg0) + 0x2FE)) = var_v1;
        var_v0 = 0x20B;
    } else {
        return;
    }
    (*(s16 *)((u8 *)(arg0) + 0x300)) = var_v0;
    (*(s16 *)((u8 *)(arg0) + 0x302)) = var_v1;
    (*(s32 *)((u8 *)(arg0) + 0x2F8)) = 1;
}
