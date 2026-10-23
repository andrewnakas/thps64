/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

extern void func_80028148(s32, f32);
extern s32 D_800C0E2C;
extern s32 D_800C0E30;
extern s32 D_800C0E34;
extern f32 D_800D1E7C;
extern s32 D_800D2838;
extern s32 D_800D9D54;
extern s32 D_800D9D58;
extern s32 D_800D9D5C;

void func_8005E5CC(s32 arg0, s32 arg1, u32 arg2) {
    f32 f;

    D_800D9D58 = arg1;
    D_800D9D54 = arg1 + arg2;
    for (D_800D9D5C = 0; arg2 < 0x1000; D_800D9D5C++) {
        arg2 <<= 1;
    }
    for (; arg2 > 0x1000; D_800D9D5C--) {
        arg2 >>= 1;
    }
    D_800C0E2C = D_800D9D54;
    D_800C0E30 = D_800D9D58;
    D_800C0E34 = D_800D9D5C;
    D_800D1E7C = f = D_800D9D54 * 0.0625f;
    if (D_800D2838 != 0) {
        func_80028148(D_800D2838, f);
    }
}
