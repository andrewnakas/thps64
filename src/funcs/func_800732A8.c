/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

void func_800BEB0C(s32, s32, s32, s32, s32, s32, s32);

void func_800732A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u8 arg4, u8 arg5, u8 arg6) {
    func_800BEB0C(arg0, arg0 + arg2, arg1, arg1 + arg3, (s32) arg4, arg5 & 0xFF, arg6 & 0xFF);
}
