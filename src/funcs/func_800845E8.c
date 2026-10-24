/* cflags: -fexpensive-optimizations */
#include "common.h"

extern u32 D_800D7368;
extern u32 D_800D7364;

s32 func_800845E8(u16 *a0, s32 a1) {
    u32 x = *a0 << 16;
    u32 t;
    s32 r;

    if (x & D_800D7368) {
        return 0;
    }
    if (~(D_800D7364 | x)) {
        return 0;
    }
    x >>= 16;
    if (x & 1) {
        return 0;
    }
    t = x & 2;
    if (a1) {
        r = 1;
        if (t) {
            return r;
        }
        return 0;
    }
    r = 0;
    if (t) {
        return r;
    }
    r = 1;
    return r;
}
