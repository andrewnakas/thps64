/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0x18];
    s16 unk18;
    u8 pad1A[2];
    void (*unk1C)(void *);
} VTbl;

typedef struct {
    u8 pad0[0x48];
    VTbl *unk48;
} Obj;

typedef struct {
    u8 pad0[4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 pad10[0x24];
    u8 unk34[0x70];
} Ent;

typedef struct {
    u8 pad0[0xC];
    u16 unkC;
} Inp;

extern s32 D_800DE820;
extern s32 D_800DC618;
extern Ent D_800DE1A4[];
extern Inp *D_800D8434;
extern s32 D_800DE7A0;
extern s32 D_800DE9A8;
extern f32 D_800D1E7C;
void func_80041F80(f32 *, void *);
void func_8009C8EC(f32 *, f32 *);
void func_8009CCC8(f32 *, f32 *);
void func_800A4624(void *, f32 *);
f32 func_8009F9D0(f32);
void func_800A4350(void *, f32, f32, f32, f32);

void func_80026B88(u8 *arg0) {
    f32 m[16];
    f32 m2[16];
    Ent *e;
    void *s;
    s32 v;
    Ent *base;
    f32 *pm;
    f32 *pm2;

    if (D_800DE820 == 0 || D_800DC618 == 2) {
        Obj *o = *(Obj **)(arg0 + 0x2248);
        VTbl *vt = o->unk48;
        vt->unk1C((u8 *)o + vt->unk18);
    }
    base = D_800DE1A4;
    e = &base[*(s8 *)(arg0 + 0xF14)];
    func_80041F80(m, e->unk34);
    pm = m;
    pm2 = m2;
    func_8009C8EC(pm2, pm);
    func_8009CCC8(pm, pm2);
    m[12] = e->unk4;
    m[13] = e->unk8;
    m[14] = e->unkC;
    m[12] *= 0.0625f;
    m[13] *= 0.0625f;
    m[14] *= 0.0625f;
    s = arg0 + 0x1B28;
    func_800A4624(s, pm);
    v = D_800D8434->unkC;
    if ((D_800DE7A0 == 7 || D_800DE9A8 == 1) && v != *(s32 *)(arg0 + 0x2384)) {
        f32 a = 2.0f * func_8009F9D0(v * 0.000244140625f);
        func_800A4350(s, a, a * 0.75f, 10.0f, D_800D1E7C);
        *(s32 *)(arg0 + 0x2384) = v;
    }
}
