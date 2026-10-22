#include "common.h"

s32 func_8009BD18(void *, s32);
s32 func_8009FF4C(void *, s32);
s32 func_800A735C(void *, s32);
s32 func_800B3A90(void *);
extern s32 D_80021F60;
extern u8 D_800D0FC0[];
extern u8 D_800D1E90[];
extern s32 D_800D2090;
extern s32 D_800D22D0;
extern s32 D_800D2510;

void func_80024414(void) {
    u8 *p;
    u8 *q;

    func_800A735C(&D_800D2510, 2);
    func_800A735C(&D_800D22D0, 2);
    func_800A735C(&D_800D2090, 2);
    p = D_800D1E90;
    *(void **)(p + 0x1C4) = &D_80021F60;
    func_800B3A90(p);
    func_8009FF4C(p, 2);
    q = D_800D0FC0;
    func_8009BD18(q + 0x40, 2);
}
