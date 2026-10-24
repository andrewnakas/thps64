/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x4];
    s32 unk4;
} Obj800A5D5C;

extern s32 func_8009E8F0(void *, s32, s32);
extern s32 func_800A5EE8(Obj800A5D5C *, s32);
extern void func_800BAFDC(void *, s32, s32, s32, s32);
extern u8 D_800EA110[];
extern u8 D_800EED10[];

s32 func_800A5D5C(Obj800A5D5C *arg0, s32 arg1) {
    s32 off;
    s32 size;
    s32 buf;

    off = arg0->unk4 + func_800A5EE8(arg0, arg1);
    size = (func_800A5EE8(arg0, arg1 + 1) - func_800A5EE8(arg0, arg1) + 1) & ~1;
    buf = func_8009E8F0(D_800EA110, size, 8);
    if (buf != 0) {
        func_800BAFDC(D_800EED10, off, size, buf, 0);
    }
    return buf;
}
