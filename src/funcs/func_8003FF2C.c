#include "common.h"

s32 func_800B43F0();                                /* extern */
s32 func_800B4480(s32);                             /* extern */

s32 func_8003FF2C(s32 arg0) {
    if (func_800B43F0() != 0) {
        return -1;
    }
    return func_800B4480(arg0) != 0;
}
