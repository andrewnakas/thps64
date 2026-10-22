#include "common.h"

extern s32 func_80063294(s32);

void func_8004B468(void *arg0, s32 arg1) {
    *(u8 *)((u8 *)arg0 + 0x1B) = func_80063294(arg1);
    *(s16 *)((u8 *)arg0 + 0x16) = 0;
}
