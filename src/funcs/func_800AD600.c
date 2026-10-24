/* cflags: -O2 */
#include "common.h"

extern f32 func_800B16C0(f32);

f32 func_800AD600(u8 *arg0) {
    u16 a = *(u16 *)(arg0 + 0xAA);
    u8 b = *(u8 *)(arg0 + 0xB6);
    f32 r;
    s32 d;

    do {
        d = a - b;
    } while (0);
    r = 0.0f;
    if (d > 0) {
        r = func_800B16C0((f32)d * *(f32 *)(arg0 + 0xDC)) * *(f32 *)(arg0 + 0x20);
        *(f32 *)(arg0 + 0x68) = r;
    }
    return r;
}
