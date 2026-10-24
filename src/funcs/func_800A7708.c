/* cflags: -O2 */
#include "common.h"

void func_800A7708(u8 *a0, f32 a1) {
    s32 x = a1 * (f32)*(s32 *)(a0 + 0x8);
    *(f32 *)(a0 + 0x18) = (f32)x * *(f32 *)(a0 + 0x0);
    *(f32 *)(a0 + 0x1C) = a1;
}
