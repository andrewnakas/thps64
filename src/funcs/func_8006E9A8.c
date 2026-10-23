#include "common.h"

void *func_8006E9A8(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    (*(s32 *)((u8 *)(arg0) + 8)) = arg1;
    (*(s32 *)((u8 *)(arg0) + 0xC)) = arg2;
    (*(s32 *)((u8 *)(arg0) + 0x10)) = arg3;
    (*(s32 *)((u8 *)(arg0) + 4)) = 0;
    return arg0;
}
