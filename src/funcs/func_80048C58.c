#include "common.h"

extern void *D_800DAD8C;

s32 func_80048C58(s32 arg0) {
    void *var_v0;

    var_v0 = D_800DAD8C;
    while (var_v0 != NULL) {
        if (var_v0 == (void *)arg0) {
            return 1;
        }
        var_v0 = *(void **)((u8 *)var_v0 + 0x1C);
    }
    return 0;
}
