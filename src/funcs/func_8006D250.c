#include "common.h"

extern s32 D_800D61A8;
extern s32 D_800DC618;
extern s32 D_800DC924;
extern s32 D_800DC928;

void func_8006D250(s32 arg0, s32 arg1) {
    if (D_800DC618 == 1) {
        if (arg0 == D_800D61A8) {
            D_800DC924 = arg1;
            return;
        }
        D_800DC928 = arg1;
    }
}
