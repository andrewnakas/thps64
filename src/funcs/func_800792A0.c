#include "common.h"

void func_800792A0(void *arg0, s32 arg1, u16 arg2) {
    *(u16 *) ((u8 *) arg0 + 0x520) = arg2;
    if (arg2 & 0xFFFF) {
        *(s32 *) ((u8 *) arg0 + 0x524) = (s32) ((s32) ((arg1 & 0xFFFF) - *(s32 *) ((u8 *) arg0 + 0x51C)) / (s32) *(u16 *) ((u8 *) arg0 + 0x520));
        return;
    }
    *(s32 *) ((u8 *) arg0 + 0x51C) = (s32) (arg1 & 0xFFFF);
}
