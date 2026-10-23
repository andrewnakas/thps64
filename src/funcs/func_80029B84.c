#include "common.h"

typedef struct {
    u16 a, b, c;
} T6;

typedef struct {
    u8 pad[0x76];
    u16 v;
    u8 pad78[0x154 - 0x78];
} T154;

typedef struct {
    s16 delta;
    s16 pad;
    void (*fn)(void *, s32);
} VEnt;

extern T6 D_800D47CC[];
extern T154 D_800D4D80[];
extern s32 D_800D4818[6];
extern u16 D_800D4796;
extern u16 D_800D47B6;
extern s32 D_800EECF0[];
extern u8 D_800F0DD0[];
extern f32 D_800F329C;
void func_800BC0F4(void *);
void *func_8004B514(s32, void *);
u8 *func_80028238(void *, s32, s32, s32);
void func_80027ED8(u8 *, s32, s32, s32, s32);
void func_8004AE2C(u8 *, s32, s32);

#define F(p, o) (*(f32 *)((p) + (o)))

u8 *func_80029B84(u8 *arg0, u8 *arg1) {
    f32 x;
    f32 y;
    f32 z;
    u8 *r;
    s32 *d;
    s32 *e;
    s32 t;

    t = (s8)++arg0[0x2A8];
    if (t < 0) {
        arg0[0x2A8] = 9;
    } else if (t >= 10) {
        arg0[0x2A8] = 0;
    }
    *(s32 *)(arg0 + 0x2AC) = 0;
    if (arg1 != NULL) {
        x = F(arg1, 0x2268);
        y = F(arg1, 0x2260);
        z = F(arg1, 0x2264);
        func_800BC0F4(D_800F0DD0);
        {
            VEnt *vt = *(VEnt **)(arg1 + 0x48);
            vt[1].fn(arg1 + vt[1].delta, 3);
        }
    }
    d = D_800D4818;
    d[0] = D_800D47CC[(s8)arg0[0x2A8]].a;
    d[2] = D_800D47CC[(s8)arg0[0x2A8]].b;
    d[4] = D_800D47CC[(s8)arg0[0x2A8]].c;
    d[1] = D_800D4D80[(s8)arg0[0x2A8]].v;
    d[3] = D_800D4796;
    d[5] = D_800D47B6;
    e = D_800EECF0;
    {
        s32 n = 3;
        *(s32 **)(e + 4) = d;
        e[3] = n;
    }
    r = func_80028238(func_8004B514(0x2388, d), (s8)arg0[0x2A8], 1, 1);
    func_80027ED8(r, D_800F329C * 200.0f, D_800F329C * 440.0f, 0x41, 0x1A4);
    func_8004AE2C(r, 0, 1);
    if (arg1 != NULL) {
        F(r, 0x2268) = x;
        F(r, 0x2260) = y;
        F(r, 0x2264) = z;
    }
    return r;
}
