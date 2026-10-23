#include "common.h"

s32 func_8004AF94(u8 *arg0, s32 arg1, s32 arg2) {
    s32 flags;

    if (arg1 == 1) {
        flags = arg0[0x116];
        if (flags & arg2) {
            return 0;
        }
        arg0[0x116] = flags | arg2;
        return 1;
    }
    arg0[0x116] &= ~arg2;
    return 0;
}
