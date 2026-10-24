/* cflags: -fcse-follow-jumps -fexpensive-optimizations */
#include "common.h"

typedef struct {
    u8 pad0[4];
    s32 v4;
    u8 pad8[0xC];
} Txt3FFF0;

typedef struct {
    u8 pad0[0x2C];
    void *p2C;
    s32 v30;
    s16 h34;
    s16 h36;
    s32 v38;
    u8 a3C[0x10];
    s8 b4C;
    u8 pad4D[0x27C - 0x4D];
    s16 h27C;
    s16 h27E;
    s16 pairs[9][2];
    s32 v2A4;
    s16 h2A8;
    s16 h2AA;
    s16 h2AC;
    s16 h2AE;
    s16 h2B0;
    s16 h2B2;
    s8 b2B4;
    s8 b2B5;
    u8 pad2B6;
    char s2B7[0x18];
    char s2CF[0x21];
    f32 f2F0;
    u16 h2F4[9];
    u8 pad306[2];
    Txt3FFF0 t308;
    Txt3FFF0 t31C;
    Txt3FFF0 t330;
    Txt3FFF0 t344;
    Txt3FFF0 t358;
    Txt3FFF0 t36C;
    Txt3FFF0 t380;
    Txt3FFF0 t394;
    Txt3FFF0 t3A8;
    u8 a3BC[0x10];
    s8 b3CC;
    u8 pad3CD[0x5FC - 0x3CD];
    u8 a5FC[0x10];
    s8 b60C;
    u8 pad60D[0x83C - 0x60D];
    Txt3FFF0 t83C;
    Txt3FFF0 t850;
    Txt3FFF0 t864;
    Txt3FFF0 t878;
} Obj3FFF0;

typedef struct {
    s32 v0;
    s32 v4;
    u8 pad8[0x2A - 8];
    u16 h2A;
    u8 pad2C[2];
    u16 h2E;
    u8 pad30[0x78 - 0x30];
} Lvl3FFF0;

typedef struct {
    u8 pad0[0x14];
    u8 b14;
    u8 pad15;
    u8 b16;
} Ctl3FFF0;

typedef struct {
    u8 pad0[8];
    u8 b8;
    u8 pad9[0x14 - 9];
} Tab3FFF0;

typedef struct {
    Tab3FFF0 e[0x6B];
    u8 pad85C[0x10];
    u8 sel;
} Big3FFF0;

void func_800057E4(char *, char *, s32);
void func_800242CC(void);
void func_80039500(void);
void func_8003A69C(void *);
void func_8003A8B4(void *);
void func_80041AAC(Obj3FFF0 *);
void func_8008B490(void *, void *, s32);
void func_8008BB2C(void *, s32);
void func_8008BB50(void *);
void func_800A72C0(void *);
void func_800A73EC(void *, s32);
void func_800A773C(void *, f32, f32);
void func_800A7AF8(void *, s32, s32, s32, s32);
void func_800A7B10(void *, s32, s32, s32, s32);
void func_800B198C(void *);
void func_800B1A80(void *, s32);
extern char D_8001A460[];
extern s32 D_8001A5F0;
extern s32 D_800C0E20;
extern Ctl3FFF0 D_800D0FC0;
extern s32 D_800D1E64;
extern s32 D_800D3F34;
extern s32 D_800D4850;
extern Lvl3FFF0 D_800D5C1C[];
extern Big3FFF0 D_800DE9F4;
extern s32 D_800DE7A0;
extern u8 D_800DF260;
extern f32 D_800EA9B0;
extern f32 D_800ECEF0;

