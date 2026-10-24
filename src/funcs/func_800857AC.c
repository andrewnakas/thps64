/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx800857AC;

typedef struct {
    f32 a;
    f32 b;
} Pair800857AC;

typedef struct {
    u8 pad0[0x80];
    f32 sx;
    f32 sy;
    s32 idx;
    s32 flag;
    s32 tex;
    s32 v94;
    u8 col[3];
    u8 pad9B;
    Pair800857AC pr[2];
} Item800857AC;

typedef struct {
    s32 pad0;
    s32 unk4;
} Spr800857AC;

typedef struct {
    u16 count;
    u16 sel;
    s32 unk4;
    u8 pad8[0xA0 - 0x8];
    s32 unkA0;
    s32 unkA4;
    s32 unkA8;
    s32 unkAC;
    s32 unkB0;
    s32 unkB4;
    u8 padB8[0xD4 - 0xB8];
    f32 w[8];
    f32 h[8];
    u8 pad114[0x164 - 0x114];
    u8 unk164[0x178 - 0x164];
    Spr800857AC *unk178;
    Spr800857AC *unk17C;
    u8 pad180[0x188 - 0x180];
    u8 sub[7][0x240];
    u8 pad1148[0x144];
    u8 tex[16][0x100];
    u8 pad228C[0x100];
    Item800857AC items[80];
    u8 pad5B4C[0x595C - 0x238C - 80 * 0xAC];
    s32 unk595C;
} Obj800857AC;

void func_800851AC(Obj800857AC *);
void func_80085EDC(Obj800857AC *);
void func_800866D8(Obj800857AC *, Item800857AC *, u8 *, u8 *);
void func_80086984(Obj800857AC *);
void func_80086FBC(Obj800857AC *);
void func_800A773C(void *, f32, f32);
void func_800A7AF8(void *, s32, s32, s32, s32);
void func_800A85C8(void *, f32, f32, char *, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);
void func_800A8678(void *, void *, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, void *, void *);
void func_800B1AC4(void *, f32, f32, f32, f32);
s32 func_800B4264(s32, s32);
void func_800B8414(s32, f32, f32, f32, f32, s32, f32, s32, f32);
void func_800B9DE0(s32);
extern char D_8001ECFC[];
extern u8 D_800D0FE3;
extern s32 D_800DC618;
extern s32 D_800DE7A0;
extern s32 D_800DE804;
extern s32 D_800E9038;
extern s32 D_800F3298;
extern Gfx800857AC *D_800F36A4;
extern s32 D_800F5628;

static inline void clamp800857AC(u8 *c) {
    s32 t = *c * 190 / 100;
    if (t < 256) {
        *c = t;
    } else {
        *c = 255;
    }
}

