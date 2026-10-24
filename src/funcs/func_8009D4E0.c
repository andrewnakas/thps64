/* cflags: -O2 */
#include "common.h"

f32 func_80001CA0(f32);
f32 func_800018C0(f32);

f32 *func_8009D4E0(f32 *m, f32 a) {
    f32 s;
    f32 c;
    f32 x;

    s = func_80001CA0(a);
    c = func_800018C0(a);
    x = m[0];
    m[0] = x * c + m[2] * s;
    m[2] = x * -s + m[2] * c;
    x = m[4];
    m[4] = x * c + m[6] * s;
    m[6] = x * -s + m[6] * c;
    x = m[8];
    m[8] = x * c + m[10] * s;
    m[10] = x * -s + m[10] * c;
    x = m[12];
    m[12] = x * c + m[14] * s;
    m[14] = x * -s + m[14] * c;
    return m;
}
