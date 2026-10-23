#include "common.h"

typedef struct {
    s32 x, y, z;
} V3;

V3 func_80046EF4(s32 *s, V3 *v) {
    V3 r;
    r.x = v->x * *s;
    r.y = v->y * *s;
    r.z = v->z * *s;
    return r;
}
