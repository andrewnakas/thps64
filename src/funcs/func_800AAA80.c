/* cflags: -O2 */
#include "common.h"

u8 *func_800AAA80(u8 *arg0, u8 *arg1) {
    u32 v;

    v = *arg1++;
    if (v & 0x80) {
        v = *arg1++ | ((v & 0x7F) << 8);
    }
    *(u16 *)(arg0 + 0xAE) = v;
    return arg1;
}
