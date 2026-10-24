/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

/* scales rows 0-2 of a 4x4 matrix by s[0..2] */
f32 (*func_8009D8B4(f32 m[4][4], f32 *s))[4] {
    f32 t;

    t = s[0];
    m[0][0] *= t;
    t = s[0];
    m[0][1] *= t;
    t = s[0];
    m[0][2] *= t;
    t = s[1];
    m[1][0] *= t;
    t = s[1];
    m[1][1] *= t;
    t = s[1];
    m[1][2] *= t;
    t = s[2];
    m[2][0] *= t;
    t = s[2];
    m[2][1] *= t;
    t = s[2];
    m[2][2] *= t;
    return m;
}
