/* cflags: -O2 */
#include "common.h"

f32 func_80001CA0(f32);
f32 func_800018C0(f32);

f32 *func_8009D710(f32 *m, f32 a) {
    f32 s;
    f32 c;
    f32 x;

    s = func_80001CA0(a);
    c = func_800018C0(a);
    x = m[0];
    m[0] = x * c + m[1] * -s;
    m[1] = x * s + m[1] * c;
    x = m[4];
    m[4] = x * c + m[5] * -s;
    m[5] = x * s + m[5] * c;
    x = m[8];
    m[8] = x * c + m[9] * -s;
    m[9] = x * s + m[9] * c;
    x = m[12];
    m[12] = x * c + m[13] * -s;
    m[13] = x * s + m[13] * c;
    return m;
}
