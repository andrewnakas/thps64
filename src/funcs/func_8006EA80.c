#include "common.h"

extern u8 D_800DCC1E;
extern s32 D_800DC958;
extern u8 D_800DCAB4[][0x24];

void *func_8006EA80(void) {
    u8 (*p)[0x24];

    if (D_800DCC1E == 0) {
        return 0;
    }
    p = D_800DCAB4;
    return p[D_800DC958];
}
