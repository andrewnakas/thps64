/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx378C;

typedef struct {
    s16 delta;
    s16 pad;
    void (*fn)(void *);
} VtEnt378C;

typedef struct {
    u8 pad0[8];
    VtEnt378C e[4];
} Vt378C;

typedef struct {
    u8 pad0[0x18];
    s32 unk18;
    u8 pad1C[0x1AC - 0x1C];
    u8 unk1AC[0x42C - 0x1AC];
    s32 *unk42C;
    s32 unk430;
    s32 unk434;
    u8 pad438[0x460 - 0x438];
    s32 unk460;
    u8 pad464[4];
    s32 unk468;
    u8 pad46C[0x494 - 0x46C];
    s32 unk494;
    u8 pad498[0x4F0 - 0x498];
    f32 unk4F0;
    f32 unk4F4;
    Vt378C *unk4F8;
} Obj378C;

s32 func_800A05F8(Obj378C *, s32, s32);
s32 func_800A0670(Obj378C *, s32, s32);
s32 func_800A06E8(Obj378C *, s32, s32);
void func_800A1E70(Obj378C *);
void func_800A3BD4(Obj378C *, void *, s32 *);
void func_800A3CD8(Obj378C *, void *, s32);
void func_800A773C(void *, f32, f32);
void func_800A7B28(void *, s32, s32, s32, s32);
void func_800A8B80(void *, s32, f32, f32, f32, s32, s32, f32, s32, s32, s32, s32, f32);
extern s32 D_800EA550;
extern s32 D_800EECE8;
extern s32 D_800F3294;
extern s32 D_800F3298;
extern Gfx378C *D_800F36A4;
extern f32 D_800F5668;

void func_800A378C(Obj378C *arg0) {
    u8 sp38[0x10];
    s32 count;
    s32 done;
    s32 justSet;
    s32 ok;
    s32 cx;
    s32 cy;
    f32 scale;
    f32 k;
    f32 w;
    Gfx378C *g;
    void *txt;

    done = 0;
    if (arg0->unk4F4 != 0.0f) {
        if (arg0->unk4F4 < arg0->unk4F0) {
            done = 1;
        } else {
            arg0->unk4F0 += D_800F5668;
        }
    }
    D_800EECE8 = -1;
    g = D_800F36A4++;
    g->w0 = 0xE7000000;
    g->w1 = 0;
    g = D_800F36A4++;
    g->w0 = 0xE3000A01;
    g->w1 = 0x100000;
    justSet = 0;
    if (arg0->unk468 == 0) {
        ok = 0;
        if (func_800A0670(arg0, arg0->unk434, 0x8000) == 0) {
            ok = func_800A0670(arg0, arg0->unk434, 0x4000) == 0;
        }
        arg0->unk468 = ok;
        if (ok) {
            justSet = 1;
        }
    }
    scale = 0.85f;
    cx = D_800F3294 / 2;
    cy = D_800F3298 / 2;
    if (arg0->unk460 != 0) {
        scale = 1.0f;
    }
    txt = arg0->unk1AC;
    k = 0.8f;
    w = scale * k;
    func_800A7B28(txt, 0xD3, 0xD3, 0xD3, 0xFF);
    func_800A773C(txt, w, scale);
    func_800A8B80(txt, arg0->unk494, cx, cy + 5, 1.2f, 2, 1, 1.0f, 0xFF, 0, 1, 1, (s32)(D_800F3294 * k));
    func_800A3BD4(arg0, sp38, &count);
    func_800A3CD8(arg0, sp38, count);
    if (count >= 2) {
        if (func_800A05F8(arg0, arg0->unk434, 0x800) != 0) {
            arg0->unk18 = (arg0->unk18 + count - 1) % count;
            arg0->unk4F8->e[0].fn((u8 *)arg0 + arg0->unk4F8->e[0].delta);
        } else if (func_800A05F8(arg0, arg0->unk434, 0x400) != 0) {
            arg0->unk18 = (arg0->unk18 + 1) % count;
            arg0->unk4F8->e[1].fn((u8 *)arg0 + arg0->unk4F8->e[1].delta);
        }
    }
    if ((arg0->unk468 != 0 && func_800A0670(arg0, arg0->unk434, 0x4000) != 0) || done) {
        switch (arg0->unk430) {
        case 0:
        case 2:
            break;
        case 6:
            arg0->unk18 = 0;
            break;
        case 8:
            arg0->unk18 = 2;
            break;
        case 1:
        case 3:
        case 4:
        case 5:
        case 7:
        case 9:
            arg0->unk18 = 1;
            break;
        }
        if (!done) {
            arg0->unk4F8->e[2].fn((u8 *)arg0 + arg0->unk4F8->e[2].delta);
        }
    }
    if ((arg0->unk468 != 0 && !justSet && func_800A06E8(arg0, arg0->unk434, 0xC000) != 0) || done) {
        if (arg0->unk42C != NULL) {
            D_800EA550 = arg0->unk42C[arg0->unk18 + 1];
        } else {
            D_800EA550 = 0;
        }
        if (D_800EA550 == 0) {
            func_800A1E70(arg0);
        }
        if (!done) {
            arg0->unk4F8->e[3].fn((u8 *)arg0 + arg0->unk4F8->e[3].delta);
        }
    }
}
