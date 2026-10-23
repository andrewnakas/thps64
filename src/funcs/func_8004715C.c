#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec3i;

Vec3i *func_8004715C(Vec3i *arg0, s32 *arg1) {
    arg0->x >>= *arg1;
    arg0->y >>= *arg1;
    arg0->z >>= *arg1;
    return arg0;
}
