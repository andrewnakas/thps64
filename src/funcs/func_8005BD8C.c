#include "common.h"

extern s32 D_800D6FDC[];

void func_8005BD8C(void) {
    s32 *p;
    s32 c;

    p = D_800D6FDC;
    c = 0x8000;
    p[0] = 0;
    p[1] = c;
    p[2] = 0;
}
