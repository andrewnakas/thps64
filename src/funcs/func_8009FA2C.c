/* cflags: -O2 */
#include "common.h"

f32 func_80001CA0(f32);
f32 func_800018C0(f32);

f32 func_8009FA2C(f32 arg0) {
    f32 s;

    s = func_80001CA0(arg0);
    return s / func_800018C0(arg0);
}
