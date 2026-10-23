#include "common.h"

extern s32 D_800DDC70;
extern s32 D_800DDC74;

void func_80073240(s32 arg0) {
    if (D_800DDC74 != arg0) {
        if (arg0 == 0) {
            D_800DDC70 -= 0x1000;
        } else {
            D_800DDC70 += 0x1000;
        }
        D_800DDC74 = arg0;
    }
}
