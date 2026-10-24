/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -ffast-math */
#include "common.h"
#include "vecmath.h"
void func_80022964(s32 *arg0) {
    Vec3f v;
    f32 x, y, z;
    f32 len;
    f32 inv;

    x = arg0[0] * 0.000244140625f;
    y = arg0[1] * 0.000244140625f;
    z = arg0[2] * 0.000244140625f;
    v.x = x; v.y = y; v.z = z;
    len = __builtin_sqrtf(x * x + y * y + z * z);
    if (len != 0.0f) {
        inv = 1.0f / len;
        v.x = x * inv;
        v.y = y * inv;
        v.z = z * inv;
    }
    arg0[0] = v.x * 4096.0f;
    arg0[1] = v.y * 4096.0f;
    arg0[2] = v.z * 4096.0f;
}
