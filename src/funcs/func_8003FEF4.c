#include "common.h"

s32 func_800B4510();                                /* extern */
s32 func_800B45A0(s32);                             /* extern */

s32 func_8003FEF4(s32 arg0) {
    if (func_800B4510() != 0) {
        return -1;
    }
    return func_800B45A0(arg0) != 0;
}
