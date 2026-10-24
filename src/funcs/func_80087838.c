/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

f64 func_80087838(f64 x) {
    f64 res;
    f64 r;
    f64 t;
    f64 term;
    f64 prev;
    s32 n;

    res = 0.0;
    if (!(x < 0.0)) {
        r = res;
        if (x != 0.0) {
            while (x >= 2.0) {
                x *= 0.5;
                r += 0.6931471805599453;
            }
            while (x < 1.0) {
                x *= 2.0;
                r -= 0.6931471805599453;
            }
            n = 1;
            t = (x - 1.0) / (x + 1.0);
            term = 2.0 * t;
            t *= t;
            do {
                prev = r;
                r += term / n;
                term *= t;
                n += 2;
            } while (r != prev);
            res = r;
        }
    }
    return res;
}
