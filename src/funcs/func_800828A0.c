/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0x208];
    s32 flags;
    u8 pad20C[0x2CC - 0x20C];
    void *partner;
    void *board;
    u8 pad2D4[0x3E0 - 0x2D4];
    s32 skin;
    u8 pad3E4[0x968 - 0x3E4];
    s32 player;
} Skater;

typedef struct {
    u8 pad0[0x5B0];
    s32 unk5B0;
} Board;

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0x78 - 0x10];
} Level;

typedef struct {
    s32 model;
    u8 pad4[0x154 - 4];
} SkinDef;

void *func_8004B514(s32);
Skater *func_8004B77C(void *);
Board *func_80073AE0(void *, Skater *, s32);
void func_80079228(Board *);
void func_8004C4E4(Skater *, s32);
extern Skater *D_800DE7A8;
extern Skater *D_800DE7AC;
extern Level D_800D5C1C[];
extern s32 D_800C0E20;
extern s32 D_800DE7A0;
extern s32 D_800DC614;
extern s32 D_800DE9C4;
extern s32 D_800DE7F0;
extern s32 D_800E9290;
extern SkinDef D_800D4D80[];
extern s32 D_800DE9A8;

void func_800828A0(void) {
    Skater *a;
    Skater *b;
    Board *bd;
    Board *bd2;

    a = func_8004B77C(func_8004B514(0xF14));
    D_800DE7A8 = a;
    D_800DE7AC = NULL;
    a->player = 0;
    bd = func_80073AE0(func_8004B514(0x724), a, 0);
    bd->unk5B0 = 1;
    if (D_800D5C1C[D_800C0E20].unkC != 0 && D_800DE7A0 == 1 && D_800DC614 == 0) {
        func_80079228(bd);
    }
    if (D_800DE7A0 != 7 || D_800DE9C4 == 0) {
        a->skin = D_800E9290;
    } else {
        a->skin = D_800DE7F0;
    }
    a->board = bd;
    func_8004C4E4(a, D_800D4D80[a->skin].model);
    if (D_800E9290 == 1) {
        a->flags |= 2;
    }
    if (D_800DE9A8 == 2 && D_800DE7A0 != 7) {
        b = func_8004B77C(func_8004B514(0xF14));
        b->player = 1;
        bd2 = func_80073AE0(func_8004B514(0x724), b, 0);
        bd2->unk5B0 = 1;
        b->skin = D_800DE7F0;
        func_8004C4E4(b, D_800D4D80[b->skin].model);
        a->flags &= ~2;
        b->flags |= 2;
        a->partner = b;
        b->partner = a;
        b->board = bd2;
        D_800DE7AC = b;
    }
}
