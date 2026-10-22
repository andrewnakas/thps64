#include "common.h"

/* Preserve the original load-before-return order. */
__asm__(".set noreorder");

s32 func_80079640(void *arg0) {
    return *(s32 *) ((u8 *) arg0 + 0x5B0);
}
