#include "common.h"

extern void *D_800DCAA0;

s32 func_8006EEBC(void *arg0) {
    void *var_v0;

    var_v0 = D_800DCAA0;
    while (var_v0 != NULL) {
        if (var_v0 == arg0) {
            return 1;
        }
        var_v0 = (*(void **)((u8 *)(var_v0) + 0x14));
    }
    return 0;
}
