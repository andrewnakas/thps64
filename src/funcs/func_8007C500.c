#include "common.h"

extern s32 func_800634A4(s32);

void func_8007C500(u8 *a0, s32 a1) {
    *(s32 *)(a0 + 0x4C) = func_800634A4(a1);
}
