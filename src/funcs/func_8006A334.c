#include "common.h"

extern u8 D_800DC5F0;
extern s32 D_800D2838;
extern s32 D_800DE7A8;
void func_80035138(s32, s32, s32);

void func_8006A334(s32 arg0, u8 arg1) {
    if (arg1) {
        D_800DC5F0 = arg1;
    }
    func_80035138(arg0, D_800D2838 != D_800DE7A8, D_800DC5F0);
}
