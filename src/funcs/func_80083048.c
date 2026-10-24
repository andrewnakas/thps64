/* compiler: cc1plus */
/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

struct Vec3 {
    f32 x, y, z;
    Vec3() {}
    Vec3(f32 a, f32 b, f32 c) { x = a; y = b; z = c; }
    Vec3(const Vec3 &v) { x = v.x; y = v.y; z = v.z; }
    Vec3 operator-(Vec3 b) const { return Vec3(x - b.x, y - b.y, z - b.z); }
};

extern "C" s32 func_80083048(Vec3 *p, Vec3 *n, Vec3 *a, Vec3 *b, Vec3 *c) {
    Vec3 e;
    Vec3 f;

    e = *p - *a;
    f = *b - *a;
    if ((e.y * f.z - e.z * f.y) * n->x - (e.x * f.z - e.z * f.x) * n->y + (e.x * f.y - e.y * f.x) * n->z > 0.0f) {
        return 0;
    }
    e = *p - *b;
    f = *c - *b;
    if ((e.y * f.z - e.z * f.y) * n->x - (e.x * f.z - e.z * f.x) * n->y + (e.x * f.y - e.y * f.x) * n->z > 0.0f) {
        return 0;
    }
    e = *p - *c;
    f = *a - *c;
    if ((e.y * f.z - e.z * f.y) * n->x - (e.x * f.z - e.z * f.x) * n->y + (e.x * f.y - e.y * f.x) * n->z > 0.0f) {
        return 0;
    }
    return 1;
}
