/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0x30];
    void *w[6];
    u8 pad48[0x154 - 0x48];
} Row2F220;

typedef struct {
    u8 pad0[0x14];
    u8 b14;
    u8 b15;
} Ctl2F220;

typedef struct {
    u8 pad0[0x864];
    u8 b864;
    u8 b865;
} Big2F220;

typedef struct {
    u8 pad0[0x6C];
    u8 a6C[0x14];
    u8 a80[0x2C0 - 0x80];
    u8 a2C0[0x500 - 0x2C0];
    u8 a500[0x740 - 0x500];
    char s740[0x20];
    char s760[0x20];
    s16 h780;
    s16 h782;
    u8 pad784[0x78C - 0x784];
    s32 v78C;
    s32 v790;
    u8 pad794[0x7A0 - 0x794];
    s32 v7A0;
    u16 h7A4;
    u16 h7A6;
    s32 v7A8;
    s32 v7AC;
    s32 v7B0;
    s32 v7B4;
} Obj2F220;

void func_80027F60(s32);
void func_8002F904(Obj2F220 *);
void func_800A7B50(void *, f32, f32, void *, s32, s32, s32);
void func_800A8678(void *, char *, f32, f32, s32, s32, f32, s32, s32, s32, s32, s32, s32, s32);
void func_800B1AC4(void *, f32, f32, f32, f32);
void func_800BE3D8(void);
void func_800BE5A4(void);
void func_800BE7D0(s32, s32, s32, s32, s32, s32, s32, s32);
void func_800BEF70(s32, s32, s32);
extern char D_80019A20[];
extern char D_80019A28[];
extern Ctl2F220 D_800D0FC0;
extern Row2F220 D_800D4D80[];
extern Big2F220 D_800DE9F4;

void func_8002F220(Obj2F220 *o) {
    func_800BE3D8();
    if (o->v7A0 < 4) {
        o->v7A0++;
        func_800BEF70(0, 0, 0);
    } else {
        func_800BE7D0(0, 0x280, 0x177, 0x1A9, 0, 0, 0, 0xFF);
    }
    func_800B1AC4(o->a6C, 40.0f, 15.0f, 0.925f, 1.9f);
    func_80027F60(o->v7B0);
    func_80027F60(o->v7B4);
    func_800A8678(o->a80, o->s740, o->h780, 395.0f, 0, 2, 3.0f, 0xAA, 0x50, 1, 0, 0, 0, 0);
    func_800A8678(o->a80, o->s760, o->h782, 395.0f, 0, 2, 3.0f, 0xAA, 0x50, 1, 0, 0, 0, 0);
    func_800A7B50(o->a500, o->h7A4, 159.0f, D_800D4D80[o->v78C].w[0], 1, 0, 0);
    func_800A7B50(o->a500, o->h7A4, 144.0f, D_800D4D80[o->v78C].w[1], 1, 0, 0);
    func_800A7B50(o->a500, o->h7A4, 129.0f, D_800D4D80[o->v78C].w[2], 1, 0, 0);
    func_800A7B50(o->a500, o->h7A4, 114.0f, D_800D4D80[o->v78C].w[3], 1, 0, 0);
    func_800A7B50(o->a500, o->h7A4, 99.0f, D_800D4D80[o->v78C].w[4], 1, 0, 0);
    func_800A7B50(o->a500, o->h7A4, 84.0f, D_800D4D80[o->v78C].w[5], 1, 0, 0);
    func_800A7B50(o->a500, o->h7A6, 159.0f, D_800D4D80[o->v790].w[0], 1, 0, 0);
    func_800A7B50(o->a500, o->h7A6, 144.0f, D_800D4D80[o->v790].w[1], 1, 0, 0);
    func_800A7B50(o->a500, o->h7A6, 129.0f, D_800D4D80[o->v790].w[2], 1, 0, 0);
    func_800A7B50(o->a500, o->h7A6, 114.0f, D_800D4D80[o->v790].w[3], 1, 0, 0);
    func_800A7B50(o->a500, o->h7A6, 99.0f, D_800D4D80[o->v790].w[4], 1, 0, 0);
    func_800A7B50(o->a500, o->h7A6, 84.0f, D_800D4D80[o->v790].w[5], 1, 0, 0);
    D_800D0FC0.b14 = D_800DE9F4.b864 = o->v78C;
    D_800D0FC0.b15 = D_800DE9F4.b865 = o->v790;
    if (o->v7A8) {
        func_800A8678(o->a2C0, D_80019A20, 233.0f, 320.0f, 2, 2, 3.0f, 0xAA, 0x50, 1, 0, 0, 0, 0);
        func_800A8678(o->a2C0, D_80019A28, 233.0f, 300.0f, 2, 2, 3.0f, 0xAA, 0x50, 1, 0, 0, 0, 0);
    }
    if (o->v7AC) {
        func_800A8678(o->a2C0, D_80019A20, 499.0f, 320.0f, 2, 2, 3.0f, 0xAA, 0x50, 1, 0, 0, 0, 0);
        func_800A8678(o->a2C0, D_80019A28, 499.0f, 300.0f, 2, 2, 3.0f, 0xAA, 0x50, 1, 0, 0, 0, 0);
    }
    func_8002F904(o);
    func_800BE5A4();
}
