#include "common.h"

void func_8006EE1C(void *, void *, s32, s32, s32);
extern s32 D_800DE93C;
extern s32 D_800DE7A8;
extern s32 D_800DDDB8;
extern s32 D_800DDDBC;
extern char D_800DC9FC[];

void func_80045F08(u8 **arg0) {
    s16 x;
    s16 y;
    s16 *px;
    s16 *py;
    s32 idx;
    s32 g;
    s32 f;
    char *t;

    g = D_800DE93C;
    f = *(u16 *)(*arg0 + 0xA24);
    idx = g * 2 + f;
    px = &x;
    py = &y;
    switch (idx) {
    case 0:
    case 1:
        *px = 0;
        *py = 0;
        break;
    case 4:
        *px = 0;
        *py = 0x3C;
        break;
    case 6:
        *px = 0x80;
        *py = 0x3C;
        break;
    case 2:
        *px = 0x80;
        *py = 0;
        break;
    case 5:
        *px = 0;
        *py = -0x3C;
        break;
    case 7:
        *px = -0x80;
        *py = -0x3C;
        break;
    case 3:
        *px = -0x80;
        *py = 0;
        break;
    }
    if ((s32)*arg0 == D_800DE7A8) {
        func_8006EE1C((void *)D_800DDDB8, D_800DC9FC, 0, x, y);
    } else {
        func_8006EE1C((void *)D_800DDDBC, t = D_800DC9FC, 0, x, y);
    }
}
