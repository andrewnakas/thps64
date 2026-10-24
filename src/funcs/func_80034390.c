/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx80034390;

typedef struct {
    u8 pad0[0x18];
    s16 delta;
    s16 pad1A;
    void (*fn)(void *, void *);
} VEnt80034390;

typedef struct {
    VEnt80034390 *vt;
} VObj80034390;

void func_800340A0(void *);
void func_800382A4(void *, void *, s32);
void func_8009B32C(void *);
void func_80033E70(void *, s32);
extern Gfx80034390 *D_800F36A4;
extern s32 D_800DE9A8;
extern f32 D_800D36D8;
extern u8 D_800D36DC[];
extern s32 D_800F5628;
extern u8 D_800FA350[];
extern s32 D_800D36F4;
extern VObj80034390 *D_800FA550[];
extern u8 D_800D36F8[];

void func_80034390(void *arg0, s32 arg1) {
    Gfx80034390 *h;
    s32 fog;
    s32 save;
    s32 i;

    {
        Gfx80034390 *_g = (Gfx80034390 *)(D_800F36A4++);
        _g->w0 = 0xDB040004;
        _g->w1 = 1;
    }
    h = D_800F36A4;
    D_800F36A4 = h + 1;
    h[0].w0 = 0xDB04000C;
    h[0].w1 = 1;
    D_800F36A4 = h + 2;
    h[1].w0 = 0xDB040014;
    h[1].w1 = 0xFFFF;
    D_800F36A4 = h + 3;
    h[2].w0 = 0xDB04001C;
    h[2].w1 = 0xFFFF;
    func_800340A0(arg0);
    if (D_800DE9A8 == 1) {
        {
            Gfx80034390 *_g = (Gfx80034390 *)(D_800F36A4++);
            _g->w0 = 0xDB040004;
            _g->w1 = 2;
        }
        h = D_800F36A4;
        D_800F36A4 = h + 1;
        h[0].w0 = 0xDB04000C;
        h[0].w1 = 2;
        D_800F36A4 = h + 2;
        h[1].w0 = 0xDB040014;
        h[1].w1 = 0xFFFE;
        D_800F36A4 = h + 3;
        h[2].w0 = 0xDB04001C;
        h[2].w1 = 0xFFFE;
    }
    fog = 1;
    if (!(D_800D36D8 < 0.999f)) {
        fog = 0;
    }
    save = D_800F5628;
    D_800F5628 = save & ~0x40000;
    if (fog) {
        D_800F5628 |= 0x20000;
        {
            Gfx80034390 *_g = (Gfx80034390 *)(D_800F36A4++);
            _g->w0 = 0xDB080000;
            _g->w1 = 0x7D008400;
        }
        {
            Gfx80034390 *_g = (Gfx80034390 *)(D_800F36A4++);
            _g->w0 = 0xF8000000;
            _g->w1 = (D_800D36DC[0] << 24) | (D_800D36DC[1] << 16) | (D_800D36DC[2] << 8) | 0xFF;
        }
    } else {
        D_800F5628 &= ~0x20000;
    }
    func_800382A4(D_800FA350, arg0, arg1);
    for (i = 0; i < D_800D36F4; i++) {
        D_800FA550[i]->vt->fn((u8 *)D_800FA550[i] + D_800FA550[i]->vt->delta, arg0);
    }
    func_8009B32C(D_800D36F8);
    func_80033E70(arg0, arg1);
    D_800F5628 = save;
}
