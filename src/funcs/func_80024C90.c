#include "common.h"

extern u8 D_80017048[];
void func_800A68A0(void *);
void func_8009CAD0(f32 (*)[4]);
void func_800A69C0(void *, s32);
void func_800A6D38(void *, s32, f32 (*)[4]);
void func_80024B98(void *, s32, s32, s32);
void func_80024B88(void *, s32, s32, s32);

u8 *func_80024C90(u8 *arg0) {
    f32 m[4][4];

    *(u8 **)(arg0 + 0x94) = D_80017048;
    func_800A68A0(arg0);
    func_8009CAD0(m);
    func_800A69C0(arg0, 0x58);
    func_800A6D38(arg0, 0, m);
    *(s32 *)(arg0 + 0x88) = 0;
    func_80024B98(arg0, 0xFF, 0xC8, 0);
    func_80024B88(arg0, 0xFF, 0, 0);
    return arg0;
}
