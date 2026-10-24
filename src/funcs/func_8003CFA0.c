/* cflags: -fexpensive-optimizations */
#include "common.h"

void func_80027F60(s32);
void func_8003D410(u8 *);
void func_8003D674(u8 *);
void func_800A602C(void *);
void func_800A7AF8(void *, s32, s32, s32, s32);
void func_800A7B10(void *, s32, s32, s32, s32);
void func_800A7B50(void *, f32, f32, s32, s32, s32, s32);
void func_800A773C(void *, f32, f32);
void func_800A8678(void *, void *, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);
void func_800B1AC4(void *, f32, f32, f32, f32);
void func_800BE3D8(void);
void func_800BE5A4(void);
void func_800BE7D0(s32, s32, s32, s32, s32, s32, s32, s32);
void func_800BEF70(s32, s32, s32);

typedef struct {
    u8 pad0[0x2C];
    char *name;
    s32 x30;
    s32 x34;
    s32 x38;
    s32 x3C;
    s32 x40;
    s32 x44;
    u8 pad48[0x154 - 0x48];
} Row8003CFA0;

typedef struct {
    u8 pad0[0x18];
    s32 x18;
} Ent8003CFA0;

extern char D_8001A218[];
extern u8 D_800D0FC0[];
extern u8 D_800D0FD6;
extern Row8003CFA0 D_800D4D80[];
extern s32 D_800DE7A0;
extern Ent8003CFA0 D_800DE9F4[];
extern u8 D_800DF258;
extern s32 D_800E9290;

#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))

void func_8003CFA0(u8 *arg0) {
    u8 *m;
    u8 *t;
    Row8003CFA0 *row;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 f;
    u8 *cfg;
    u8 *g;
    Row8003CFA0 *r;
    f32 k;
    f32 k3;

    func_800BE3D8();
    func_800A602C(arg0 + 0x4F8);
    if (S32(arg0, 0x518) < 4) {
        S32(arg0, 0x518)++;
        func_800BEF70(0, 0, 0);
    } else {
        func_800BE7D0(0, 0x280, 0x177, 0x1A9, 0, 0, 0, 0xFF);
    }
    func_800B1AC4(arg0 + 0x38, 40.0f, 15.0f, 0.925f, 1.89999998f);
    m = arg0 + 0x4C;
    func_80027F60(S32(arg0, 0x4F4));
    k = 1.29999995f;
    func_800A773C(m, k, k);
    func_800A8678(m, arg0 + 0x4CC, (f32)*(s16 *)(arg0 + 0x4EC), 409.0f, 0, 0, k3 = 3.0f, 0xAA, 0x50, 1, 0, 0, 0, 0);
    if (D_800D0FD6 != 0x1D && (g = (u8 *)D_800DE9F4, *(s32 *)(g + S32(arg0, 0x30) * 20 + 0x18) == 0) && S32(arg0, 0x4F0) != 1 && D_800DE7A0 == 1) {
        func_800A7AF8(m, 0xC8, 0x32, 0x32, 0xFF);
        func_800A7B10(m, 0xC8, 0x32, 0x32, 0xFF);
        func_800A773C(m, 0.699999988f, k);
        func_800A8678(m, D_8001A218, k = 495.0f, 290.0f, 2, 0, k3, 0xAA, 0x50, 1, 0, 0, 0, 0);
        func_800A8678(m, D_800D4D80[S32(arg0, 0x30)].name, k, 267.0f, 2, 0, k3, 0xAA, 0x50, 1, 0, 0, 0, 0);
        func_800A7AF8(m, 0x87, 0xC2, 0xF3, 0xFF);
        func_800A7B10(m, 0x87, 0xC2, 0xF3, 0xFF);
    }
    r = D_800D4D80;
    row = &r[S32(arg0, 0x30)];
    b = row->x34;
    a = row->x30;
    c = row->x38;
    d = row->x3C;
    e = row->x40;
    f = row->x44;
    t = arg0 + 0x28C;
    func_800A7B50(t, *(u16 *)(arg0 + 0x7AC), 186.0f, a, 1, 0, 0);
    func_800A7B50(t, *(u16 *)(arg0 + 0x7AC), 166.0f, b, 1, 0, 0);
    func_800A7B50(t, *(u16 *)(arg0 + 0x7AC), 146.0f, c, 1, 0, 0);
    func_800A7B50(t, *(u16 *)(arg0 + 0x7AC), 126.0f, d, 1, 0, 0);
    func_800A7B50(t, *(u16 *)(arg0 + 0x7AC), 106.0f, e, 1, 0, 0);
    func_800A7B50(t, *(u16 *)(arg0 + 0x7AC), 86.0f, f, 1, 0, 0);
    D_800DF258 = (cfg = D_800D0FC0)[0x14] = arg0[0x33];
    D_800E9290 = cfg[0x14];
    func_8003D410(arg0);
    func_8003D674(arg0);
    func_800BE5A4();
}
