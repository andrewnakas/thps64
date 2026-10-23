#include "common.h"
extern void *D_800D61A8;
extern u8 D_800DC618[];
extern u8 D_800DC6D8[];
extern s32 D_800DC824;
extern s32 D_800DC934;
extern s32 D_800DC93C;
void func_8006D1A0(s32 *arg0) {
    u8 *p;
    if ((void *)arg0 == D_800D61A8) {
        p = D_800DC618;
    } else {
        p = D_800DC6D8;
    }
    if (D_800DC824 == 0) {
        D_800DC824 = 1;
        D_800DC934 = *(s32 *)(p + 0x1C);
        D_800DC93C = arg0[2];
    }
}
