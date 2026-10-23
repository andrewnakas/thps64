#include "common.h"

f32 func_8009F9D0(f32);

s32 func_8002311C(s32 arg0) {
    f32 a;

    a = func_8009F9D0((f32)arg0 * 0.000244140625f);
    if (a < 0.0f) {
        a += 6.2831855f;
    }
    a *= 0.15915494f;
    return (s32)(a * 4096.0f);
}
