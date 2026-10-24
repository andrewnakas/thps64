/* cflags: -O2 */
#include "common.h"

extern void *D_800DE6F4;

s32 func_80081DD4(void) {
    s32 var_v0;

    var_v0 = 1;
    if (D_800DE6F4 != NULL) {
        var_v0 = (*(s32 *)((u8 *)D_800DE6F4 + 0x214)) >= 0x28;
    }
    return var_v0;
}
