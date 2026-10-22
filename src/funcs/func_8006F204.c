#include "common.h"

s32 func_8006E9CC(void);
extern u16 D_800DCAAC;
extern u8 D_800DCC1E;

s32 func_8006F204(void) {
    if (D_800DCC1E != 0) {
        return func_8006E9CC();
    }
    return D_800DCAAC;
}
