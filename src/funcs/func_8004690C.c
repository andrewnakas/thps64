#include "common.h"

typedef struct {
    s16 x, y, z;
} V3S;

V3S func_8004690C(V3S *a, V3S *b) {
    V3S r;

    r.x = a->x - b->x;
    r.y = a->y - b->y;
    r.z = a->z - b->z;
    return r;
}
