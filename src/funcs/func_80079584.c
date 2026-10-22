#include "common.h"
s32 func_80023190(s32, s32);
s32 func_800233EC(s32);
extern s32 D_800DE12C;
extern s32 D_800DE130;
void func_80079584(s32 arg0, s32 arg1) {
    register s32 temp_v0 __asm__("$2") = arg0 * arg0;
    s32 temp_v1;
    s32 *temp_s2;
    __asm__ volatile ("nop\n\tnop" : "+r" (temp_v0));
    temp_v1 = arg1 * arg1;
    D_800DE130 = func_800233EC(temp_v0 + temp_v1);
    temp_s2 = &D_800DE12C;
    *temp_s2 = func_80023190(arg1, arg0);
}
