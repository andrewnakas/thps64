#include "common.h"

extern u16 D_800D4918[];

void func_80043364(u16 *arg0) {
    D_800D4918[0] = arg0[0];
    D_800D4918[1] = arg0[1];
    D_800D4918[2] = arg0[2];
}
