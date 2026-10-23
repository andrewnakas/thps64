#include "common.h"

typedef struct {
    s32 unk0[4];
} Unk80087DB0;

extern u8 D_800D0FC0[];
extern u8 D_800DC3F8[];

void func_80087DB0(u8 *arg0) {
    u8 *table = D_800DC3F8;
    u8 *context = D_800D0FC0;

    ((Unk80087DB0 *) (table + 0x120))[context[0x16]].unk0[0] = 0;
    arg0[0x539] = 0;
    arg0[0x535] = 0;
    ((Unk80087DB0 *) (table + 0x120))[context[0x16]].unk0[1] = 1;
    arg0[0x53A] = 1;
    arg0[0x536] = 1;
    ((Unk80087DB0 *) (table + 0x120))[context[0x16]].unk0[2] = 2;
    arg0[0x53B] = 2;
    arg0[0x537] = 2;
    ((Unk80087DB0 *) (table + 0x120))[context[0x16]].unk0[3] = 3;
    arg0[0x53C] = 3;
    arg0[0x538] = 3;
    *(s32 *) (arg0 + 0x550) = 1;
    *(s32 *) (arg0 + 0x554) = 1;
    *(s32 *) (arg0 + 0x528) = 1;
}
