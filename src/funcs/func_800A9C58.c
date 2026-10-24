#include "common.h"

extern void func_8009E0F0(void *, s32, s32);

void func_800A9C58(u8 *a0) {
    if (*(s32 *)a0 != 0 && a0[0x530] != 0) {
        *(s32 *)(a0 + 0x39C) = 0;
        a0[0x530] = 0;
        a0[0x531] = 0;
        a0[0x532] = 0;
        func_8009E0F0(a0 + 0x3A0, 0, 400);
    }
}
