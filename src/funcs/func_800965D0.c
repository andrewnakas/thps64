/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 x, y, z;
} V3_800965D0;

typedef struct {
    u8 pad0[4];
    V3_800965D0 pos;
    u8 pad10[6];
    s16 unk16;
    u8 pad18[0xC];
    s16 unk24;
    s16 unk26;
    s16 unk28;
    u8 pad2A[0x10];
    u16 type;
    u8 pad3C[0xC];
    s32 *vt;
    u8 pad4C[0x38];
    V3_800965D0 unk84;
    u8 pad90[0x10];
    s32 unkA0;
    u8 padA4[0x11];
    s8 unkB5;
    s8 unkB6;
    s8 unkB7;
    u8 padB8[2];
    s16 unkBA;
    u8 padBC[0xA0];
    s16 unk15C;
    u8 pad15E[0xAE];
    s32 *unk20C;
    s32 unk210;
    s32 unk214;
    u8 pad218[0x20];
    s32 unk238;
    s32 unk23C;
    s32 unk240;
    V3_800965D0 unk244;
    V3_800965D0 unk250;
    u8 pad25C;
    u8 unk25D;
    u8 pad25E[0xA];
    V3_800965D0 unk268;
    u8 pad274[2];
    s16 unk276;
    s16 unk278;
    s16 unk27A;
    s16 unk27C;
    u8 pad27E[2];
    s32 unk280;
} Ped_800965D0;

s32 func_80049D60(s32);
void func_8004A08C();
void func_8004B30C(Ped_800965D0 *, s32 *);
void func_8004B468(Ped_800965D0 *, s32 *);
s16 func_80063654(s32, u8);
s32 func_8006648C(s32);
void func_80097114(Ped_800965D0 *);
extern s32 D_80020724;
extern s32 D_8002072C;
extern s32 D_800207E0;
extern u8 D_800DACCE;
extern s32 D_800DC5A0;
extern s32 D_800DE7A0;
extern s32 D_800E93E0;

Ped_800965D0 *func_800965D0(Ped_800965D0 *p, u16 type, V3_800965D0 *pos, V3_800965D0 *v2, s32 a4, s32 a5, V3_800965D0 *v6, s32 a7, s16 a8) {
    func_8004A08C();
    p->vt = &D_800207E0;
    p->unk238 = a4;
    p->unk23C = a4;
    p->unk240 = a5;
    p->unk244 = *pos;
    p->unk250 = *v2;
    p->unk24 = a4;
    p->unk26 = a4;
    p->unk28 = a4;
    p->unk280 = 0;
    p->type = type;
    p->unk27C = a8;
    p->unk214 = 0;
    p->unk210 = 0;
    p->unk268 = *pos;
    p->pos = *pos;
    p->unk84 = *v6;
    p->unkB5 = 5;
    p->unkB6 = 5;
    p->unkB7 = 5;
    p->unkBA = 100;
    p->unkA0 = 0x8000;
    p->unk27A = func_80049D60(20) + 90;
    p->unk276 = 50;
    p->unk278 = 50;
    p->unk15C = 300;
    func_8004B468(p, &D_80020724);
    switch (p->type) {
    case 0x664:
        func_8004B468(p, &D_8002072C);
        p->unk25D = 1;
        p->unk16 = func_80063654(0x54636518, D_800DACCE);
        break;
    case 0x665:
        func_8004B468(p, &D_8002072C);
        p->unk25D = 1;
        p->unk16 = func_80063654(0xBA6D0434, D_800DACCE);
        break;
    case 0x666:
        func_8004B468(p, &D_8002072C);
        p->unk25D = 1;
        p->unk16 = func_80063654(0x2364558E, D_800DACCE);
        break;
    case 0x10:
    case 0x12:
        p->unk20C = &D_800E93E0;
        p->unkBA = 150;
        p->unk25D = 1;
        break;
    }
    if (D_800DE7A0 != 1) {
        switch (p->type) {
        case 4:
        case 5:
        case 6:
        case 10:
        case 15:
        case 16:
            p->unk27C = 1;
            break;
        }
    } else {
        switch (p->type) {
        case 4:
        case 5:
        case 6:
        case 10:
        case 15:
            if (func_8006648C(2) != 0) {
                p->unk27C = 1;
            }
            break;
        case 16:
            if (func_8006648C(3) != 0) {
                p->unk27C = 1;
            }
            break;
        }
    }
    func_8004B30C(p, &D_800DC5A0);
    if (p->unk25D == 0) {
        func_80097114(p);
    }
    return p;
}
