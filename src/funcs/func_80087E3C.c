#include "common.h"

typedef struct {
    u8 unk0[16];
} Unk80087E3C;

extern u8 D_800D0FC0[];
extern u8 D_800DC3F8[];

void func_80087E3C(u8 *arg0) {
    u8 *table = D_800DC3F8;
    u8 *context = D_800D0FC0;
    u8 value;

    value = ((Unk80087E3C *) (table + 0x120))[context[0x16]].unk0[3];
    arg0[0x539] = value;
    arg0[0x535] = value;
    value = ((Unk80087E3C *) (table + 0x120))[context[0x16]].unk0[7];
    arg0[0x53A] = value;
    arg0[0x536] = value;
    value = ((Unk80087E3C *) (table + 0x120))[context[0x16]].unk0[11];
    arg0[0x53B] = value;
    arg0[0x537] = value;
    value = ((Unk80087E3C *) (table + 0x120))[context[0x16]].unk0[15];
    arg0[0x53C] = value;
    arg0[0x538] = value;
    *(s32 *) (arg0 + 0x550) = ((s32 *) (table + 0x118))[context[0x16]];
    *(s32 *) (arg0 + 0x554) = ((s32 *) (table + 0x110))[context[0x16]];
}
