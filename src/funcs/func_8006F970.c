#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec3i;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s8 unk10;
    s8 unk11;
    s8 pad12[2];
    Vec3i pos;
} Cmd;

extern s32 D_800DDA28;
extern Cmd *D_800DDA2C;

void func_8006F970(Vec3i *arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4, s32 arg5) {
    Cmd *p;
    s32 c;
    s32 t;
    s32 *q;

    D_800DDA2C->unk0 = 0;
    D_800DDA2C->pos = *arg0;
    D_800DDA2C->unk10 = 1;
    D_800DDA2C->unk11 = arg5;
    p = D_800DDA2C;
    p->unk8 = arg1;
    q = &D_800DDA28;
    t = arg4 << 0x10;
    c = *q;
    c |= t;
    c |= arg3 << 8;
    c |= arg2;
    p->unkC = c;
    D_800DDA2C = p + 1;
    p[1].unk0 = 1;
}
