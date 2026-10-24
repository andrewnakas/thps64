/* cflags: -O2 */

#include "common.h"

typedef struct {
    u16 unk0;
    u8 pad2[0x28 - 0x2];
    void *unk28;
} B06A0_C;

typedef struct {
    u8 pad0[0x14];
    void *unk14;
    u8 pad18[0x20 - 0x18];
    s32 unk20;
    s32 unk24;
} B06A0_D;

typedef struct {
    u32 unk0;
    u32 unk4;
    u16 unk8;
    u16 unkA;
    u16 unkC;
    u16 padE;
    f32 unk10;
    f32 unk14;
    s32 unk18;
    f32 unk1C;
    B06A0_C *unk20;
    B06A0_D *unk24;
} B06A0_B;

typedef struct {
    u8 pad0[0x14];
    u16 *unk14;
    u16 *unk18;
    u32 unk1C;
    B06A0_B *unk20;
    u8 unk24;
} B06A0_A;

typedef struct {
    u8 pad0[0x18];
    s32 unk18;
    u8 unk1C;
    u8 pad1D[3];
    s32 *unk20;
} B06A0_Arg;

void func_8000D560(void *);
void *func_80010480(s32, s32, s32, u32, s32);
extern s32 D_800ECD40[];
extern s32 D_800ECDA8[];
extern s32 D_800ECE30[];
extern s32 D_800ECE58[];
extern s32 D_800ECE80[];
extern s32 D_800ECEA8[];

void func_800B06A0(B06A0_A **arg0, B06A0_Arg *arg1, s32 arg2) {
    B06A0_A *a;
    B06A0_B *b;
    s32 *tbl;
    u16 k;
    u16 i;
    u16 j;
    u32 diff;
    f64 dv;
    u8 n;
    f64 f;

    a = func_80010480(0, 0, arg2, 1, 0x2C);
    *arg0 = a;
    switch (arg1->unk1C) {
    case 1:
        tbl = D_800ECD40;
        k = 2;
        break;
    case 2:
        tbl = D_800ECDA8;
        k = 2;
        break;
    case 5:
        tbl = D_800ECE30;
        k = 2;
        break;
    case 3:
        tbl = D_800ECE58;
        k = 2;
        break;
    case 4:
        tbl = D_800ECE80;
        k = 2;
        break;
    case 6:
        tbl = arg1->unk20;
        k = 2;
        break;
    default:
        tbl = D_800ECEA8;
        k = 2;
        break;
    }
    a->unk24 = tbl[0];
    a->unk1C = tbl[1];
    a->unk20 = func_80010480(0, 0, arg2, a->unk24, 0x28);
    a->unk18 = a->unk14 = func_80010480(0, 0, arg2, a->unk1C, 2);
    for (i = 0; i < a->unk1C; i++) {
        a->unk14[i] = 0;
    }
    for (j = 0; j < a->unk24; j++) {
        b = &a->unk20[j];
        b->unk0 = tbl[k++];
        b->unk4 = tbl[k++];
        b->unkA = tbl[k++];
        b->unk8 = tbl[k++];
        b->unkC = tbl[k++];
        if (tbl[k] != 0) {
            f = (f32)tbl[k++] / 1000.0f;
            diff = b->unk4 - b->unk0;
            b->unk10 = 2.0 * f / arg1->unk18;
            /* (f64)diff for u32 diff, written out so the 2^32 comes from the game's rodata */
            dv = (s32)diff;
            {
                f64 q = (f32)tbl[k++] / 173123.404906676;
                if ((s32)diff < 0) {
                    dv += 4294967296.0;
                }
                b->unk1C = q * dv;
            }
            b->unk18 = 0;
            b->unk14 = 1.0f;
            b->unk24 = func_80010480(0, 0, arg2, 1, 0x34);
            b->unk24->unk14 = func_80010480(0, 0, arg2, 1, 0x20);
            b->unk24->unk20 = 0;
            b->unk24->unk24 = 1;
        } else {
            b->unk24 = NULL;
            k += 2;
        }
        if (tbl[k] != 0) {
            b->unk20 = func_80010480(0, 0, arg2, 1, 0x30);
            b->unk20->unk28 = func_80010480(0, 0, arg2, 1, 8);
            b->unk20->unk0 = tbl[k++];
            func_8000D560(b->unk20);
        } else {
            b->unk20 = NULL;
            k++;
        }
    }
}
