/* cflags: -O2 */
#include "common.h"

typedef struct {
    f32 min[3];
    f32 max[3];
} Box_800B76C8;

#define ABSF(x) ((x) >= 0.0f ? (x) : -(x))

s32 func_800B76C8(Box_800B76C8 *b, f32 *p, f32 r, f32 *t, s32 *side) {
    f32 d0, d1, d2, d3, d4, d5;
    s32 n;
    s32 ret;
    f32 x;

    x = p[0];
    if (r < (d0 = b->min[0] - x)) {
        return 0;
    }
    if (r < (d1 = x - b->max[0])) {
        return 0;
    }
    x = p[1];
    if (r < (d2 = b->min[1] - x)) {
        return 0;
    }
    if (r < (d3 = x - b->max[1])) {
        return 0;
    }
    x = p[2];
    if (r < (d4 = b->min[2] - x)) {
        return 0;
    }
    if (r < (d5 = x - b->max[2])) {
        return 0;
    }
    n = 0;
    if (ABSF(d0) < r) {
        side[n] = -1;
        t[n] = -d0 / r;
        n++;
    }
    if (ABSF(d1) < r) {
        side[n] = 1;
        t[n] = -d1 / r;
        n++;
    }
    if (ABSF(d2) < r) {
        side[n] = -2;
        t[n] = -d2 / r;
        n++;
    }
    if (ABSF(d3) < r) {
        side[n] = 2;
        t[n] = -d3 / r;
        n++;
    }
    if (ABSF(d4) < r) {
        side[n] = -3;
        t[n] = -d4 / r;
        n++;
    }
    if (ABSF(d5) < r) {
        side[n] = 3;
        t[n] = -d5 / r;
        n++;
    }
    ret = -1;
    if (n != 0) {
        ret = n;
    }
    return ret;
}
