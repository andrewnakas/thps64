#include "common.h"

s32 func_800469BC(void *arg0, void *arg1) {
    s32 var_a2;

    var_a2 = 0;
    if (((*(s16 *)((u8 *)(arg0) + 0)) != (*(s16 *)((u8 *)(arg1) + 0))) || ((*(s16 *)((u8 *)(arg0) + 2)) != (*(s16 *)((u8 *)(arg1) + 2))) || ((*(s16 *)((u8 *)(arg0) + 4)) != (*(s16 *)((u8 *)(arg1) + 4)))) {
        var_a2 = 1;
    }
    return var_a2;
}
