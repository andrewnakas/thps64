/* cflags: -O2 */
#include "common.h"

void *func_8009E6B4(s32 *, s32, s32);
s32 func_800A5EE8(void *, s32);
void func_800BAFDC(s32 *, s32, s32, void *, s32);
extern s32 D_800EA110;
extern s32 D_800EED10;

void *func_800A5C50(u8 *arg0, void **arg1, s32 arg2) {
    s32 base;
    s32 size;
    void *buf;

    base = *(s32 *)(arg0 + 4) + func_800A5EE8(arg0, arg2);
    size = (func_800A5EE8(arg0, arg2 + 1) - func_800A5EE8(arg0, arg2) + 1) & ~1;
    buf = func_8009E6B4(&D_800EA110, size, 8);
    if (buf != NULL) {
        func_800BAFDC(&D_800EED10, base, size, buf, 0);
    }
    arg1[1] = buf;
    arg1[0] = buf;
    return buf;
}
