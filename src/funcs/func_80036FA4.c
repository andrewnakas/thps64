/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

void *func_80028238(s32, s32, s32, s32);
void func_80028148(u8 *, s32);
void func_80033D70(s32);
void func_80035384(s32);
void func_80035A60(u8 *);
void func_800361DC(u8 *);
void func_80043B24(void);
void func_8004652C(s32, s32);
void func_8004A89C(void *);
void func_8004AB58(void);
void func_8004ACF0(void *);
s32 func_8004B514(s32);
void func_8005EDD0(void);
void func_80079228(s32, u8 *);
s32 func_800847E8(void *, void *);

typedef struct {
    u8 pad0[0xC];
    s32 xC;
    u8 pad10[0x78 - 0x10];
} Ent800D5C1C;

typedef struct {
    u8 pad0[0xEBC];
    s32 xEBC;
} Cfg800D0FC0;

extern s32 D_800C0E20;
extern Cfg800D0FC0 D_800D0FC0;
extern u8 D_800D0FE8;
extern u8 D_800D1E72[];
extern Ent800D5C1C D_800D5C1C[];
extern s32 D_800D6180;
extern s32 D_800DC5A0;
extern s32 D_800DC614;
extern s32 D_800DDC60;
extern s32 D_800DE7A0;
extern s32 D_800DE7A4;
extern u8 *D_800DE7A8;
extern u8 *D_800DE7AC;
extern s32 D_800DE7C4;
extern s32 D_800DE7C8;
extern s32 D_800DE7F0;
extern s32 D_800DE804;
extern s32 D_800DE93C;
extern s32 D_800DE9A8;
extern s32 D_800DE9C4;
extern u8 D_800E8A20[];
extern s32 D_800E9290;

void func_80036FA4(u8 *arg0) {
    s32 id;
    u8 *p;
    s32 c;
    s32 m;
    s32 k;

    func_80033D70(*(s32 *)(arg0 + 0x40));
    func_80035384(0x44);
    D_800DE7C4 = 0;
    D_800DE7C8 = 0;
    switch (D_800C0E20) {
    case 3:
    case 6:
    case 8:
        func_80035384(0x3D);
        break;
    }
    if (D_800DE804 != 0) {
        func_80035384(func_800847E8(D_800E8A20, D_800D1E72));
    }
    func_80035A60(arg0);
    if (D_800DE9A8 == 2 && D_800DE7A0 != 7) {
        D_800DE7AC = func_80028238(func_8004B514(0x2388), *(s32 *)(arg0 + 0x3C), 0, 1);
        *(s32 *)(D_800DE7AC + 0x82C) = 0;
        D_800DE7A8 = func_80028238(func_8004B514(0x2388), *(s32 *)(arg0 + 0x38), 0, 0);
        *(u8 **)(D_800DE7AC + 0x2CC) = D_800DE7A8;
        *(u8 **)(D_800DE7A8 + 0x2CC) = D_800DE7AC;
    } else if (D_800DE7A0 == 7) {
        if (D_800DE9C4 != 0) {
            id = D_800DE7F0;
        } else {
            id = D_800E9290;
        }
        D_800DE7A8 = func_80028238(func_8004B514(0x2388), id, 0, 0);
        D_800DE7AC = NULL;
        *(u8 **)(D_800DE7A8 + 0x2CC) = NULL;
    } else {
        D_800DE7A8 = p = func_80028238(func_8004B514(0x2388), *(s32 *)(arg0 + 0x38), 0, 0);
        D_800DE7AC = NULL;
        *(u8 **)(p + 0x2CC) = NULL;
        if (D_800D5C1C[D_800C0E20].xC != 0 && D_800DE7A0 == 1 && D_800DC614 == 0) {
            func_80079228(*(s32 *)(p + 0x2D0), p);
        }
    }
    m = D_800DE9A8;
    k = 1;
    if (m == k || D_800DE7A0 == 7) {
        D_800DE93C = 0;
    } else if (m == 2) {
        c = D_800D0FE8;
        if (c == 0) {
            D_800DE93C = 4;
        } else if (c == k) {
            D_800DE93C = 3;
        } else if (D_800D0FE8 == 2) {
            D_800DE93C = D_800D0FE8;
        }
        if (D_800DE93C >= 4) {
            D_800DE93C = 0;
        }
    }
    func_8004652C(m, k);
    func_8005EDD0();
    func_80043B24();
    func_800361DC(arg0);
    *(s32 *)(arg0 + 0x30) = 0;
    func_80028148(D_800DE7A8, D_800D0FC0.xEBC);
    if (D_800DE7AC != NULL) {
        func_80028148(D_800DE7AC, D_800D0FC0.xEBC);
    }
    D_800DE7C4 = 0;
    func_8004A89C(&D_800DC5A0);
    func_8004ACF0(&D_800D6180);
    func_8004ACF0(&D_800DE7A4);
    func_8004A89C(&D_800DDC60);
    func_8004AB58();
}
