/* cflags: -O2 */
#include "common.h"

s32 func_800B68D0(s32 arg0, u8 *p) {
    s32 n;
    u8 c;

    n = 0;
    while ((c = *p) != 0) {
        if (c & 0x80) {
            p += 2;
            n += 8;
            if (*p & 0x80) {
                p += 2;
            }
        } else {
            switch (c & 0x60) {
            case 0x40:
                p += 2;
                n += 8;
                break;
            case 0x20:
                p += 2;
                n += 8;
                break;
            case 0x60:
                p += 5;
                n += 8;
                break;
            }
        }
    }
    return n + 8;

}
