/* cflags: -O2 */
#include "common.h"

void func_800A0978(u8 *, s32, u8 *, s32);

void func_800A0D0C(u8 *arg0, s32 arg1) {
    if (arg1 != 0) {
        func_800A0978(arg0, arg1, arg0 + 0x480, 4);
        *(s32 *)(arg0 + 0x458) = 1;
    } else {
        *(s32 *)(arg0 + 0x458) = 0;
    }
}
