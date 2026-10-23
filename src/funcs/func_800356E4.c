#include "common.h"

void func_800356CC(u8, u8, u8);
extern u8 D_800D36E0[];

void func_800356E4(u8 arg0, u8 arg1, u8 arg2) {
    D_800D36E0[0] = arg0;
    D_800D36E0[1] = arg1;
    D_800D36E0[2] = arg2;
    func_800356CC(arg0, arg1, arg2);
}
