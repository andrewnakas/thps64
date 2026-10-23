#include "common.h"

typedef struct {
    s16 x, y, z;
} V3S;

V3S func_800466C4(V3S *a, s32 *sh) {
    V3S r;

    r.x = a->x << *sh;
    r.y = a->y << *sh;
    r.z = a->z << *sh;
    return r;
}
