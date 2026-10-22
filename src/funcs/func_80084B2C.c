#include "common.h"
s32 func_80084AA8(s32);
void func_8009B7D8(s32, s32, s32, s32);
void func_80084B2C(s32 arg0) {
    s32 temp_v0 = func_80084AA8(arg0);
    register s32 temp_a0 __asm__("$4") = arg0;
    __asm__("" : "+r" (temp_a0));
    func_8009B7D8(temp_a0, temp_a0, temp_v0, 8);
}
