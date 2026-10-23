#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec3i;

Vec3i func_80046E04(Vec3i *a, s32 *d) {
    Vec3i r;
    s32 dv = *d;

    if (dv == 0) {
        return *a;
    }
    r.x = a->x / dv;
    r.y = a->y / *d;
    r.z = a->z / *d;
    return r;
}
