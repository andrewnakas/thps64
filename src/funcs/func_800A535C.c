/* cflags: -O2 */
#include "common.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    u8 pad0[0x90];
    Vec3f pos;
    u8 pad9C[0xD8];
    f32 unk174;
    u8 pad178[0x58];
    Vec3f planes[5];
} Cam;

s32 func_800A535C(Cam *arg0, Vec3f *arg1, f32 arg2, s32 arg3) {
    Vec3f d;
    Vec3f c;
    f32 r;
    f32 dist;
    s32 i;
    s32 off;
    Vec3f *pl;
    Vec3f *pos;
    f32 xx, yy, zz;

    pos = &arg0->pos;
    c.x = pos->x;
    c.y = pos->y;
    c.z = pos->z;
    xx = arg1->x - c.x;
    yy = arg1->y - c.y;
    zz = arg1->z - c.z;
    d.x = xx;
    d.y = yy;
    d.z = zz;
    if (arg3 != 0) {
        dist = xx * xx + yy * yy + zz * zz;
        r = arg2 + arg0->unk174;
        if (r * r < dist) {
            return 0;
        }
    }
    i = 0;
    off = 0;
    while (1) {
        if (i >= 5) {
            break;
        }
        pl = (Vec3f *)(off + (s32)arg0);
        pl = (Vec3f *)((s32)pl + 0x1D0);
        off += 0xC;
        if (pl->x * d.x + pl->y * d.y + pl->z * d.z + arg2 < 0.0f) {
            return 0;
        }
        i++;
    }
    return 1;
}
