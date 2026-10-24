/* cflags: -O2 */
#include "common.h"

s8 func_800ADB48(u8);

u8 *func_800AB28C(u8 *arg0, u8 *arg1) {
    arg0[0xBD] = func_800ADB48(*arg1++);
    arg0[0xBD] += *arg1++;
    return arg1;
}
