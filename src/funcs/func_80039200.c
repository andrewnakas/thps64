#include "common.h"

extern s32 func_80039328(void *, s32);
extern u8 D_800D3EB0[];

s32 func_80039200(s32 arg0, s32 arg1) {
    u8 *p;
    s32 a;
    s32 b;

    p = D_800D3EB0;
    a = func_80039328(p, arg1 + 1);
    b = func_80039328(p, arg1);
    a -= b;
    return a != 0;
}
