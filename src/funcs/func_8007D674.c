#include "common.h"

extern u8 D_800DE568[];

void func_8007D674(u8 arg0, u8 arg1, u8 arg2) {
    D_800DE568[0] = arg0;
    D_800DE568[1] = arg1;
    D_800DE568[2] = arg2;
}
