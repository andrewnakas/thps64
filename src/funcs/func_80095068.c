#include "common.h"

typedef struct {
    u8 pad0[0x13];
    u8 unk13;
    u8 pad14[0x48 - 0x14];
} E48;

typedef struct {
    char *unk0;
    char *unk4;
    u8 pad8[0x13 - 0x8];
    u8 unk13;
    s8 unk14;
    u8 pad15[0x154 - 0x15];
} T154;

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0x14 - 0x10];
    char *unk14;
    u8 pad18[0x78 - 0x18];
} E78;

void func_8003A0D4(s32);
void func_8004652C(void);
s32 func_80049034(char *, s32, s32);
void func_80049DC4(s32);
void func_8005EDD0(void);
void func_8005F02C(s32);
void func_80061CC4(void *);
s32 func_8006278C(char *, s32, s32);
void func_80062EBC(void);
void func_80063160(void);
void func_8006FA98(void);
void func_80079748(s32);
void func_800797C0(void);
void func_800828A0(void);
void func_80094FA8(void);
extern char D_80020184[];
extern char D_8002018C[];
extern char D_80020194[];
extern s32 D_800C0E20;
extern T154 D_800D4D80[];
extern E78 D_800D5C1C[];
extern s32 D_800DA670;
extern s32 D_800DA680;
extern s8 D_800DACCD;
extern s8 D_800DACCE;
extern E48 D_800DAF98[];
extern s32 D_800DE7A0;
extern s32 D_800DE7F0;
extern s32 D_800DE864;
extern s32 D_800DE988;
extern s32 D_800DE9A8;
extern s32 D_800DF404;
extern s32 D_800E8E70;
extern s32 D_800E9290;

void func_80095068(u8 *arg0) {
    s32 i;
    s32 idx;
    s32 name;
    char *s;
    E78 *p;

    D_800E8E70 = (s32)(arg0 + 4);
    func_80049DC4(0x12A6CC58);
    func_80079748(0x7D0);
    func_8003A0D4(0);
    D_800DAF98[func_8006278C(D_80020184, 0, 0)].unk13 = 1;
    idx = func_8006278C(D_8002018C, 0, 0);
    D_800DAF98[idx].unk13 = 1;
    D_800DACCD = idx;
    func_80062EBC();
    func_80079748(4);
    func_8004652C();
    func_8006FA98();
    func_800797C0();
    func_80063160();
    if (D_800D5C1C[D_800C0E20].unkC != 0 && D_800DE7A0 == 1) {
        idx = func_8006278C(D_80020194, 0, 0);
    }
    D_800DACCE = idx;
    if (D_800DE864 != 0) {
        D_800DA670 = D_800D4D80[D_800E9290].unk13;
        D_800DA680 = D_800D4D80[D_800E9290].unk14;
    }
    if (D_800DE9A8 == 2 && D_800DE7A0 != 7) {
        s = D_800D4D80[D_800E9290].unk4;
    } else {
        s = D_800D4D80[D_800E9290].unk0;
    }
    func_8006278C(s, 0, 0);
    func_80062EBC();
    D_800DA670 = -1;
    if (D_800DE9A8 == 2) {
        if (D_800DE864 != 0) {
            D_800DA680 = D_800D4D80[D_800DE7F0].unk14;
            D_800DA670 = D_800D4D80[D_800DE7F0].unk13;
        }
        if (D_800DE7A0 != 7) {
            s = D_800D4D80[D_800DE7F0].unk4;
        } else {
            s = D_800D4D80[D_800DE7F0].unk0;
        }
        func_8006278C(s, 0, 0);
        func_80062EBC();
        D_800DA670 = -1;
    }
    name = D_800E8E70;
    i = 0;
    if (*(u8 *)D_800D5C1C[0].unk14 != 0) {
        p = D_800D5C1C;
        do {
            if (func_80049034(p->unk14, name, -1) != 0) {
                D_800DE988 = i;
                break;
            }
            i++;
            p++;
        } while (i < 0x29 && *(u8 *)p->unk14 != 0);
    }
    func_80079748(0x7D0);
    func_8005F02C(D_800E8E70);
    func_80079748(4);
    if (D_800DF404 == 0) {
        func_800828A0();
        s = (char *)arg0 + 0xD;
        if (*(u8 *)s != 0) {
            func_80061CC4(s);
        }
        func_8005EDD0();
        func_80094FA8();
    }
}
