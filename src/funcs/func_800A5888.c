/* cflags: -O2 */
#include "common.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    u8 pad0[0x174];
    f32 unk174;
} Cam;

s32 func_800A5458(Cam *, void *, Vec3f *, f32 *);

s32 func_800A5888(Cam *arg0, void *arg1, s16 *pan, u8 *vol) {
    Vec3f v;
    f32 d;
    f32 lim;
    f32 t;
    f32 q;
    f32 f;
    u32 u;

    lim = 1.0f;
    d = lim;
    if (func_800A5458(arg0, arg1, &v, &d) == 0) {
        return 0;
    }
    if (d < 0.001f) {
        return 0;
    }
    if (pan != NULL) {
        *pan = v.z / d * 16352.0f + 16352.0f;
    }
    if (vol == NULL) {
        return 1;
    }
    q = v.z * v.z / d;
    t = q / arg0->unk174;
    if (t >= 0.0f && t <= lim) {
        t *= t;
        f = t * 255.0f + 0.5f;
        if (!(f >= 2147483648.0f)) {
            u = (s32)f;
        } else {
            u = (s32)(f - 2147483648.0f);
            u |= 0x80000000;
        }
        *vol = u;
    }
    return 1;
}
