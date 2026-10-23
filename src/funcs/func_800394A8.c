#include "common.h"

extern void func_800A5FD0(void *, s32);
extern void func_8009E334(void *);
extern s32 D_80019EB0;

void func_800394A8(u8 *arg0, s32 arg1) {
    *(void **)(arg0 + 0x2C) = &D_80019EB0;
    func_800A5FD0(arg0 + 8, 2);
    if (arg1 & 1) {
        func_8009E334(arg0);
    }
}
