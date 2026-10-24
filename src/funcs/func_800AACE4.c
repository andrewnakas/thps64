#include "common.h"

u8 *func_800AACE4(u8 *a0, u8 *a1) {
    u16 v = *a1;
    *(u16 *)(a0 + 0xB2) = 0;
    *(u16 *)(a0 + 0xB4) = v;
    return a1 + 1;
}
