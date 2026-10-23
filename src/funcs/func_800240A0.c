/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

s32 func_8009CC10(void *, f32);                 /* extern */
s32 func_8009D1BC(void *, f32);                 /* extern */
s32 func_8009D624(void *, s32);                 /* extern */
f32 func_800B4200(s32, s32);                /* extern */
s32 func_800B4240(s32, s32);                /* extern */
s32 func_800B4264(s32, s32);            /* extern */
extern f32 D_800D2750;
extern f32 D_800D2754;
extern s32 D_800D2758;
extern f32 D_800F5668;

void func_800240A0(void *arg0) {
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f22;
    f32 temp_f22_2;
    f32 temp_f24;
    f32 var_f26;
    f32 var_f28;
    f32 var_f30;
    s32 temp_v0;

    temp_f20 = 5.0f;
    temp_f22 = 60.0f;
    D_800D2750 += -D_800F5668 * func_800B4200(0, 0x78);
    D_800D2754 += -D_800F5668 * func_800B4200(0, 0x79);
    temp_v0 = func_800B4240(0, 0xFFFF);
    var_f26 = 0.0f;
    var_f28 = 0.0f;
    var_f30 = 0.0f;
    if (temp_v0 & 0x4000) {
        var_f30 = D_800F5668 * -temp_f20;
    }
    if (temp_v0 & 0x8000) {
        var_f30 = D_800F5668 * temp_f20;
    }
    if (temp_v0 & 8) {
        var_f26 = D_800F5668 * temp_f20;
    }
    if (temp_v0 & 4) {
        var_f26 = D_800F5668 * -temp_f20;
    }
    if (temp_v0 & 2) {
        var_f28 = D_800F5668 * -temp_f20;
    }
    if (temp_v0 & 1) {
        var_f28 = D_800F5668 * temp_f20;
    }
    if (temp_v0 & 0x2000) {
        var_f28 *= temp_f22;
        var_f26 *= temp_f22;
        var_f30 *= temp_f22;
    }
    temp_f20_2 = (*(f32 *)((u8 *)(arg0) + 0x30));
    temp_f22_2 = (*(f32 *)((u8 *)(arg0) + 0x34));
    temp_f24 = (*(f32 *)((u8 *)(arg0) + 0x38));
    func_8009CC10(arg0, D_800D2750);
    func_8009D1BC(arg0, D_800D2754);
    func_8009D624(arg0, D_800D2758);
    (*(f32 *)((u8 *)(arg0) + 0x30)) = (f32) (temp_f20_2 + (var_f28 * (*(f32 *)((u8 *)(arg0) + 0))) + (var_f26 * (*(f32 *)((u8 *)(arg0) + 0x10))) + (var_f30 * (*(f32 *)((u8 *)(arg0) + 0x20))));
    (*(f32 *)((u8 *)(arg0) + 0x34)) = (f32) (temp_f22_2 + (var_f28 * (*(f32 *)((u8 *)(arg0) + 4))) + (var_f26 * (*(f32 *)((u8 *)(arg0) + 0x14))) + (var_f30 * (*(f32 *)((u8 *)(arg0) + 0x24))));
    (*(f32 *)((u8 *)(arg0) + 0x38)) = (f32) (temp_f24 + (var_f28 * (*(f32 *)((u8 *)(arg0) + 8))) + (var_f26 * (*(f32 *)((u8 *)(arg0) + 0x18))) + (var_f30 * (*(f32 *)((u8 *)(arg0) + 0x28))));
    func_800B4264(0, 0x800);
}
