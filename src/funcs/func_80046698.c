#include "common.h"

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Vec3s_80046698;

Vec3s_80046698 *func_80046698(Vec3s_80046698 *arg0, Vec3s_80046698 *arg1) {
    s16 x;
    s16 y;
    s16 z;

    x = -arg1->x;
    y = -arg1->y;
    z = -arg1->z;
    arg0->x = x;
    arg0->y = y;
    arg0->z = z;
    return arg0;
}
