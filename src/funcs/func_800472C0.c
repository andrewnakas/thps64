#include "common.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3i_800472C0;

Vec3i_800472C0 *func_800472C0(Vec3i_800472C0 *arg0, Vec3i_800472C0 *arg1) {
    arg0->x += arg1->x;
    arg0->y += arg1->y;
    arg0->z += arg1->z;
    return arg0;
}
