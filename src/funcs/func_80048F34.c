#include "common.h"

typedef struct {
    s16 x;
    s16 y;
} Ang48F34;

s32 func_80047D40(Ang48F34 *, void *, void *);

s32 func_80048F34(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    Ang48F34 ang;
    s32 dist;
    s32 d;
    s32 t;

    dist = func_80047D40(&ang, arg0 + 4, arg1 + 4);
    if (arg4 < dist) {
        return 0;
    }
    t = ang.y;
    d = *(s16 *)(arg0 + 0x12);
    d = t - d;
    if (d < -0x800) {
        d += 0x1000;
    }
    if (d > 0x800) {
        d -= 0x1000;
    }
    if (d < 0) {
        d = -d;
    }
    if (arg2 < d) {
        return 0;
    }
    t = ang.x;
    d = *(s16 *)(arg0 + 0x10);
    d = t - d;
    if (d < -0x800) {
        d += 0x1000;
    }
    if (d > 0x800) {
        d -= 0x1000;
    }
    if (d < 0) {
        d = -d;
    }
    if (arg3 < d) {
        return 0;
    }
    if (dist == 0) {
        dist = 1;
    }
    return dist;
}
