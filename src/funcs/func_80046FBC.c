#include "common.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} V3i;

V3i func_80046FBC(V3i *arg1, V3i *arg2) {
    V3i r;

    r.x = arg1->x - arg2->x;
    r.y = arg1->y - arg2->y;
    r.z = arg1->z - arg2->z;
    return r;
}
