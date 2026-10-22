#include "common.h"

extern s32 D_800FBCCC;
extern s32 D_800FBCD0;
extern s32 D_800FBCD4;

void func_80079558(s32 arg0) {
    D_800FBCCC = arg0;
    D_800FBCD0 = 0x12B9B0A1;
    D_800FBCD4 = 0x0AA2FB3F;
}
