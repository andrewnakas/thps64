#include "common.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} V3i;

V3i func_80046D54(V3i *arg1, s32 *arg2) {
    V3i r;

    r.x = arg1->x << *arg2;
    r.y = arg1->y << *arg2;
    r.z = arg1->z << *arg2;
    return r;
}
