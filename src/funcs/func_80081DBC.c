#include "common.h"

extern u8 D_800DE640[];

void func_80081DBC(void) {
    u8 *p = D_800DE640;

    *(s32 *)(p + 0xB4) = 0;
    *(s32 *)(p + 0xB8) = 0;
    *(s32 *)(p + 0xBC) = 0;
}
