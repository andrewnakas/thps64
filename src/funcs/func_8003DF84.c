#include "common.h"

typedef struct {
    u8 pad[0x2C];
    s32 unk2C;
    u8 pad2[0x154 - 0x30];
} Ent8003DF84;

typedef struct {
    u8 pad[0x30];
    s32 unk30;
    u8 pad2[0x4CC - 0x34];
    u8 unk4CC[0x20];
    s16 unk4EC;
    s32 unk4F0;
} Struct8003DF84;

void func_800057E4(void *, void *, s32);
extern s32 D_8001A1E4;
extern Ent8003DF84 D_800D4D80[];

void func_8003DF84(Struct8003DF84 *arg0) {
    s16 t;
    s32 *p;

    if (arg0->unk4EC == 0x8C && arg0->unk4F0 == 2) {
        arg0->unk4F0 = 0;
        return;
    }
    t = arg0->unk4EC;
    if (arg0->unk4EC < -0x3C) {
        if (arg0->unk4F0 == 1) {
            p = &D_8001A1E4;
            func_800057E4(arg0->unk4CC, p, D_800D4D80[arg0->unk30].unk2C);
            arg0->unk4F0 = 2;
            return;
        }
    } else if (arg0->unk4F0 == 1) {
        arg0->unk4EC = t - 0x28;
        return;
    }
    if (arg0->unk4F0 == 2) {
        arg0->unk4EC += 0x28;
    }
}
