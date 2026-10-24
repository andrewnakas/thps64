#include "common.h"

s32 func_8009EFF8(u8 *a0, s32 a1) {
    s32 old = *(s32 *)(a0 + 0xC);
    *(s32 *)(a0 + 0xC) = a1;
    return old;
}
