#include "common.h"

typedef struct {
    u8 pad0[0x1B];
    u8 idx;
} Obj5DEBC;

typedef struct {
    u8 pad0[0x28];
    s32 unk28;
    u8 pad2C[0x48 - 0x2C];
} Ent5DEBC;

extern Ent5DEBC D_800DAF98[];

void func_8005DEBC(Obj5DEBC *arg0, s32 arg1) {
    arg1 += 4;
    D_800DAF98[arg0->idx].unk28 = arg1;
}
