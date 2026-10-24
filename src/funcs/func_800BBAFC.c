#include "common.h"

u32 func_80010B30(void);
extern s32 D_800F0DC0;
extern s32 D_800FC840;
extern s32 D_800FC844;

s32 func_800BBAFC(void) {
    s32 t;
    s32 r;

    t = func_80010B30() >> 2;
    if (t >= 0xB9 && D_800F0DC0 != 0) {
        r = D_800FC844;
        D_800F0DC0 = 0;
    } else {
        D_800F0DC0 = 1;
        do {
            r = D_800FC840;
        } while (0);
    }
    return r;
}
