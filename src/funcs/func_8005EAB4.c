#include "common.h"
extern u8 D_800EA110[];
s32 func_8009E6B4(void *, s32, s32);
s32 func_8009E8F0(void *, s32, s32);
s32 func_8005EAB4(s32 arg0, s32 arg1) {
    if (arg1 == 0) {
        return func_8009E8F0(D_800EA110, arg0, 8);
    } else {
        return func_8009E6B4(D_800EA110, arg0, 8);
    }
}
