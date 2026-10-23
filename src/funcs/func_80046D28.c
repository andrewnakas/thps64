#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec3i;

Vec3i *func_80046D28(Vec3i *arg0, Vec3i *arg1) {
    s32 x = -arg1->x;
    s32 y = -arg1->y;
    s32 z = -arg1->z;
    arg0->x = x;
    arg0->y = y;
    arg0->z = z;
    return arg0;
}
