/* cflags: -O2 */
#include "common.h"

f32 func_800018C0(f32);
f32 func_80001CA0(f32);

f32 (*func_8009D624(f32 (*m)[4], f32 a))[4] {
    f32 s;
    f32 c;
    f32 t;

    s = func_80001CA0(a);
    c = func_800018C0(a);
    t = m[0][0];
    m[0][0] = c * t + s * m[1][0];
    m[1][0] = -s * t + c * m[1][0];
    t = m[0][1];
    m[0][1] = c * t + s * m[1][1];
    m[1][1] = -s * t + c * m[1][1];
    t = m[0][2];
    m[0][2] = c * t + s * m[1][2];
    m[1][2] = -s * t + c * m[1][2];
    return m;
}
