/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-no-m4100 */
#include "common.h"

u32 func_80047C34(s32 *, s32 *);

u32 func_80049A24(s32 *a, s32 *o, s32 *b) {
    u32 la;
    u32 lb;
    s32 ax, ay, az, bx, by, bz;

    la = func_80047C34(a, o);
    lb = func_80047C34(b, o);
    if (la > 40000 || lb > 40000) {
        return 10000;
    }
    ax = (a[0] - o[0]) >> 12;
    ay = (a[1] - o[1]) >> 12;
    az = (a[2] - o[2]) >> 12;
    bx = (b[0] - o[0]) >> 12;
    by = (b[1] - o[1]) >> 12;
    bz = (b[2] - o[2]) >> 12;
    return (((u32)(ax * bx + ay * by + az * bz) / la) << 12) / lb;
}
