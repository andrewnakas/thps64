/* cflags: -O2 */
#include "common.h"

s32 func_8009B988();
s32 func_8009B9A0(s32 **, s32, s32);
s32 func_8009E8F0(s32 *, s32, s32);
s32 func_8009ECF8(s32 *, s32);
s32 func_800B2CF0(void *, s32, s32, s32);
extern s32 D_800EA110;

s32 func_8009B898(void *arg0, s32 arg1, s32 count) {
    s32 *info;
    s32 base;
    s32 size;
    s32 total;
    s32 buf;

    base = *(s32 *)((u8 *)arg0 + 4) + func_8009B988();
    if (count == -1) {
        buf = func_8009E8F0(&D_800EA110, 4, 8);
        if (buf == 0) {
            return 0;
        }
        func_800B2CF0((u8 *)arg0 + 0xC, base, 4, buf);
        func_8009B9A0(&info, buf, base);
        count = *info;
        func_8009ECF8(&D_800EA110, buf);
    }
    total = count * 4 + 8;
    size = total;
    buf = func_8009E8F0(&D_800EA110, size, 8);
    if (buf != 0) {
        func_800B2CF0((u8 *)arg0 + 0xC, base, size, buf);
        return buf;
    }
    return 0;
}
