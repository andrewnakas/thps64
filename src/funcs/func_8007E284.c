#include "common.h"

void func_8007E284(u8 *arg0, u8 arg1, u8 arg2, u8 arg3) {
    *(s32 *)(arg0 + 0x4C) = (*(s32 *)(arg0 + 0x4C) & 0xFF000000) | (arg3 << 16) | (arg2 << 8) | arg1;
}
