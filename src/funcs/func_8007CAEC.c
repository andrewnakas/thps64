#include "common.h"

void func_8007CAEC(u8 *a0, s16 a1) {
    s32 i = 0;
    while (1) {
        if (i >= *(s32 *)(a0 + 0x48)) break;
        *(s16 *)((*(u8 ***)(a0 + 0x5C))[i] + 0x5E) = a1;
        i++;
    }
}
