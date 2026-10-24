#include "common.h"

typedef struct Vec80073A40 { s32 x, y, z; } Vec80073A40;

void func_800617B8(Vec80073A40 *, s32);
extern s32 D_800DDF10;
extern s16 D_800DE02C[];

void func_80073A40(s32 arg0) {
    Vec80073A40 sp10;

    func_800617B8(&sp10, arg0);
    D_800DE02C[D_800DDF10] = arg0;
    D_800DDF10 += 1;
}
