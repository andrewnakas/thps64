#include "common.h"

extern s32 D_800D61A8;

void func_8004641C(s32 arg0, s32 arg1) {
    if (arg1 == D_800D61A8) {
        *(s16 *)((u8 *)arg1 + 0xA24) = 1;
        return;
    }
    *(s16 *)((u8 *)arg1 + 0xA24) = 0;
}
