#include "common.h"

void func_80084A14(void *arg0, s32 arg1, s32 arg2) {
    *(s32 *) ((u8 *) arg0 + 0x0) = arg1;
    *(s32 *) ((u8 *) arg0 + 0x4) = arg2;
}
