/* cflags: -O2 */
#include "common.h"

void *func_8009E8F0(s32 *, s32, s32);
void func_8009ECF8(s32 *, void *);
void func_800B2CF0(u8 *, s32, s32, void *);
void func_800BA1B8(u8 *, void *);
s32 func_800BA9EC(u8 *, s32);
extern u8 D_800EECA0[];
extern s32 D_800EA110;

void func_800BA768(u8 *arg0, s32 arg1) {
    u8 *p;
    s32 base;
    s32 size;
    void *buf;

    p = D_800EECA0;
    base = *(s32 *)(p + 4) + func_800BA9EC(p, arg1);
    size = (func_800BA9EC(p, arg1 + 1) - func_800BA9EC(p, arg1) + 1) & ~1;
    if (base != 0) {
        *(s16 *)(arg0 + 0x66) = arg1;
        buf = func_8009E8F0(&D_800EA110, size, 8);
        func_800B2CF0(p + 0xC, base, size, buf);
        func_800BA1B8(arg0, buf);
        func_8009ECF8(&D_800EA110, buf);
    }
}
