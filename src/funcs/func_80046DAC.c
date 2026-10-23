#include "common.h"

typedef struct {
    s32 x, y, z;
} V3I;

V3I func_80046DAC(V3I *a, s32 *sh) {
    V3I r;

    r.x = a->x >> *sh;
    r.y = a->y >> *sh;
    r.z = a->z >> *sh;
    return r;
}
