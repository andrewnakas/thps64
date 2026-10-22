#include "common.h"

void func_8009E334(void *, s32);                               /* extern */

void func_80079178(void *arg0, s32 arg1) {
    s32 temp_a1;

    temp_a1 = arg1 & 1;
    if (temp_a1 != 0) {
        func_8009E334(arg0, temp_a1);
    }
}
