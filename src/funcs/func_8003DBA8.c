#include "common.h"

typedef struct {
    u8 pad0[8];
    s16 off;
    s16 pad;
    void (*fn)(void *, s32);
} VT3DBA8;

typedef struct {
    u8 pad0[0x48];
    VT3DBA8 *vt;
    u8 pad4C[0x2260 - 0x4C];
    f32 f2260;
    f32 f2264;
    f32 f2268;
} O3DBA8;

void func_80027ED8(O3DBA8 *, s32, s32, s32, s32);
O3DBA8 *func_80028238(void *, s32, s32, s32);
void func_8004AE2C(O3DBA8 *, s32, s32);
void *func_8004B514(s32);
void func_800BC0F4(void *);
extern s32 D_800D4760;
extern u16 D_800D4788[];
extern u16 D_800D47A8[];
extern u16 D_800D47CC[][3];
extern s32 D_800D4818[6];
typedef struct {
    u16 x[16];
} Sub3DBA8;
typedef struct {
    u8 pad[0x56];
    Sub3DBA8 sub[7];
    u8 pad2[0x154 - 0x56 - 0xE0];
} Ent3DBA8;
extern Ent3DBA8 D_800D4D80[];
extern u8 D_800DE9F4[];
extern s32 D_800EECF0[];
extern s32 D_800F0DD0;
extern s32 D_800F3294;
extern s32 D_800F3298;
extern f32 D_800F329C;

O3DBA8 *func_8003DBA8(O3DBA8 *arg0, s32 arg1) {
    f32 a, b, c;
    f32 w;
    O3DBA8 *o;
    s32 *e;

    if (arg0 != NULL) {
        a = arg0->f2268;
        b = arg0->f2260;
        c = arg0->f2264;
        func_800BC0F4(&D_800F0DD0);
        arg0->vt->fn((u8 *)arg0 + arg0->vt->off, 3);
    }
    D_800D4818[0] = D_800D47CC[arg1][0];
    D_800D4818[2] = D_800D47CC[arg1][1];
    D_800D4818[4] = D_800D47CC[arg1][2];
    D_800D4818[1] = D_800D4D80[arg1].sub[D_800DE9F4[0x866]].x[0];
    D_800D4818[3] = D_800D4788[D_800DE9F4[0x868]];
    D_800D4818[5] = D_800D47A8[D_800DE9F4[0x868]];
    e = D_800EECF0;
    {
        s32 n = 3;
        e[4] = (s32)D_800D4818;
        e[3] = n;
    }
    o = func_80028238(func_8004B514(0x2388), arg1, 1, 1);
    w = D_800F3294;
    func_80027ED8(o, (f32)((s32)(w * 0.65f) + D_800D4760) * D_800F329C, (f32)((s32)(w * 0.88f) + D_800D4760) * D_800F329C,
                  (f32)D_800F3298 * 0.35f, (f32)D_800F3298 * 0.85f);
    func_8004AE2C(o, 0, 1);
    if (arg0 != NULL) {
        o->f2268 = a;
        o->f2260 = b;
        o->f2264 = c;
    }
    return o;
}
