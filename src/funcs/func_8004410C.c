#include "common.h"

void func_8004410C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    (*(s32 *)((u8 *)(arg0) + 0x150)) = arg5;
    (*(s32 *)((u8 *)(arg0) + 0x154)) = arg6;
    (*(s32 *)((u8 *)(arg0) + 0x158)) = arg7;
    (*(s32 *)((u8 *)(arg0) + 0x15C)) = arg8;
}
