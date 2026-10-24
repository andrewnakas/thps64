/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx800BD740;

typedef struct {
    s16 vscale[4];
    s16 vtrans[4];
} Vp800BD740;

typedef union {
    s32 w;
    s32 mm;
    s32 k;
    struct {
        s16 hi;
        u16 lo;
    } h;
} Dim800BD740;

extern s32 D_800F3294;
extern Dim800BD740 D_800F3298;
extern s32 D_800F3698;
extern Gfx800BD740 *D_800F36A4;
extern Vp800BD740 D_800FC950;

#define FX(v) ((s32)((f32)(v) * 4.0f) & 0xFFF)

void func_800BD740(s32 x0, s32 x1, s32 y0, s32 y1) {
    s32 l;
    s32 r;
    s32 t;
    s32 b;
    s32 m;
    s32 w;
    s32 mm;
    s32 k;

    if (x0 < 0) {
        x0 = 0;
    } else if (x0 > D_800F3294) {
        x0 = D_800F3294;
    }
    if (x1 < 0) {
        x1 = 0;
    } else if (x1 > D_800F3294) {
        x1 = D_800F3294;
    }
    if (y0 < 0) {
        y0 = 0;
    } else if (y0 > D_800F3298.w) {
        y0 = D_800F3298.w;
    }
    if (y1 < 0) {
        y1 = 0;
    } else if (y1 > D_800F3298.w) {
        y1 = D_800F3298.w;
    }
    l = x0;
    if (l < 0) {
        l = 0;
    }
    r = x1;
    w = D_800F3294;
    if (r > w - 1) {
        r = w - 1;
    }
    t = y0;
    if (t < 0) {
        t = 0;
    }
    b = y1;
    if (b > D_800F3298.w - 1) {
        b = D_800F3298.w - 1;
    }
    D_800FC950.vscale[0] = (r - l) * 2;
    D_800FC950.vscale[1] = (b - t) * 2;
    D_800FC950.vscale[2] = 0x1FF;
    D_800FC950.vscale[3] = 0;
    D_800FC950.vtrans[0] = (l + ((r - l) >> 1)) * 4;
    D_800FC950.vtrans[1] = (D_800F3298.h.lo - (t + ((b - t) >> 1))) * 4;
    D_800FC950.vtrans[2] = 0x1FF;
    D_800FC950.vtrans[3] = 0;
    {
        Gfx800BD740 *_g = D_800F36A4++;
        _g->w0 = 0xDC080008;
        _g->w1 = (u32)&D_800FC950;
    }
    m = D_800F3698;
    if (l < m) {
        l = m;
    } else {
        k = w;
        mm = m + 1;
        if (l > k - mm) {
            l = k - mm;
        }
    }
    if (r < m) {
        r = m;
    } else {
        k = D_800F3294;
        mm = m + 1;
        if (r > k - mm) {
            r = k - mm;
        }
    }
    if (t < m) {
        t = m;
    } else {
        k = D_800F3298.w;
        mm = m + 1;
        if (t > k - mm) {
            t = k - mm;
        }
    }
    if (b < m) {
        b = m;
    } else {
        k = D_800F3298.w;
        mm = m + 1;
        if (b > k - mm) {
            b = k - mm;
        }
    }
    {
        Gfx800BD740 *_g = D_800F36A4++;
        s32 fl = FX(l);
        s32 h = D_800F3298.w;
        _g->w0 = 0xED000000 | (fl << 12) | FX(h - b);
        _g->w1 = (FX(r) << 12) | FX(h - t);
    }
}
