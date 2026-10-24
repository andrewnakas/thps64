/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x4];
    s32 unk4;
} Tbl800A93B0;

typedef struct {
    u8 pad0[0x54];
    s32 unk54;
} Obj800A93B0;

extern void func_8009E0F0(s32, s32, s32);
extern s32 func_800AAA40(Tbl800A93B0 *, s32);
extern void func_800BAFDC(void *, s32, s32, s32, s32);
extern u8 D_800EED10[];
extern Tbl800A93B0 D_800F5678;

s32 func_800A93B0(Obj800A93B0 *arg0, s32 arg1) {
    Tbl800A93B0 *t;
    s32 size;

    func_8009E0F0(arg0->unk54, 0, 4);
    t = &D_800F5678;
    size = func_800AAA40(t, arg1 + 1) - func_800AAA40(t, arg1);
    if (size & 1) {
        size++;
    }
    func_800BAFDC(D_800EED10, t->unk4 + func_800AAA40(t, arg1), size, arg0->unk54, 0);
    return 1;
}
