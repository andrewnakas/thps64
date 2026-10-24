/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    f32 x, y, z;
} Vec3f_800226A0;

typedef struct {
    f32 m[3][4];
    Vec3f_800226A0 t;
    f32 w;
} Mtx_800226A0;

typedef struct {
    s32 x, y, z;
} Vec3i_800226A0;

void func_80041F80(Mtx_800226A0 *, void *);
void func_8009C8EC(Mtx_800226A0 *, Mtx_800226A0 *);
void func_8009CA84(Mtx_800226A0 *, Mtx_800226A0 *);

static inline void vset(Vec3f_800226A0 *v, f32 x, f32 y, f32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline void vscale(Vec3f_800226A0 *v, f32 s) {
    v->x *= s;
    v->y *= s;
    v->z *= s;
}

static inline void f2i(s32 *d, f32 f) {
    s32 v;

    if (f < -2147483648.0f) {
        v = 0x80000000;
    } else if (f > 2147483648.0f) {
        v = 0x80000000;
    } else {
        v = (s32)f;
    }
    *d = v;
}

Vec3i_800226A0 *func_800226A0(u8 *arg0, Vec3i_800226A0 *arg1, Vec3i_800226A0 *arg2) {
    Vec3f_800226A0 a;
    Vec3f_800226A0 r;
    Mtx_800226A0 m;
    Vec3f_800226A0 t;
    Vec3f_800226A0 p;
    Mtx_800226A0 inv;
    f32 k;

    func_80041F80(&m, arg0);
    vset(&p, *(s32 *)(arg0 + 0x14), *(s32 *)(arg0 + 0x18), *(s32 *)(arg0 + 0x1C));
    k = 0.00024414062f;
    vset(&t, p.x * k, p.y * k, p.z * k);
    m.t = t;
    func_8009C8EC(&inv, &m);
    func_8009CA84(&m, &inv);
    vset(&t, arg1->x * k, arg1->y * k, arg1->z * k);
    a = t;
    vset(&t, a.x * m.m[0][0] + a.y * m.m[1][0] + a.z * m.m[2][0] + m.t.x,
         a.x * m.m[0][1] + a.y * m.m[1][1] + a.z * m.m[2][1] + m.t.y,
         a.x * m.m[0][2] + a.y * m.m[1][2] + a.z * m.m[2][2] + m.t.z);
    r = t;
    vscale(&r, 4096.0f);
    f2i(&arg2->x, r.x);
    f2i(&arg2->y, r.y);
    f2i(&arg2->z, r.z);
    return arg2;
}
