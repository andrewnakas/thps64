#include "common.h"

extern s32 D_800E8A10;

s32 func_80084724(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_800E8A10;
    D_800E8A10 = arg0;
    return temp_v0;
}
