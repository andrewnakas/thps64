#include "common.h"

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} V3s;

V3s func_800468A8(V3s *a, s32 *s) {
    V3s r;

    r.x = a->x * *s;
    r.y = a->y * *s;
    r.z = a->z * *s;
    return r;
}
