/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx80033E70;

typedef struct {
    u8 pad0[2];
    s16 unk2;
    u8 pad4[0x2C];
    f32 unk30;
} Model80033E70;

typedef struct {
    u8 pad0[4];
    Model80033E70 *unk4;
    u16 *unk8;
    u8 padC[4];
    u8 unk10[0x20];
    f32 unk30;
    u8 pad34[0x98 - 0x34];
    f32 pos[3];
    u8 unkA4[0xD0 - 0xA4];
    s8 color;
    s8 own;
    u8 hidden;
    u8 padD3[5];
} Ent80033E70;

typedef struct {
    u8 prim[4];
    u8 env[4];
} Color80033E70;

void func_800B4978(void *);
void func_800B4998(void *, s32, s32);
void func_800B9DE0(void *);
s32 func_800A535C(void *, f32 *, f32, s32);
void func_8009BC18(void *, void *);
void func_800A6E74(void *, void *, s32, s32, s32);
extern u8 D_800ECFE0[];
extern void *D_800D3C28;
extern s32 D_800D36EC;
extern Ent80033E70 D_800F78C0[];
extern Color80033E70 D_800D3C10[];
extern Gfx80033E70 *D_800F36A4;
extern s32 D_800F5628;

void func_80033E70(void *arg0, s32 arg1) {
    s32 mask;
    s32 i;
    f32 v[3];
    f32 r;
    Gfx80033E70 *h;
    Ent80033E70 *e;
    Color80033E70 *c;
    s32 col;
    s32 t;

    func_800B4978(D_800ECFE0);
    func_800B9DE0(D_800D3C28);
    mask = 0x40;
    if (arg1 == 0) {
        mask = 1;
    }
    i = 0;
    while (1) {
        if (i >= D_800D36EC) {
            break;
        }
        e = &D_800F78C0[i];
        if (e->hidden != 0) {
            goto next;
        }
        if (*e->unk8 & mask) {
            goto next;
        }
        {
            do {
                v[0] = e->pos[0];
                v[1] = e->pos[1];
                v[2] = e->pos[2];
                if (e->own) {
                    r = e->unk30 * 0.0625f;
                } else {
                    r = e->unk4->unk30 * 0.0625f;
                }
                if (func_800A535C(arg0, v, r, 1) == 0) {
                    goto next;
                }
            } while (0);
            {
                col = e->color;
                if (col >= 0) {
                    {
                        Gfx80033E70 *_g = (Gfx80033E70 *)(D_800F36A4++);
                        _g->w0 = 0xE7000000;
                        _g->w1 = 0;
                    }
                    h = D_800F36A4;
                    D_800F36A4 = h + 1;
                    h[0].w0 = 0xFA000000;
                    c = &D_800D3C10[col];
                    h[0].w1 = (c->prim[0] << 24) | (c->prim[1] << 16)
                        | (c->prim[2] << 8) | c->prim[3];
                    D_800F36A4 = h + 2;
                    h[1].w0 = 0xFB000000;
                    h[1].w1 = (c->env[0] << 24) | (c->env[1] << 16)
                        | (c->env[2] << 8) | c->env[3];
                    func_8009BC18(e->unkA4, arg0);
                }
                if (e->own) {
                    t = -1;
                } else {
                    t = e->unk4->unk2;
                }
                func_800A6E74(e->unk10, arg0, -1, 0, t);
            }
        }
    next:
        i++;
    }
    D_800F5628 |= 0x40000;
    func_800B4998(D_800ECFE0, 1, 1);
}
