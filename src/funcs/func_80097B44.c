/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

extern void func_800A3250(void *, s32, s32, s32);
extern u8 D_800D3130[];
extern u8 D_800D0FC2;

void func_80097B44(u8 *a0) {
    func_800A3250(D_800D3130, D_800D0FC2, 1, *(s32 *)(a0 + 0x90) == 0);
}
