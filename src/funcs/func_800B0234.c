#include "common.h"

extern u8 *D_800ECC34;

void func_800B0234(s32 *a0) {
    u8 *p = D_800ECC34;
    a0[0] = *(s32 *)(p + 0x40);
    *(s32 **)(p + 0x40) = a0;
}
