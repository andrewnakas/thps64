/* cflags: -O2 */
#include "common.h"

s16 func_800AEFF8(f64 a, f64 b, s32 n, u16 *frac) {
    f64 x;
    s16 i1;
    s16 i2;
    f64 y;
    f64 z;
    f64 inv;
    u32 v;

    if (n == 0) {
        if (a <= b) {
            *frac = 0xFFFF;
            return 0x7FFF;
        }
        *frac = 0;
        return 0;
    }
    inv = 1.0 / n;
    if (b < 1.0) {
        b = 1.0;
    }
    if (a <= 0.0) {
        a = 1.0;
    }
    y = (b - a) * inv * 8.0;
    i1 = y;
    z = (y - i1) + 1.0;
    i2 = z;
    x = (z - i2) * 65535.0;
    i1--;
    i1 += i2;
    if (x >= 2147483648.0) {
        goto big;
    }
    v = (s32) x;
    goto end;
big:
    v = (s32) (x - 2147483648.0);
    v |= 0x80000000;
end:
    *frac = v;
    return i1;
}
