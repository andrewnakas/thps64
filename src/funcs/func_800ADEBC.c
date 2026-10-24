/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

void func_800ADEBC(s32 *a0, s32 a1, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        if (a0[i] != 0) {
            a0[i] += a1;
        }
    }
}
