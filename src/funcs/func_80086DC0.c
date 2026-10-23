#include "common.h"

#define D_8001EDDC (*(const f32 *) 0x8001EDDC)

void func_80086DC0(void *arg0, f32 *arg1, f32 *arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8) {
    f32 first_scale = arg5 - arg3;
    f32 second_scale = arg6 - arg4;
    register f32 value __asm__("$f0");
    first_scale /= arg7;
    second_scale /= arg8;

    value = *arg1;
    value *= first_scale;
    *arg1 = value + arg3;
    value = *arg2;
    value *= second_scale;
    *arg2 = (arg6 - value) + D_8001EDDC;
}
