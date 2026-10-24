#include "common.h"

typedef struct State80073A90 { u8 pad0[0xC]; u16 unkC; } State80073A90;

extern State80073A90 *D_800D8434;
extern s32 D_800DDF10;
extern s32 D_800DE0C0;
extern s32 D_800DE0C4;
extern s32 D_800DE0C8;

void func_80073A90(void) {
    D_800DDF10 = 0;
    D_800D8434->unkC = 0xD55;
    D_800DE0C0 = 0x122;
    D_800DE0C4 = 0x96;
    D_800DE0C8 = -0x6C;
}
