/* cflags: -O2 */
#include "common.h"

s32 func_8009CA84(s32 arg0, s32 arg1) {
    f32 *temp_v0;
    f32 *temp_v1;
    s32 var_a2;
    s32 var_a3;
    s32 var_t0;
    s32 var_t1;

    var_t1 = 0;
loop_1:
    var_t0 = 0;
    if (var_t1 < 4) {
        var_a3 = var_t1 * 4;
        var_a2 = var_t1 * 0x10;
        do {
            temp_v0 = (f32 *)(arg1 + var_a3);
            var_a3 += 0x10;
            temp_v1 = (f32 *)(arg0 + var_a2);
            var_a2 += 4;
            var_t0 += 1;
            *temp_v1 = *temp_v0;
        } while (var_t0 < 4);
        var_t1 += 1;
        goto loop_1;
    }
    return arg0;
}
