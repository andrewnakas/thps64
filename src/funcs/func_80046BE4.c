#include "common.h"

typedef struct {
    s16 x, y, z;
} Vec3s;

Vec3s *func_80046BE4(Vec3s *arg0, Vec3s *arg1) {
    arg0->x -= arg1->x;
    arg0->y -= arg1->y;
    arg0->z -= arg1->z;
    return arg0;
}
