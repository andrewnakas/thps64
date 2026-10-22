#include "common.h"

s32 func_800795F4(void *arg0, u8 arg1) {
    arg0 = (u8 *) arg0 + arg1 * 2;
    return (*(s16 *) ((u8 *) arg0 + 0x638) + *(s16 *) ((u8 *) arg0 + 0x628)) >> 1;
}
