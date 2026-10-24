/* cflags: -O2 */
#include "common.h"

f32 func_8009FB08(f32 a, f32 b, f32 t, f32 s) {
    f32 d;

    while (a > 3.1415927f) {
        a -= 6.2831855f;
    }
    while (a < -3.1415927f) {
        a += 6.2831855f;
    }
    while (b > 3.1415927f) {
        b -= 6.2831855f;
    }
    while (b < -3.1415927f) {
        b += 6.2831855f;
    }
    d = a - b;
    if (d >= 0.0f ? d > 3.1415927f : -d > 3.1415927f) {
        if (b > 0.0f) {
            b -= 6.2831855f;
        } else {
            b += 6.2831855f;
        }
    }
    return b + (a - b) * t * s;
}
