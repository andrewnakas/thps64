/* cflags: -O2 -Wa,-O0 */
#include "common.h"

u16 func_80007400(void);

f32 func_8009F228(void) {
    s32 x;
    f64 d;

    x = func_80007400();
    d = x;
    if (x < 0) {
        d += 4294967296.0;
    }
    return (f32)d * 1.5258789e-05f;
}
