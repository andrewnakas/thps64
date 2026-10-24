/* cflags: -O2 */
#include "common.h"

u8 *func_8009FD60(u8 *dst, u8 *src) {
    u8 *d;
    u8 c;

    d = dst;
    c = *src;
    if (c != 0) {
        do {
            src++;
            *d = c;
            c = *src;
            d++;
        } while (c != 0);
    }
    *d = 0;
    return dst;
}
