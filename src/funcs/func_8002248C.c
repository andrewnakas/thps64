/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -ffast-math */
#include "common.h"
typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;
s32 func_8002248C(s32 *arg0, s32 *arg1) {
    Vec3f v;
    Vec3f t;
    f32 x, y, z;
    f32 len;
    f32 inv;

    x = arg0[0] * 0.000244140625f;
    y = arg0[1] * 0.000244140625f;
    z = arg0[2] * 0.000244140625f;
    t.x = x; t.y = y; t.z = z;
    v = t;
    len = __builtin_sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
    if (len == 0.0f) {
        arg1[2] = 0;
        arg1[1] = 0;
        arg1[0] = 0;
        return 0;
    }
    inv = 1.0f / len;
    v.x *= inv;
    v.y *= inv;
    v.z *= inv;
    arg1[0] = v.x * 4096.0f;
    arg1[1] = v.y * 4096.0f;
    arg1[2] = v.z * 4096.0f;
    return len * 4096.0f;
}
