#include "common.h"

void func_800394A8(void *, s32);
void func_8003E1C8(void);
void func_800A735C(void *, s32);
void func_800A9460(void *, s32, f32, s32);
void func_800B19C0(void *, s32);
extern u8 D_8001A090[];
extern s32 D_800D0FCC;
extern u8 D_800EA9C0[];

void func_8003BD38(u8 *arg0, s32 arg1) {
    *(void **) (arg0 + 0x2C) = D_8001A090;
    func_800A9460(D_800EA9C0, 0, 0.0f, -1);
    func_8003E1C8();
    D_800D0FCC = 0;
    func_800A735C(arg0 + 0x44, 2);
    func_800B19C0(arg0 + 0x30, 2);
    func_800394A8(arg0, arg1);
}
