/* cflags: -O2 */
#include "common.h"

extern f32 func_8009F588(f32, f32);

void func_8009E03C(f32 *m, f32 *a, f32 *b, f32 *c) {
    *a = func_8009F588(m[8], m[10]);
    *b = -func_8009F588(m[9], __builtin_sqrtf(m[8] * m[8] + m[10] * m[10]));
    *c = -func_8009F588(-m[1], m[5]);
}
