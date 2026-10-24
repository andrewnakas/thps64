/* cflags: -O2 */
#include "common.h"

s32 func_800AADF0(u8 *arg0, s32 arg1) {
    arg0[0xD5] = 0;
    *(s32 *)(arg0 + 0x68) = 0;
    return arg1;
}
