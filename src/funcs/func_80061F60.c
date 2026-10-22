#include "common.h"

typedef struct {
    s8 unk0;
    u8 pad[0x14];
    s8 unk15;
    u8 pad2[3];
} Slot80061F60;

typedef struct {
    s8 unk0;
    u8 pad1[0x11];
    s8 unk12;
    s8 unk13;
    u8 pad2[4];
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    u8 pad3[4];
    s32 unk30;
    s32 unk34;
    u8 pad4[3];
    s8 unk3B;
    s8 unk3C;
    u8 pad5[0x48 - 0x3D];
} Ent80061F60;

extern s32 D_800DAD70[];
extern s32 D_800DAD78[];
extern s32 D_800DAD8C;
extern s32 D_800DAD90;
extern s32 D_800DAD94;
extern s32 D_800DAD98;
extern s32 D_800DAD9C;
extern Slot80061F60 D_800DADA4[];
extern Ent80061F60 D_800DAF98[];
extern s32 D_800DBAE0[];

void func_80061F60(void) {
    Slot80061F60 *s;
    Ent80061F60 *e;
    s32 *w;
    s32 i;

    i = 0;
    s = D_800DADA4;
    while (1) {
        if (i >= 0x14) {
            break;
        }
        i++;
        s->unk15 = 0;
        s->unk0 = 0;
        s++;
    }
    D_800DAD94 = 0;
    D_800DAD98 = 0;
    i = 0;
    e = D_800DAF98;
    do {
        e->unk0 = 0;
        e->unk13 = 0;
        e->unk12 = 0;
        e->unk18 = 0;
        e->unk1C = 0;
        e->unk20 = 0;
        e->unk24 = 0;
        e->unk34 = 0;
        e->unk30 = 0;
        e->unk28 = 0;
        e->unk3B = 0;
        e->unk3C = 0;
        i++;
        e++;
    } while (i < 0x28);
    w = D_800DBAE0;
    i = 0x1FF;
    w += 0x1FF;
    do {
        *w = 0;
        i--;
        w--;
    } while (i >= 0);
    D_800DAD9C = 0;
    D_800DAD70[0] = -1;
    D_800DAD70[1] = -1;
    D_800DAD78[0] = 0;
    D_800DAD78[1] = 0;
    D_800DAD8C = 0;
    D_800DAD90 = 0;
}
