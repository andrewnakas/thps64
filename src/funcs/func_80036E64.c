#include "common.h"

void func_80033A58(void);
void func_80036FA4(s32);
void func_8003A2DC(void);
void func_8003A3E4(s32 *);
void func_8006140C(void);
void func_8008B3AC(s32);
void func_800964CC(void);
extern u8 D_800D0FE3;
extern s32 D_800D3E98;
extern s32 D_800D3F34[];
extern s32 D_800DE7CC;
extern s32 D_800DE804;
extern s32 D_800DE9A8;
extern s32 D_800DE9D0;

s32 func_80036E64(s32 arg0) {
    s32 a;
    s32 b;
    s32 old;
    s32 cur;
    s32 *pa = &D_800D3E98;
    s32 *pb = &D_800DE804;

    old = *pa;
    cur = *pb;
    if (old != cur) {
        *pa = cur;
    }
    if (cur == 0) {
        return 0;
    }
    func_8003A2DC();
    if (D_800D0FE3 != 2) {
        a = 4;
        func_800964CC();
    } else {
        a = 0x17;
    }
    if (D_800DE9A8 == 2) {
        b = 0xC;
    } else {
        b = 0xB;
    }
    D_800DE9D0 = 0;
    if (D_800D0FE3 != 8) {
        func_8003A3E4(D_800D3F34);
    }
    switch (D_800DE804) {
    case 11:
        return 0xE;
    case 10:
        return b;
    case 12:
        return 0x11;
    case 2:
    case 3:
    case 4:
        return 4;
    case 8:
        return a;
    case 7:
        func_80033A58();
        func_8008B3AC(1);
        func_8006140C();
        D_800DE7CC = 0;
        func_80036FA4(arg0);
        return 0;
    }
}
