#include "common.h"

/* Arm stores go through a struct field: the MEM_IN_STRUCT store gives each arm's
   constant a REG_EQUIV (mem) note, which stops jump.c from if-converting
   the if/else into 'x = b; if (c) x = a'. */
typedef struct {
    s32 unk0;
    s32 unk4;
    u8 pad8[0x428 - 0x8];
    s32 unk428;
    u8 pad42C[0x474 - 0x42C];
    s32 unk474;
} MenuState;

extern s32 D_800EA550;

void func_800A0E74(MenuState *arg0, s32 arg1, s32 arg2) {
    D_800EA550 = 6;
    if (arg1 != 0) {
        arg0->unk4 = 0x28;
    } else {
        arg0->unk4 = 0x29;
    }
    arg0->unk428 = arg2;
    arg0->unk474 = 0;
}
