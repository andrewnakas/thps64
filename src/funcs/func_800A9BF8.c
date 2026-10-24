/* cflags: -O2 */
#include "common.h"

extern s32 func_800A9D64(s32 *, s32);

void func_800A9BF8(s32 *arg0, s32 arg1, s32 arg2) {
    if (*arg0 != 0 && func_800A9D64(arg0, arg1) != 0) {
        { u8 *p = (u8 *)arg0; p += arg1 * 0x24; p[0x54A] = arg2; }
    }
}
