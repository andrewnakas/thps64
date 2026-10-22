#include "common.h"

/* Preserve the original load-before-return order. */
__asm__(".set noreorder");

s32 func_8007966C(void *arg0) {
    return *(s32 *) ((u8 *) arg0 + 0x528);
}
