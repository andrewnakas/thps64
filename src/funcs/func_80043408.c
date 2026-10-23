#include "common.h"

extern u16 D_800D48A4[3];

void func_80043408(u16 *arg0) {
    u16 *p = D_800D48A4;
    p[0] = arg0[1];
    p[1] = arg0[3];
    p[2] = arg0[5];
}
