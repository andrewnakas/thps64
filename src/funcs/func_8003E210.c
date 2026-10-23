/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx8003E210;

extern Gfx8003E210 *D_800F36A4;

void func_8003E210(s32 *arg0) {
    Gfx8003E210 *g;
    Gfx8003E210 *h;

    h = D_800F36A4;
    g = h++;
    D_800F36A4 = h;
    g->w0 = 0xE7000000;
    g->w1 = 0;
    D_800F36A4 = h + 1;
    h[0].w0 = 0xE3000A01;
    h[0].w1 = 0;
    D_800F36A4 = h + 2;
    h[1].w0 = 0xE3000C00;
    h[1].w1 = 0;
    D_800F36A4 = h + 3;
    h[2].w0 = 0xE200001C;
    h[2].w1 = 0x504240;
    D_800F36A4 = h + 4;
    h[3].w0 = 0xFCFFFFFF;
    h[3].w1 = 0xFFFCF279;
    if (arg0[1] != 0) {
        D_800F36A4 = h + 5;
        h[4].w0 = 0xE3001201;
        h[4].w1 = 0x2000;
    } else {
        D_800F36A4 = h + 5;
        h[4].w0 = 0xE3001201;
        h[4].w1 = 0;
    }
}
