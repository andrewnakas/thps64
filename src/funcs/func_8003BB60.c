#include "common.h"

void func_80039E60(s32, s32, s32);
void func_800A8678(void *, s32, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);
void func_800B1AC4(void *, f32, f32, f32, f32);
s32 func_800B4264(s32, s32);
void func_800BE3D8(void);
void func_800BE5A4(void);
void func_800BEF70(s32, s32, s32);
extern u8 D_800D0FC0[];
extern s32 D_800DDCB8;

s32 func_8003BB60(u8 *arg0) {
    s32 var_s0;
    s32 var_s2;
    s32 temp_s1;
    s32 temp_s3;

    temp_s1 = D_800D0FC0[2];
    temp_s3 = D_800D0FC0[3];
    var_s2 = 0;
    func_800BE3D8();
    func_800BEF70(0, 0, 0);
    func_800B1AC4(arg0 + 0x30, 32.0f, 10.0f, 0.925f, 2.0f);
    func_800A8678(arg0 + 0x44, D_800DDCB8, 330.0f, 150.0f, 2, 0, 1.0f, 0x64, 0x64, 1, 0, 0, 0, 0);
    var_s0 = 0;
    func_800BE5A4();
    if ((func_800B4264(temp_s1, 0x1000) != 0) || (func_800B4264(temp_s3, 0x1000) != 0)) {
        var_s0 = 1;
    }
    if (var_s0 != 0) {
        func_80039E60(0x91, 0x2710, 0);
        var_s2 = 4;
    }
    return var_s2;
}
