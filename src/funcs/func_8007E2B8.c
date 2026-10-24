#include "common.h"

void func_8007E2B8(u8 *arg0, u8 arg1) {
    *(s32 *)(arg0 + 0x4C) = (*(s32 *)(arg0 + 0x4C) & 0xFF000000) | (arg1 << 16) | (arg1 << 8) | arg1;
}
