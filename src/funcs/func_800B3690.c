/* cflags: -O2 */
#include "common.h"

s32 func_800B345C(s32, s32); /* extern */

void func_800B3690(s32 arg0) {
    s32 i;

    for (i = 0; i < 4; i++) {
        func_800B345C(i, arg0);
    }
}
