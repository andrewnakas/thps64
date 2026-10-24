/* cflags: -O2 */
#include "common.h"

void func_800B18C8(u8 *dst, u8 *src, s32 n) {
    if (src < dst) {
        dst += n;
        src += n;
        for (n--; n != -1; n--) {
            *--dst = *--src;
        }
    } else {
        for (n--; n != -1; n--) {
            *dst++ = *src++;
        }
    }
}
