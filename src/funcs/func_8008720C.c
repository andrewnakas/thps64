#include "common.h"

void func_8008720C(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    void *temp_a0;

    *(s32 *) ((u8 *) arg0 + 0xCC) = arg1;
    *(s32 *) ((u8 *) arg0 + 0xD0) = arg2;
    temp_a0 = arg0 + ((arg5 ^ 1) * 4);
    *(s32 *) ((u8 *) temp_a0 + 0xBC) = arg3;
    *(s32 *) ((u8 *) temp_a0 + 0xC4) = arg4;
}
