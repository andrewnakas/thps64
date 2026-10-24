/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx800A602C;

typedef struct {
    u8 *vp;
    u8 pad4[3];
    u8 idx;
    u8 pad8[0xC];
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;
} View_800A602C;

extern s32 D_800F3294;
extern s32 D_800F3298;
extern s32 D_800F3698;
extern Gfx800A602C *D_800F36A4;

void func_800A602C(View_800A602C *v) {
    s32 x0, y0, x1, y1;
    s32 t;
    s32 lo;

    {
        Gfx800A602C *_g = D_800F36A4++;
        _g->w0 = 0xDC080008;
        _g->w1 = (u32)(v->vp + v->idx * 0x10);
    }
    x0 = v->x0;
    y0 = v->y0;
    y1 = D_800F3298 - v->x1;
    x1 = D_800F3298 - v->y1;
    lo = D_800F3698;
    if (x0 < lo) {
        x0 = lo;
    } else {
        {
            s32 d = D_800F3294;
            s32 u = lo + 1;
            t = d - u;
        }
        if (t < x0) {
            x0 = t;
        }
    }
    if (y0 < lo) {
        y0 = lo;
    } else {
        {
            s32 d = D_800F3294;
            s32 u = lo + 1;
            t = d - u;
        }
        if (t < y0) {
            y0 = t;
        }
    }
    if (y1 < lo) {
        y1 = lo;
    } else {
        {
            s32 d = D_800F3298;
            s32 u = lo + 1;
            t = d - u;
        }
        if (t < y1) {
            y1 = t;
        }
    }
    if (x1 < lo) {
        x1 = lo;
    } else {
        {
            s32 d = D_800F3298;
            s32 u = lo + 1;
            t = d - u;
        }
        if (t < x1) {
            x1 = t;
        }
    }
    {
        Gfx800A602C *g = D_800F36A4++;
        g->w0 = 0xED000000 | (((s32)(x0 * 4.0f) & 0xFFF) << 12) | ((s32)(x1 * 4.0f) & 0xFFF);
        g->w1 = (((s32)(y0 * 4.0f) & 0xFFF) << 12) | ((s32)(y1 * 4.0f) & 0xFFF);
    }
}
