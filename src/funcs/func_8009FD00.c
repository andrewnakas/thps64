/* cflags: -O2 */
#include "common.h"

void func_8009FD00(s32 arg0, s8 *arg1, s8 *arg2, s8 *arg3) {
    *arg1 = (s8) ((u32) (arg0 & 0xF800) >> 8);
    *arg2 = (s8) ((u32) (arg0 & 0x7C0) >> 3);
    *arg3 = (arg0 & 0x3E) * 4;
}
