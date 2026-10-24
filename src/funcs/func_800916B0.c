/* cflags: -fexpensive-optimizations */
#include "common.h"

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0x68];
} Player;

s32 func_80081F04(void);
void func_8003A3E4(void *);
void func_80043FA8(void *);
s32 func_80096020(s32, s32);
void func_800960E8(s32, s32);
void func_8006EEF0(void);
void func_80043F84(s32, s32);
void func_8003A268(void);
void func_8003A1AC(s32, s32, s32);
extern s32 D_800E929C;
extern s32 D_800C0E20;
extern Player D_800D5C1C[];
extern s32 D_800DE7A0;
extern u8 D_800D0FE3;
extern u8 D_800D3F34[];
extern s32 D_800E8FA8;
extern s32 D_800DE7E0;
extern u8 D_800D49E0[];
extern s32 D_800E9038;
extern s32 D_800E9054;
extern s32 D_800DDE3C;
extern s32 D_800D60D0;
extern s32 D_800E91C4;

void func_800916B0(void) {
    s32 v;

    if (D_800E929C == 0) {
        if (D_800D5C1C[D_800C0E20].unkC != 0) {
            if (D_800DE7A0 == 1 && func_80081F04() == 0) {
                v = 0x19;
            } else {
                goto other;
            }
        } else {
            goto other;
        }
    } else {
    other:
        if (D_800E929C == 0) {
            v = 0xF;
        } else {
            v = 0x10;
        }
    }
    if (D_800D0FE3 != 8) {
        func_8003A3E4(D_800D3F34);
    }
    D_800E8FA8 = v;
    D_800DE7E0 = v;
    func_80043FA8(D_800D49E0);
    func_80043FA8(D_800D49E0 + 0x18C);
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
