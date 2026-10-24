/* cflags: -Wa,-no-m4100 */
#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec3_49BA0;

s32 func_800233B8(s32);

s32 func_80049BA0(Vec3_49BA0 *a, Vec3_49BA0 *b) {
    Vec3_49BA0 d;

    d.x = (a->x - b->x) >> 12;
    d.y = (a->y - b->y) >> 12;
    d.z = (a->z - b->z) >> 12;
    return func_800233B8(d.x * d.x + d.y * d.y + d.z * d.z);
}
