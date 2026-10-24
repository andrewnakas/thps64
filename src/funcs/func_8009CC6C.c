/* cflags: -O2 */
#include "common.h"

extern f32 func_800018C0(f32);
extern f32 func_80001CA0(f32);
extern f32 *func_8009CAD0(f32 *);

static __inline__ f32 *set_(f32 *m, f32 s, f32 c) {
    m[1] = s;
    m[4] = -s;
    m[5] = c;
    m[0] = c;
    return m;
}

f32 *func_8009CC6C(f32 *arg0, f32 arg1) {
    f32 s;
    f32 c;

    func_8009CAD0(arg0);
    s = func_80001CA0(arg1);
    c = func_800018C0(arg1);
    return set_(arg0, s, c);
}
