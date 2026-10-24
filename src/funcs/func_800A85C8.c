/* cflags: -O2 */
#include "common.h"

extern void func_800A8678(f32 *, s32, s32, s32, s32, s32, f32, u8, u8, s32, s32, f32, s32, s32);

void func_800A85C8(f32 *arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, f32 arg8, u8 arg9, u8 arg10, s32 arg11, s32 arg12, f32 arg13, s32 arg14) {
    f32 x;
    f32 y;

    x = arg0[0];
    y = arg0[1];
    arg0[0] = arg1;
    arg0[1] = arg2;
    func_800A8678(arg0, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14, 0);
    arg0[0] = x;
    arg0[1] = y;

}
