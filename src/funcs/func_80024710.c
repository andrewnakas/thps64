/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

void func_800A602C(void *);
void func_800A773C(void *, f32, f32);
void func_800A8678(void *, char *, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);
void func_800BE3D8(void);
void func_800BE5A4(void);
void func_800BE7D0(s32, s32, s32, s32, s32, s32, s32, s32);
extern char D_80016F60[];
extern char D_80016F7C[];
extern char D_80016F94[];
extern char D_80016FB0[];
extern char D_80016FD0[];
extern char D_80016FF0[];
extern u8 D_800D0FE9;
extern s32 D_800F3294;
extern s32 D_800F3298;

s32 func_80024710(u8 *arg0) {
    func_800BE3D8();
    func_800A602C(arg0 + 8);
    func_800BE7D0(0, D_800F3294 - 1, 0, D_800F3298 - 1, 0, 0, 0, 0xFF);
    if (D_800D0FE9 != 0) {
        func_800A8678(arg0 + 0x30, D_80016F60, 160.0f, 130.0f, 2, 2, 1.0f, 0, 0, 1, 1, 0, 0, 0);
        func_800A8678(arg0 + 0x30, D_80016F7C, 160.0f, 105.0f, 2, 2, 1.0f, 0, 0, 1, 1, 0, 0, 0);
    } else {
        func_800A773C(arg0 + 0x30, 0.75f, 0.75f);
        func_800A8678(arg0 + 0x30, D_80016F94, 160.0f, 170.0f, 2, 2, 1.0f, 0, 0, 1, 1, 0, 0, 0);
        func_800A8678(arg0 + 0x30, D_80016FB0, 160.0f, 150.0f, 2, 2, 1.0f, 0, 0, 1, 1, 0, 0, 0);
        func_800A8678(arg0 + 0x30, D_80016FD0, 160.0f, 130.0f, 2, 2, 1.0f, 0, 0, 1, 1, 0, 0, 0);
        func_800A8678(arg0 + 0x30, D_80016FF0, 160.0f, 110.0f, 2, 2, 1.0f, 0, 0, 1, 1, 0, 0, 0);
    }
    func_800BE5A4();
    return 0;
}
