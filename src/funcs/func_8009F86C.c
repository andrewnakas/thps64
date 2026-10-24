/* compiler: cc1plus */
/* cflags: -O2 */
/* Cubic Bezier point. r.z is written through a reference: the store is then a scalar (non-struct) MEM at a fixed
   frame address, which GCC 2.8's sched.c disambiguates from the struct stores through the return pointer, so it
   sinks after out->x/out->y like the game. */
#include "common.h"

struct Vec3 {
    f32 x, y, z;
    Vec3() {}
    Vec3(f32 a, f32 b, f32 c) : x(a), y(b), z(c) {}
    Vec3(const Vec3 &v) : x(v.x), y(v.y), z(v.z) {}
};

extern "C" Vec3 func_8009F86C(f32 t, Vec3 *p0, Vec3 *p1, Vec3 *p2, Vec3 *p3) {
    Vec3 r;
    f32 u, k, t3, u3, b1, b2;

    r.x = 0.0f;
    r.y = 0.0f;
    r.z = 0.0f;
    if (t < 0.0 || t > 1.0) {
        return r;
    }
    u = 1.0f - t;
    k = u * 3.0f;
    u3 = u * u * u;
    b1 = k * u * t;
    t3 = t * t * t;
    b2 = k * t * t;
    r.x = u3 * p0->x + b1 * p1->x + b2 * p2->x + t3 * p3->x;
    r.y = u3 * p0->y + b1 * p1->y + b2 * p2->y + t3 * p3->y;
    f32 &z = r.z;
    z = u3 * p0->z + b1 * p1->z + b2 * p2->z + t3 * p3->z;
    return Vec3(r.x, r.y, r.z);
}
