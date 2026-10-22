#include "common.h"

s32 func_800394A8(void *, s32);             /* extern */
s32 func_800A735C(void *, s32);             /* extern */
s32 func_800B19C0(void *, s32);             /* extern */
extern s32 D_8001A5F0;
extern u8 D_800C0E23;
extern u8 D_800DF260;
extern s32 D_800EA9B0;
extern s32 D_800ECEF0;

void func_800405CC(void *arg0, s32 arg1) {
    (*(void **)((u8 *)(arg0) + 0x2C)) = &D_8001A5F0;
    D_800DF260 = D_800C0E23;
    D_800ECEF0 = 0;
    D_800EA9B0 = 0;
    func_800B19C0(arg0 + 0x878, 2);
    func_800B19C0(arg0 + 0x864, 2);
    func_800B19C0(arg0 + 0x850, 2);
    func_800B19C0(arg0 + 0x83C, 2);
    func_800A735C(arg0 + 0x5FC, 2);
    func_800A735C(arg0 + 0x3BC, 2);
    func_800B19C0(arg0 + 0x3A8, 2);
    func_800B19C0(arg0 + 0x394, 2);
    func_800B19C0(arg0 + 0x380, 2);
    func_800B19C0(arg0 + 0x36C, 2);
    func_800B19C0(arg0 + 0x358, 2);
    func_800B19C0(arg0 + 0x344, 2);
    func_800B19C0(arg0 + 0x330, 2);
    func_800B19C0(arg0 + 0x31C, 2);
    func_800B19C0(arg0 + 0x308, 2);
    func_800A735C(arg0 + 0x3C, 2);
    func_800394A8(arg0, arg1);
}
