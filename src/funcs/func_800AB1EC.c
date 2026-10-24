/* cflags: -O2 */
#include "common.h"

extern u8 func_800ADB48(u8);

u8 *func_800AB1EC(u8 *a0, u8 *a1) {
    u8 v = func_800ADB48(*a1++);
    a0[0xB9] = v;
    a0[0xB9] = v + *a1;
    return a1 + 1;
}
