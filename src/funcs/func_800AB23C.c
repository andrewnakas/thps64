/* cflags: -O2 */
#include "common.h"

s8 func_800ADB48(u8); /* extern */

u8 *func_800AB23C(u8 *arg0, u8 *arg1) {
    s8 v;

    v = func_800ADB48(*arg1++);
    arg0[0xBC] = v;
    arg0[0xBC] = v + *arg1++;
    return arg1;
}
