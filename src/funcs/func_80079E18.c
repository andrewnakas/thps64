#include "common.h"

extern u8 D_8001E2A8;
extern u8 D_8001E338;
extern u8 D_8001E388;
extern s32 D_800DE520;

void *func_80079E18(void *arg0) {
    *(void * *) ((u8 *) arg0 + 0x44) = &D_8001E388;
    *(u8 *) ((u8 *) arg0 + 0x3C) = 1;
    *(u8 *) ((u8 *) arg0 + 0x3D) = 1;
    *(u8 *) ((u8 *) arg0 + 0x3E) = 1;
    D_800DE520 += 1;
    *(void * *) ((u8 *) arg0 + 0x44) = &D_8001E338;
    *(u16 *) ((u8 *) arg0 + 0x5C) = 0x80;
    *(u16 *) ((u8 *) arg0 + 0x5E) = 0x190;
    *(s32 *) ((u8 *) arg0 + 0x4C) = 0x2C808080;
    *(void * *) ((u8 *) arg0 + 0x44) = &D_8001E2A8;
    *(u8 *) ((u8 *) arg0 + 0x6D) = 0x20;
    *(u16 *) ((u8 *) arg0 + 0x66) = 1;
    *(s32 *) ((u8 *) arg0 + 0x68) = 0x10001000;
    return arg0;
}
