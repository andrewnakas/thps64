#include "common.h"

extern char D_800FA350[];
extern s32 func_80038F9C(void *, s32);
extern void func_80038DDC(void *, s32, s32, u8);

void func_80035138(s32 a0, s32 a1, u8 a2) {
    void *p;
    s32 r;

    p = D_800FA350;
    r = func_80038F9C(p, a0);
    if (r != 0) {
        func_80038DDC(p, r, a1, a2);
    }
}
