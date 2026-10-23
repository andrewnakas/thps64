#include "common.h"

s32 func_80049034(u8 *a, u8 *b, s32 n) {
    u8 c1;
    u8 c2;

    if (a == NULL) {
        if (b == NULL) {
            return 1;
        }
    } else if (b != NULL) {
        goto loop;
    }
    return 0;
loop:
    do {
        c1 = *a++;
        c2 = *b++;
        if (c1 >= 'A' && c1 <= 'Z') {
            c1 += 0x20;
        }
        if (c2 >= 'A' && c2 <= 'Z') {
            c2 += 0x20;
        }
        if (c1 != c2) {
            break;
        }
        if (c1 == 0) {
            break;
        }
    } while (--n != 0);
    return c1 == c2;
}
