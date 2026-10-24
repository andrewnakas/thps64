#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec3i_8007D134;

s32 func_80049D60(s32);
void func_80079E18();
extern s32 D_8001E200;

void *func_8007D134(u8 *arg0, Vec3i_8007D134 *arg1, u8 arg2, u8 arg3, u8 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 arg10) {
    s32 n;

    func_80079E18();
    *(s32 **)(arg0 + 0x44) = &D_8001E200;
    *(Vec3i_8007D134 *)(arg0 + 0x18) = *arg1;
    if (arg7 != 0) {
        *(s32 *)(arg0 + 0x4C) |= 0x02000000;
    }
    *(s32 *)(arg0 + 0x4C) = (*(s32 *)(arg0 + 0x4C) & 0xFF000000) | (arg4 << 0x10) | (arg3 << 8) | arg2;
    do {
        *(s16 *)(arg0 + 0x5E) = arg6;
    } while (0);
    n = (arg8 * 2) + 1;
    *(s32 *)(arg0 + 0x24) = (func_80049D60(n) - arg8) << 0xC;
    *(s32 *)(arg0 + 0x28) = -(func_80049D60(arg8) << 0xC);
    *(s32 *)(arg0 + 0x2C) = (func_80049D60(n) - arg8) << 0xC;
    *(s32 *)(arg0 + 0x34) = arg9;
    *(s8 *)(arg0 + 0x3C) = 3;
    *(s8 *)(arg0 + 0x3D) = 3;
    *(s8 *)(arg0 + 0x3E) = 3;
    *(s16 *)(arg0 + 0xA) = func_80049D60(arg10);
    return arg0;
}
