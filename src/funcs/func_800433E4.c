#include "common.h"

extern u16 D_800D48A4[];

void func_800433E4(u16 *arg0) {
    D_800D48A4[0] = arg0[1];
    D_800D48A4[1] = arg0[3];
    D_800D48A4[2] = arg0[5];
}
