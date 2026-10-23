#include "common.h"

extern f64 D_8001EE98;
extern f64 D_8001EEA0;
extern f64 D_8001EEA8;
extern f64 D_8001EEB0;
extern f64 D_8001EEB8;
extern f64 D_8001EEC0;
extern f64 D_8001EEC8;

f64 func_8008772C(f64 arg0) {
    f64 previous;
    f64 remainder;
    f64 magnitude;
    f64 sum;
    f64 term;
    s32 denominator;
    s32 exponent;

    magnitude = __builtin_fabs(arg0);
    if (magnitude < D_8001EEA0) {
        return D_8001EEA8;
    }
    exponent = (s32) (magnitude * D_8001EEB0);
    if (exponent >= 0x401) {
        if (arg0 >= 0.0) {
            return D_8001EE98;
        }
        return 0.0;
    }
    remainder = magnitude - (f64)exponent * D_8001EEB8;
    denominator = 1;
    sum = D_8001EEC0;
    term = sum;
    do {
        previous = sum;
        term *= remainder / (f64) denominator;
        sum += term;
        denominator += 1;
    } while (sum != previous);
    if (exponent != 0) {
        do {
            exponent -= 1;
            sum *= 2.0;
        } while (exponent != 0);
    }
    if (arg0 >= 0.0) {
        return sum;
    }
    return D_8001EEC8 / sum;
}
