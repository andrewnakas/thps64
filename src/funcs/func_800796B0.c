#include "common.h"

void func_800796B0(void *arg0, s32 arg1) {
    *(s32 *) ((u8 *) arg0 + 0x4F0) = 1;
    *(s32 *) ((u8 *) arg0 + 0x4EC) = arg1;
    *(s32 *) ((u8 *) arg0 + 0x4CC) = 1;
}
