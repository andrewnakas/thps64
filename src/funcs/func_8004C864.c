#include "common.h"

void func_8004C864(void *arg0, s32 arg1, s32 arg2) {
    (*(s32 *)((u8 *)(arg0) + 0x99C)) = arg1;
    (*(s32 *)((u8 *)(arg0) + 0x9A0)) = arg2;
}
