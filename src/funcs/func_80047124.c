#include "common.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3i_80047124;

Vec3i_80047124 *func_80047124(Vec3i_80047124 *arg0, s32 *arg1) {
    arg0->x <<= *arg1;
    arg0->y <<= *arg1;
    arg0->z <<= *arg1;
    return arg0;
}
