#include "common.h"

void func_80024B88(void *arg0, s8 arg1, s8 arg2, s8 arg3) {
    (*(s8 *)((u8 *)(arg0) + 0x8F)) = arg1;
    (*(s8 *)((u8 *)(arg0) + 0x90)) = arg2;
    (*(s8 *)((u8 *)(arg0) + 0x91)) = arg3;
}
