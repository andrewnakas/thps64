/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} SVec800465A0;

SVec800465A0 func_800465A0(SVec800465A0 *a, SVec800465A0 *b) {
    SVec800465A0 r;
    s16 t;

    {
        s16 dx = a->x - b->x;
        s16 dy = a->y - b->y;
        s16 dz = a->z - b->z;
        r.x = dx;
        r.y = dy;
        r.z = dz;
    }
    if (r.x < -0x800) {
        r.x += 0x1000;
    }
    if (r.x > 0x800) {
        r.x -= 0x1000;
    }
    if (r.y < -0x800) {
        r.y += 0x1000;
    }
    if (r.y > 0x800) {
        r.y -= 0x1000;
    }
    if (r.z < -0x800) {
        r.z += 0x1000;
    }
    if (r.z > 0x800) {
        r.z -= 0x1000;
    }
    return r;
}
