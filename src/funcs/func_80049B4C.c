/* cflags: -Wa,-no-m4100 */
#include "common.h"

s32 func_800233B8(s32);

s32 func_80049B4C(s32 *arg0, s32 *arg1) {
    s32 dx;
    s32 dz;

    dx = (arg0[0] - arg1[0]) >> 12;
    dz = (arg0[2] - arg1[2]) >> 12;
    return func_800233B8(dx * dx + dz * dz);
}
