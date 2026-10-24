/* cflags: -O2 */
#include "common.h"

f32 func_8009F6BC(f32 x, f32 y) {
    f32 len;
    f32 ay, ax, t, r, d, k;
    s32 swap;
    f32 res;

    len = __builtin_sqrtf(x * x + y * y);
    if (len == 0.0f) {
        return 0.0f;
    }
    if (len != 1.0) {
        x /= len;
        y /= len;
    }
    if (y == 0.0f && x == 0.0f) {
        return 0.0f;
    }
    ay = (y >= 0.0f) ? y : -y;
    ax = (x >= 0.0f) ? x : -x;
    swap = 0;
    if (ay < ax) {
        t = ay;
        ay = ax;
        ax = t;
        swap = 1;
    }
    t = ax / ay;
    r = t * 0.7853982f;
    d = ax - ay;
    if (d >= 0.0f) {
        k = d * 0.309f;
    } else {
        k = -d * 0.309f;
    }
    do { r = r + k * t; } while (0);
    if (y >= 0.0f) {
        if (swap) {
            r = 1.5707964f - r;
        }
    } else if (swap) {
        r += 1.5707964f;
    } else {
        r = 3.1415927f - r;
    }
    if (x >= 0.0f) {
        return r;
    }
    return -r;
}
