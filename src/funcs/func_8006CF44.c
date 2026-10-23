#include "common.h"

extern s32 D_800D61A8;
extern u8 D_800DC618[];
extern u8 D_800DC6D8[];

void func_8006CF44(s32 arg0) {
    u8 *p;

    if (arg0 == D_800D61A8) {
        p = D_800DC618;
    } else {
        p = D_800DC6D8;
    }
    *(s32 *)(p + 0x10) = *(s32 *)(p + 0x8);
    *(s32 *)(p + 0x18) = 0;
    *(s32 *)(p + 0x20) = *(s32 *)(p + 0x1C);
}
