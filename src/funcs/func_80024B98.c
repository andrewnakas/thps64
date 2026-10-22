#include "common.h"

void func_80024B98(void *arg0, s8 arg1, s8 arg2, s8 arg3) {
    (*(s8 *)((u8 *)(arg0) + 0x8C)) = arg1;
    (*(s8 *)((u8 *)(arg0) + 0x8D)) = arg2;
    (*(s8 *)((u8 *)(arg0) + 0x8E)) = arg3;
}
