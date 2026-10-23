#include "common.h"

void func_8009E334(void *);
extern u8 D_80017188[];

void func_800261DC(void **arg0, s32 arg1) {
    *arg0 = D_80017188;
    if (arg1 & 1) {
        func_8009E334(arg0);
    }
}
