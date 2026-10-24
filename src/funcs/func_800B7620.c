#include "common.h"

typedef struct {
    f32 x, y, z;
} Vec800B7620;

typedef struct {
    Vec800B7620 min;
    Vec800B7620 max;
    s32 empty;
} Box800B7620;

void func_800B7620(Box800B7620 *arg0, Vec800B7620 *arg1) {
    f32 *mn;
    f32 *mx;
    f32 *v;
    f32 *end;
    f32 t;

    mn = &arg0->min.x;
    mx = &arg0->max.x;
    if (arg0->empty != 0) {
        arg0->empty = 0;
        arg0->max = *arg1;
        arg0->min = arg0->max;
        return;
    }
    v = &arg1->x;
    end = v + 3;
    while (1) {
        if ((s32)v >= (s32)end) break;
        t = *v;
        if (*mn < t) {
            t = *mn;
        }
        *mn = t;
        t = *v;
        if (t < *mx) {
            t = *mx;
        }
        *mx = t;
        mx++;
        v++;
        mn++;
    }
}
