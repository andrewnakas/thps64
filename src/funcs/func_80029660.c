#include "common.h"

s32 func_80029B84(void *, s32);
void func_80039500(void);
void func_8003A880(void *);
void func_8008B490(void *, void *, s32);
void func_8008BB2C(void *, s32);
void func_8008BB50(void *);
void func_800A5F10(void *);
void func_800A72C0(void *);
void func_800A73EC(void *, s32);
void func_800A773C(void *, f32, f32);
void func_800A7AF8(void *, s32, s32, s32, s32);
void func_800A7B10(void *, s32, s32, s32, s32);
void func_800A9220(void *, s32, f32);
void func_800B198C(void *);
extern s32 D_80019060;
extern u8 D_800D0FD6;
extern s32 D_800D3F34;
extern s32 D_800EA9C0;

typedef struct {
    u8 pad0[0x2C];
    void *p2C;
    u8 a30[0x14];
    s32 v44;
    u8 a48[0x20];
    u8 a68[0x10];
    s8 b78;
    u8 pad79[0x2A8 - 0x79];
    s8 b2A8;
    u8 pad2A9[3];
    s32 v2AC;
    s32 v2B0;
    f32 f2B4;
    s32 v2B8;
    s32 v2BC;
    s32 v2C0;
    s32 v2C4;
} S80029660;

S80029660 *func_80029660(S80029660 *arg0) {
    s32 sp18;
    s32 *p;
    f32 f;
    void *q;

    func_80039500();
    arg0->p2C = &D_80019060;
    func_800B198C(arg0->a30);
    func_800A5F10(arg0->a48);
    func_800A72C0(arg0->a68);
    func_8003A880(&D_800D3F34);
    p = &D_800EA9C0;
    f = 2.0f;
    func_800A9220(p, 3, f);
    if (D_800D0FD6 == 0) {
        func_800A9220(p, 3, f);
    } else {
        func_800A9220(p, 4, f);
    }
    q = arg0->a68;
    func_8008BB50(&sp18);
    func_800A73EC(q, 0x4C6);
    func_8008B490(&sp18, q, 0x4C6);
    arg0->b78 = 1;
    func_800A7AF8(q, 0xFC, 0xC2, 0x6B, 0xFF);
    func_800A7B10(q, 0x98, 0x5E, 7, 0xFF);
    func_800A773C(q, 1.4f, 2.0f);
    arg0->b2A8 = -1;
    arg0->v44 = func_80029B84(arg0, 0);
    arg0->v2AC = 0;
    arg0->v2B0 = 0;
    arg0->v2B8 = -0xA;
    arg0->f2B4 = 40.0f;
    arg0->v2BC = 0x32;
    arg0->v2C4 = 0;
    arg0->v2C0 = 0;
    func_8008BB2C(&sp18, 2);
    return arg0;
}
