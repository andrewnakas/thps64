/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -ffast-math */
#include "common.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec800278AC;

typedef struct {
    u8 pad0[0x2250];
    s32 unk2250;
    Vec800278AC unk2254;
} Obj800278AC;



void func_800278AC(Obj800278AC *arg0, s32 arg1, Vec800278AC *arg2) {
    Vec800278AC sum;
    Vec800278AC a;
    Vec800278AC b;
    f32 k, k2;
    f32 ax, ay, az, bx, by, bz;
    f32 len;
    f32 inv;

    arg0->unk2250 = arg1;

    k = 0.1f;
    ax = arg2->x * k;
    ay = arg2->y * k;
    az = arg2->z * k;
    a.x = ax;
    a.y = ay;
    a.z = az;

    k2 = 0.9f;
    bx = arg0->unk2254.x * k2;
    by = arg0->unk2254.y * k2;
    bz = arg0->unk2254.z * k2;
    b.x = bx;
    b.y = by;
    b.z = bz;
    ax = ax + bx;
    ay = ay + by;
    az = az + bz;
    sum.x = ax;
    sum.y = ay;
    sum.z = az;
    arg0->unk2254 = sum;
    len = __builtin_sqrtf(arg0->unk2254.x * arg0->unk2254.x + arg0->unk2254.y * arg0->unk2254.y + arg0->unk2254.z * arg0->unk2254.z);
    if (len != 0.0f) {
        inv = 1.0f / len;
        arg0->unk2254.x *= inv;
        arg0->unk2254.y *= inv;
        arg0->unk2254.z *= inv;
    }
}
