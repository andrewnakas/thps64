/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-no-m4100 */
#include "common.h"

typedef struct {
    s32 x, y, z, w;
} Q4;

Q4 func_800673B0(Q4 *a, Q4 *b) {
    Q4 q;
    s32 w, x, y, z;

    q = *b;
    w = (q.w * a->w - q.x * a->x - q.y * a->y - q.z * a->z) >> 12;
    x = (q.w * a->x + q.x * a->w + q.y * a->z - q.z * a->y) >> 12;
    y = (q.w * a->y + q.y * a->w + q.z * a->x - q.x * a->z) >> 12;
    z = (q.w * a->z + q.z * a->w + q.x * a->y - q.y * a->x) >> 12;
    q.x = x;
    q.y = y;
    q.z = z;
    q.w = w;
    return q;
}
