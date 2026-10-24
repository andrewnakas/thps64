/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-O0 */
#include "common.h"

extern f64 D_8001EE00;

static inline f64 ln_(f64 x) {
    f64 l;
    f64 prev;
    f64 term;
    f64 z;
    f64 z2;
    s32 i;

    if (x < 0.0 || x == 0.0) {
        return 0.0;
    }
    l = 0.0;
    while (x >= 2.0) {
        x *= 0.5;
        l += 0.6931471805599453;
    }
    while (x < 1.0) {
        x += x;
        l -= 0.6931471805599453;
    }
    i = 1;
    x = (x - 1.0) / (x + 1.0);
    term = x + x;
    x *= x;
    do {
        prev = l;
        l += term / i;
        term *= x;
        i += 2;
    } while (l != prev);
    return l;
}

static inline f64 exp_(f64 a) {
    f64 fa;
    f64 t;
    f64 r;
    f64 term;
    f64 prev;
    s32 i;
    s32 k;

    fa = __builtin_fabs(a);
    if (fa < 2.220446049250313e-16) {
        return 1.0;
    }
    k = fa * 1.4426950408889634;
    if (k > 1024) {
        if (a >= 0.0) {
            return D_8001EE00;
        }
        return 0.0;
    }
    t = fa - k * 0.6931471805599453;
    r = 1.0;
    term = r;
    i = 1;
    do {
        prev = r;
        term *= t / i;
        r += term;
        i++;
    } while (r != prev);
    while (k != 0) {
        k--;
        r += r;
    }
    if (a >= 0.0) {
        return r;
    }
    return 1.0 / r;
}

f64 func_800872F0(f64 x, f64 y) {
    s32 n;
    f64 t;

    n = y;
    if (x != 0.0 && y == 0.0) {
        return 1.0;
    }
    if (x == 0.0) {
        return 0.0;
    }
    if (x < 0.0 && y != n) {
        return 0.0;
    }
    if (y != n) {
        x = exp_(y * ln_(x));
    } else if (y > 0.0) {
        y -= 1.0;
        t = x;
        while (y-- != 0.0) {
            x *= t;
        }
    } else {
        t = 1.0;
        while (y++ != 0.0) {
            t /= x;
        }
        x = t;
    }
    return x;
}
