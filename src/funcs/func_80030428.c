#include "common.h"

typedef struct {
    u8 pad0[0x2C];
    s32 unk2C;
    u8 pad30[0x154 - 0x30];
} Info;

typedef struct {
    u8 pad0[0x760];
    u8 unk760[0x22];
    s16 unk782;
    u8 pad784[4];
    s32 unk788;
    u8 pad78C[4];
    s32 unk790;
} Obj;

void func_800057E4(void *, void *, s32);
extern s32 D_800199F0;
extern Info D_800D4D80[];

void func_80030428(Obj *arg0) {
    u16 v;
    s32 *q;
    Info *tbl;

    if (arg0->unk782 == 0x188 && arg0->unk788 == 2) {
        arg0->unk788 = 0;
        return;
    }
    v = arg0->unk782;
    if (arg0->unk782 > 500) {
        if (arg0->unk788 == 1) {
            q = &D_800199F0;
            tbl = D_800D4D80;
            func_800057E4(arg0->unk760, q, tbl[arg0->unk790].unk2C);
            arg0->unk788 = 2;
            return;
        }
    } else if (arg0->unk788 == 1) {
        arg0->unk782 = v + 50;
        return;
    }
    if (arg0->unk788 == 2) {
        arg0->unk782 -= 50;
    }
}
