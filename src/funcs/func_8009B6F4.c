/* cflags: -O2 */
#include "common.h"

void func_8009B9A0(s32 **, s32, s32);
s32 func_8009E6B4(s32 *, s32, s32);
s32 func_8009E8F0(s32 *, s32, s32);
void func_8009ECF8(s32 *, s32);
void func_800B2CF0(u8 *, s32, s32, s32);
extern s32 D_800EA110;

s32 func_8009B6F4(u8 *arg0) {
    s32 *hdr;
    s32 tmp;
    s32 size;
    s32 buf;
    u8 *f;
    s32 *heap;
    s32 mask;

    mask = ~1;
    heap = &D_800EA110;
    tmp = func_8009E8F0(heap, 4, 8);
    f = arg0 + 0xC;
    if (tmp != 0) {
        func_800B2CF0(f, 0, 4, tmp);
        func_8009B9A0(&hdr, tmp, 0);
        size = (*hdr * 4 + 9) & mask;
        buf = func_8009E6B4(heap, size, 8);
        if (buf != 0) {
            func_800B2CF0(f, 0, size, buf);
        }
        func_8009ECF8(heap, tmp);
        return buf;
    }
    return 0;
}
