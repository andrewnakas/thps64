/* cflags: -O2 */
#include "common.h"

f32 func_80001CA0(f32);
f32 func_800018C0(f32);

f32 *func_8009D080(f32 *m, f32 x, f32 y, f32 z, f32 a) {
    f32 s;
    f32 c;
    f32 t;
    f32 xx, yy, zz, xy, yz, zx;
    f32 txy, tyz, tzx;
    f32 xs, ys, zs;

    s = func_80001CA0(a);
    c = func_800018C0(a);
    xx = x * x;
    yy = y * y;
    xy = x * y;
    zz = z * z;
    yz = y * z;
    zx = z * x;
    xs = x * s;
    ys = y * s;
    zs = z * s;
    t = 1.0f - c;
    txy = xy * t;
    tyz = yz * t;
    tzx = zx * t;
    c *= 1.0f - t;
    xx += c;
    m[3] = m[7] = m[11] = m[12] = m[13] = m[14] = 0.0f;
    m[15] = 1.0f;
    m[9] = tyz - xs;
    m[6] = tyz + xs;
    m[8] = tzx + ys;
    m[2] = tzx - ys;
    m[4] = txy - zs;
    m[1] = txy + zs;
    m[0] = xx;
    m[5] = yy + c;
    m[10] = zz + c;
    return m;
}
