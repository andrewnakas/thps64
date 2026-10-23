/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-no-m4100 */
#include "common.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
    s32 w;
} Quat80067A48;

typedef struct {
    s16 m[3][3];
    s32 t[3];
} Mtx80067A48;

void func_80067A48(Quat80067A48 *q, Mtx80067A48 *m) {
    s32 wx;
    s32 wy;
    s32 wz;
    s32 xx;
    s32 xy;
    s32 xz;
    s32 yy;
    s32 yz;
    s32 zz;

    wx = (q->w * q->x) >> 11;
    wy = (q->w * q->y) >> 11;
    wz = (q->w * q->z) >> 11;
    xx = (q->x * q->x) >> 11;
    xy = (q->x * q->y) >> 11;
    xz = (q->x * q->z) >> 11;
    yy = (q->y * q->y) >> 11;
    yz = (q->y * q->z) >> 11;
    zz = (q->z * q->z) >> 11;
    m->m[0][0] = 0x1000 - (yy + zz);
    m->m[0][1] = xy + wz;
    m->m[0][2] = xz - wy;
    m->m[1][0] = xy - wz;
    m->m[1][1] = 0x1000 - (xx + zz);
    m->m[1][2] = yz + wx;
    m->m[2][0] = xz + wy;
    m->m[2][1] = yz - wx;
    m->m[2][2] = 0x1000 - (xx + yy);
    m->t[0] = 0;
    m->t[1] = 0;
    m->t[2] = 0;
}