Obj3FFF0 *func_8003FFF0(Obj3FFF0 *o) {
    u8 sp18[4];
    s32 *p;
    f32 f;
    void *q1;
    void *q2;
    void *q3;
    char *fmt;
    Lvl3FFF0 *lvl;
    Ctl3FFF0 *c;
    Big3FFF0 *b;
    s32 t;

    func_80039500();
    o->p2C = &D_8001A5F0;
    func_800A72C0(o->a3C);
    func_800B198C(&o->t308);
    func_800B198C(&o->t31C);
    func_800B198C(&o->t330);
    func_800B198C(&o->t344);
    func_800B198C(&o->t358);
    func_800B198C(&o->t36C);
    func_800B198C(&o->t380);
    func_800B198C(&o->t394);
    func_800B198C(&o->t3A8);
    func_800A72C0(o->a3BC);
    func_800A72C0(o->a5FC);
    func_800B198C(&o->t83C);
    func_800B198C(&o->t850);
    func_800B198C(&o->t864);
    func_800B198C(&o->t878);
    p = &D_800D3F34;
    func_8003A69C(p);
    func_8003A8B4(p);
    f = D_800D4850;
    D_800ECEF0 = f;
    D_800EA9B0 = f;
    func_800242CC();
    c = &D_800D0FC0;
    if (c->b16 == 0x1D || (b = &D_800DE9F4, b->e[c->b14].b8 == 0)) {
        c->b16 = 0x1F;
        D_800C0E20 = D_800DF260 = 0;
    } else {
        D_800C0E20 = b->sel;
    }
    t = D_800C0E20;
    if (t >= 9) {
        D_800C0E20 = 8;
    } else if (t < 0) {
        D_800C0E20 = 0;
    }
    o->v38 = D_800C0E20 + 0x32;
    func_80041AAC(o);
    o->pairs[0][0] = 0xB4;
    o->pairs[0][1] = 0x168;
    o->pairs[1][0] = 0x103;
    o->pairs[1][1] = 0x186;
    o->pairs[2][0] = 0x108;
    o->pairs[2][1] = 0x174;
    o->pairs[3][0] = 0xDC;
    o->pairs[3][1] = 0x190;
    o->pairs[4][0] = 0xCD;
    o->pairs[4][1] = 0x181;
    o->pairs[5][0] = 0xD2;
    o->pairs[5][1] = 0x1A4;
    o->pairs[6][0] = 0xEB;
    o->pairs[6][1] = 0x18B;
    o->pairs[7][0] = 0xD2;
    o->pairs[7][1] = 0x154;
    o->pairs[8][0] = 0xE6;
    o->pairs[8][1] = 0x17C;
    o->h2F4[0] = 6;
    o->h2F4[1] = 7;
    o->h2F4[2] = 0xB;
    o->h2F4[3] = 9;
    o->h2F4[4] = 8;
    o->h2F4[5] = 0xA;
    o->h2F4[6] = 0xD;
    o->h2F4[7] = 0xC;
    o->h2F4[8] = 0xE;
    func_8008BB50(sp18);
    q1 = o->a3C;
    func_800A73EC(q1, 0x501);
    func_8008B490(sp18, q1, 0x501);
    o->b4C = 1;
    func_800A773C(q1, 1.1f, 1.3f);
    func_800A7AF8(q1, 0x87, 0xC2, 0xF3, 0xFF);
    func_800A7B10(q1, 0x87, 0xC2, 0xF3, 0xFF);
    func_800B1A80(&o->t308, 0x12);
    func_800B1A80(&o->t31C, o->h2F4[D_800C0E20]);
    o->t308.v4 = 1;
    o->t31C.v4 = 1;
    o->h2B0 = o->pairs[D_800C0E20][0];
    o->h2B2 = o->pairs[D_800C0E20][1];
    o->b2B4 = 0;
    o->b2B5 = 0;
    fmt = D_8001A460;
    lvl = D_800D5C1C;
    func_800057E4(o->s2B7, fmt, lvl[D_800C0E20].v0);
    func_800057E4(o->s2CF, fmt, lvl[D_800C0E20].v4);
    func_800B1A80(&o->t330, 4);
    o->t330.v4 = 1;
    func_800B1A80(&o->t344, 5);
    o->t344.v4 = 1;
    func_800B1A80(&o->t36C, 2);
    func_800B1A80(&o->t358, 3);
    func_800B1A80(&o->t380, 1);
    D_800D1E64 = 0xA6;
    o->h27C = 0xA0;
    o->h27E = 0x7D;
    o->h2A8 = lvl[D_800C0E20].h2A;
    o->h2AA = lvl[D_800C0E20].h2E;
    o->h2AC = 0x15E;
    o->h2AE = 0x64;
    o->f2F0 = 1.8f;
    if (D_800DE7A0 == 1) {
        func_800B1A80(&o->t83C, 0x9E);
    } else if (D_800DE7A0 == 3) {
        func_800B1A80(&o->t83C, 0x9F);
    }
    o->t83C.v4 = 1;
    func_800B1A80(&o->t394, 0xA4);
    o->t394.v4 = 1;
    func_800B1A80(&o->t3A8, 0xA5);
    o->t3A8.v4 = 1;
    q2 = o->a3BC;
    func_800A73EC(q2, 0x501);
    func_8008B490(sp18, q2, 0x501);
    func_800A773C(q2, 1.0f, 1.0f);
    func_800A7AF8(q2, 0xAA, 0, 0, 0xFF);
    func_800A7B10(q2, 0xAA, 0, 0, 0xFF);
    o->b3CC = 0;
    q3 = o->a5FC;
    func_800A73EC(q3, 1);
    if (D_800DE7A0 == 1) {
        func_800A773C(q3, 1.8f, 1.8f);
    } else {
        func_800A773C(q3, 1.4f, 1.5f);
    }
    func_800A7AF8(o->a5FC, 0x87, 0xC2, 0xF3, 0xFF);
    func_800A7B10(o->a5FC, 0x87, 0xC2, 0xF3, 0xFF);
    o->b60C = 0;
    o->v30 = 0;
    o->v2A4 = 0;
    o->h34 = 0;
    o->h36 = 0;
    func_800B1A80(&o->t850, 0xA3);
    o->t850.v4 = 1;
    func_800B1A80(&o->t864, 0xA2);
    o->t864.v4 = 1;
    func_800B1A80(&o->t878, 0xA1);
    o->t878.v4 = 1;
    func_8008BB2C(sp18, 2);
    return o;
}
