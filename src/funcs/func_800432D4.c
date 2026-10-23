#include "common.h"

extern s16 D_800D48A4[];
extern s32 D_800D48AC;
extern s16 D_800D4918[];

void func_800432D4(void) {
    s32 s;
    D_800D48AC = 0;
    s = D_800D4918[0] * D_800D48A4[0];
    D_800D48AC = s;
    s += D_800D4918[1] * D_800D48A4[1];
    D_800D48AC = s;
    s += D_800D4918[2] * D_800D48A4[2];
    D_800D48AC = s;
}