void func_800857AC(Obj800857AC *arg0, s32 arg1) {
    u8 sp40[0x180];
    u8 col[3];
    u8 *c1;
    u8 *c2;
    s32 i;
    s32 t;
    f32 w;
    f32 h;
    f32 W;
    f32 y;
    f32 s;
    u8 *p1;
    u8 *p2;

    if (arg1 == 0 || D_800DE804 != 0) {
        arg0->count = 0;
        return;
    }
    arg0->unk595C = D_800F5628;
    D_800F5628 &= 0xFFF8FFFF;
    if (arg0->unk4 != 0) {
        func_80086984(arg0);
    } else if (D_800D0FE3 == 4) {
        func_800A7AF8(arg0->sub[2], 200, 150, 0, 255);
        func_800A85C8(arg0->sub[2], 0.75f, 0.75f, D_8001ECFC, 150.0f, 200.0f, 2, 1, 1.0f, 255, 0, 1, 1, 0, 0, 0);
    } else if (arg0->unkB0 != 0) {
        func_80085EDC(arg0);
    } else {
        if (D_800DE7A0 != 7 && D_800DC618 != 2 && D_800E9038 == 0) {
            func_800851AC(arg0);
        }
        i = 0;
        while (1) {
            if (i >= arg0->count) {
                break;
            }
            col[0] = arg0->items[i].col[0];
            col[1] = arg0->items[i].col[1];
            col[2] = arg0->items[i].col[2];
            c1 = &col[1];
            c2 = &col[2];
            clamp800857AC(&col[0]);
            clamp800857AC(c1);
            clamp800857AC(c2);
            w = arg0->w[arg0->items[i].idx];
            h = arg0->h[arg0->items[i].idx];
            func_800B4264(0, 0x2000);
            if (arg0->items[i].sx <= 0.0 || arg0->items[i].sy <= 0.0f) {
                goto next;
            }
            if (arg0->items[i].flag != 0) {
                func_800866D8(arg0, &arg0->items[i], arg0->items[i].col, sp40);
                p1 = sp40;
            } else {
                func_800A7AF8(arg0->sub[arg0->items[i].idx], col[0], col[1], col[2], 255);
                p1 = NULL;
            }
            p2 = NULL;
            if (arg0->items[i].tex != 0) {
                if (arg0->items[i].tex >= 16) {
                    goto next;
                }
                p2 = arg0->tex[arg0->items[i].tex];
                p1 = NULL;
            }
            func_800A773C(arg0->sub[arg0->items[i].idx], w * arg0->items[i].sx, h * arg0->items[i].sy);
            func_800A8678(arg0->sub[arg0->items[i].idx], &arg0->items[i], arg0->items[i].pr[arg0->sel].a, arg0->items[i].pr[arg0->sel].b, arg0->items[i].v94, 2, 1.0f, 255, 100, 1, 1, 0, p1, p2);
        next:
            i++;
        }
        W = 14.0f;
        if (arg0->unkA0 != 0 || arg0->unkA4 != 0 || arg0->unkA8 != 0) {
            s32 tx = arg0->unk178->unk4;
            {
                Gfx800857AC *_g = D_800F36A4++;
                _g->w0 = 0xE7000000;
                _g->w1 = 0;
            }
            {
                Gfx800857AC *_g = D_800F36A4++;
                _g->w0 = 0xE3000A01;
                _g->w1 = 0x100000;
            }
            func_800B9DE0(tx);
            {
                Gfx800857AC *_g = D_800F36A4++;
                _g->w0 = 0xFCFFFFFF;
                _g->w1 = 0xFFFCF238;
            }
            func_800B8414(arg0->unk178->unk4, 124.0f, W + 124.0f, (f32)D_800F3298 - (W + 202.0f), (f32)(D_800F3298 - 202), 0, 1.0f, 0, 1.0f);
        }
        if (arg0->unkAC != 0) {
            s32 tx = arg0->unk178->unk4;
            {
                Gfx800857AC *_g = D_800F36A4++;
                _g->w0 = 0xE7000000;
                _g->w1 = 0;
            }
            {
                Gfx800857AC *_g = D_800F36A4++;
                _g->w0 = 0xE3000A01;
                _g->w1 = 0x100000;
            }
            func_800B9DE0(tx);
            {
                Gfx800857AC *_g = D_800F36A4++;
                _g->w0 = 0xFCFFFFFF;
                _g->w1 = 0xFFFCF238;
            }
            func_800B8414(arg0->unk178->unk4, 194.0f, W + 194.0f, (f32)D_800F3298 - (y = W + 202.0f), (f32)(D_800F3298 - 202), 0, s = 1.0f, 0, s);
            tx = arg0->unk17C->unk4;
            {
                Gfx800857AC *_g = D_800F36A4++;
                _g->w0 = 0xE7000000;
                _g->w1 = 0;
            }
            {
                Gfx800857AC *_g = D_800F36A4++;
                _g->w0 = 0xE3000A01;
                _g->w1 = 0x100000;
            }
            func_800B9DE0(tx);
            {
                Gfx800857AC *_g = D_800F36A4++;
                _g->w0 = 0xFCFFFFFF;
                _g->w1 = 0xFFFCF238;
            }
            func_800B8414(arg0->unk17C->unk4, 49.0f, W + 49.0f, (f32)D_800F3298 - y, (f32)(D_800F3298 - 202), 0, s, 0, s);
        }
        if (arg0->unkB4 != 0) {
            func_800B1AC4(arg0->unk164, 95.0f, 22.0f, 0.5f, 0.9f);
        }
    }
    func_80086FBC(arg0);
}
