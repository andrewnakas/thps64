#include "common.h"

extern s32 D_800D61A8;
extern s32 D_800DC618[];
extern s32 D_800DC6D8[];

void func_8006CF7C(s32 arg0) {
    s32 *p;

    if (arg0 == D_800D61A8) {
        p = D_800DC618;
    } else {
        p = D_800DC6D8;
    }
    p[0] = 0;
    p[4] = 0xDEADBEEF;
    p[6] = 0;
}
