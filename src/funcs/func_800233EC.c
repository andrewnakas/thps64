/* cflags: -ffast-math */
#include "common.h"
s32 func_800233EC(s32 a0) {
    if (a0 > 0) {
        return __builtin_sqrtf((double)a0);
    }
    return 0;
}
