#include "common.h"

extern s32 *func_8005EAB4(u32, s32, s32);

s32 *func_8004B514(u32 arg0) {
    s32 *ret;
    s32 *p;
    u32 i;

    ret = func_8005EAB4(arg0, 0, 1);
    arg0 += 3;
    p = ret;
    arg0 >>= 2;
    for (i = 0; i < arg0; i++) {
        *p++ = 0;
    }
    return ret;
}
