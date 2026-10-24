/* cflags: -O2 */
#include "common.h"

void func_8009CA00(u8 *, u8 *, f32 *);

void func_800A4568(u8 *arg0, f32 l, f32 r, f32 b, f32 t) {
    f32 *m;
    f32 w;
    f32 h;

    w = r - l;
    m = (f32 *)(arg0 + 0xA0);
    h = t - b;
    m[0] = 2.0f / w;
    m[5] = 2.0f / h;
    m[10] = -1.0f;
    m[12] = -(r + l) / w;
    m[13] = -(t + b) / h;
    m[15] = 1.0f;
    m[1] = m[2] = m[3] = m[4] = m[6] = m[7] = m[8] = m[9] = m[11] = m[14] = 0.0f;
    func_8009CA00(arg0 + 0x120, arg0 + 0xE0, m);
}
