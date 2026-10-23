#include "common.h"

extern s32 D_800D8430;
extern s32 D_800DA63C;
void func_800BE3D8(s32, s32, s32);

void func_8005E4D0(s32 arg0, s32 arg1, s32 arg2) {
    D_800D8430 = arg0;
    D_800DA63C = arg2;
    func_800BE3D8(arg0, arg1, arg2);
}
