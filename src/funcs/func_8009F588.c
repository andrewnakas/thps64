/* cflags: -O2 */
#include "common.h"

f32 func_8009F588(f32 y, f32 x) {
    f32 ax;
    f32 ay;
    f32 t;
    f32 r;
    f32 k;
    s32 swap;

    if (x == 0.0f && y == 0.0f) {
        return 0.0f;
    }
    ax = (x >= 0.0f) ? x : -x;
    ay = (y >= 0.0f) ? y : -y;
    swap = 0;
    if (ax < ay) {
        r = ax;
        ax = ay;
        ay = r;
        swap = 1;
    }
    r = ay / ax;
    t = r * 0.7853982f;
    k = ay - ax;
    t += ((k >= 0.0f) ? k : -k) * 0.309f * r;
    if (x >= 0.0f) {
        if (swap) {
            t = 1.5707964f - t;
        }
    } else if (swap) {
        t += 1.5707964f;
    } else {
        t = 3.1415927f - t;
    }
    if (y >= 0.0f) {
        return t;
    }
    return -t;
}
