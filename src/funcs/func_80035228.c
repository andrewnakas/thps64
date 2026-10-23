#include "common.h"

extern s32 D_800FA550[];
extern s32 D_800D36F4;

void func_80035228(s32 arg0) {
    D_800FA550[D_800D36F4++] = arg0;
}
