#include "common.h"

typedef struct {
    u8 pad0[0x168];
    s8 b168;
    s8 b169;
} Pad4BE0C;

typedef struct {
    u8 pad0[0xC];
    s32 vC;
    u8 pad10[0x154 - 0x10];
} T154;

typedef struct {
    u8 pad0[4];
    s32 v4;
    s32 v8;
    s32 vC;
    u8 pad10[0x20 - 0x10];
    s32 v20;
    u8 pad24[0x120 - 0x24];
    s32 v120;
    u8 pad124[4];
    s32 v128;
    u8 pad12C[0x160 - 0x12C];
    u16 h160;
    s16 h162;
    u8 pad164[0x16C - 0x164];
    u8 a16C[0x21E - 0x16C];
    u16 h21E;
    u8 pad220[0x28C - 0x220];
    s32 v28C;
    u8 pad290[0x3DC - 0x290];
    s32 v3DC;
    s32 v3E0;
    u8 pad3E4[0x408 - 0x3E4];
    s32 v408;
    s32 v40C;
    u8 pad410[0x428 - 0x410];
    s32 v428;
    u8 pad42C[0x7E8 - 0x42C];
    s32 v7E8;
    u8 pad7EC[0x82C - 0x7EC];
    s32 v82C;
    u8 pad830[0x964 - 0x830];
    Pad4BE0C *pad;
    u8 pad968[0x988 - 0x968];
    u8 b988;
    u8 pad989[3];
    s8 b98C;
    s8 b98D;
    u8 pad98E[0x9F4 - 0x98E];
    u8 b9F4;
    u8 b9F5;
    u16 h9F6;
    u8 pad9F8[0xA14 - 0x9F8];
    s32 vA14;
} Sk4BE0C;

void func_8004BA74(Sk4BE0C *);
void func_8004C14C(Sk4BE0C *);
void func_80059BEC(Sk4BE0C *);
void func_8005BDA8(Sk4BE0C *);
void *func_8005CA90(void *, void *, void *, s32, s32);
void func_80066D94(void *, Sk4BE0C *);
void func_8006C7D4(Sk4BE0C *);
void func_8006CDAC(Sk4BE0C *);
s32 func_80079218(s32);
extern T154 D_800D4D80[];
extern Sk4BE0C *D_800D61A8;
extern s32 D_800D62D8;
extern s32 D_800DC5A0;
extern s32 D_800DC618;
extern s32 D_800DC6D8;
extern s32 D_800DDC60;
extern s32 D_800DE144;
extern s32 D_800DE7CC;
extern s32 D_800DE820;
extern s32 D_800DE994;
extern s32 D_800E9038;

void func_8004BE0C(Sk4BE0C *p) {
    u8 sp18[16];
    s32 *mode;
    u8 t;
    s32 a;
    s32 b;
    void *hit;

    if (D_800E9038 != 0) {
        return;
    }
    if (D_800DE820 != 0 && (D_800DC618 != 2 || D_800DE7CC != 0)) {
        return;
    }
    if (func_80079218(D_800DE144) != 0) {
        p->v428 = D_800DE994 + 0xE2E;
        return;
    }
    if (p->b988 != 0) {
        return;
    }
    if (p->v408 != 0 && D_800DE994 - p->v408 >= 0xB) {
        p->v408 = 0;
    }
    if (p->v40C != 0 && D_800DE994 - p->v40C >= 0xB) {
        p->v40C = 0;
    }
    mode = (p == D_800D61A8) ? &D_800DC618 : &D_800DC6D8;
    switch (*mode) {
    case 1:
        func_8006CDAC(p);
        p->v7E8 = 100;
        break;
    case 2:
        func_8006C7D4(p);
        func_8005BDA8(p);
        return;
    default:
        p->v7E8 = 100;
        break;
    }
    p->v20 = 0x404040;
    p->b98D = p->pad->b168;
    p->b98C = p->pad->b169;
    if (D_800E9038 == 0 && D_800DE820 == 0) {
        func_80059BEC(p);
    }
    func_8004C14C(p);
    if (((p->h160 >> 1) ^ 1) & 1) {
        p->h9F6++;
    } else {
        p->h9F6 = 0;
        p->b9F5 = 0;
    }
    if (p->b98C | p->b98D) {
        if (p->vA14 < 8) {
            p->vA14++;
        }
    } else {
        if (p->vA14 != 0) {
            p->vA14--;
        }
    }
    if (D_800D62D8 != 0) {
        D_800D62D8--;
    }
    t = p->b9F4;
    if (t != 0) {
        p->b9F4 = t - 1;
    }
    func_8005CA90(p->a16C, &p->v4, sp18, D_800DDC60, 0);
    hit = func_8005CA90(p->a16C, &p->v4, sp18, D_800DC5A0, 0);
    if (hit != NULL) {
        func_80066D94(hit, p);
    }
    if (p->v82C != 0 || (a = p->v8, b = p->v3DC, (a - b < 0 ? -(a - b) : a - b) > 0x40)) {
        p->v3DC = p->v8;
    } else {
        p->v120 = p->v4;
        p->v128 = p->vC;
    }
    func_8004BA74(p);
    if (p->h162 < 0) {
        p->h162 = 0;
    }
    if (D_800D4D80[p->v3E0].vC == 0x4000) {
        if (p->h21E != 0x3F) {
            p->v28C |= 0x1000;
        } else {
            p->v28C &= ~0x1000;
        }
    }
}
