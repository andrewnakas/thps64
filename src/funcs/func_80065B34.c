#include "common.h"

typedef struct {
    s32 x, y, z;
} V3_80065B34;

typedef struct {
    u16 flags;
    u8 pad2[2];
    V3_80065B34 pos;
    u8 pad10[0x48 - 0x10];
    void *unk48;
    u8 pad4C[0x184 - 0x4C];
    V3_80065B34 home;
    u8 pad190[0x294 - 0x190];
    s8 unk294;
    u8 pad295[0x2A8 - 0x295];
    s32 unk2A8;
    u8 pad2AC[0x2CC - 0x2AC];
    s16 unk2CC;
    u8 pad2CE[0x324 - 0x2CE];
    s16 unk324;
    u8 pad326[0x340 - 0x326];
    s32 unk340;
} Obj80065B34;

void func_8004B30C(Obj80065B34 *, void *);
void func_8004B468(Obj80065B34 *, s32);
void func_80072DFC(Obj80065B34 *);
extern s32 D_8001CB18;
extern s32 D_800D6180;
extern s32 D_800DACB8;

Obj80065B34 *func_80065B34(Obj80065B34 *arg0, V3_80065B34 *arg1) {
    void *head;

    func_80072DFC(arg0);
    arg0->unk48 = &D_8001CB18;
    func_8004B468(arg0, D_800DACB8);
    arg0->pos = arg0->home = *arg1;
    head = &D_800D6180;
    func_8004B30C(arg0, head);
    arg0->flags = (arg0->flags | 0x111) & 0xFFFD;
    arg0->unk324 = 0x192;
    arg0->unk2A8 = 0;
    arg0->unk340 = -1;
    arg0->unk2CC = 0x20;
    arg0->unk294 = 0;
    return arg0;
}
