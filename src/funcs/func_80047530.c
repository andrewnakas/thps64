#include "common.h"

f32 func_800018C0(f32);
f32 func_80001CA0(f32);

#define COSI(r, a) \
    if ((a) == 0) { \
        r = 0x1000; \
    } else { \
        r = func_800018C0((f64)((a) % 4096 * 0.000244140625f) * 6.283185) * 4096.0f; \
    }
#define SINI(r, angle) \
    { \
        s32 a = (angle); \
        r = 0; \
        if (a != 0) { \
            a = (angle) - a / 4096 * 4096; \
            r = func_80001CA0((f64)(a * 0.000244140625f) * 6.283185) * 4096.0f; \
        } \
    }

void func_80047530(s32 *out, s32 *in, s32 ang) {
    s32 c;
    s32 s;
    s32 x;
    s32 z;

    COSI(c, ang);
    SINI(s, ang);
    z = in[0] >> 3;
    x = z * c;
    z = (in[2] >> 3) * s;
    out[0] = (x + z) >> 9;
    out[1] = in[1];
    COSI(c, ang);
    SINI(s, ang);
    z = in[2] >> 3;
    x = z * c;
    z = (in[0] >> 3) * s;
    out[2] = (x - z) >> 9;
}
