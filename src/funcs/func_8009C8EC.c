/* cflags: -O2 */
#include "common.h"

s32 *func_8009C8EC(s32 *a0, s32 *a1) {
    s32 *d = a0;
    s32 i = 16;
    do {
        *d++ = *a1++;
        i--;
    } while (i != 0);
    return a0;
}
