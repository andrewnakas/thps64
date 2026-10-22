#include "common.h"

extern s32 D_800D4890[3];

void func_800435B4(s32 *arg0) {
    s32 *p = D_800D4890;
    p[0] = arg0[0];
    p[1] = arg0[1];
    p[2] = arg0[2];
}
