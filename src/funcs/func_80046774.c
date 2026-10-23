#include "common.h"

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} V3s_80046774;

V3s_80046774 func_80046774(V3s_80046774 *arg0, s32 *arg1) {
    V3s_80046774 r;

    r.x = arg0->x / *arg1;
    r.y = arg0->y / *arg1;
    r.z = arg0->z / *arg1;
    return r;
}
