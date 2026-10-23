/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct { s16 x, y, z; } V3s;
typedef struct { s32 x, y, z; } V3i;

extern V3s D_800D48A4;
extern V3i D_800D48AC;
extern s16 D_800D48BC;

void func_80042D1C(void) {
    V3i *pos;
    s32 s;
    V3s *vel;
    s32 tx;
    s32 ty;
    s32 tz;
    s32 x;
    s32 y;
    s32 z;
    pos = &D_800D48AC;
    s = D_800D48BC;
    vel = &D_800D48A4;
    tx = (s * vel->x) >> 12;
    x = pos->x;
    x += tx;
    ty = (s * vel->y) >> 12;
    y = pos->y;
    y += ty;
    tz = (s * vel->z) >> 12;
    z = pos->z;
    z += tz;
    pos->x = x;
    vel->x = x;
    pos->y = y;
    vel->y = y;
    pos->z = z;
    vel->z = z;
}
