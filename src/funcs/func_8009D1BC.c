/* cflags: -O2 */
#include "common.h"

f32 func_800018C0(f32);
f32 func_80001CA0(f32);

f32 (*func_8009D1BC(f32 (*m)[4], f32 a))[4] {
    f32 s;
    f32 c;
    f32 t;

    s = func_80001CA0(a);
    c = func_800018C0(a);
    t = m[1][0];
    m[1][0] = c * t + s * m[2][0];
    m[2][0] = -s * t + c * m[2][0];
    t = m[1][1];
    m[1][1] = c * t + s * m[2][1];
    m[2][1] = -s * t + c * m[2][1];
    t = m[1][2];
    m[1][2] = c * t + s * m[2][2];
    m[2][2] = -s * t + c * m[2][2];
    return m;
}
