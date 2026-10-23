/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

void func_800BF6AC(s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern u8 D_800D0FC0[];
extern s32 D_800F3294;
extern s32 D_800F3298;

void func_80035B88(void) {
    u8 *g = D_800D0FC0;

    if (g[0x28] == 3) {
        return;
    }
    switch (g[0x28]) {
    case 0:
        func_800BF6AC(D_800F3294 / 2 - 1, D_800F3294 / 2 + 1, 0, D_800F3298 - 1, 0, 0, 0, 0xFF, 0);
        break;
    case 2:
        {
            s32 h = D_800F3298 / 2;
            func_800BF6AC(0, D_800F3294, h - 1, h + 1, 0, 0, 0, 0xFF, 0);
        }
        break;
    case 1:
        func_800BF6AC(0, D_800F3294 / 2, 0, D_800F3298 / 2, 0, 0, 0, 0xFF, 0);
        func_800BF6AC(D_800F3294 / 2, D_800F3294, D_800F3298 / 2, D_800F3298, 0, 0, 0, 0xFF, 0);
        break;
    }
}
