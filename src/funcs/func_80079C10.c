#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Unk80079C10;

typedef struct {
    s32 unk0;
    s32 unk4;
} Pair80079C10;

s32 func_8005EAB4(s32, s32, s32);
extern u8 D_8001E2D8;
extern u8 D_8001E388;
extern s32 D_800DE520;

void *func_80079C10(u8 *arg0, Unk80079C10 *arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8,
                    u8 arg9) {
    s32 base;
    u32 color;
    u32 hi;
    u32 i;

    *(void **) (arg0 + 0x44) = &D_8001E388;
    arg0[0x3C] = 1;
    arg0[0x3D] = 1;
    arg0[0x3E] = 1;
    D_800DE520 += 1;
    *(void **) (arg0 + 0x44) = &D_8001E2D8;
    *(s32 *) (arg0 + 0x50) = 8;
    *(u16 *) (arg0 + 0x5C) = 0x200;
    *(s32 *) (arg0 + 0x54) = 1;
    base = func_8005EAB4(*(s32 *) (arg0 + 0x50) * 0x10, 0, 1);
    *(s32 *) (arg0 + 0x48) = base;
    *(s32 *) (arg0 + 0x4C) = base + *(s32 *) (arg0 + 0x50) * 8;
    *(Unk80079C10 *) (arg0 + 0x18) = *arg1;
    for (i = 0; i < (u32) *(s32 *) (arg0 + 0x50); i++) {
        (*(Pair80079C10 **) (arg0 + 0x48))[i].unk0 = arg2;
    }
    *(s32 *) (arg0 + 0x58) = 0x32000000 | (arg6 << 16) | (arg5 << 8) | arg4;
    hi = (arg9 << 16) | (arg8 << 8);
    color = hi | arg7;
    for (i = 0; i < (u32) *(s32 *) (arg0 + 0x50); i++) {
        (*(Pair80079C10 **) (arg0 + 0x48))[i].unk4 = color;
    }
    for (i = 0; i < (u32) *(s32 *) (arg0 + 0x50); i++) {
        (*(Pair80079C10 **) (arg0 + 0x4C))[i].unk0 = arg3;
        (*(Pair80079C10 **) (arg0 + 0x4C))[i].unk4 = 0x3A000000;
    }
    *(s32 *) (arg0 + 0x64) = -1;
    return arg0;
}
