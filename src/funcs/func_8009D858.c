/* cflags: -O2 -fno-strength-reduce */
#include "common.h"

f32 *func_8009D858(f32 *m, f32 *v) {
    s32 i;
    f32 *p;

    i = 0;
    p = m;
    while (1) {
        if (i >= 3) break;
        i++;
        p[12] += v[0] * p[0] + v[1] * p[4] + v[2] * p[8];
        p++;
    }
    return m;
}
