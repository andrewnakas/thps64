/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

extern void *D_800DC5C0;
s32 func_80068E6C(s32, s32);

void func_80068F14(void) {
    while (D_800DC5C0 != 0) {
        func_80068E6C((s32)D_800DC5C0, 3);
    }
    D_800DC5C0 = 0;
}
