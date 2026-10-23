#include "common.h"

s32 func_80049034(s32, s32, s32);
s32 func_800617B8(void *, s32);
extern s32 D_800DACAC;
extern s16 **D_800DACB0;
extern s32 D_800DACB4;

void func_80061CC4(s32 arg0) {
    s32 buf[4];
    s32 i;

    D_800DACAC = 0xFFFF;
    i = 0;
    while (1) {
        if (i >= D_800DACB4) {
            break;
        }
        if (*D_800DACB0[i] == 8) {
            if (func_80049034(func_800617B8(buf, i) + 6, arg0, -1) != 0) {
                D_800DACAC = i;
                break;
            }
        }
        i++;
    }
}
