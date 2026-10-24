#include "common.h"

extern s32 *D_800FC318;

void func_800AC290(s32 *a0) {
    if (a0 != NULL && a0[4] < 0) {
        D_800FC318 = a0;
    }
}
