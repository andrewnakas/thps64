/* cflags: -O2 */
#include "common.h"

extern s32 func_800B42A8(s32, s32);

s32 func_800A06E8(s32 arg0, s32 arg1, s32 arg2) {
    s32 i;

    i = 0;
    do {
        if (arg1 == i || arg1 == -1) {
            if (func_800B42A8(i, arg2) != 0) {
                return 1;
            }
        }
        i++;
    } while (i < 4);
    return 0;
}
