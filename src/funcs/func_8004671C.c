#include "common.h"

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} V3s;

V3s func_8004671C(V3s *arg1, s32 *arg2) {
    V3s r;

    r.x = arg1->x >> *arg2;
    r.y = arg1->y >> *arg2;
    r.z = arg1->z >> *arg2;
    return r;
}
