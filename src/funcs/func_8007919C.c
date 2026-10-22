#include "common.h"

void *func_8007919C(void *arg0) {
    s32 temp = 0x1000;
    *(s32 *) ((u8 *) arg0 + 0x18) = 0;
    *(s32 *) ((u8 *) arg0 + 0x1C) = 0;
    *(s32 *) ((u8 *) arg0 + 0x20) = 0;
    *(s32 *) ((u8 *) arg0 + 0x24) = temp;
    *(s32 *) ((u8 *) arg0 + 0x3C) = 0;
    *(s32 *) ((u8 *) arg0 + 0x40) = 0;
    *(s32 *) ((u8 *) arg0 + 0x44) = 0;
    *(s32 *) ((u8 *) arg0 + 0x48) = temp;
    *(s32 *) ((u8 *) arg0 + 0x6C) = 0;
    *(s32 *) ((u8 *) arg0 + 0x70) = 0;
    *(s32 *) ((u8 *) arg0 + 0x74) = 0;
    *(s32 *) ((u8 *) arg0 + 0x78) = temp;
    return arg0;
}
