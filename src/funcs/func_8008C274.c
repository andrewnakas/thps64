/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */

#include "common.h"

typedef struct {
    u8 name[4];
    u8 unk4;
    u8 pad5[3];
    u32 score;
} HiEnt;

typedef struct {
    u8 pad0[0xE4];
    HiEnt tbl[20][8];
    u8 pad864[0x9B0 - 0xE4 - 20 * 0x60];
    u8 unk9B0[4];
} S9F4;

typedef struct {
    u8 pad0[0x1C];
    void *unk1C;
    u8 pad20[0xA20 - 0x20];
    u32 unkA20;
} S61A8;

typedef struct {
    u8 pad0[0x3E3];
    u8 unk3E3;
    u8 pad3E4[0x9F0 - 0x3E4];
    s32 unk9F0;
} SE7A8;

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0x78 - 0x10];
} E78;

void func_800057E4(void *, void *);
void func_80039E60(s32, s32, s32);
void func_8003A1AC(s32, s32, s32);
void func_8003A268(void);
void func_80043F84(s32, s32);
void func_80043FA8(void *);
void func_8006CFB4(void *);
void func_8006EC84(void *);
void func_8006EEF0(void);
s32 func_80096020(s32, s32);
void func_800960E8(s32, s32);
extern s32 D_800C0E20;
extern u8 D_800D49E0[];
extern E78 D_800D5C1C[];
extern s32 D_800D60D0;
extern S61A8 *D_800D61A8;
extern s32 D_800DC618;
extern s32 D_800DC6D8;
extern s32 D_800DDE3C;
extern s32 D_800DE7A0;
extern SE7A8 *D_800DE7A8;
extern s32 D_800DE7E0;
extern s32 D_800DE9A8;
extern s32 D_800DE9AC;
extern s32 D_800DE9E8;
extern S9F4 D_800DE9F4;
extern u8 D_800E8E98[];
extern s32 D_800E8EE0;
extern s32 D_800E8F98;
extern s32 D_800E8F9C;
extern s32 D_800E8FA8;
extern s32 D_800E9038;
extern s32 D_800E9054;
extern s32 D_800E91A8;
extern s32 D_800E91C4;
extern s32 D_800E91D4[];
extern s32 D_800E91F4[];

void func_8008C274(void) {
    S61A8 *cur;
    void *other;
    s32 i;
    s32 j;
    s32 c;
    s32 v;
    s32 k;
    u8 *d;
    u8 *src;

    D_800DE9AC = 0;
    if (D_800E8FA8 == 0xB || D_800E8FA8 == 0xD) {
        return;
    }
    cur = D_800D61A8;
    other = cur->unk1C;
    if (D_800DC618 != 0) {
        func_8006CFB4(cur);
    }
    if (other != NULL && D_800DC6D8 != 0) {
        func_8006CFB4(other);
    }
    D_800DE7E0 = 0xD;
    if (D_800DE7A8->unk9F0 != 0 && D_800DE9A8 == 1) {
        func_80039E60(0x13, 0x2710, 0);
        v = 0xB;
        D_800E8FA8 = v;
        D_800DE7E0 = v;
    } else {
        if (D_800DE7A0 == 2) {
            s32 m = 0xE;
            D_800E8FA8 = m;
            D_800DE7E0 = m;
        } else {
            s32 m = 0xD;
            D_800E8FA8 = m;
            D_800DE7E0 = m;
        }
    }
    if ((D_800DE7A0 == 1 && D_800D5C1C[D_800C0E20].unkC == 0) || D_800DE7A0 == 3) {
        D_800E8F98 = -1;
        D_800E8F9C = 0;
        i = 0;
        while (1) {
            if (i >= 8) {
                break;
            }
            if (cur->unkA20 >= D_800DE9F4.tbl[D_800C0E20][i].score) {
            for (j = 7; i < j; j--) {
                D_800DE9F4.tbl[D_800C0E20][j].score = D_800DE9F4.tbl[D_800C0E20][j - 1].score;
                D_800DE9F4.tbl[D_800C0E20][j].unk4 = D_800DE9F4.tbl[D_800C0E20][j - 1].unk4;
                d = D_800DE9F4.tbl[D_800C0E20][j].name;
                c = 3;
                src = D_800DE9F4.tbl[D_800C0E20][j - 1].name;
                do {
                    *d = *src;
                    d++;
                    src++;
                } while (--c != -1);
            }
            D_800DE9F4.tbl[D_800C0E20][i].score = cur->unkA20;
            D_800DE9F4.tbl[D_800C0E20][i].unk4 = D_800DE7A8->unk3E3;
            func_800057E4(D_800DE9F4.tbl[D_800C0E20][i].name, D_800DE9F4.unk9B0);
            D_800E8F98 = i;
            i = 8;
            }
            i++;
        }
    }
    if (D_800DE7A0 == 7) {
        func_8006EC84(D_800E8E98);
        D_800E91A8 = 0;
        D_800DE9E8 = 0x2D;
        D_800E8EE0 = 0;
    }
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
    for (k = 0; k < 8; k++) {
        D_800E91D4[k] = -100 - (4 - k) * 30;
        D_800E91F4[k] = (4 - k) * 30 + 0x264;
    }
}
