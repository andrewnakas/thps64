#include "common.h"

s32 func_8005EAB4(s32, s32, s32);
void func_8006E0B8(s32, s32, s32, s32, s32);
void func_80079720(void);
void func_80079730(s32);
s32 func_80079738(s32);

void func_8006EBB0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 h;

    h = func_8005EAB4(func_80079738(arg0), 1, 1);
    func_80079730(h);
    func_80079720();
    func_8006E0B8(arg0, h, arg1, arg2, arg3);
}
