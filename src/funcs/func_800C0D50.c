/* cflags: -O2 */
#include "common.h"

f32 func_800C0D50(s64 arg0) {
    f64 d;
    f64 r;
    f64 e;
    s32 neg;

    neg = 0;
    if (arg0 < 0) {
        arg0 = -arg0;
        neg = 1;
    }
    if ((u64)arg0 >= (1ULL << 53)) {
        if ((u32)arg0 & 0x7FF) {
            arg0 |= 0x800;
        }
    }
    d = (s32)(arg0 >> 32);
    if ((s32)(arg0 >> 32) < 0) {
        d += 4294967296.0;
    }
    d *= 65536.0;
    d *= 65536.0;
    e = (s32)arg0;
    if ((s32)arg0 < 0) {
        e += 4294967296.0;
    }
    r = d + e;
    if (neg) {
        r = -r;
    }
    return r;

}
