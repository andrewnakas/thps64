#include "common.h"

void func_8009E334(void *);

void func_80072FAC(void *arg0, s32 arg1) {
    s32 temp_a1;

    temp_a1 = arg1 & 1;
    if (temp_a1 != 0) {
        func_8009E334(arg0);
    }
}
