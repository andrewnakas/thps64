/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

void func_80039E60(s32, s32, s32);
void func_800A3250(void *, u8, s32, s32);
extern u8 D_800D0FC2;
extern u8 D_800D3130[];

void func_80097AF0(u8 *arg0) {
    func_80039E60(0x91, 10000, 0);
    func_800A3250(D_800D3130, D_800D0FC2, 1, *(s32 *)(arg0 + 0x90) == 0);
    *(s32 *)(arg0 + 0x90) = 0;
}
