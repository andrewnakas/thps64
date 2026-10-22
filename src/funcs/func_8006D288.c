#include "common.h"

extern s32 D_800DC924;
extern s32 D_800DC928;

void func_8006D288(void) {
    s32 *a = &D_800DC924;
    s32 *b = &D_800DC928;
    s32 v = -1;
    *b = v;
    *a = v;
}
