#include "common.h"

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Vec3s_80046AB8;

Vec3s_80046AB8 *func_80046AB8(Vec3s_80046AB8 *arg0, s32 *arg1) {
    arg0->x >>= *arg1;
    arg0->y >>= *arg1;
    arg0->z >>= *arg1;
    return arg0;
}
