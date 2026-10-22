#include "common.h"

s32 func_800394A8(void *, s32);             /* extern */
s32 func_800A735C(void *, s32);             /* extern */
s32 func_800B19C0(void *, s32);             /* extern */
extern s32 D_80017368;
extern u8 D_800D0FC0[];
extern f32 D_800DC3F8[];
extern u8 D_800DE9F4[];

void func_80029024(void *arg0, s32 arg1) {
    u8 *a;
    u8 *b;

    (*(void **)((u8 *)(arg0) + 0x2C)) = &D_80017368;
    a = D_800DE9F4;
    b = D_800D0FC0;
    *(f32 *)(a + 0x870) = *(f32 *)(b + 0x2C);
    D_800DC3F8[0] = *(f32 *)(b + 0x2C);
    *(f32 *)(a + 0x874) = *(f32 *)(b + 0x30);
    D_800DC3F8[1] = *(f32 *)(b + 0x30);
    func_800B19C0(arg0 + 0x2DC, 2);
    func_800B19C0(arg0 + 0x2C8, 2);
    func_800B19C0(arg0 + 0x2B4, 2);
    func_800B19C0(arg0 + 0x2A0, 2);
    func_800B19C0(arg0 + 0x28C, 2);
    func_800A735C(arg0 + 0x4C, 2);
    func_800394A8(arg0, arg1);
}
