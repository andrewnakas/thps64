/* cflags: -O2 */
#include "common.h"

void func_800A0D0C(u8 *, s32);
extern s32 D_800EA550;

#define W(o, t) (*(t *)(arg0 + (o)))

void func_800A1EA4(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 *arg4, s32 *arg5, s32 arg6, s32 arg7, s32 arg8,
                   s32 arg9) {
    D_800EA550 = 4;
    W(0x8, s32) = 0x14;
    W(0x434, s32) = arg1;
    W(0x498, s32) = arg2;
    W(0x49C, s32) = arg3;
    W(0x420, s32) = arg9;
    W(0x4E8, s32 *) = arg4;
    W(0x43C, s32 *) = arg5;
    W(0x45C, s32) = arg6;
    W(0x464, s32) = arg7;
    func_800A0D0C(arg0, arg8);
    *W(0x4E8, s32 *) = 0;
    *W(0x43C, s32 *) = 0;
}
