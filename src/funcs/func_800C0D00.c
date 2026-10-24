#include "common.h"

s32 func_800C0D00(s32 arg0, u32 arg1, s32 arg2, u32 arg3) {
    if (arg0 < arg2) {
        return 0;
    }
    if (arg2 < arg0) {
        return 2;
    }
    if (arg1 < arg3) {
        return 0;
    }
    if (arg3 < arg1) {
        return 2;
    }
    return 1;
}
