/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 unk0;
    u8 pad4[3];
    s8 unk7;
    s32 unk8;
    u8 padC[0x10];
    s32 *unk1C;
} Obj800A5F10;

s32 func_8009E6B4(s32 *, s32, s32);
void func_800A62C4(void *, s32, s32, s32, s32);
extern s32 D_80021828;
extern s32 D_800EA110;
extern s32 D_800F3294;
extern s32 D_800F3298;

static __inline__ void reset_(Obj800A5F10 *o) {
    o->unk8 = -1;
    func_800A62C4(o, 0, D_800F3294 - 1, 0, D_800F3298 - 1);
}

Obj800A5F10 *func_800A5F10(Obj800A5F10 *arg0) {
    s32 r;

    arg0->unk1C = &D_80021828;
    r = func_8009E6B4(&D_800EA110, 0x20, 8);
    arg0->unk7 = 0;
    arg0->unk0 = r;
    reset_(arg0);
    reset_(arg0);
    return arg0;
}
