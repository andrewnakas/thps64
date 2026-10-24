/* cflags: -O2 */
#include "common.h"

void func_800A6758(void);
extern s32 D_800EA580;
extern s32 D_800EA584;

f64 func_800A67B4(s32 *arg0) {
    s32 t;
    s32 u;
    s32 w;
    f64 hi;
    f64 a;
    f64 b;

    func_800A6758();
    t = D_800EA584 - arg0[0];
    hi = t;
    if (t < 0) {
        hi += 4294967296.0;
    }
    hi *= 93.875101696;
    u = D_800EA580;
    a = u;
    if (u < 0) {
        a += 4294967296.0;
    }
    w = arg0[1];
    b = w;
    if (w < 0) {
        b += 4294967296.0;
    }
    return hi + (a - b) / 45751932.284543216;
}
