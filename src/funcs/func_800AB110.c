/* cflags: -O2 */
#include "common.h"

u8 *func_800AB110(u8 *arg0, u8 *arg1) {
    s32 v;

    v = *arg1++;
    if (v >= 0x80) {
        v &= 0x7F;
        v <<= 8;
        v |= *arg1++;
    }
    *(s32 *)(arg0 + 0x84) = *(s32 *)(*(u8 **)(arg0 + 0x74) + 0x1C) + v * 6;
    return arg1;
}
