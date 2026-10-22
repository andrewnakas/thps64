#include "common.h"

extern s32 D_8001E308[];
extern s32 D_8001E388[];
extern s32 D_800DE520;

void *func_800798A4(void *arg0, u16 *arg1, u16 *arg2, u16 *arg3) {
    *(void **) ((u8 *) arg0 + 0x44) = &D_8001E388;
    *(u8 *) ((u8 *) arg0 + 0x3C) = 1;
    *(u8 *) ((u8 *) arg0 + 0x3D) = 1;
    *(u8 *) ((u8 *) arg0 + 0x3E) = 1;
    D_800DE520 += 1;
    *(void **) ((u8 *) arg0 + 0x44) = &D_8001E308;
    *(u8 *) ((u8 *) arg0 + 0x43) = 5;
    *(u16 *) ((u8 *) arg0 + 0x4C) = (u16) arg1[0];
    *(u16 *) ((u8 *) arg0 + 0x4E) = (u16) arg1[1];
    *(u16 *) ((u8 *) arg0 + 0x50) = (u16) arg1[2];
    *(u16 *) ((u8 *) arg0 + 0x54) = (u16) arg2[0];
    *(u16 *) ((u8 *) arg0 + 0x56) = (u16) arg2[1];
    *(u16 *) ((u8 *) arg0 + 0x58) = (u16) arg2[2];
    *(u16 *) ((u8 *) arg0 + 0x5C) = (u16) arg3[0];
    *(u16 *) ((u8 *) arg0 + 0x5E) = (u16) arg3[1];
    *(u16 *) ((u8 *) arg0 + 0x60) = (u16) arg3[2];
    return arg0;
}
