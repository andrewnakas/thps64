/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s16 x, y, z;
} S3_80049934;

typedef struct {
    s16 x;
    u16 y;
} S2_80049934;

typedef struct {
    s16 x, y;
} O2_80049934;

void func_80049934(S3_80049934 a, O2_80049934 *zero, O2_80049934 *out, S3_80049934 b, s32 k) {
    S2_80049934 d;

    d.x = b.x - a.x;
    d.y = b.y - a.y;
    if (d.x < -0x800) {
        d.x += 0x1000;
    }
    if (d.x > 0x800) {
        d.x -= 0x1000;
    }
    if ((s16)d.y < -0x800) {
        d.y += 0x1000;
    }
    if ((s16)d.y > 0x800) {
        d.y -= 0x1000;
    }
    if (d.x == 0 && d.y == 0) {
        zero->x = 0;
        zero->y = 0;
        return;
    }
    out->x = (k * d.x) >> 8;
    out->y = (k * (s16)d.y) >> 8;
}
