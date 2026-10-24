/* cflags: -O2 */
#include "common.h"

s32 func_800B4240(s32, s32);

s32 func_800A0670(void *arg0, s32 arg1, s32 arg2) {
    s32 i = 0;

    do {
        if ((arg1 == i || arg1 == -1) && func_800B4240(i, arg2)) {
            return 1;
        }
        i++;
    } while (i < 4);
    return 0;
}
