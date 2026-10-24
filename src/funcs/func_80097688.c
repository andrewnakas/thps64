/* cflags: -O2 -fno-schedule-insns2 */
#include "common.h"

s32 func_8009E334(s32, s32); /* extern */
extern s16 D_800D0FD8;

void func_80097688(s32 arg0, s32 arg1) {
    s32 temp_a1;

    temp_a1 = arg1 & 1;
    D_800D0FD8 = 0;
    if (temp_a1 != 0) {
        func_8009E334(arg0, temp_a1);
    }
}
