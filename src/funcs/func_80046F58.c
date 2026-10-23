#include "common.h"

typedef struct {
    s32 x, y, z;
} V3i_80046F58;

V3i_80046F58 func_80046F58(V3i_80046F58 *v, s32 *s) {
    V3i_80046F58 r;

    r.x = v->x * *s;
    r.y = v->y * *s;
    r.z = v->z * *s;
    return r;
}
