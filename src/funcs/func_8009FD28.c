#include "common.h"

u8 *func_8009FD28(u8 *dst, u8 *src, u32 n) {
    u8 *d = dst;
    u8 c;

    while (n-- != 0) {
        c = *src++;
        if (c == 0) {
            break;
        }
        *d++ = c;
    }
    *d = 0;
    return dst;
}
