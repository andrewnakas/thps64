#include "common.h"

typedef struct {
    s32 unk0;
    s16 unk4;
    s16 unk6;
    s32 unk8;
    s32 unkC;
    s8 unk10;
    s8 unk11;
    s8 pad12[0xE];
} Cmd;

extern s32 D_800DDA28;
extern Cmd *D_800DDA2C;

void func_8006F9F8(s16 arg0, s16 arg1, s32 arg2, u8 arg3, u8 arg4, u8 arg5, s32 arg6) {
    Cmd *p;
    s32 c;
    s32 t;
    s32 *q;

    D_800DDA2C->unk0 = 0;
    D_800DDA2C->unk4 = arg0;
    D_800DDA2C->unk6 = arg1;
    D_800DDA2C->unk10 = 0;
    D_800DDA2C->unk11 = arg6;
    p = D_800DDA2C;
    p->unk8 = arg2;
    q = &D_800DDA28;
    t = arg5 << 0x10;
    c = *q;
    c |= t;
    c |= arg4 << 8;
    c |= arg3;
    p->unkC = c;
    D_800DDA2C = p + 1;
    p[1].unk0 = 1;
}
