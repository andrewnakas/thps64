/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0xC];
    s32 vC;
    s32 v10;
    u8 pad14[0x78 - 0x14];
} E40A18;

typedef struct {
    u8 pad0[0x30];
    s32 v30;
    s16 v34;
    s16 v36;
    s32 v38;
    u8 pad3C[0x2B4 - 0x3C];
    u8 b2B4;
    u8 b2B5;
} O40A18;

s32 func_8004156C(O40A18 *, s32 *, s32);
void func_800416F4(O40A18 *, s32);
void func_80039E60(s32, s32, s32);
s32 func_800B4264(s32, s32);
void func_800A9460(void *, s32, f32, s32);
void func_8007F1F0(void);
void func_80041C14(O40A18 *);
void func_80041D28(O40A18 *);
void func_800406F0(O40A18 *);
extern s32 D_800C0E20;
extern u8 D_800D0FC0[];
extern E40A18 D_800D5C1C[];
extern s32 D_800DE7A0;
extern u8 D_800EA9C0[];

s32 func_80040A18(O40A18 *o) {
    s32 ret;
    s32 c2, c3;
    s32 r;
    s32 hit;
    s32 v;

    ret = 0;
    c2 = D_800D0FC0[2];
    c3 = D_800D0FC0[3];
    r = func_8004156C(o, &o->v30, c2);
    if (o->v30 == 1) {
        o->v34 = 3;
        o->v36 = 0;
        o->b2B4 = 1;
        o->b2B5 = 1;
        func_80039E60(0x90, 0x2710, ret);
    }
    if (o->v30 == -1) {
        o->v34 = 0;
        o->v36 = 3;
        o->b2B4 = 1;
        o->b2B5 = 1;
        func_80039E60(0x90, 0x2710, 0);
    }
    func_800416F4(o, r);
    hit = 0;
    if (func_800B4264(c2, 0x8000) || func_800B4264(c3, 0x8000)) {
        hit = 1;
    }
    if (hit) {
        if (D_800D5C1C[D_800C0E20].v10 == 0) {
            o->v38 = 0;
            func_800416F4(o, D_800C0E20 + 0x32);
            ret = 0x11;
        } else {
            func_80039E60(0x92, 0x2710, 0);
        }
    }
    o->v38 = r;
    hit = 0;
    if (func_800B4264(c2, 0x4000) || func_800B4264(c3, 0x4000)) {
        hit = 1;
    }
    if (hit) {
        func_80039E60(0x93, 0x2710, 0);
        v = D_800DE7A0;
        if (v == 7 || v == 8 || v == 5) {
            ret = 0xC;
        } else {
            ret = 0xB;
        }
    }
    if (ret == 0x11) {
        func_80039E60(0x91, 0x2710, 0);
        func_800A9460(D_800EA9C0, 0, 0.0f, -1);
        if (D_800D5C1C[D_800C0E20].vC != 0) {
            func_8007F1F0();
        }
    }
    func_80041C14(o);
    func_80041D28(o);
    func_800406F0(o);
    return ret;
}
