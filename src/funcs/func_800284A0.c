/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0x2C];
    void *vt;
    s16 unk30;
    s16 unk32;
    f32 unk34;
    f32 unk38;
    s16 unk3C;
    s16 unk3E;
    u8 unk40;
    u8 unk41;
    u8 pad42[2];
    f32 unk44;
    s16 unk48;
    u8 pad4A[2];
    u8 unk4C[0x10];
    u8 unk5C;
    u8 pad5D[0x28C - 0x5D];
    u8 spr28C[4];
    s32 v290;
    u8 pad294[0xC];
    u8 spr2A0[4];
    s32 v2A4;
    u8 pad2A8[0xC];
    u8 spr2B4[4];
    s32 v2B8;
    u8 pad2BC[0xC];
    u8 spr2C8[4];
    s32 v2CC;
    u8 pad2D0[0xC];
    u8 spr2DC[4];
    s32 v2E0;
    u8 pad2E4[0xC];
    f32 v2F0;
    s32 v2F4;
    s32 v2F8;
} Obj284A0;

void func_80039500(Obj284A0 *);
void func_800A72C0(void *);
void func_800B198C(void *);
void func_800B1A80(void *, s32);
void func_8008BB50(void *);
void func_800A73EC(void *, s32);
void func_800A773C(void *, f32, f32);
void func_8008B490(void *, void *, s32);
void func_8008BB2C(void *, s32);
extern u8 D_80017368[];
extern s32 D_800D2840;
extern f32 D_800ECEF0;
extern f32 D_800EA9B0;
extern f32 D_800D0FF0;
extern f32 D_800D0FEC;

Obj284A0 *func_800284A0(Obj284A0 *o) {
    u8 buf[8];
    f32 f;
    f32 c;
    u8 *p;
    u32 u;
    u32 m;
    f32 tt;
    f32 f2;
    f32 c2;
    f32 tt2;
    u32 u2;
    u32 m2;
    f32 g;

    func_80039500(o);
    o->vt = D_80017368;
    func_800A72C0(o->unk4C);
    func_800B198C(o->spr28C);
    func_800B198C(o->spr2A0);
    func_800B198C(o->spr2B4);
    func_800B198C(o->spr2C8);
    func_800B198C(o->spr2DC);
    g = D_800D2840;
    D_800ECEF0 = g;
    D_800EA9B0 = g;
    o->unk48 = 0x65;
    o->unk44 = 0.1f;
    o->unk30 = 0x163;
    o->unk32 = 0xFA;
    f = D_800D0FF0 * 10.0f;
    p = &o->unk40;
    if (!((c = 2147483648.0f) <= f)) {
        u = (s32)f;
    } else {
        tt = f - c;
        m = 0x80000000;
        u = (s32)tt;
        u |= m;
    }
    *p = u;
    f2 = D_800D0FEC * 10.0f;
    p = &o->unk41;
    if (!((c2 = 2147483648.0f) <= f2)) {
        u2 = (s32)f2;
    } else {
        tt2 = f2 - c2;
        m2 = 0x80000000;
        u2 = (s32)tt2;
        u2 |= m2;
    }
    *p = u2;
    if (o->unk40 >= 11) {
        o->unk40 = 10;
    }
    if (o->unk41 >= 11) {
        o->unk41 = 10;
    }
    func_800B1A80(o->spr28C, 0x9A);
    o->v290 = 1;
    func_800B1A80(o->spr2A0, 0x9C);
    o->v2A4 = 1;
    func_800B1A80(o->spr2B4, 0x9B);
    o->v2B8 = 1;
    func_8008BB50(buf);
    o->unk34 = 1.3f;
    o->unk38 = 1.5f;
    func_800A73EC(o->unk4C, 0x501);
    o->unk5C = 0;
    func_800A773C(o->unk4C, o->unk34, o->unk34);
    func_8008B490(buf, o->unk4C, 0x501);
    func_800B1A80(o->spr2C8, 3);
    o->v2CC = 1;
    func_800B1A80(o->spr2DC, 2);
    o->v2E0 = 1;
    o->v2F8 = 1;
    o->v2F0 = 0.5f;
    o->v2F4 = 1;
    o->unk3C = 0xAA;
    o->unk3E = 0x87;
    func_8008BB2C(buf, 2);
    return o;
}
