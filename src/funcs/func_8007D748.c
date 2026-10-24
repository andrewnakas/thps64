#include "common.h"

extern u8 D_8001E278;
extern u8 D_8001E388;
extern s32 D_800DE520;

void *func_8007D748(void *arg0) {
    (*(u8 **)((u8 *)arg0 + 0x44)) = &D_8001E388;
    (*(s8 *)((u8 *)arg0 + 0x3C)) = 1;
    (*(s8 *)((u8 *)arg0 + 0x3D)) = 1;
    (*(s8 *)((u8 *)arg0 + 0x3E)) = 1;
    D_800DE520 += 1;
    (*(u8 **)((u8 *)arg0 + 0x44)) = &D_8001E278;
    return arg0;
}
