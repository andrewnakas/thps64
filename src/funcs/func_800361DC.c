/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s16 a;
    s16 b;
    s32 pad;
} Pair361DC;

typedef struct {
    s32 x0;
    u8 *x4;
    u8 pad8[0x44];
    s32 x4C;
    Pair361DC x50[1];
} G361DC;

typedef struct {
    u8 pad0[0xC];
    s32 xC;
    u8 pad10[0x68];
} Ent5C1C_361DC;

void func_80043B24(void);
void func_8004A89C(void *);
s32 func_8006648C(s32);
void func_8006A994(void);
void func_8006AB44(u8 *, s32, s32, s32);
void func_8006D020(void);
s32 func_80079218(s32);
extern s32 D_800C0E20;
extern s32 D_800C0E40;
extern u8 D_800D0FE3;
extern Ent5C1C_361DC D_800D5C1C[];
extern s32 D_800D6138;
extern volatile s32 D_800D613C;
extern u8 *D_800D61A8;
extern u8 D_800DC5D4;
extern s32 D_800DC614;
extern G361DC D_800DC618;
extern u8 *D_800DC61C;
extern s32 D_800DC664;
extern s32 D_800DC724;
extern s32 D_800DE144;
extern s32 D_800DE7A0;
extern u8 *D_800DE7A8;
extern u8 *D_800DE7AC;
extern s32 D_800DE7CC;
extern s32 D_800DE804;
extern s32 D_800DE808;
extern s32 D_800DE80C;
extern s32 D_800DE820;
extern s32 D_800DE944;
extern s32 D_800DE948;
extern s32 D_800DE94C;
extern s32 D_800DE950;
extern s32 D_800DE964;
extern s32 D_800DE968;
extern u8 *D_800DE96C;
extern u8 *D_800DE970;
extern u8 *D_800DE974;
extern u8 *D_800DE978;
extern u8 *D_800DE97C;
extern u8 *D_800DE980;
extern s32 D_800DE994;
extern s32 D_800DE998;
extern s32 D_800DE9AC;
extern u8 D_800DE9F0;
extern s32 D_800E9038;
extern s32 D_800E929C;

void func_800361DC(u8 *arg0) {
    s32 i;
    u8 *p1;
    u8 *p0;
    u8 *p2;
    u8 *q;

    func_80043B24();
    D_800DE998 = 0;
    D_800DE994 = 0;
    D_800D6138 = 0;
    D_800D613C = 0;
    D_800DE808 = 0;
    D_800DC5D4 = 0;
    D_800C0E40 = 0;
    D_800DE80C = 0;
    D_800DE944 = D_800D613C;
    D_800DE948 = 0;
    D_800DE94C = 0;
    D_800E9038 = 0;
    D_800DE820 = 0;
    D_800DE9AC = 0;
    *(s32 *)(arg0 + 0x4C) = 0;
    *(s32 *)(arg0 + 0x50) = 0;
    *(s32 *)(arg0 + 0x54) = 0;
    D_800DE804 = 0;
    D_800DE9AC = 0;
    D_800DE964 = 0;
    D_800DE968 = 0;
    D_800DE950 = 0x640;
    if (D_800E929C != 0 && D_800D0FE3 != 2) {
        D_800DE950 = 0;
    }
    if (D_800DC614 == 0) {
        if (D_800DE7A0 == 1) {
            D_800DE9F0 = 0;
            if (func_8006648C(3) != 0) {
                D_800DE9F0 |= 1;
            }
            if (func_8006648C(2) != 0) {
                D_800DE9F0 |= 2;
            }
        } else {
            D_800DE9F0 = 3;
        }
    } else {
        D_800DE9F0 = D_800DC61C[0x238];
    }
    if (D_800DE7A0 == 1 && D_800D5C1C[D_800C0E20].xC == 0) {
        if (D_800DE9F0 & 2) {
            *(s16 *)(D_800DE96C + 0x230) = 1;
            *(s16 *)(D_800DE970 + 0x230) = 1;
            *(s16 *)(D_800DE974 + 0x230) = 1;
            *(s16 *)(D_800DE978 + 0x230) = 1;
            *(s16 *)(D_800DE97C + 0x230) = 1;
        }
        if (D_800DE9F0 & 1) {
            *(s16 *)(D_800DE980 + 0x230) = 1;
        }
    }
    if (D_800DC614 != 0) {
        D_800DE7CC = 1;
        p1 = *(u8 **)(D_800D61A8 + 0x1C);
        if (D_800DC614 > 0) {
            D_800DC618.x4C = D_800DC614;
            D_800DC724 = D_800DC614;
            func_8006AB44(D_800D61A8, 2, D_800DC618.x50[D_800DC614 - 1].a, D_800DC618.x50[D_800DC614 - 1].b);
            if (p1 != NULL) {
                func_8006AB44(p1, 2, D_800DC618.x50[D_800DC614 - 1].a, D_800DC618.x50[D_800DC614 - 1].b);
            }
            func_8006A994();
        } else {
            D_800DC614 = 0;
            D_800DC664 = 0;
            D_800DC724 = 0;
            func_8006AB44(D_800D61A8, 2, 1, 0x7FFFFFFF);
            if (p1 != NULL) {
                func_8006AB44(p1, 2, 1, 0x7FFFFFFF);
            }
        }
        *(s32 *)(D_800D61A8 + 0x428) = D_800D613C + 0x34BDE;
        q = *(u8 **)(D_800D61A8 + 0x1C);
        if (q != NULL) {
            *(s32 *)(q + 0x428) = D_800D613C + 0x34BDE;
        }
    } else {
        func_8006D020();
        p0 = D_800D61A8;
        p2 = *(u8 **)(p0 + 0x1C);
        if (D_800DC618.x0 == 0 && func_80079218(D_800DE144) == 0) {
            func_8006AB44(p0, 1, 1, 0x7FFFFFFF);
            if (p2 != NULL) {
                func_8006AB44(p2, 1, 1, 0x7FFFFFFF);
            }
            D_800DC618.x4[0x238] = D_800DE9F0;
        }
    }
    *(s32 *)(D_800DE7A8 + 0x84) = *(s32 *)(D_800DE7A8 + 0x8D0) * 20;
    *(s32 *)(D_800DE7A8 + 0x88) = *(s32 *)(D_800DE7A8 + 0x8D4) * 20;
    *(s32 *)(D_800DE7A8 + 0x8C) = *(s32 *)(D_800DE7A8 + 0x8D8) * 20;
    if (D_800DE7AC != NULL) {
        *(s32 *)(D_800DE7AC + 0x84) = *(s32 *)(D_800DE7AC + 0x8D0) * 20;
        *(s32 *)(D_800DE7AC + 0x88) = *(s32 *)(D_800DE7AC + 0x8D4) * 20;
        *(s32 *)(D_800DE7AC + 0x8C) = *(s32 *)(D_800DE7AC + 0x8D8) * 20;
    }
    for (i = 0; i < 10; i++) {
        func_8004A89C(&D_800DE144);
    }
    *(s32 *)(D_800DE7A8 + 0x84) = 0;
    *(s32 *)(D_800DE7A8 + 0x88) = 0;
    *(s32 *)(D_800DE7A8 + 0x8C) = 0;
    if (D_800DE7AC != NULL) {
        *(s32 *)(D_800DE7AC + 0x84) = 0;
        *(s32 *)(D_800DE7AC + 0x88) = 0;
        *(s32 *)(D_800DE7AC + 0x8C) = 0;
    }
}
