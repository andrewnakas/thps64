#include "common.h"

extern u16 D_800D4938[3];

void func_80043388(u16 *arg0) {
    u16 *p = D_800D4938;
    p[0] = arg0[0];
    p[1] = arg0[1];
    p[2] = arg0[2];
}
