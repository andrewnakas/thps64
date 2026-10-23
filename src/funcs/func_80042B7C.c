#include "common.h"

extern u8 D_8001A750[];
extern void func_800B19C0(void *, s32);
extern void func_8003C894(void *, s32);
extern void func_800394A8(void *, s32);

void func_80042B7C(u8 *a0, s32 a1) {
    *(void **)(a0 + 0x2C) = D_8001A750;
    func_800B19C0(a0 + 0x6CC, 2);
    func_800B19C0(a0 + 0x6B8, 2);
    func_800B19C0(a0 + 0x6A4, 2);
    func_8003C894(a0 + 0x34, 2);
    func_800394A8(a0, a1);
}
