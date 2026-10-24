/* cflags: -fcse-follow-jumps */
#include "common.h"

s32 func_80082F54(f32 *p, f32 *a, f32 *b, f32 *c, f32 sign) {
    do {
        f32 d1, d2, d3, d4;

        d1 = p[0] - a[0];
        d2 = p[2] - a[2];
        d3 = b[0] - a[0];
        d4 = b[2] - a[2];
        d1 = d1 * d4 - d2 * d3;
        if (d1 * sign < 0.0f) {
            return 0;
        }
        d1 = p[0] - b[0];
        d2 = p[2] - b[2];
        d3 = c[0] - b[0];
        d4 = c[2] - b[2];
        if ((d1 * d4 - d2 * d3) * sign < 0.0f) {
            return 0;
        }
        d1 = p[0] - c[0];
        d2 = p[2] - c[2];
        d3 = a[0] - c[0];
        d4 = a[2] - c[2];
        if ((d1 * d4 - d2 * d3) * sign < 0.0f) {
            return 0;
        }
        return 1;
    } while (0);
}
