#include "common.h"

void func_800394A8(u8 *, s32);
void func_800A735C(void *, s32);
void func_800B19C0(void *, s32);

typedef struct {
    u16 x0;
    u16 x2;
    u16 x4;
} Tri80030EA4;

typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    s32 x14;
} Rec80030EA4;

typedef struct {
    u16 x0;
    u8 pad2[0x1E];
} Sub80030EA4;

typedef struct {
    u8 pad0[0x56];
    Sub80030EA4 e[7];
    u8 pad136[0x154 - 0x136];
} Row80030EA4;

extern u8 D_80019C10[];
extern u8 D_800D0FC0[];
extern u16 D_800D4788[];
extern u16 D_800D47A8[];
extern Tri80030EA4 D_800D47CC[];
extern Rec80030EA4 D_800D4818[2];
extern Row80030EA4 D_800D4D80[];
extern u8 D_800DE9F4[];
typedef struct {
    u8 pad0[0xC];
    s32 xC;
    void *x10;
} Ctl80030EA4;

extern Ctl80030EA4 D_800EECF0;

#define U8(p, o) (*(u8 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define D4D80(i, j) (D_800D4D80[i].e[j].x0)

void func_80030EA4(u8 *arg0, s32 arg1) {
    s32 a;
    s32 b;
    Rec80030EA4 *p;
    Rec80030EA4 *q;
    u8 v;
    u8 *g;
    u8 *cfg;

    *(u8 **)(arg0 + 0x2C) = D_80019C10;
    g = D_800DE9F4;
    cfg = D_800D0FC0;
    v = arg0[0x3E];
    cfg[0x1B] = v;
    g[0x866] = v;
    v = arg0[0x46];
    cfg[0x1C] = v;
    g[0x86A] = v;
    v = arg0[0x44];
    cfg[0x1D] = v;
    g[0x868] = v;
    v = arg0[0x3F];
    cfg[0x1E] = v;
    g[0x867] = v;
    v = arg0[0x47];
    cfg[0x1F] = v;
    g[0x86B] = v;
    v = arg0[0x45];
    cfg[0x20] = v;
    g[0x869] = v;
    a = 0;
    b = a;
    if (S32(cfg, 0xC) == 1 && S32(cfg, 0x8) == S32(cfg, 0xC)) {
        a = arg0[0x3C] == 10;
    }
    p = D_800D4818;
    p[0].x0 = D_800D47CC[arg0[0x3C] + a].x0;
    p[0].x8 = D_800D47CC[arg0[0x3C] + a].x2;
    p[0].x10 = D_800D47CC[arg0[0x3C] + a].x4;
    p[0].x4 = D4D80(arg0[0x3C], arg0[0x3E]);
    p[0].xC = D_800D4788[arg0[0x44]];
    p[0].x14 = D_800D47A8[arg0[0x44]];
    cfg = D_800D0FC0;
    if (S32(cfg, 0xC) == 1 && S32(cfg, 0x8) == S32(cfg, 0xC)) {
        if (arg0[0x3D] == 10) {
            b = 1;
        }
    }
    q = D_800D4818;
    q[1].x0 = D_800D47CC[arg0[0x3D] + b].x0;
    q[1].x8 = D_800D47CC[arg0[0x3D] + b].x2;
    q[1].x10 = D_800D47CC[arg0[0x3D] + b].x4;
    q[1].x4 = D4D80(arg0[0x3D], arg0[0x3F]);
    q[1].xC = D_800D4788[arg0[0x45]];
    q[1].x14 = D_800D47A8[arg0[0x45]];
    {
        Ctl80030EA4 *c = &D_800EECF0;
        s32 n = 6;
        c->x10 = q;
        c->xC = n;
    }
    func_800B19C0(arg0 + 0x610, 2);
    func_800B19C0(arg0 + 0x5FC, 2);
    func_800B19C0(arg0 + 0x5E8, 2);
    func_800B19C0(arg0 + 0x5D4, 2);
    func_800B19C0(arg0 + 0x5C0, 2);
    func_800B19C0(arg0 + 0x5AC, 2);
    func_800B19C0(arg0 + 0x598, 2);
    func_800B19C0(arg0 + 0x584, 2);
    func_800B19C0(arg0 + 0x570, 2);
    func_800B19C0(arg0 + 0x55C, 2);
    func_800B19C0(arg0 + 0x548, 2);
    func_800B19C0(arg0 + 0x534, 2);
    func_800B19C0(arg0 + 0x520, 2);
    func_800B19C0(arg0 + 0x50C, 2);
    func_800B19C0(arg0 + 0x4F8, 2);
    func_800A735C(arg0 + 0x298, 2);
    func_800A735C(arg0 + 0x58, 2);
    func_800394A8(arg0, arg1);
}
