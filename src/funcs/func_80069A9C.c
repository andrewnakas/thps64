/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-no-m4100 */
#include "common.h"

typedef struct {
    u32 tag;
    u32 code;
    s16 x0, y0, x1, y1;
} LineF2_80069A9C;

extern s32 D_800DC5FC;
extern s32 D_800DC5F4;
extern s32 D_800DC5F8;
extern LineF2_80069A9C *D_800D0FA8;
extern u32 D_800DE9A4;
extern u8 *D_800D0F9C;

void func_80069A9C(s32 x0, s32 y0, s32 x1, s32 y1, s32 col) {
    s32 s;
    s32 t;
    LineF2_80069A9C *p;
    LineF2_80069A9C *q;
    u8 *ot;
    u32 u;
    u32 u2;

    s = D_800DC5FC;
    x0 *= s;
    x1 *= s;
    y0 *= s;
    y1 *= s;
    x0 /= 15872;
    x1 /= 15872;
    y0 /= -25600;
    y1 /= -25600;
    if (x0 == x1 && y0 == y1) {
        return;
    }
    x0 += D_800DC5F4;
    x1 += D_800DC5F4;
    y0 += D_800DC5F8;
    y1 += D_800DC5F8;
    if (x1 < x0) {
        t = x0;
        x0 = x1;
        x1 = t;
        t = y0;
        y0 = y1;
        y1 = t;
    }
    if (x1 < 0 || x0 >= 512) {
        return;
    }
    if (x0 < 0) {
        y0 += -x0 * (y1 - y0) / (x1 - x0);
        x0 = 0;
    }
    if (x1 >= 512) {
        y1 = (511 - x0) * (y1 - y0) / (x1 - x0) + y0;
        x1 = 511;
    }
    if (y1 < y0) {
        t = x0;
        x0 = x1;
        x1 = t;
        t = y0;
        y0 = y1;
        y1 = t;
    }
    if (y1 < 0 || y0 >= 240) {
        return;
    }
    if (y0 < 0) {
        x0 += -y0 * (x1 - x0) / (y1 - y0);
        y0 = 0;
    }
    if (y1 >= 240) {
        x1 = (239 - y0) * (x1 - x0) / (y1 - y0) + x0;
        y1 = 239;
    }
    p = D_800D0FA8;
    q = p + 1;
    if (D_800DE9A4 < (u32)q) {
        return;
    }
    D_800D0FA8 = q;
    p->tag = 0x3000000;
    p->code = col + 0x40000000;
    p->x0 = x0;
    p->y0 = y0;
    p->x1 = x1;
    p->y1 = y1;
    ot = D_800D0F9C;
    u = *(u32 *)(ot + 0x84) >> 8 << 8;
    p->tag = ((u8 *)p)[3] | u;
    u2 = (u32)p << 8;
    *(u32 *)(ot + 0x84) = ot[0x87] | u2;
}
