/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    f32 x, y, z;
} Vec3;

typedef struct {
    u8 pad0[0x68];
    s32 hit;
    u8 pad6C[0xA4 - 0x6C];
    Vec3 a;
    Vec3 b;
    u8 padBC[0x100 - 0xBC];
} Ctx2744C;

void func_80024A60(void *, void *);
void func_80026E24(void *, void *, s32);
void func_8005CCD8(Ctx2744C *, s32);
void func_8005DF8C(Ctx2744C *, s32);
void func_80084C5C(void *);
s32 func_800A535C(void *, Vec3 *, f32, s32);
void func_800A5738(void *, s32);
void func_800A57E0(void *, s32);
extern void *D_800D2838;
extern s32 D_800ED018;
extern s32 D_800F5628;

void func_8002744C(u8 *o, void *arg1, s32 mode) {
    Vec3 v;
    Ctx2744C ctx;
    f32 x, y, z;
    f32 x2, y2, z2;
    f32 k, k2;
    s32 saved;
    s32 flag;
    void *prev;

    if (arg1 != o + 0x1B28) {
        k = 0.0625f;
        x = *(f32 *)(o + 0x2238) * k;
        y = *(f32 *)(o + 0x223C) * k;
        z = *(f32 *)(o + 0x2240) * k;
        v.x = x;
        v.y = y;
        v.z = z;
        if (func_800A535C(arg1, &v, 12.5f, 1) == 0) {
            return;
        }
    }
    saved = D_800F5628;
    D_800F5628 = saved & ~0x20000;
    flag = *(s32 *)(o + 0x208) & 2;
    if (flag) {
        D_800ED018 = 1;
    }
    if (mode == 1) {
        if (arg1 != o + 0x1B28) {
            mode = 2;
        } else {
            k2 = 16.0f;
            x2 = *(f32 *)(o + 0x1BB8) * k2;
            y2 = *(f32 *)(o + 0x1BBC) * k2;
            z2 = *(f32 *)(o + 0x1BC0) * k2;
            v.x = x2;
            v.y = y2;
            v.z = z2;
            ctx.a = v;
            ctx.b = *(Vec3 *)(o + 0x2238);
            prev = D_800D2838;
            D_800D2838 = o;
            func_8005CCD8(&ctx, 1);
            func_8005DF8C(&ctx, 0);
            D_800D2838 = prev;
            if (ctx.hit != 0) {
                mode = 2;
            }
        }
    }
    if (mode == 2) {
        func_800A5738(arg1, 1);
    }
    if (mode != 0 && *(s32 *)(o + 0x82C) != 4) {
        func_80026E24(o, arg1, mode);
    }
    func_80084C5C(o + 0xF18);
    if (flag) {
        D_800ED018 = 0;
    }
    D_800F5628 = saved;
    func_80024A60(o + 0x22D0, arg1);
    if (mode == 2) {
        func_800A57E0(arg1, 1);
    }
}
