/* cflags: -O2 */
#include "common.h"

s32 func_800A901C(u8 *a0, s32 a1) {
    s32 i;
    if (a0[0x60] == 0) {
        return 0;
    }
    for (i = 0; i < a0[0x60]; i++) {
        if ((*(s32 **)(a0 + 0x58))[i] == a1) {
            return 1;
        }
    }
    return 0;
}
