#include "common.h"

extern u8 D_800DE564[];

void func_8007D68C(u8 arg0, u8 arg1, u8 arg2) {
    D_800DE564[0] = arg0;
    D_800DE564[1] = arg1;
    D_800DE564[2] = arg2;
}
