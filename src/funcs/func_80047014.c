#include "common.h"

typedef struct {
    s32 x, y, z;
} V3I;

V3I func_80047014(V3I *a, V3I *b) {
    V3I r;

    r.x = a->x + b->x;
    r.y = a->y + b->y;
    r.z = a->z + b->z;
    return r;
}
