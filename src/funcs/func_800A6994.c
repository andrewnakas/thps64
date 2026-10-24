#include "common.h"

void func_800A6994(u8 *arg0, u8 arg1) {
    arg0[0x80] = arg1;
    if (arg1 != 0) {
        *(s32 *)(arg0 + 0xC) = *(s32 *)(arg0 + 0x6C);
    }
}
