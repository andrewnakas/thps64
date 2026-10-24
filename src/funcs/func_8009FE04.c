#include "common.h"

s32 func_800057E4(char *, char *, ...);
extern char D_800209C4[];
extern char D_800209D0[];
extern char D_800209DC[];
extern char D_800209E8[];
extern char D_800209EC[];

void func_8009FE04(f32 t, char *buf, s32 mode) {
    char *fmt;
    char *pad;
    s32 min;

    switch (mode) {
    case 0:
        fmt = D_800209C4;
        break;
    case 1:
        fmt = D_800209D0;
        break;
    case 2:
        fmt = D_800209DC;
        break;
    }
    min = t / 60.0f;
    t = t - min * 60.0f;
    if (t < 9.95f) {
        pad = D_800209E8;
    } else {
        pad = D_800209EC;
    }
    func_800057E4(buf, fmt, min, pad, t);
}
