#include "common.h"

void func_80039500(void);
void func_8003A69C(void *);
void func_8003A8B4(void *);
void func_8003E910(u8 *);
s32 func_8003FE90(s32, s32);
void func_8008B490(void *, void *, s32);
void func_8008BB2C(void *, s32);
void func_8008BB50(void *);
void func_800A72C0(void *);
void func_800A73EC(void *, s32);
void func_800A7AF8(void *, s32, s32, s32, s32);
void func_800A7B10(void *, s32, s32, s32, s32);
void func_800B198C(void *);
void func_800B1A80(void *, s32);
void func_800B231C(void *, s32, s32, s32, s32);

typedef struct {
    u16 x0;
    u16 x2;
    u8 pad4[4];
    u8 x8;
    u8 pad9[0x17];
} Sub8003E2E0;

typedef struct {
    u8 pad0[0x54];
    Sub8003E2E0 e[8];
} Row8003E2E0;

typedef struct {
    u8 pad0[8];
    u8 x8;
    u8 pad9[0x14 - 9];
} Ent8003E2E0;

extern u8 D_8001A2F0[];
extern u8 D_8001A430[];
extern u8 D_800D0FC0[];
extern u8 D_800D3F34[];
extern u8 D_800D4770[];
extern u8 D_800D4774[];
extern u8 D_800D4778[];
extern u8 D_800D47C8[];
extern s32 D_800D4814;
extern Row8003E2E0 D_800D4D80[];
extern u8 D_800DE9F4[];
extern f32 D_800EA9B0;
extern f32 D_800ECEF0;

#define ENT(g, i) (((Ent8003E2E0 *)(g))[i])

u8 *func_8003E2E0(u8 *arg0) {
    u8 buf[8];
    u8 *cfg;
    u8 *g;
    u8 *q;
    u8 *g2;
    u8 v;
    f32 f;
    s32 i;

    func_80039500();
    *(u8 **)(arg0 + 0x2C) = D_8001A430;
    func_800A72C0(arg0 + 0x74);
    func_800B198C(arg0 + 0x2B4);
    func_800B198C(arg0 + 0x2C8);
    func_800B198C(arg0 + 0x2DC);
    func_800B198C(arg0 + 0x2F0);
    func_800B198C(arg0 + 0x304);
    func_800B198C(arg0 + 0x318);
    func_800B198C(arg0 + 0x32C);
    *(u8 **)(arg0 + 0x33C) = D_8001A2F0;
    func_800B198C(arg0 + 0x340);
    *(u8 **)(arg0 + 0x350) = D_8001A2F0;
    func_800B198C(arg0 + 0x354);
    *(u8 **)(arg0 + 0x364) = D_8001A2F0;
    func_800B198C(arg0 + 0x368);
    *(u8 **)(arg0 + 0x378) = D_8001A2F0;
    func_800B198C(arg0 + 0x37C);
    func_800B198C(arg0 + 0x390);
    q = D_800D3F34;
    func_8003A69C(q);
    func_8003A8B4(q);
    f = D_800D4814;
    D_800ECEF0 = f;
    D_800EA9B0 = f;
    cfg = D_800D0FC0;
    arg0[0x60] = cfg[0x14];
    g = D_800DE9F4;
    v = g[0x866];
    cfg[0x1B] = v;
    arg0[0x61] = v;
    arg0[0x62] = v;
    v = g[0x868];
    cfg[0x1D] = v;
    arg0[0x64] = v;
    arg0[0x63] = v;
    v = g[0x86A];
    cfg[0x1C] = v;
    arg0[0x65] = v;
    arg0[0x66] = D_800D4770[v];
    if (cfg[0x16] == 0x1D || ENT(g, cfg[0x14]).x8 == 0) {
        arg0[0x61] = 0;
        arg0[0x62] = 0;
        arg0[0x65] = 0;
        arg0[0x64] = 0;
        arg0[0x63] = 0;
    }
    g2 = D_800DE9F4;
    *(s32 *)(arg0 + 0x68) = ENT(g2, arg0[0x60]).x8 >= D_800D4D80[arg0[0x60]].e[arg0[0x61]].x8;
    if (*(s32 *)(arg0 + 0x68)) {
        *(s32 *)(arg0 + 0x6C) = D_800D4D80[arg0[0x60]].e[arg0[0x61]].x0;
    } else {
        *(s32 *)(arg0 + 0x6C) = 0x40;
    }
    func_8003E910(arg0);
    arg0[0x67] = 0;
    func_8008BB50(buf);
    func_800A73EC(arg0 + 0x74, 0x501);
    func_8008B490(buf, arg0 + 0x74, 0x501);
    arg0[0x84] = 0;
    func_800A7AF8(arg0 + 0x74, 0x87, 0xC2, 0xF3, 0xFF);
    func_800A7B10(arg0 + 0x74, 0x87, 0xC2, 0xF3, 0xFF);
    *(s16 *)(arg0 + 0x70) = 0x8C;
    arg0[0x72] = 0;
    func_800B1A80(arg0 + 0x318, 0x11);
    *(s32 *)(arg0 + 0x31C) = 1;
    func_800B1A80(arg0 + 0x32C, *(s32 *)(arg0 + 0x6C));
    *(s32 *)(arg0 + 0x330) = 1;
    *(s32 *)(arg0 + 0x344) = 1;
    *(s32 *)(arg0 + 0x358) = 1;
    func_800B1A80(arg0 + 0x37C, D_800D4774[arg0[0x65]]);
    *(s32 *)(arg0 + 0x380) = 1;
    func_800B1A80(arg0 + 0x368, D_800D4778[arg0[0x64]]);
    *(s32 *)(arg0 + 0x36C) = 1;
    func_800B1A80(arg0 + 0x390, D_800D47C8[arg0[0x67]]);
    *(s32 *)(arg0 + 0x394) = 1;
    func_800B1A80(arg0 + 0x2C8, 0x8F);
    *(s32 *)(arg0 + 0x2CC) = 1;
    func_800B1A80(arg0 + 0x2DC, 0x8D);
    *(s32 *)(arg0 + 0x2E0) = 1;
    func_800B1A80(arg0 + 0x2F0, 0x8E);
    *(s32 *)(arg0 + 0x2F4) = 1;
    func_800B1A80(arg0 + 0x304, 0x94);
    *(s32 *)(arg0 + 0x308) = 1;
    func_800B1A80(arg0 + 0x2B4, 0x94);
    *(s32 *)(arg0 + 0x2B8) = 1;
    func_800B231C(arg0 + 0x2B4, 0x4B, 0x4B, 0x4B, 0xFF);
    *(f32 *)(arg0 + 0x30) = 0.949999988f;
    *(s16 *)(arg0 + 0x34) = 0x8B;
    *(s16 *)(arg0 + 0x36) = 0x8B;
    *(s16 *)(arg0 + 0x38) = 0x127;
    *(s32 *)(arg0 + 0x3A8) = 0;
    i = arg0[0x60];
    arg0[0x3A4] = func_8003FE90(i, ENT(D_800DE9F4, i).x8);
    func_8008BB2C(buf, 2);
    return arg0;
}
