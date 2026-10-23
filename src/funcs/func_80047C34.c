#include "common.h"

s32 func_80047C34(s32 *a, s32 *b) {
    s32 d[3];
    s32 x;
    s32 y;
    s32 z;
    s32 p;
    s32 q;
    s32 s;
    s32 r;

    x = a[0] - b[0];
    d[0] = x;
    y = a[1] - b[1];
    d[1] = y;
    z = a[2] - b[2];
    d[2] = z;
    if (x < 0) {
        d[0] = -x;
    }
    if (y < 0) {
        d[1] = -y;
    }
    if (z < 0) {
        d[2] = -z;
    }
    p = d[0];
    q = d[1];
    if (p < q) {
        y = d[2];
        if (q < y) {
            return ((p >> 2) + (q >> 1) + y) >> 12;
        } else if (y < p) {
            return ((y >> 2) + (p >> 1) + q) >> 12;
        } else {
            return ((p >> 2) + (y >> 1) + q) >> 12;
        }
    } else {
        y = d[2];
        if (p < y) {
            return ((q >> 2) + (p >> 1) + y) >> 12;
        } else if (y < q) {
            return ((y >> 2) + (q >> 1) + p) >> 12;
        } else {
            return ((q >> 2) + (y >> 1) + p) >> 12;
        }
    }
}
