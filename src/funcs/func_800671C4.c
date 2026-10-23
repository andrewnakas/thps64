#include "common.h"

s32 func_8004B514(s32);
void func_800664D0(s32, u16, s32, s32, s32, s32);

void func_800671C4(u16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_800664D0(func_8004B514(0x238), arg0, arg1, arg4, arg2, arg3);
}
