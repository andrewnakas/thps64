/* cflags: -Wa,-no-m4100 */
#include "common.h"

void func_8006DEB0(void *, s32);
void func_8006EB3C(s32);
s32 func_8006EC3C(void *);
void func_8006EC54(void *, s32);
void func_8006F178(s32, s32, void *, s32, s32, s32);
void func_8006F1A8(s32, s32, s32, s32);
s32 func_8006F204();
void func_8006F23C(s32, s32, s32);
void func_8006F274(s32);
extern s32 D_800DC618;
extern s32 D_800DE7A0;
extern u8 *D_800DE7A8;
extern s32 D_800DE820;
extern s32 D_800DE9A8;
extern s32 D_800DE9B8;
extern s32 D_800DF3EC;

typedef struct {
    u8 pad0[0x14C];
    u32 state;
    s32 timer;
    u8 pad154[4];
    s32 x158;
} Banner80045030;

void func_80045030(Banner80045030 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    s32 r;
    s32 g;
    s32 b;
    s32 w;
    s32 h;
    s32 n;
    s32 lh;
    s32 ret;
    s32 t;
    u8 *p;

    func_8006EB3C(D_800DE9B8);
    if ((D_800DC618 ^ 2) == 0 || D_800DF3EC == 0) {
        return;
    }
    func_8006F1A8(0x80, 0x80, 0x80, 0);
    if (D_800DE7A0 == 8) {
        if (arg1 == D_800DE7A8) {
            r = 0x50;
            g = r;
            b = 0x80;
        } else {
            r = 0x80;
            g = 0x50;
            b = g;
        }
        func_8006F1A8(r, g, b, 0);
    }
    func_8006F274(0);
    if (D_800DE9A8 == 1) {
        w = 0xBC;
        h = 0x100;
    } else {
        w = 0xBC;
        h = w;
    }
    switch (arg0->state) {
    case 0:
        return;
    case 1:
        t = arg0->timer;
        n = 5;
        func_8006F23C((h - 0x3C) * t / n + 0x3C, w, h);
        if (arg0->timer == n) {
            arg0->timer = 0;
            arg0->state = 2;
        }
        break;
    case 2:
        t = arg0->timer;
        n = 5;
        func_8006F23C(h + (w - h) * t / n, w, h);
        if (arg0->timer == n) {
            arg0->timer = 0;
            arg0->state = 3;
        }
        break;
    case 3:
        func_8006F23C(w, w, h);
        if (arg0->timer == 30) {
            arg0->timer = 0;
            arg0->state = 4;
        }
        if (arg0->x158 != 0) {
            arg0->state = 5;
            arg0->x158 = 0;
        }
        break;
    case 4:
        t = arg0->timer;
        n = 10;
        func_8006F23C(w + -w * t / n, w, h);
        if (arg0->timer == n) {
            arg0->timer = 0;
            arg0->state = 0;
        }
        if (arg0->x158 != 0) {
            arg0->x158 = 0;
        }
        break;
    case 5:
        break;
    }
    if (arg0->state == 5) {
        func_8006DEB0(arg1 + 0xB80, 1);
    } else {
        func_8006EC54(arg1 + 0xB80, func_8006F204() & 0xFFFF);
    }
    if (D_800DE820 == 0) {
        arg0->timer++;
    }
    t = func_8006F204() * 13;
    lh = t / 188;
    p = arg1 + 0xE70;
    if (*p != 0) {
        func_8006F178(arg2 & 0xFFFF, arg3 & 0xFFFF, p, 0, 0, 0x100);
        arg3 -= lh;
    }
    p = arg1 + 0xE0C;
    if (*p != 0) {
        func_8006F178(arg2 & 0xFFFF, arg3 & 0xFFFF, p, 0, 0, 0x100);
        arg3 -= lh;
    }
    func_8006F178(arg2 & 0xFFFF, arg3 & 0xFFFF, arg1 + 0xDA8, 0, 0, 0x100);
    ret = func_8006EC3C(arg1 + 0xB80);
    if (arg0->state == 5) {
        func_8006DEB0(arg1 + 0xB80, 0);
        if (ret == 0) {
            *(s32 *)(arg1 + 0xB68) = 0;
        }
    }
}
