/* cflags: -O2 */
#include "common.h"

u8 *func_800AAE00(u8 *a0, u8 *a1) {
    s32 v = *a1;
    a1++;
    if (v >= 0x80) {
        v &= 0x7F;
        v <<= 8;
        v |= *a1;
        a1++;
    }
    *(s16 *)(a0 + 0xAC) = v;
    return a1;
}
