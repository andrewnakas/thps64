#include "common.h"

s32 func_800242CC();                            /* extern */
s32 func_80039500();                            /* extern */
s32 func_800A72C0(void *);                      /* extern */
s32 func_800A73EC(void *, s32);             /* extern */
s32 func_800A773C(void *, f32, f32);
s32 func_800A7B28(void *, s32, s32, s32, s32); /* extern */
s32 func_800B198C(void *);                      /* extern */
s32 func_800B1A80(void *, s32);             /* extern */
extern s32 D_80019270;
extern s32 D_800F3294;
extern s32 D_800F3298;

void *func_80029EC0(void *arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_s0;
    void *temp_s0;
    void *var_s1;

    func_80039500();
    (*(void **)((u8 *)(arg0) + 0x2C)) = &D_80019270;
    func_800B198C(arg0 + 0x30);
    func_800B198C(arg0 + 0x44);
    var_s1 = arg0 + 0x58;
    var_s0 = 1;
    do {
        func_800B198C(var_s1);
        var_s0 -= 1;
        var_s1 += 0x14;
    } while (var_s0 != -1);
    temp_s0 = arg0 + 0x80;
    func_800A72C0(temp_s0);
    func_800242CC();
    func_800A73EC(temp_s0, 0x501);
    (*(s8 *)((u8 *)(arg0) + 0x90)) = 0;
    func_800A7B28(temp_s0, 0xF0, 0xF0, 0xF0, 0xFF);
    func_800A773C(temp_s0, 0.7f, 1.2f);
    func_800B1A80(arg0 + 0x30, 0xD0);
    func_800B1A80(arg0 + 0x44, 0xD1);
    func_800B1A80(arg0 + 0x58, 0xE2);
    func_800B1A80(arg0 + 0x6C, 0xE3);
    (*(s32 *)((u8 *)(arg0) + 0x2F0)) = (s32) (((s32) D_800F3294 / 2) - 0x100);
    temp_v0 = (s32) D_800F3298 / 2;
    (*(s32 *)((u8 *)(arg0) + 0x2F4)) = (s32) (temp_v0 - 0x44);
    (*(s32 *)((u8 *)(arg0) + 0x2F8)) = (s32) (temp_v0 - 0x67);
    (*(s32 *)((u8 *)(arg0) + 0x2FC)) = (s32) ((s32) (D_800F3298 - 0x120) / 2);
    (*(s32 *)((u8 *)(arg0) + 0x2C0)) = 0;
    (*(s32 *)((u8 *)(arg0) + 0x2D4)) = 1;
    (*(s32 *)((u8 *)(arg0) + 0x2D8)) = 1;
    (*(s32 *)((u8 *)(arg0) + 0x2DC)) = 1;
    (*(s32 *)((u8 *)(arg0) + 0x2C4)) = 0;
    (*(s32 *)((u8 *)(arg0) + 0x2C8)) = 0;
    (*(s32 *)((u8 *)(arg0) + 0x2CC)) = 0;
    (*(s32 *)((u8 *)(arg0) + 0x2D0)) = 0xFF;
    (*(s32 *)((u8 *)(arg0) + 0x2EC)) = 1;
    (*(s32 *)((u8 *)(arg0) + 0x2E4)) = arg1;
    (*(s32 *)((u8 *)(arg0) + 0x2E8)) = -1;
    return arg0;
}
