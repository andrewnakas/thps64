#include "common.h"

extern s32 D_800DDA2C;
extern s32 D_800DCC20;
extern s32 D_800DDC30;
extern s32 D_800DDA30;

void func_8006FA6C(void) {
    D_800DDA2C = (s32)&D_800DCC20;
    D_800DCC20 = 1;
    D_800DDC30 = (s32)&D_800DDA30;
}
