/* cflags: -Wa,-no-m4100 */
/* MATCHES (z3) only with permuter noise: u32 t = len>>1 copy into h2 AND a later dummy 't = 12' used as a shift count; t needs a 2nd set after its use. */
#include "common.h"

f32 func_800018C0(f32);
f32 func_80001CA0(f32);
void func_8002248C(s32 *, s32 *);
u32 func_800233B8(s32);

static __inline__ void set4_(s32 *q, s32 x, s32 y, s32 z, s32 w) {
    q[0] = x;
    q[1] = y;
    q[2] = z;
    q[3] = w;
}

s32 *func_80067528(s32 *q, s32 *v) {
    s32 n[3];
    u32 len;
    s32 c;
    s32 s;
    s32 h;
    s32 h2;
    u32 t;

    len = func_800233B8(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
    if (len == 0) {
        set4_(q, 0, 0, 0, 0x1000);
    } else {
        func_8002248C(v, n);
        c = 0x1000;
        h = len >> 1;
        if (h) {
            h %= 4096;
            c = func_800018C0(h * 0.000244140625f * 6.283185) * 4096.0f;
        }
        if (!(len >> 1)) {
            s = 0;
        } else {
            t = len >> 1;
            h2 = t;
            s = func_80001CA0(h2 % 4096 * 0.000244140625f * 6.283185) * 4096.0f;
        }
        t = 12;
        set4_(q, (s * n[0]) >> t, (s * n[1]) >> 12, (s * n[2]) >> 12, c);
    }
    return q;
}
