#include "common.h"

void func_80046298(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    (*(s32 *)((u8 *)(arg0) + 0x10)) = arg1;
    (*(s32 *)((u8 *)(arg0) + 0)) = arg2;
    (*(s32 *)((u8 *)(arg0) + 4)) = arg3;
    (*(s32 *)((u8 *)(arg0) + 8)) = arg4;
    (*(s32 *)((u8 *)(arg0) + 0xC)) = 0x12;
}
