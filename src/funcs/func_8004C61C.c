#include "common.h"

void func_8004C61C(void *arg0, s8 arg1, s8 arg2, s8 arg3, s32 arg4, s32 arg5) {
    (*(s8 *)((u8 *)(arg0) + 0x96F)) = arg1;
    (*(s8 *)((u8 *)(arg0) + 0x970)) = arg2;
    (*(s8 *)((u8 *)(arg0) + 0x971)) = arg3;
    (*(s8 *)((u8 *)(arg0) + 0x972)) = (s8) arg4;
    (*(s8 *)((u8 *)(arg0) + 0x973)) = (s8) arg5;
}
