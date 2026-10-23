#include "common.h"

extern u8 D_800170B8[];
extern u8 D_800170E0[];
extern u8 D_800F0DD0[];
extern u8 D_800EECF0[];
extern void func_800BC0F4(void *);
extern void func_800BAC04(void *, s32);
extern void func_8009E334(void *);

void func_800252D8(void **a0, s32 a1) {
    *a0 = D_800170B8;
    func_800BC0F4(D_800F0DD0);
    func_800BAC04(D_800EECF0, 0x4CB);
    *a0 = D_800170E0;
    if (a1 & 1) {
        func_8009E334(a0);
    }
}
