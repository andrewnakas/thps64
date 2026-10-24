/* cflags: -O2 */
#include "common.h"

typedef struct {
    f32 x, y, z;
} VDCE0;

static inline VDCE0 vsub_DCE0(VDCE0 *a, VDCE0 *b) {
    VDCE0 r;
    VDCE0 t;
    f32 x, y, z;
    t.x = b->x;
    t.y = b->y;
    t.z = b->z;
    x = a->x - t.x;
    y = a->y - t.y;
    z = a->z - t.z;
    r.x = x;
    r.y = y;
    r.z = z;
    return r;
}

static inline VDCE0 vcross_DCE0(VDCE0 *a, VDCE0 *b) {
    VDCE0 r;
    f32 x, y, z;
    x = a->y * b->z - a->z * b->y;
    y = a->z * b->x - a->x * b->z;
    z = a->x * b->y - a->y * b->x;
    r.x = x;
    r.y = y;
    r.z = z;
    return r;
}

static inline void vnorm_DCE0(VDCE0 *v) {
    f32 xx = v->x * v->x;
    f32 yy = v->y * v->y;
    f32 zz = v->z * v->z;
    f32 len = __builtin_sqrtf(xx + yy + zz);
    if (len != 0.0f) {
        f32 inv = 1.0f / len;
        f32 x = v->x * inv;
        f32 y = v->y * inv;
        f32 z = v->z * inv;
        v->x = x;
        v->y = y;
        v->z = z;
    }
}

static inline void vnorm2_DCE0(VDCE0 *v) {
    f32 xx = v->x * v->x;
    f32 yy = v->y * v->y;
    f32 zz = v->z * v->z;
    f32 len = __builtin_sqrtf(xx + yy + zz);
    if (len != 0.0f) {
        f32 inv = 1.0f / len;
        v->x *= inv;
        v->y *= inv;
        v->z *= inv;
    }
}

f32 (*func_8009DCE0(f32 (*m)[4], VDCE0 *eye, VDCE0 *at, VDCE0 *up))[4] {
    VDCE0 x;
    VDCE0 y;
    VDCE0 z;

    z = vsub_DCE0(eye, at);
    vnorm_DCE0(&z);
    x = vcross_DCE0(up, &z);
    vnorm2_DCE0(&x);
    y = vcross_DCE0(&z, &x);
    vnorm_DCE0(&y);
    {
        f32 xx = x.x, xy = x.y, xz = x.z;
        f32 yx = y.x, yy = y.y, yz = y.z;
        f32 zx = z.x, zy = z.y, zz = z.z;
        m[0][3] = 0.0f;
        m[1][3] = 0.0f;
        m[2][3] = 0.0f;
        m[0][0] = xx;
        m[0][1] = xy;
        m[0][2] = xz;
        m[1][0] = yx;
        m[1][1] = yy;
        m[1][2] = yz;
        m[2][0] = zx;
        m[2][1] = zy;
        m[2][2] = zz;
    }
    m[3][0] = eye->x;
    m[3][1] = eye->y;
    m[3][2] = eye->z;
    m[3][3] = 1.0f;
    return m;
}
