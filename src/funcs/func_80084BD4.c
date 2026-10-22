#include "common.h"

/* Preserve the load before the return and its empty delay slot. */
__asm__(".set noreorder");

s32 func_80084BD4(s32 *arg0, s32 arg1) {
    return *(s32 *) ((arg1 * 4) + *arg0 + 4);
}
