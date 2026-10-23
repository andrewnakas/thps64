#include "common.h"

void func_80044130(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    *(s32 *)(arg0 + 0x140) = arg1;
    *(s32 *)(arg0 + 0x144) = arg2;
    *(s32 *)(arg0 + 0x148) = arg3;
    *(s32 *)(arg0 + 0x14C) = arg4;
}
