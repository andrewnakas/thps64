#include "common.h"

extern u8 D_800D49E0[];
extern s32 D_800E9048;

s32 func_80096400(void) {
    s32 dir;

    dir = 0;
    if (D_800D49E0[0xA0] != 0 || D_800D49E0[0x22C] != 0 || D_800D49E0[0xB0] != 0 || D_800D49E0[0x23C] != 0) {
        if (D_800E9048 == 0 || (D_800E9048 >= 0x10 && !(D_800E9048 & 3))) {
            if (D_800D49E0[0xB0] != 0 || D_800D49E0[0x23C] != 0) {
                dir = 1;
            }
            if (D_800D49E0[0xA0] != 0 || D_800D49E0[0x22C] != 0) {
                dir = -1;
            }
        }
        D_800E9048++;
    } else {
        D_800E9048 = 0;
    }
    return dir;
}
