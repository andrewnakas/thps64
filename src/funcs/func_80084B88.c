#include "common.h"

s32 func_80084BD4(void *, s32);                          /* extern */
void func_8009B650(s32, s32);                          /* extern */
extern s32 D_800F566C[];

void func_80084B88(s32 arg0) {
    register s32 *temp_s1 __asm__("$17") = D_800F566C;

    s32 temp_a1;
    s32 temp_v0;
    __asm__("" : "+r" (temp_s1));
    temp_v0 = func_80084BD4(temp_s1, 1);
    temp_a1 = *(s32 *) ((u8 *) temp_s1 + 4);
    temp_a1 += temp_v0;
    func_8009B650(arg0, temp_a1);
}
