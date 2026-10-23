#include "common.h"

s32 func_8004A494(u8 *arg0, s32 arg1, s32 arg2) {
    s32 lo;
    s32 hi;

    if (arg1 != arg0[0x230]) {
        return 0;
    }
    lo = *(s16 *)(arg0 + 0x22C);
    hi = *(s16 *)(arg0 + 0x22E);
    if (lo <= hi) {
        if (*(s8 *)(arg0 + 0x231) >= 0) {
            if (arg2 >= lo && arg2 <= hi) {
                return 1;
            }
            return 0;
        }
        if (arg2 <= lo || arg2 >= hi) {
            return 1;
        }
        return 0;
    }
    if (*(s8 *)(arg0 + 0x231) >= 0) {
        if (arg2 <= hi || arg2 >= lo) {
            return 1;
        }
        return 0;
    }
    if (arg2 >= hi) {
        if (arg2 <= lo) {
            return 1;
        }
    }
    return 0;
}
