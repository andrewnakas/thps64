/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

f32 func_800018C0(f32);
f32 func_80001CA0(f32);

void func_80022C04(f32 *m, s16 *r) {
    f32 sx, sy, sz, cx, cy, cz;

    sx = func_80001CA0(r[0] * 0.0015339808f);
    sy = func_80001CA0(r[1] * 0.0015339808f);
    sz = func_80001CA0(r[2] * 0.0015339808f);
    cx = func_800018C0(r[0] * 0.0015339808f);
    cy = func_800018C0(r[1] * 0.0015339808f);
    cz = func_800018C0(r[2] * 0.0015339808f);
    m[0] = cy * cz + sy * sx * sz;
    m[4] = sy * sx * cz - cy * sz;
    m[8] = sy * cx;
    m[1] = cx * sz;
    m[5] = cx * cz;
    m[9] = -sx;
    m[2] = cy * sx * sz - sy * cz;
    m[6] = sy * sz + cy * sx * cz;
    m[10] = cy * cx;
    m[3] = m[7] = m[11] = m[12] = m[13] = m[14] = 0.0f;
    m[15] = 1.0f;
}
