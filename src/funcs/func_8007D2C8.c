#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec8007D2C8;

void func_80079E18(void *);
extern s32 D_8001E218;
extern s32 D_8001E230;

void *func_8007D2C8(u8 *arg0, Vec8007D2C8 *arg1, Vec8007D2C8 *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    func_80079E18(arg0);
    *(s32 **)(arg0 + 0x44) = &D_8001E230;
    *(Vec8007D2C8 *)(arg0 + 0x18) = *arg1;
    *(Vec8007D2C8 *)(arg0 + 0x24) = *arg2;
    *(s32 *)(arg0 + 0x4C) |= 0x02000000;
    *(s16 *)(arg0 + 0x5E) = arg4;
    *(s16 *)(arg0 + 0x4A) = arg5;
    *(s16 *)(arg0 + 0x48) = arg6;
    *(s32 **)(arg0 + 0x44) = &D_8001E218;
    return arg0;
}
