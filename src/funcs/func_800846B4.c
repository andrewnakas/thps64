#include "common.h"

typedef struct { s32 x, y, z; } V3_846B4;
typedef struct { u8 pad0[4]; u16 *p; } A2_846B4;
typedef struct {
    f32 f0;
    V3_846B4 v4;
    u8 pad10[0xC];
    u16 h1C;
    A2_846B4 *p20;
    s32 w24;
    u8 pad28[8];
    s32 w30;
    u8 pad34[4];
} E_846B4;

extern u8 D_800FC0C0;
extern E_846B4 D_800FBD40[];

void func_800846B4(f32 f, V3_846B4 *v, A2_846B4 *a2, u16 *a3) {
    u32 n = D_800FC0C0;
    s32 i = n & 0xFF;
    E_846B4 *base = D_800FBD40;
    E_846B4 *e;

    D_800FC0C0 = n + 1;
    e = &base[i];
    e->f0 = f;
    e->v4 = *v;
    e->p20 = a2;
    e->h1C = *a2->p;
    e->w30 = a3[0] << 16;
    e->w24 = a3[1];
}
