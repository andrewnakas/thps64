/* cflags: -O2 */
#include "common.h"

extern u32 D_800F5664;

s32 func_800A72A0(u32 *a0) {
    return !(a0[2] + 1 < D_800F5664);
}
