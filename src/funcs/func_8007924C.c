#include "common.h"

s16 func_8007924C(s32 arg0, s32 arg1) {
    s32 temp_v1;
    arg0 &= 0xFFF;
    do {
        arg1 &= 0xFFF;
        arg1 -= arg0;
        temp_v1 = (s16) arg1;
        arg0 = arg1;
    } while (0);
    if (temp_v1 >= 0x801) {
        arg0 = arg1 - 0x1000;
    } else if (temp_v1 < -0x800) {
        arg0 = arg1 + 0x1000;
    }
    return (s16) arg0;
}
