#include "common.h"
extern s32 D_800DACA8;
extern s32 D_800DAC50;
extern s32 D_800DACA4;
void func_8005EA48(s32);
void func_80061C7C(void) {
    if (D_800DACA8 != 0) {
        func_8005EA48(D_800DACA8);
        D_800DACA8 = 0;
    }
    D_800DAC50 = 0;
    D_800DACA4 = 0;
}
