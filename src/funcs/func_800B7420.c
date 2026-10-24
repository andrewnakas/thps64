/* cflags: -O2 */
#include "common.h"

s32 func_800B7420(void *arg0) {
    s32 temp_a0;
    s32 temp_v0;
    s32 var_v1;
    void *var_a1;

    var_a1 = (*(void **)arg0);
    var_v1 = ((*(s32 *)((u8 *)arg0 + 8)) * 4) + 8;
    if (var_a1 != NULL) {
        do {
            temp_v0 = (*(s32 *)((u8 *)var_a1 + 8));
            temp_a0 = (*(s32 *)((u8 *)var_a1 + 4));
            var_a1 = (*(void **)((u8 *)var_a1 + 0x10));
            var_v1 = (((var_v1 + temp_v0) - 1) & -temp_v0) + temp_a0;
        } while (var_a1 != NULL);
    }
    return var_v1;
}
