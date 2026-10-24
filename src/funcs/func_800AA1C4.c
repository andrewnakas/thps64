/* cflags: -O2 */
#include "common.h"

s32 func_800AA1C4(u8 *arg0) {
    u8 a;
    u8 b;
    s32 d;

    a = arg0[0x398];
    b = arg0[0x399];
    d = a - b;
    if (d < 0) {
        d = a + 200;
        d -= b;
    }
    return d;
}
