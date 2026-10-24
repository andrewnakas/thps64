#include "common.h"

typedef struct { s16 x, y, z; } V3s80046964;

V3s80046964 func_80046964(V3s80046964 *a, V3s80046964 *b) {
    V3s80046964 r;

    r.x = a->x + b->x;
    r.y = a->y + b->y;
    r.z = a->z + b->z;
    return r;
}
