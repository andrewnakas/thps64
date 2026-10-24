/* cflags: -O2 */
#include "common.h"

extern void func_8009F588(f32, f32);

void func_8009FA60(f32 x) {
    func_8009F588(x, __builtin_sqrtf(1.0001f - x * x));
}
