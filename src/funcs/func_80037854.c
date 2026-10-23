#include "common.h"

extern u8 D_80019E30[];
void func_800392A0(void *, s32);
void func_800A6944(void *, s32);
void func_800A415C(void *, s32);
void func_800394A8(void *, s32);

void func_80037854(u8 *arg0, s32 arg1) {
    *(void **)(arg0 + 0x2C) = D_80019E30;
    func_800392A0(arg0 + 0x798, 2);
    func_800A6944(arg0 + 0x710, 2);
    func_800A415C(arg0 + 0x30, 2);
    func_800394A8(arg0, arg1);
}
