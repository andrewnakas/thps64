/* cflags: -O2 */
#include "common.h"

s32 func_8009FD8C(u8 *a, u8 *b) {
    while (*a != 0 && *b != 0) {
        if (*a > *b) {
            return 1;
        }
        if (*a < *b) {
            return -1;
        }
        a++;
        b++;
    }
    if (*a != 0) {
        if (*b != 0) {
            goto zero;
        }
        return 1;
    }
    if (*b != 0) {
        return -1;
    }
zero:
    return 0;
}
