#include "common.h"

extern void func_800A735C(void *, s32);
extern void func_800392A0(void *, s32);
extern void func_800394A8(void *, s32);
extern s32 D_800171C8;

void func_8002652C(u8 *arg0, s32 arg1) {
    *(void **)(arg0 + 0x2C) = &D_800171C8;
    func_800A735C(arg0 + 0x8C, 2);
    func_800392A0(arg0 + 0x34, 2);
    func_800394A8(arg0, arg1);
}
