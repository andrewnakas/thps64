/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    s32 unk10;
    u8 pad14[0x14];
    s32 unk28;
    u8 unk2C[8];
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    f32 unk44;
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s16 unk58;
    s16 unk5A;
    s16 unk5C;
    s16 unk5E;
    s16 unk60;
    s16 unk62;
    volatile s16 unk64;
    s16 unk66;
    s16 unk68;
    u8 pad6A[4];
    s16 unk6E;
    s32 unk70;
    s32 unk74;
    s32 unk78;
    s32 unk7C;
    s32 unk80;
    s32 unk84;
} Mixer;

s32 func_80010480(s32, s32, s32, s32, s32);

void func_800B0A88(Mixer *arg0, s32 (*arg1)(void *), s32 arg2) {
    arg0->unkC = func_80010480(0, 0, arg2, 1, 0x20);
    arg0->unk10 = func_80010480(0, 0, arg2, 1, 0x20);
    arg0->unk28 = arg1(arg0->unk2C);
    arg0->unk34 = 0;
    arg0->unk38 = 1;
    arg0->unk3C = 0;
    arg0->unk40 = func_80010480(0, 0, arg2, 1, 0x20);
    arg0->unk4C = 0;
    arg0->unk50 = 1;
    arg0->unk48 = 0;
    arg0->unk44 = 1.0f;
    arg0->unk54 = func_80010480(0, 0, arg2, 1, 0x50);
    arg0->unk78 = 1;
    arg0->unk84 = 0;
    arg0->unk5A = 1;
    arg0->unk68 = 1;
    arg0->unk6E = 1;
    arg0->unk5C = 1;
    arg0->unk5E = 1;
    arg0->unk60 = 0;
    arg0->unk62 = 0;
    arg0->unk66 = 1;
    arg0->unk64 = 0;
    arg0->unk64 = 0;
    arg0->unk70 = 0;
    arg0->unk74 = 0;
    arg0->unk58 = 0;
    arg0->unk7C = 0;
    arg0->unk80 = 0;
}
