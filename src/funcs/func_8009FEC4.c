/* Matches with the -fwrapv cc1 (PR 233): D + 0x80000000 compiles to addu like the game. */
#include "common.h"

extern u32 D_800F56C0;

s32 func_8009FEC4(u32 a0) {
    s32 r = 0;
    if (a0 > 0x800003FF) {
        r = !(a0 > D_800F56C0 + 0x80000000);
    }
    return r;
}
