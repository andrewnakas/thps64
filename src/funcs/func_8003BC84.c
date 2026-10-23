#include "common.h"

void func_800A8678(void *, s32, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);
void func_800B1AC4(void *, f32, f32, f32, f32);
void func_800BE3D8(void);
void func_800BE5A4(void);
void func_800BEF70(s32, s32, s32);
extern s32 D_800DDCB8;

void func_8003BC84(u8 *arg0) {
    func_800BE3D8();
    func_800BEF70(0, 0, 0);
    func_800B1AC4(arg0 + 0x30, 32.0f, 10.0f, 0.925f, 2.0f);
    func_800A8678(arg0 + 0x44, D_800DDCB8, 330.0f, 150.0f, 2, 0, 1.0f, 0x64, 0x64, 1, 0, 0, 0, 0);
    func_800BE5A4();
}
