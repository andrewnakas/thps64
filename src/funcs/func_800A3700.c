#include "common.h"

s32 func_800A0E74(void *, s32, s32); /* extern */
extern s32 D_800EA550;

void func_800A3700(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x18) == 0) {
        *(s32 *)(arg0 + 0x10) = 0x34;
        func_800A0E74(arg0, 0, D_800EA550);
        return;
    }
    D_800EA550 = 0;
}
