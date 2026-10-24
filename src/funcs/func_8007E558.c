#include "common.h"

extern u8 D_8001E388[];
extern s32 D_800DE520;
extern void func_8005EA48(void *);

void func_8007E558(u8 *a0, s32 a1) {
    *(void **)(a0 + 0x44) = D_8001E388;
    D_800DE520--;
    if (a1 & 1) {
        func_8005EA48(a0);
    }
}
