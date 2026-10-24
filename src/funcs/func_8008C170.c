/* cflags: -fexpensive-optimizations */
#include "common.h"

typedef struct {
    u8 pad0[0x1C];
    void *unk1C;
} Skater;

void func_80039E60(s32, s32, s32);
void func_8003A268(void);
void func_80043F84(s32, s32);
void func_80043FA8(void *);
void func_8006CFB4(void *);
void func_8006EEF0(void);
s32 func_80096020(s32, s32);
void func_800960E8(s32, s32);
extern u8 D_800D49E0[];
extern s32 D_800D60D0;
extern Skater *D_800D61A8;
extern s32 D_800DC618;
extern s32 D_800DC6D8;
extern s32 D_800DDE3C;
extern s32 D_800DE7E0;
extern s32 D_800E8FA8;
extern s32 D_800E9054;
extern s32 D_800E91C8;
extern s32 D_800E91CC;
extern s32 D_800E91D0;

void func_8008C170(void) {
    void *other;
    s32 v;

    D_800E91C8 = 0;
    D_800E91CC = 0;
    D_800E91D0 = 0;
    other = D_800D61A8->unk1C;
    if (D_800DC618 != 0) {
        func_8006CFB4(D_800D61A8);
    }
    if (other != NULL && D_800DC6D8 != 0) {
        func_8006CFB4(other);
    }
    v = 0x13;
    D_800E8FA8 = v;
    D_800DE7E0 = v;
    func_80043FA8(D_800D49E0);
    func_80043FA8(D_800D49E0 + 0x18C);
    func_800960E8(D_800E9054, func_80096020(D_800E9054, D_800DDE3C) & 0xFF);
    func_8006EEF0();
    func_80043F84(0, 0);
    func_80043F84(0, 1);
    func_8003A268();
    func_80039E60(0x17, 10000, 0);
    D_800D60D0 = 0;
}
