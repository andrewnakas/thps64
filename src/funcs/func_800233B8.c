/* cflags: -ffast-math */
#include "common.h"
extern f64 D_80016B78;
s32 func_800233B8(s32 a0) {
    f64 d = a0;
    if (a0 < 0) {
        d += D_80016B78;
    }
    return __builtin_sqrtf((f32)d);
}
