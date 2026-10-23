/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

void func_8006A1C0(s32, s32);
extern s32 D_800DC5E0;

void func_8006A2F0(void) {
    while (D_800DC5E0 != 0) {
        func_8006A1C0(D_800DC5E0, 3);
    }
}
