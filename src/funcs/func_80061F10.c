#include "common.h"

extern s32 D_800DACD0[];
extern s32 D_800DACBC;

void func_80061F10(void) {
    s32 *p;
    s32 i;

    p = D_800DACD0;
    for (i = 39, p += 39; i >= 0; i--) {
        *p = 0;
        p--;
    }
    D_800DACBC = 0;
}
