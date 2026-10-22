#include "common.h"

s32 func_800470A8(void *arg0, void *arg1) {
    s32 var_a2;

    var_a2 = 0;
    if (((*(s32 *)((u8 *)(arg0) + 0)) == (*(s32 *)((u8 *)(arg1) + 0))) && ((*(s32 *)((u8 *)(arg0) + 4)) == (*(s32 *)((u8 *)(arg1) + 4)))) {
        var_a2 = (*(s32 *)((u8 *)(arg0) + 8)) == (*(s32 *)((u8 *)(arg1) + 8));
    }
    return var_a2;
}
