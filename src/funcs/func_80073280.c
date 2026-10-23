#include "common.h"

extern s32 D_800DDC70;
extern s32 D_800DDC74;

void func_80073280(void) {
    D_800DDC74 = 0;
    D_800DDC70 = 0xFFF;
}
