/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx800BFC3C;

extern s32 D_800F3298;
extern Gfx800BFC3C *D_800F36A4;

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define _SHIFTL(v, s, w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define CLAMPF(v, sh) _SHIFTL(MAX((s16)(v), 0), sh, 12)

void func_800BFC3C(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 xl;
    s32 xh;
    s32 yl;
    s32 yh;

    {
        Gfx800BFC3C *_g = D_800F36A4++;
        _g->w0 = 0xE7000000;
        _g->w1 = 0;
    }
    {
        Gfx800BFC3C *_g = D_800F36A4++;
        _g->w0 = 0xE3000A01;
        _g->w1 = 0;
    }
    {
        Gfx800BFC3C *_g = D_800F36A4++;
        _g->w0 = 0xE200001C;
        _g->w1 = 0x504240;
    }
    {
        Gfx800BFC3C *_g = D_800F36A4++;
        _g->w0 = 0xFCFFFFFF;
        _g->w1 = 0xFFFDF6FB;
    }
    {
        Gfx800BFC3C *_g = D_800F36A4++;
        _g->w0 = 0xFA000000;
        _g->w1 = 0;
    }
    xl = arg0 * 4;
    xh = arg1 * 4;
    yl = (D_800F3298 - arg3) * 4;
    yh = (D_800F3298 - arg2) * 4;
    {
        Gfx800BFC3C *_g = D_800F36A4++;
        u32 w0, w1;
        w0 = (0xE4000000 | CLAMPF(xh, 12)) | CLAMPF(yh, 0);
        _g->w0 = w0;
        w1 = (0x01000000 | CLAMPF(xl, 12)) | CLAMPF(yl, 0);
        _g->w1 = w1;
    }
    {
        Gfx800BFC3C *_g = D_800F36A4++;
        _g->w0 = 0xE1000000;
        _g->w1 = 0;
    }
    {
        Gfx800BFC3C *_g = D_800F36A4++;
        _g->w0 = 0xF1000000;
        _g->w1 = 0;
    }
    {
        Gfx800BFC3C *_g = D_800F36A4++;
        _g->w0 = 0xE7000000;
        _g->w1 = 0;
    }
    {
        Gfx800BFC3C *_g = D_800F36A4++;
        _g->w0 = 0xE3000A01;
        _g->w1 = 0x100000;
    }
}
