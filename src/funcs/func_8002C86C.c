#include "common.h"

extern void func_800B19C0(void *, s32);
extern void func_800394A8(void *, s32);
extern s32 D_80019598;
extern s32 D_800F0CD8;

void func_8002C86C(u8 *arg0, s32 arg1) {
    *(void **)(arg0 + 0x2C) = &D_80019598;
    D_800F0CD8 = 1;
    func_800B19C0(arg0 + 0x30, 2);
    func_800394A8(arg0, arg1);
}
