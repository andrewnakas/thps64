/* cflags: -O2 */
#include "common.h"

f32 func_800018C0(f32);
f32 func_80001CA0(f32);

f32 (*func_8009D2A8(f32 (*m)[4], f32 a))[4] {
    f32 s;
    f32 c;
    f32 t;

    s = func_80001CA0(a);
    c = func_800018C0(a);
    t = m[0][1];
    m[0][1] = t * c + m[0][2] * -s;
    m[0][2] = t * s + m[0][2] * c;
    t = m[1][1];
    m[1][1] = t * c + m[1][2] * -s;
    m[1][2] = t * s + m[1][2] * c;
    t = m[2][1];
    m[2][1] = t * c + m[2][2] * -s;
    m[2][2] = t * s + m[2][2] * c;
    t = m[3][1];
    m[3][1] = t * c + m[3][2] * -s;
    m[3][2] = t * s + m[3][2] * c;
    return m;
}
