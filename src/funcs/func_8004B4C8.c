#include "common.h"

extern s32 D_8001B4A0;
extern s32 D_800D83F4;

void *func_8004B4C8(void *arg0) {
    *(void **)((u8 *)arg0 + 0x48) = &D_8001B4A0;
    *(s16 *)((u8 *)arg0 + 0x24) = 0x1000;
    *(s16 *)((u8 *)arg0 + 0x26) = 0x1000;
    *(s16 *)((u8 *)arg0 + 0x28) = 0x1000;
    *(void **)((u8 *)arg0 + 0x3C) = &D_800D83F4;
    return arg0;
}
