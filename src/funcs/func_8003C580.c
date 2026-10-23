#include "common.h"

s32 func_8003C580(u8 *arg0, s32 arg1, s32 *arg2) {
    s32 i;
    s32 r;

    i = 0;
    while (1) {
        r = i < arg1;
        if (r == 0) {
            return r;
        }
        if ((arg0[0x29C] ^ 2) == 0) {
            *arg2 = 1;
            return i;
        }
        arg0 += 0x40;
        i++;
    }
}
