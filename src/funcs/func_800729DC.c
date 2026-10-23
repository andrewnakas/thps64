#include "common.h"

s32 func_80048F34(void *, void *, s32, s32, s32);
s32 func_8004AEE0(void *);
extern void *D_800D61A8;

s32 func_800729DC(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (func_8004AEE0(D_800D61A8) != 0) {
        return 0;
    }
    return func_80048F34(arg0, D_800D61A8, arg1, arg2, arg3);
}
