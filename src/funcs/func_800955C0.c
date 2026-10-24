#include "common.h"

s32 func_8003A1AC(s32, s32, s32);   /* extern */
s32 func_8003A268();                            /* extern */
s32 func_80043F84(s32, s32);            /* extern */
s32 func_80043FA8(u8 *);                   /* extern */
s32 func_8006EEF0();                            /* extern */
s32 func_80096020(s32, s32);                        /* extern */
s32 func_800960E8(s32, s32);                    /* extern */
extern u8 D_800D49E0[];
extern s32 D_800D60D0;
extern s32 D_800DDE3C;
extern s32 D_800DE7E0;
extern s32 D_800E8FA8;
extern s32 D_800E9038;
extern s32 D_800E9054;
extern s32 D_800E91C4;

void func_800955C0(void) {
    u8 *p;
    s32 v;

    v = 0x22;
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
