/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

void func_80086DC0(void *arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8) {
    f32 first_scale = arg5 - arg3;
    f32 second_scale = arg6 - arg4;

    first_scale /= arg7;
    second_scale /= arg8;
    *arg1 = *arg1 * first_scale + arg3;
    *arg2 = (arg6 - *arg2 * second_scale) + 10.0f;
}
