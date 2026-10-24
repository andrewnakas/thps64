/* cflags: -O2 */
#include "common.h"

extern u32 D_800EA138;

f32 func_8009F274(void) {
    s32 x;
    f64 d;

    D_800EA138 = D_800EA138 * 0x41C64E6F + 0x303B;
    x = (D_800EA138 >> 16) & 0x7FFF;
    d = x;
    if (x < 0) {
        d += 4294967296.0;
    }
    return (f32)d * 3.0517578125e-05f;
}
