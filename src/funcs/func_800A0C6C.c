/* cflags: -O2 */
#include "common.h"

void func_800A0C6C(u8 *arg0, s32 arg1) {
    s32 i;

    for (i = 4; i >= 0; i--) {
        ((s32 *)(arg0 + 0x444))[i] = arg1;
    }
}
