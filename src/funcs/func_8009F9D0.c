/* cflags: -O2 */
#include "common.h"

extern void func_8009F588(f32, f32);

void func_8009F9D0(f32 x) {
    f32 one;
    f32 s;

    one = 1.0f;
    s = __builtin_sqrtf(x * x + one);
    func_8009F588(x / s, one / s);
}
