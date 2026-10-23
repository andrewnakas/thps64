/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

extern s32 D_800DCAA8;
extern u8 D_800FBB90[];

void func_8006F1A8(u8 arg0, u8 arg1, u8 arg2, s32 arg3) {
    D_800FBB90[0] = arg0;
    D_800FBB90[1] = arg1;
    D_800FBB90[2] = arg2;
    D_800DCAA8 = (arg2 << 16) | (arg1 << 8) | arg0;
    D_800DCAA8 |= arg3 ? 0x2E000000 : 0x2C000000;
}
