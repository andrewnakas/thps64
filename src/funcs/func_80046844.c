#include "common.h"

typedef struct {
    s16 x, y, z;
} V3s_80046844;

V3s_80046844 func_80046844(s32 *s, V3s_80046844 *v) {
    V3s_80046844 r;

    r.x = v->x * *s;
    r.y = v->y * *s;
    r.z = v->z * *s;
    return r;
}
