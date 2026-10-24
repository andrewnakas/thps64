/* cflags: -O2 */
#include "common.h"

void func_800A04D8(u8 *a0, s32 a1) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (a1 == i || a1 == -1) {
            ((s32 *)(a0 + 0x408))[i] = -1;
        }
    }
}
