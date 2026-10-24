/* cflags: -fcse-follow-jumps */
#include "common.h"

typedef struct {
    s32 x, y, z;
} V3_80077A60;

typedef struct {
    s32 x, y, z, w;
} Q_80077A60;

typedef struct {
    u8 pad0[0x64];
    s32 unk64;
    s32 unk68;
    s32 unk6C;
    s16 unk70;
    s16 unk72;
    s16 unk74;
    u8 pad76[0x78 - 0x76];
} E_80077A60;

void func_800226A0(void *, void *, void *);
void func_80046E04(void *, void *, s32 *);
void func_80046EF4(void *, void *, void *);
void func_80046F58(void *, void *, s32 *);
void func_80046FBC(void *, void *, void *);
void func_8004A89C(void *);
void func_800673B0(void *, void *, void *);
void func_800676D0(void *, s32);
void func_800677F8(void *, s32);
void func_80067920(void *, s32);
void func_80067A48(void *, void *);
void func_80067F30(Q_80077A60, Q_80077A60, u32, void *);
void func_8006AB44(s32, s32, s32, s32);
void func_80081DF8(void);
extern s32 D_800C0E20;
extern u8 D_800D49E0[];
extern E_80077A60 D_800D5C1C[];
extern s32 D_800D61A8;
extern s32 D_800DE130;
extern V3_80077A60 D_800DE134;
extern u8 D_800DE144[];
extern u8 *D_800DE7A8;

#define I32(o) (*(s32 *)(c + (o)))
#define U32(o) (*(u32 *)(c + (o)))
#define V3(o) (*(V3_80077A60 *)(c + (o)))
#define Q(o) (*(Q_80077A60 *)(c + (o)))
#define G32(o) (*(s32 *)(D_800DE7A8 + (o)))

void func_80077A60(u8 *c) {
    Q_80077A60 q28;
    Q_80077A60 q38;
    Q_80077A60 q48;
    Q_80077A60 q58;
    Q_80077A60 q68;
    Q_80077A60 q78;
    Q_80077A60 q88;
    s32 i98;
    s32 i9C;
    s32 i;
    s32 h;
    s32 flag;
    s32 k;
    Q_80077A60 *p48;
    Q_80077A60 *p58;
    Q_80077A60 *p68;
    Q_80077A60 *p78;
    Q_80077A60 *p88;
    E_80077A60 *tbl;
    u32 *p654;
    Q_80077A60 *pm;
    u32 n;

    if (U32(0x654) == 0) {
        I32(0x5B0) = 1;
        G32(0x84) = G32(0x8D0) * 20;
        G32(0x88) = G32(0x8D4) * 20;
        G32(0x8C) = G32(0x8D8) * 20;
        for (i = 0; i < 10; i++) {
            func_8004A89C(D_800DE144);
        }
        G32(0x84) = 0;
        G32(0x88) = 0;
        G32(0x8C) = 0;
        I32(0x5B0) = 0x17;
        h = D_800DE130 >> 1;
        I32(0x684) = h;
        ((V3_80077A60 *)&q28)->x = 0;
        ((V3_80077A60 *)&q28)->y = 0;
        ((V3_80077A60 *)&q28)->z = -(h << 12);
        pm = &q48;
        func_80067A48(c + 0x554, pm);
        func_800226A0(pm, &q28, &q38);
        q28.x = D_800DE134.x;
        q28.y = D_800DE134.y;
        q28.z = D_800DE134.z;
        func_800226A0(pm, &q28, c + 0x6F0);
        I32(0x4) = I32(0x4D0) + q38.x;
        I32(0x8) = I32(0x4D4) + q38.y;
        I32(0xC) = I32(0x4D8) + q38.z;
        I32(0x65C) = I32(0x4);
        I32(0x660) = I32(0x8);
        I32(0x664) = I32(0xC);
    }
    k = 0x1000;
    q28.x = 0;
    q28.y = 0;
    q28.z = 0;
    q28.w = k;
    q38.x = 0;
    q38.y = 0;
    q38.z = 0;
    q38.w = k;
    q38 = Q(0x564);
    p48 = &q48;
    p58 = &q58;
    p68 = &q68;
    tbl = D_800D5C1C;
    func_800677F8(p68, tbl[D_800C0E20].unk72);
    p78 = &q78;
    func_800676D0(p78, tbl[D_800C0E20].unk70);
    func_800673B0(p58, p68, p78);
    p88 = &q88;
    func_80067920(p88, tbl[D_800C0E20].unk74);
    func_800673B0(p48, p58, p88);
    q28 = q48;
    n = (U32(0x654) << 12) / 130;
    p654 = (u32 *)(c + 0x654);
    q48 = q28;
    func_80067F30(q48, q38, n, c + 0x554);
    if (U32(0x654) >= 0x83) {
        func_8006AB44(D_800D61A8, 1, 1, 0x7FFFFFFF);
        I32(0x5B0) = 1;
        return;
    }
    func_80081DF8();
    q48.x = tbl[D_800C0E20].unk64 << 12;
    q48.y = tbl[D_800C0E20].unk68 << 12;
    q48.z = tbl[D_800C0E20].unk6C << 12;
    func_80046FBC(p78, p48, c + 0x65C);
    i98 = 0x82;
    func_80046E04(p68, p78, &i98);
    *(V3_80077A60 *)&q58 = *(V3_80077A60 *)&q68;
    i9C = 0x82;
    func_80046F58(p78, p58, &i9C);
    func_80046EF4(p88, p654, p58);
    func_80046FBC(p68, p78, p88);
    I32(0x4) = I32(0x65C) + q68.x;
    I32(0x8) = I32(0x660) + q68.y;
    I32(0xC) = I32(0x664) + q68.z;
    flag = 0;
    if (D_800D49E0[0x30] != 0 || D_800D49E0[0x1BC] != 0) {
        flag = 1;
    }
    if (flag) {
        I32(0x658) = 1;
    }
    if (I32(0x658) != 0) {
        I32(0x654) += 6;
    } else {
        I32(0x654) += 1;
    }
}
