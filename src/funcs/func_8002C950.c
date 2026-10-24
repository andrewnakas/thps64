#include "common.h"

void func_80039500(void);
void func_800B198C(void *);
void func_800A5F10(void *);
void func_800A72C0(void *);
void func_8008BB50(void *);
void func_800A62C4(void *, s32, s32, s32, s32);
void func_800A73EC(void *, s32);
void func_8008B490(void *, void *, s32);
void func_800A7B28(void *, s32, s32, s32, s32);
void func_800A773C(void *, f32, f32);
void func_800B1A80(void *, s32);
void func_8002EA7C(u8 *);
s32 func_800BAB04(void *, s32);
void func_8002EC18(u8 *);
void func_8002CF90(u8 *);
s32 func_8004B514(s32);
s32 func_80028238(s32, s32, s32, s32);
void func_80027ED8(s32, s32, s32, s32, s32);
void func_8004AE2C(s32, s32, s32);
void func_8008BB2C(void *, s32);

typedef struct {
    u16 x0;
    u16 x2;
    u16 x4;
} Tri8002C950;

typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    s32 x14;
} Rec8002C950;

typedef struct {
    u16 x0;
    u8 pad2[0x1E];
} Sub8002C950;

typedef struct {
    u8 pad0[0x56];
    Sub8002C950 e[7];
    u8 pad136[0x154 - 0x136];
} Row8002C950;

typedef struct {
    u8 pad0[0xC];
    s32 xC;
    void *x10;
} Ctl8002C950;

extern u8 D_800199C8[];
extern u8 D_800D0FC0[];
extern s32 D_800D36A0;
extern u16 D_800D4788[];
extern u16 D_800D47A8[];
extern Tri8002C950 D_800D47CC[];
extern Rec8002C950 D_800D4818[2];
extern Row8002C950 D_800D4D80[];
extern u8 D_800DE9F4[];
extern f32 D_800EA9B0;
extern f32 D_800ECEF0;
extern Ctl8002C950 D_800EECF0;
extern s32 D_800F3294;
extern s32 D_800F3298;
extern f32 D_800F329C;

#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))

typedef struct {
    u8 pad0[0x5C8];
    struct {
        u8 pad0[8];
        u16 x8;
        u8 padA[10];
    } it[4];
} Obj8002C950;

u8 *func_8002C950(u8 *arg0) {
    s32 buf;
    f32 f;
    Ctl8002C950 *c;
    u8 *cfg;
    u8 *g;
    Rec8002C950 *p;
    s32 v;

    func_80039500();
    *(u8 **)(arg0 + 0x2C) = D_800199C8;
    func_800B198C(arg0 + 0x30);
    func_800B198C(arg0 + 0x44);
    func_800B198C(arg0 + 0x58);
    func_800B198C(arg0 + 0x6C);
    func_800B198C(arg0 + 0x80);
    func_800B198C(arg0 + 0x94);
    func_800B198C(arg0 + 0xA8);
    func_800B198C(arg0 + 0xBC);
    func_800B198C(arg0 + 0xD0);
    func_800B198C(arg0 + 0xE4);
    func_800B198C(arg0 + 0xF8);
    func_800A5F10(arg0 + 0x110);
    func_800A72C0(arg0 + 0x130);
    func_800A72C0(arg0 + 0x370);
    func_8008BB50(&buf);
    func_800A62C4(arg0 + 0x110, 0, D_800F3294 - 1, 0, D_800F3298 - 1);
    f = D_800D36A0;
    D_800ECEF0 = f;
    D_800EA9B0 = f;
    func_800A73EC(arg0 + 0x130, 0x501);
    func_8008B490(&buf, arg0 + 0x130, 0x501);
    arg0[0x140] = 1;
    func_800A7B28(arg0 + 0x130, 0x87, 0xC2, 0xF3, 0xFF);
    func_800A773C(arg0 + 0x130, 1.29999995f, 1.10000002f);
    func_800A73EC(arg0 + 0x370, 1);
    func_800A7B28(arg0 + 0x370, 0x87, 0xC2, 0xF3, 0xFF);
    func_800A773C(arg0 + 0x370, 0.800000012f, 1.39999998f);
    func_800B1A80(arg0 + 0x30, 0x98);
    S32(arg0, 0x34) = 1;
    func_800B1A80(arg0 + 0x44, 0xCF);
    S32(arg0, 0x48) = 1;
    S32(arg0, 0x5CC) = 0;
    arg0[0x832] = 0;
    S32(arg0, 0x834) = 0;
    func_8002EA7C(arg0);
    c = &D_800EECF0;
    S32(arg0, 0x838) = func_800BAB04(c, 0x588);
    S32(arg0, 0x83C) = func_800BAB04(c, 0x585);
    S32(arg0, 0x840) = func_800BAB04(c, 0x586);
    S32(arg0, 0x844) = func_800BAB04(c, 0x587);
    func_800B1A80(arg0 + 0x58, 0xD9);
    func_800B1A80(arg0 + 0x6C, 0xD3);
    func_800B1A80(arg0 + 0x80, 0xD6);
    func_800B1A80(arg0 + 0x94, 0xD8);
    func_800B1A80(arg0 + 0xA8, 0xDB);
    func_800B1A80(arg0 + 0xBC, 0xDA);
    func_800B1A80(arg0 + 0xD0, 0xD5);
    func_800B1A80(arg0 + 0xE4, 0xD4);
    func_800B1A80(arg0 + 0xF8, 0xD7);
    S32(arg0, 0x5C) = 1;
    S32(arg0, 0x70) = 1;
    S32(arg0, 0x84) = 1;
    S32(arg0, 0x98) = 1;
    S32(arg0, 0xAC) = 1;
    S32(arg0, 0xC0) = 1;
    S32(arg0, 0xD4) = 1;
    S32(arg0, 0xE8) = 1;
    S32(arg0, 0xFC) = 1;
    S32(arg0, 0x5B0) = 0xED;
    S32(arg0, 0x5B4) = 0x7F;
    S32(arg0, 0x5B8) = 0x145;
    S32(arg0, 0x5BC) = 0x178;
    p = D_800D4818;
    p[0].x0 = D_800D47CC[(cfg = D_800D0FC0)[0x14]].x0;
    p[0].x8 = D_800D47CC[cfg[0x14]].x2;
    p[0].x10 = D_800D47CC[cfg[0x14]].x4;
    p[0].x4 = D_800D4D80[cfg[0x14]].e[(g = D_800DE9F4)[0x866]].x0;
    p[0].xC = D_800D4788[g[0x868]];
    p[0].x14 = D_800D47A8[g[0x868]];
    v = 3;
    c->x10 = p;
    c->xC = v;
    func_8002EC18(arg0);
    func_8002CF90(arg0);
    S32(arg0, 0x5C4) = 0;
    S32(arg0, 0x5C0) = 0;
    S32(arg0, 0x10C) = func_80028238(func_8004B514(0x2388), cfg[0x14], 0, 0);
    func_80027ED8(S32(arg0, 0x10C), (D_800D36A0 + 0xF1) * D_800F329C, (D_800D36A0 + 0x19A) * D_800F329C, 0x87, 0x15E);
    func_8004AE2C(S32(arg0, 0x10C), ((Obj8002C950 *)arg0)->it[S32(arg0, 0x5C0)].x8, 1);
    func_8008BB2C(&buf, 2);
    return arg0;
}
