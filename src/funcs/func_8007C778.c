#include "common.h"

extern void func_800797E4(s32, s32);

void func_8007C778(u8 *arg0) {
    s32 i;

    if (*(s32 *)(arg0 + 0x60) != 0) {
        for (i = 0; i < *(s32 *)(arg0 + 0x48); i++) {
            func_800797E4((*(s32 **)(arg0 + 0x5C))[i], 0);
        }
    }

}
