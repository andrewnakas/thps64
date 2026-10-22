#include "common.h"
void func_8009B7D8(s32, s32, s32, s32);
void func_80084B64(s32 arg0, s32 arg1) {
    register s32 temp_a0 __asm__("$4") = arg0;
    __asm__("" : "+r" (temp_a0));
    func_8009B7D8(temp_a0, temp_a0, arg1, 8);
}
