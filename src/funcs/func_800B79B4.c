/* cflags: -O2 */
#include "common.h"

s32 func_800B79B4(f32 *b, f32 *p, f32 m) {
    f32 v;

    v = p[0];
    if (m < b[0] - v) {
        return 0;
    }
    if (m < v - b[3]) {
        return 0;
    }
    v = p[1];
    if (m < b[1] - v) {
        return 0;
    }
    if (m < v - b[4]) {
        return 0;
    }
    v = p[2];
    if (m < b[2] - v) {
        return 0;
    }
    if (m < v - b[5]) {
        return 0;
    }
    return 1;

}
