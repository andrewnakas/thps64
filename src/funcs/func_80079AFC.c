#include "common.h"

s32 func_8005EAB4(s32, s32, s32);                       /* extern */
extern u8 D_8001E2D8;
extern u8 D_8001E388;
extern s32 D_800DE520;

void *func_80079AFC(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;
    u32 temp_a1;
    u32 var_a0;
    s32 temp_a0;

    *(s32 *) ((u8 *) arg0 + 0x44) = &D_8001E388;
    *(u8 *) ((u8 *) arg0 + 0x3C) = 1;
    *(u8 *) ((u8 *) arg0 + 0x3D) = 1;
    *(u8 *) ((u8 *) arg0 + 0x3E) = 1;
    D_800DE520 += 1;
    *(s32 *) ((u8 *) arg0 + 0x44) = &D_8001E2D8;
    temp_a1 = arg1 * 2;
    *(s32 *) ((u8 *) arg0 + 0x50) = temp_a1;
    *(u16 *) ((u8 *) arg0 + 0x5C) = (s16) (0x1000U / temp_a1);
    *(s32 *) ((u8 *) arg0 + 0x54) = arg2;
    temp_a0 = *(s32 *) ((u8 *) arg0 + 0x50);
    temp_v0 = func_8005EAB4((temp_a0 + temp_a0 * arg2) * 8, 0, 1);
    *(s32 *) ((u8 *) arg0 + 0x48) = temp_v0;
    *(s32 *) ((u8 *) arg0 + 0x4C) = (s32) (temp_v0 + (*(s32 *) ((u8 *) arg0 + 0x50) * 8));
    var_a0 = 0;
    if ((*(s32 *) ((u8 *) arg0 + 0x50) * *(s32 *) ((u8 *) arg0 + 0x54)) != 0) {
        do {
            *(s32 *) ((var_a0 * 8) + *(s32 *) ((u8 *) arg0 + 0x4C) + 4) = 0x3A000000;
            var_a0 += 1;
        } while (var_a0 < (u32) (*(s32 *) ((u8 *) arg0 + 0x50) * *(s32 *) ((u8 *) arg0 + 0x54)));
    }
    *(s32 *) ((u8 *) arg0 + 0x58) = 0x32000000;
    *(s32 *) ((u8 *) arg0 + 0x64) = -1;
    return arg0;
}
