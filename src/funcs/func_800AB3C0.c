/* cflags: -O2 */
#include "common.h"

u8 *func_800AB3C0(u8 *arg0, u8 *arg1) {
    f32 f;

    *(f32 *)(arg0 + 0x6C) = (f32)*arg1++ * 0.015625;
    f = *(f32 *)(arg0 + 0x70);
    *(f32 *)(arg0 + 0x24) = f * f;
    return arg1;
}
