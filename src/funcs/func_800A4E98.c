#include "common.h"

void func_800A4E98(u8 *a0, s32 a1) {
    s32 t = *(s32 *)(a0 + 0x178);
    t |= a1;
    *(s32 *)(a0 + 0x178) = t;
}
