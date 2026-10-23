#include "common.h"

extern s16 **D_800DACB0;

u16 func_80068F60(u16 *arg0) {
    u16 idx;

    if (arg0[-1] == 0xB) {
        idx = arg0[1];
        if (*D_800DACB0[idx] == 0xA) {
            return idx;
        }
        return arg0[2];
    }
    return arg0[1];
}
