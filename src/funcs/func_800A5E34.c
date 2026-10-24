/* cflags: -O2 */
#include "common.h"

extern s32 func_8009E6B4(u8 *, s32, s32);
extern s32 func_800A5EE8(u8 *, s32);
extern void func_800BAFDC(u8 *, s32, s32, s32, s32);
extern u8 D_800EA110[];
extern u8 D_800EED10[];

s32 func_800A5E34(u8 *arg0, s32 arg1, s32 arg2) {
    s32 off;
    s32 size;
    s32 p;

    off = *(s32 *)(arg0 + 4) + func_800A5EE8(arg0, arg1);
    size = (func_800A5EE8(arg0, arg1 + 1) - func_800A5EE8(arg0, arg1) + 1) & ~1;
    p = func_8009E6B4(D_800EA110, size, arg2);
    if (p != 0) {
        func_800BAFDC(D_800EED10, off, size, p, 0);
    }
    return p;

}
