/* cflags: -O2 */
#include "common.h"

f32 *func_8009CAD0(f32 *);
f32 func_800018C0(f32);
f32 func_80001CA0(f32);

f32 *func_8009CC10(f32 *m, f32 a) {
    f32 s;
    f32 c;

    func_8009CAD0(m);
    s = func_80001CA0(a);
    c = func_800018C0(a);
    m[8] = s;
    m[2] = -s;
    m[10] = c;
    m[0] = c;
    return m;
}
