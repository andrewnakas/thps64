/* cflags: -O2 */
#include "common.h"

s32 func_8009E8F0(s32 *, s32, s32);         /* extern */
s32 func_8009ECF8(s32 *, s32);              /* extern */
s32 func_800A5EE8();                                /* extern */
s32 func_800A5F00(s32 **, s32, s32);            /* extern */
s32 func_800BAFDC(s32 *, s32, s32, s32, s32); /* extern */
extern s32 D_800EA110;
extern s32 D_800EED10;

s32 func_800A5A60(void *arg0, s32 arg1, s32 count) {
    s32 *sp18;
    s32 base;
    s32 buf;
    s32 total;
    s32 size;

    base = (*(s32 *)((u8 *)arg0 + 4)) + func_800A5EE8();
    if (count == -1) {
        buf = func_8009E8F0(&D_800EA110, 4, 8);
        if (buf == 0) {
            return 0;
        }
        func_800BAFDC(&D_800EED10, base, 4, buf, 0);
        func_800A5F00(&sp18, buf, base);
        count = *sp18;
        func_8009ECF8(&D_800EA110, buf);
    }
    total = count * 4 + 8;
    size = total;
    buf = func_8009E8F0(&D_800EA110, size, 8);
    if (buf != 0) {
        func_800BAFDC(&D_800EED10, base, size, buf, 0);
        return buf;
    }
    return 0;
}
