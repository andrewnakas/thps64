#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
} P8006AB44;

typedef struct {
    s32 mode;
    s32 *buf;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28[4];
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    P8006AB44 unk54[5];
    s32 unk7C_pad;
    s32 unk80;
    s16 unk84;
    s16 unk86;
    s16 unk88;
    s16 unk8A;
    s16 unk8C;
    s16 unk8E;
    s16 unk90;
    s16 unk92;
    s32 unk94;
    s32 unk98;
    s32 unk9C;
    s32 unkA0;
    s32 unkA4;
    s32 unkA8;
    s32 unkAC;
    s32 unkB0;
    s32 unkB4;
    s32 unkB8;
    s32 unkBC;
} S8006AB44;

void func_8004C774(u8 *);
extern s32 D_800D613C;
extern u8 *D_800D61A8;
extern S8006AB44 D_800DC618;
extern S8006AB44 D_800DC6D8;
extern s32 D_800DC824;
extern s32 D_800DC91C;
extern s32 D_800DC920;
extern s32 D_800DC924;
extern s32 D_800DC928;
extern s32 D_800DC92C;
extern s32 D_800DC930;

void func_8006AB44(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    S8006AB44 *t;
    s32 i;
    s32 j;
    u8 *p;
    s32 *q;

    if (arg0 == D_800D61A8) {
        t = &D_800DC618;
    } else {
        t = &D_800DC6D8;
    }
    D_800DC824 = 0;
    D_800DC91C = 0;
    D_800DC920 = 0;
    D_800DC924 = D_800DC928 = -1;
    D_800DC92C = D_800DC930 = -1;
    t->mode = arg1;
    if (arg1 == 1) {
        t->unk1C = 0;
        t->unk18 = 0x20;
        for (i = 4, p = (u8 *)t + 0x20; i >= 0; i--) {
            ((S8006AB44 *)p)->unk54[0].unk0 = 0;
            p -= 8;
        }
        t->unk4C = 0;
        q = t->buf;
        for (j = 0x17FF, q += 0x17FF; j >= 0; j--) {
            *q = 0;
            q--;
        }
    } else {
        t->unk18 = 0;
    }
    t->unk10 = t->unk8;
    t->unk14 = 0;
    t->unk20 = t->unk1C;
    t->unk24 = -1;
    t->unk44 = -2;
    t->unk38 = 0;
    t->unk40 = 0;
    t->unk3C = -1;
    if (arg3 != 0x7FFFFFFF) {
        t->unk20 = arg3 - arg2 + 1;
    }
    t->unk94 = t->unk98 = t->unk9C = 0;
    t->unkA0 = t->unkA4 = t->unkA8 = 0;
    t->unk84 = t->unk86 = t->unk88 = 0;
    t->unk8C = t->unk8E = t->unk90 = 0;
    t->unk54[4].unk4 = 0;
    t->unk7C_pad = 0;
    t->unk80 = 0;
    t->unkAC = 0;
    t->unkB8 = t->unkB4 = D_800D613C;
    t->unkBC = 0;
    *(s16 *)(arg0 + 0x21C) = *(s16 *)(arg0 + 0x21E) = 0;
    *(s32 *)(arg0 + 0x81C) = 0;
    func_8004C774(arg0);
}
