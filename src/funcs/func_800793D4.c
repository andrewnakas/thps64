#include "common.h"

void func_800793D4(void *arg0) {
    *(s32 *) ((u8 *) arg0 + 0x5E8) = (s32) *(s32 *) ((u8 *) arg0 + 0x5D8);
    *(s32 *) ((u8 *) arg0 + 0x5EC) = (s32) *(s32 *) ((u8 *) arg0 + 0x5DC);
    *(u16 *) ((u8 *) arg0 + 0x5F0) = (u16) *(u16 *) ((u8 *) arg0 + 0x5E0);
    *(u16 *) ((u8 *) arg0 + 0x5F2) = (u16) *(u16 *) ((u8 *) arg0 + 0x5E2);
    *(u16 *) ((u8 *) arg0 + 0x5F4) = (u16) *(u16 *) ((u8 *) arg0 + 0x5E4);
    *(s32 *) ((u8 *) arg0 + 0x5D8) = 0;
    *(s32 *) ((u8 *) arg0 + 0x5DC) = 0;
    *(u16 *) ((u8 *) arg0 + 0x5E0) = 0U;
    *(u16 *) ((u8 *) arg0 + 0x5E2) = 0U;
    *(u16 *) ((u8 *) arg0 + 0x5E4) = 0U;
}
