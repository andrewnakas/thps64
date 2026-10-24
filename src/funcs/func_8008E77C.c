/* cflags: -fexpensive-optimizations */
#include "common.h"

void func_800057E4(char *, char *, ...);
s32 func_8006DF40(s32, s32, char *, s32, s32, s32, s32);
void func_8006F1A8(u8, u8, u8, s32);
void func_8006F274(s32);
extern char D_8001FE7C[];
extern char D_8001FE84[];
extern char D_8001FE8C[];
extern char D_8001FE94[];
extern char D_8001FE9C[];
extern char D_8001FEA4[];
extern char D_8001FEAC[];

s32 func_8008E77C(u8 *o, s32 x, s32 y, u8 r, u8 g, u8 b, s32 v6, s32 v7, s32 v8, s32 v9) {
    char buf[0x10];
    s32 x2;

    func_8006F1A8(r, g, b, 0);
    func_8006F274(1);
    func_8006DF40(x + 0x14, y, D_8001FE7C, 0, 0, 0x100, 0);
    func_8006DF40(x + 0x14, y + 0x11, D_8001FE84, 0, 0, 0x100, 0);
    func_8006DF40(x + 0x14, y + 0x33, D_8001FE8C, 0, 0, 0x100, 0);
    func_8006DF40(x + 0x14, y + 0x44, D_8001FE94, 0, 0, 0x100, 0);
    func_8006DF40(x + 0x14, y + 0x55, D_8001FE9C, 0, 0, 0x100, 0);
    func_8006DF40(x + 0x14, y + 0x66, D_8001FEA4, 0, 0, 0x100, 0);
    func_8006F274(2);
    func_800057E4(buf, D_8001FEAC, *(s32 *)(o + 0x2E8));
    x2 = x + 0x88;
    func_8006DF40(x2, y, buf, 0, 0, 0x100, 0);
    func_800057E4(buf, D_8001FEAC, *(s32 *)(o + 0x2EC));
    func_8006DF40(x2, y + 0x11, buf, 0, 0, 0x100, 0);
    func_800057E4(buf, D_8001FEAC, v9);
    func_8006DF40(x2, y + 0x33, buf, 0, 0, 0x100, 0);
    func_800057E4(buf, D_8001FEAC, v6);
    func_8006DF40(x2, y + 0x44, buf, 0, 0, 0x100, 0);
    func_800057E4(buf, D_8001FEAC, v7);
    func_8006DF40(x2, y + 0x55, buf, 0, 0, 0x100, 0);
    func_800057E4(buf, D_8001FEAC, v8);
    return func_8006DF40(x2, y + 0x66, buf, 0, 0, 0x100, 0);
}
