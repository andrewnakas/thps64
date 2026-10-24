#include "common.h"

extern u8 D_8001E140[];
extern void func_8007AC04(void *, s32);
extern void func_8005EA48(void *);

void func_8007C7E4(u8 *a0, s32 a1) {
    *(void **)(a0 + 0x44) = D_8001E140;
    func_8007AC04(a0, 0);
    if (a1 & 1) {
        func_8005EA48(a0);
    }
}
