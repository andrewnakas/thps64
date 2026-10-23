#include "common.h"

extern s32 D_800D48AC[];
extern s16 D_800D48A4[];

void func_80043288(void) {
    s32 *d = D_800D48AC;
    s16 *s = D_800D48A4;
    d[0] = s[0] * s[0];
    d[1] = s[1] * s[1];
    d[2] = s[2] * s[2];
}
