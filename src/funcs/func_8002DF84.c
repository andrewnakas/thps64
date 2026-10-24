/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0x38];
    u16 w;
    u16 h;
} Img_8002DF84;

typedef struct {
    u8 pad0[4];
    Img_8002DF84 *img;
} Spr_8002DF84;

typedef struct {
    u8 pad0[0x58];
    u8 b58[0x14];
    u8 b6C[0x14];
    u8 b80[0x14];
    u8 b94[0x14];
    u8 bA8[0x14];
    u8 bBC[0x14];
    u8 bD0[0x14];
    u8 bE4[0x14];
    u8 bF8[0x5C0 - 0xF8];
    s32 row;
    u8 pad5C4[0x5D8 - 0x5C4];
    s16 keys[1][10];
} Ctx_8002DF84;

#define CTX_SPR(o) (*(Spr_8002DF84 **)((u8 *)c + (o)))

typedef struct {
    u32 w0;
    u32 w1;
} Gfx_8002DF84;

void func_800B1AC4(void *, f32, f32, f32, f32);
void func_800B8414(Img_8002DF84 *, f32, f32, f32, f32, s32, f32, s32, f32);
void func_800B9DE0(Img_8002DF84 *);
extern s32 D_800D36A0;
extern s32 D_800F3298;
extern f32 D_800F329C;
extern Gfx_8002DF84 *D_800F36A4;

#define ICON(b) func_800B1AC4(b, x, y, 1.0f, 1.0f)

#define SPR(o) \
    { \
        Gfx_8002DF84 *g; \
        Gfx_8002DF84 *h; \
        Img_8002DF84 *im = CTX_SPR(o)->img; \
 \
        h = D_800F36A4; \
        g = h++; \
        D_800F36A4 = h; \
        g->w0 = 0xE7000000; \
        g->w1 = 0; \
        D_800F36A4 = h + 1; \
        h[0].w0 = 0xE3000A01; \
        h[0].w1 = 0x100000; \
        func_800B9DE0(im); \
        h = D_800F36A4++; \
        h->w0 = 0xFCFFFFFF; \
        h->w1 = 0xFFFCF238; \
    } \
    { \
        Spr_8002DF84 *s = CTX_SPR(o); \
        s32 t = x + D_800D36A0; \
        func_800B8414(s->img, t * D_800F329C, (t + s->img->w) * D_800F329C, \
                      D_800F3298 - (y + s->img->h), D_800F3298 - y, 0, 1.0f, 0, 1.0f); \
    }

void func_8002DF84(Ctx_8002DF84 *c) {
    s32 i;
    s32 w;
    s32 x;
    s32 y;

    w = 0;
    for (i = 0; c->keys[c->row][i] != -10; i++) {
        w += 0x23;
    }
    x = 0x14A - w / 2;
    y = 0x17C;
    i = 0;
    while (1) {
        if (c->keys[c->row][i] == -10) {
            break;
        }
        switch (c->keys[c->row][i]) {
        case 0x800:
            ICON(c->b58);
            break;
        case 0x200:
            ICON(c->b80);
            break;
        case 0x100:
            ICON(c->b94);
            break;
        case 0x400:
            ICON(c->b6C);
            break;
        case 8:
            SPR(0x838)
            break;
        case 2:
            SPR(0x840)
            break;
        case 1:
            SPR(0x844)
            break;
        case 4:
            SPR(0x83C)
            break;
        case -0x2D:
            func_800B1AC4(c->bF8, x, y, 1.5f, 1.5f);
            break;
        case 0xA00:
            ICON(c->bBC);
            break;
        case 0x900:
            ICON(c->bA8);
            break;
        case 0x600:
            ICON(c->bE4);
            break;
        case 0x500:
            ICON(c->bD0);
            break;
        }
        x += 0x23;
        i++;
    }
}
