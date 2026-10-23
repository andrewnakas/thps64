#include "common.h"

extern u16 D_800D48A4[3];

void func_800431F8(u16 *arg0) {
    u16 *p = D_800D48A4;
    arg0[0] = p[0];
    arg0[1] = p[1];
    arg0[2] = p[2];
}
