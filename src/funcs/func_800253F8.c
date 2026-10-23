#include "common.h"

void func_8009E334(void *);
extern u8 D_800170E0[];

void func_800253F8(void **arg0, s32 arg1) {
    *arg0 = D_800170E0;
    if (arg1 & 1) {
        func_8009E334(arg0);
    }
}
