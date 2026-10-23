#include "common.h"

typedef struct {
    u8 pad0[0x34];
    s16 unk34;
    s16 unk36;
    s16 unk38;
    s16 pad3A;
    s32 unk3C;
    u8 pad40[0x61 - 0x40];
    u8 unk61;
    u8 unk62;
    u8 unk63;
    u8 unk64;
    u8 pad65[0x70 - 0x65];
    s16 unk70;
    u8 unk72;
    u8 unk73;
} Obj;

void func_8003E910(Obj *);

void func_8003FD30(Obj *arg0) {
    u16 x;

    if (arg0->unk36 == 0x8B) {
        arg0->unk62 = arg0->unk61;
    } else if (arg0->unk3C == 1) {
        arg0->unk34 -= 0x34;
        arg0->unk36 -= 0x34;
    } else if (arg0->unk3C == -1) {
        arg0->unk34 += 0x34;
        arg0->unk36 += 0x34;
    }
    if (arg0->unk38 == 0x127) {
        arg0->unk63 = arg0->unk64;
    } else if (arg0->unk3C == 1) {
        arg0->unk34 -= 0x14;
        arg0->unk38 -= 0x14;
    } else if (arg0->unk3C == -1) {
        arg0->unk34 += 0x14;
        arg0->unk38 += 0x14;
    }
    if ((*(s32 *)&arg0->unk70 & ~0xFF) == 0x8C0200) {
        arg0->unk72 = 0;
    } else if (x = arg0->unk70, arg0->unk70 < -0x32) {
        if (arg0->unk72 == 1) {
            func_8003E910(arg0);
            arg0->unk72 = 2;
        } else if (arg0->unk72 == 2) {
            arg0->unk70 += 0x28;
        }
    } else {
        if (arg0->unk72 == 1) {
            arg0->unk70 = x - 0x28;
        } else if (arg0->unk72 == 2) {
            arg0->unk70 += 0x28;
        }
    }
}
