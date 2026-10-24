/* cflags: -O2 */
#include "common.h"

s32 func_8009E6B4(s32 *, s32, s32);
s32 func_8009E8F0(s32 *, s32, s32);
void func_8009ECF8(s32 *, s32);
void func_800A5F00(s32 **, s32, s32);
void func_800BAFDC(s32 *, s32, s32, s32, s32);
extern s32 D_800EA110;
extern s32 D_800EED10;

s32 func_800A5B58(s32 arg0) {
    s32 *sp18;
    s32 *heap;
    s32 *file;
    s32 size;
    s32 buf;
    s32 hdr;
    s32 mask;

    mask = ~1;
    heap = &D_800EA110;
    hdr = func_8009E8F0(heap, 4, 8);
    if (hdr != 0) {
        file = &D_800EED10;
        func_800BAFDC(file, arg0, 4, hdr, 0);
        func_800A5F00(&sp18, hdr, arg0);
        size = (*sp18 * 4 + 9) & mask;
        buf = func_8009E6B4(heap, size, 8);
        if (buf != 0) {
            func_800BAFDC(file, arg0, size, buf, 0);
        }
        func_8009ECF8(heap, hdr);
        return buf;
    }
    return 0;
}
