#include "common.h"

void *func_80084EE8(void *arg0) {
    *(s32 *) ((u8 *) arg0 + 0xC08) = -1;
    *(s32 *) ((u8 *) arg0 + 0xC00) = 0;
    *(s32 *) ((u8 *) arg0 + 0xC04) = 0;
    return arg0;
}
