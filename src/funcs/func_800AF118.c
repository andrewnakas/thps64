/* cflags: -O2 */
#include "common.h"

s16 func_800AF118(s16 arg0, s32 arg1, s16 arg2, s32 arg3) {
    arg1 >>= 3;
    if (arg1 == 0) {
        return arg0;
    }
    {
        s32 x = (arg3 & 0xFFFF) * arg1;
        x >>= 16;
        x += arg2 * arg1;
        return arg0 + x;
    }
}
