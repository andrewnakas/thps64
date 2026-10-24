/* cflags: -O2 */
#include "common.h"

u8 *func_800AAE60(u8 *a0, u8 *a1) {
    s32 v = *a1++;
    f32 f;
    if (v & 0x80) {
        v |= -0x100;
    }
    f = (f32)v / 100.0;
    *(f32 *)(a0 + 0x30) = *(f32 *)(a0 + 0x30) - *(f32 *)(a0 + 0x90) + f;
    *(f32 *)(a0 + 0x90) = f;
    return a1;
}
