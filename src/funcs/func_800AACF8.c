/* cflags: -O2 */
#include "common.h"

u8 *func_800AACF8(u8 *a0, u8 *a1) {
    s32 hi;
    s32 lo;
    hi = *a1;
    a1++;
    lo = *a1;
    *(s16 *)(a0 + 0xB4) = 0;
    *(s16 *)(a0 + 0xB2) = (hi << 8) | lo;
    return a1 + 1;
}
