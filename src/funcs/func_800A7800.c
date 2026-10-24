#include "common.h"

void func_800A7800(u8 *arg0, s32 arg1) {
    if (arg1 == 0 || arg1 == 2) {
        *(s32 *)(arg0 + 0x20) = arg1;
    }
}
