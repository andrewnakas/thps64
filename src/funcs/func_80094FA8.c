#include "common.h"

u8 *func_800617B8(s32 *, s32);
s32 func_80095498(u8 *);
extern u8 *D_800D61A8;
extern s32 D_800DACAC;
extern u8 *D_800E8E70;
extern u8 D_800E9094[];
extern u8 D_800E9098[];
extern u8 D_800E90A1[];

void func_80094FA8(void) {
    s32 sp10[4];
    u8 *src;
    u8 *dst;
    u8 c;
    u8 *p;

    src = D_800E8E70;
    dst = D_800E9098;
    while ((c = *src) != 0) {
        *dst = c;
        src++;
        dst++;
    }
    *dst = 0;
    src = func_800617B8(sp10, D_800DACAC) + 6;
    dst = D_800E90A1;
    while (*src != 0) {
        *dst = *src;
        src++;
        dst++;
    }
    *dst = 0;
    if (D_800D61A8 != NULL) {
        p = D_800E9094;
        *(s32 *)(p + 0x64) = *(s16 *)(D_800D61A8 + 0x162);
        p[0x42] = 0;
    }
    *(s32 *)D_800E9094 = func_80095498(D_800E9094);
}
