/* cflags: -ffast-math */
#include "common.h"

f32 func_8009F6BC(f32, f32);

void func_80022A30(s16 *arg0, s16 *arg1) {
    s32 a = arg1[2];
    s32 b = arg1[3];
    s32 c = arg1[4];
    s32 d = arg1[5];
    s32 e = arg1[8];
    s32 sq;
    s32 sr;
    f64 dd;
    f32 r;
    f32 t;
    f32 k;
    f32 zero;
    f32 m1;
    f32 m2;

    sq = a * (a * 2);
    dd = sq;
    if (sq < 0) {
        dd += 4294967296.0;
    }
    sr = __builtin_sqrtf((f32)dd);
    t = -d;
    k = 0.00024414062f;
    r = func_8009F6BC(t * k, sr * k);
    zero = 0.0f;
    if (r < zero) {
        r += 6.2831855f;
    }
    arg0[0] = (r = r * (m1 = 0.15915494f)) * (m2 = 4096.0f);
    r = func_8009F6BC(a * k, e * k);
    if (r < zero) {
        r += 6.2831855f;
    }
    r = r * m1;
    arg0[1] = r * m2;
    r = func_8009F6BC(b * k, c * k);
    if (r < zero) {
        r += 6.2831855f;
    }
    r = r * m1;
    arg0[2] = r * m2;
}
