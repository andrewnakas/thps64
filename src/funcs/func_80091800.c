#include "common.h"

s32 func_8003A1AC(s32, s32, s32);
s32 func_8003A268();
s32 func_80043F84(s32, s32);
s32 func_80043FA8(u8 *);
s32 func_8006EEF0();
s32 func_80096020(u8 *, s32);
s32 func_800960E8(u8 *, s32);
s32 func_80049034(s32, s32, s32);
extern u8 D_800D49E0[];
extern s32 D_800D60D0;
extern s32 D_800DDE38;
extern s32 D_800DDE3C;
extern s32 D_800DE7E0;
extern s32 D_800E8FA8;
extern s32 D_800E9038;
extern u8 *D_800E9054;
extern s32 D_800E91C4;

void func_80091800(void) {
    u8 *base;
    s32 name;
    s32 i;
    s32 sel;
    u8 *e;
    u8 *p;
    u8 *b;
    u8 *e2;
    s32 j;
    s32 v;
    u16 *f;
    s32 *pn;

    pn = &D_800DDE38;
    base = D_800E9054;
    name = *pn;
    i = 0;
    if (i < base[5]) {
        e = base;
        do {
            if (func_80049034(name, *(s32 *)(e + 0x14), -1) != 0) {
                sel = i;
                goto found;
            }
            e += 0x18;
            i++;
        } while (i < base[5]);
    }
    sel = 0;
found:
    b = D_800E9054;
    b[2] = sel;
    for (j = 0, e2 = b; j < 15; j++) {
        f = (u16 *)(e2 + 0x1A);
        *f = (j == b[2]) ? *(u16 *)(e2 + 0x1C) : *(u16 *)(e2 + 0x1E);
        *(u16 *)(e2 + 0x18) = *(u16 *)(e2 + 0x1A);
        e2 += 0x18;
    }
    v = 5;
    D_800E8FA8 = v;
    D_800DE7E0 = v;
    p = D_800D49E0;
    func_80043FA8(p);
    func_80043FA8(p + 0x18C);
    D_800E9038 = 1;
    func_800960E8(D_800E9054, func_80096020(D_800E9054, D_800DDE3C) & 0xFF);
    func_8006EEF0();
    func_80043F84(0, 0);
    func_80043F84(0, 1);
    func_8003A268();
    func_8003A1AC(0x17, 0x1000, 0);
    D_800D60D0 = 0;
    D_800E91C4 = 0;
}
