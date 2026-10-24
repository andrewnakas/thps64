/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-no-m4100 */
#include "common.h"

s32 func_8002311C(s32);
u32 func_800233B8(s32);

u32 func_80047D40(s16 *out, s32 *a, s32 *b) {
    s32 dx;
    s32 dy;
    s32 dz;
    u32 d;

    dx = (b[0] - a[0]) >> 12;
    dy = (b[1] - a[1]) >> 12;
    dz = (b[2] - a[2]) >> 12;
    if (dz != 0) {
        if (dz > 0) {
            out[1] = 0x800 - func_8002311C((dx << 12) / -dz);
        } else {
            out[1] = func_8002311C((dx << 12) / dz);
        }
    } else {
        out[1] = (dx > 0) ? -0x400 : 0x400;
    }
    d = func_800233B8(dx * dx + dz * dz);
    if (d != 0) {
        if (dy > 0) {
            out[0] = func_8002311C((u32)(dy << 12) / d);
        } else {
            out[0] = -func_8002311C((u32)(-dy << 12) / d);
        }
    } else {
        out[0] = (dy <= 0) ? -0x400 : 0x400;
    }
    out[0] &= 0xFFF;
    out[1] &= 0xFFF;
    out[2] = 0;
    return d;
}
