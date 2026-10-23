/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

s32 func_800420D8(u8 *a, u8 *b) {
    u8 c0;
    u8 c1;
    u8 c2;

    while (1) {
        c0 = *a;
        if (c0 == 0) {
            break;
        }
        c1 = c0;
        c2 = *b;
        a++;
        b++;
        if (c0 == c2) {
            continue;
        }
        if (c1 >= 'a' && c1 <= 'z') {
            c1 -= 0x20;
        }
        if (c2 >= 'a' && c2 <= 'z') {
            c2 -= 0x20;
        }
        if (c1 != c2) {
            return 1;
        }
    }
    return 0;
}
