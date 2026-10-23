#include "common.h"

extern u8 D_800D0FC4;
void *func_8009E30C(s32);
void func_80025348(void *, s32);

void func_8004C4A4(s32 arg0) {
    if (D_800D0FC4 != 0) {
        func_80025348(func_8009E30C(0x478), arg0);
    }
}
