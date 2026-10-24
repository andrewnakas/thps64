/* compiler: cc1plus */
/* cflags: -O2 -ffast-math -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

struct Vec3 {
    f32 x, y, z;
    Vec3() {}
    Vec3(const Vec3 &v) { x = v.x; y = v.y; z = v.z; }
    Vec3(f32 a, f32 b, f32 c) { x = a; y = b; z = c; }
    Vec3 operator-(Vec3 b) const { return Vec3(x - b.x, y - b.y, z - b.z); }
    Vec3 operator+(const Vec3 &b) const { return Vec3(x + b.x, y + b.y, z + b.z); }
    Vec3 operator*(f32 s) const { return Vec3(x * s, y * s, z * s); }
    Vec3 operator^(const Vec3 &b) const { return Vec3(y * b.z - z * b.y, z * b.x - x * b.z, x * b.y - y * b.x); }
};

extern "C" s32 func_80083048(Vec3, Vec3, Vec3, Vec3, Vec3);
extern "C" s32 func_80082F54(Vec3, Vec3, Vec3, Vec3, f32);

extern "C" s32 func_800833A8(Vec3 *org, Vec3 *end, Vec3 *v0, Vec3 *v1, Vec3 *v2, f32 *tout, Vec3 *n) {
    Vec3 unused; /* the game frame keeps an unreferenced Vec3 below e1 */
    Vec3 e1;
    Vec3 e2;
    f32 denom;
    f32 num;
    f32 t;
    s32 r;

    e1 = *v1 - *v0;
    e2 = *v2 - *v0;
    *n = e1 ^ e2;
    Vec3 d = *end - *org;
    denom = n->x * d.x + n->y * d.y + n->z * d.z;
    if (denom > 0.0f) {
        return 0;
    }
    num = (v0->x - org->x) * n->x + (v0->y - org->y) * n->y + (v0->z - org->z) * n->z;
    if (denom == 0.0f) {
        return 0;
    }
    t = num / denom;
    if (t < 0.0f) {
        return 0;
    }
    if (t > 1.0f) {
        return 0;
    }
    Vec3 p = *org + (*end - *org) * t;
    if (n->y == 0.0f) {
        r = func_80083048(p, *n, *v0, *v1, *v2);
    } else {
        r = func_80082F54(p, *v0, *v1, *v2, n->y);
    }
    if (r == 0) {
        return 0;
    }
    {
        f32 len = __builtin_sqrtf(n->x * n->x + n->y * n->y + n->z * n->z);
        if (len != 0.0f) {
            f32 inv = 1.0f / len;
            n->x *= inv;
            n->y *= inv;
            n->z *= inv;
        }
    }
    *tout = t;
    return 1;
}
