#include "common.h"

f32 func_8009F6BC(f32, f32);

s32 func_80023190(s32 arg0, s32 arg1) {
    f32 a;

    a = func_8009F6BC((f32)arg0 * 0.000244140625f, (f32)arg1 * 0.000244140625f);
    if (a < 0.0f) {
        a += 6.2831855f;
    }
    a *= 0.15915494f;
    return (s32)(a * 4096.0f);
}
