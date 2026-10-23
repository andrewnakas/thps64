/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

void func_8003925C(void *);
void func_8009B5B0(void *, s32);
void func_8009B620(void *, s32, s32, s32, s32);
void func_800A4568(void *, f32, f32, f32, f32);
void *func_800BAB04(void *, s32);
extern s32 D_800D36F8;
extern s32 D_800D3C28;
extern s32 D_800EECF0;
extern s32 D_800F65E0;
extern s32 D_800FA350;
extern f32 D_800FA590;

void func_800352D4(void) {
    s32 *p;

    p = &D_800D36F8;
    func_8009B5B0(p, 0x4CE);
    func_8009B620(p, 0x80, 0x80, 0x80, 0x3C);
    if (D_800D3C28 == 0) {
        D_800D3C28 = *(s32 *)((u8 *)func_800BAB04(&D_800EECF0, 0x4C9) + 4);
    }
    func_8003925C(&D_800FA350);
    D_800FA590 = 0.0f;
    {
        s32 *q = &D_800F65E0;
        f32 z = D_800FA590;
        func_800A4568(q, z, 320.0f, z, 240.0f);
    }
}
