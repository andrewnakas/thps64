#include "common.h"

extern s32 D_800DC92C;
extern s32 D_800DC930;

void func_8006D238(void) {
    s32 *a;
    s32 *b;
    s32 v;

    a = &D_800DC92C;
    b = &D_800DC930;
    v = -1;
    *b = v;
    *a = v;
}
