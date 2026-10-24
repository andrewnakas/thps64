/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"
u32 func_80095498(u32 *a0) {
    u32 x = 0;
    u32 i;
    for (i = 1; i < 0x22; i++) {
        x ^= a0[i];
    }
    x |= 1;
    return x;
}
