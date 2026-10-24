/* cflags: -O2 */
/* NON_MATCHING: aln 0.478. Equivalent C; FPU scheduling and register allocation differ throughout (the game spills t0*k to sp+0; KMC gas moves the texrect mult out of the bgez delay slot). */
/* NEAR (-O2): texrect s-part: game has 'mult; bgez dsdx; nop' (KMC gas moved GCC's delay-slot mult out); our GCC puts mult in the bgez delay slot - known toolchain gap. Also spill choice differs (game spills t0*k to sp+0). */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx800B8414;

typedef struct {
    u8 pad[0x38];
    u16 w;
    u16 h;
} Tex800B8414;

extern Gfx800B8414 *D_800F36A4;
extern s32 D_800F3298;

#define _SHIFTL(v, s, w) ((u32)(((u32)(v) & ((1 << (w)) - 1)) << (s)))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

void func_800B8414(Tex800B8414 *tex, f32 x0, f32 x1, f32 y0, f32 y1, f32 s0, f32 s1, f32 t0, f32 t1) {
    f32 fh;
    f32 fw;
    f32 k;
    f32 ta;
    f32 tb;
    f32 dx;
    f32 dy;
    f32 ds;
    s32 s;
    s32 t;
    s32 dsdx;
    s32 dtdy;
    s32 xl;
    s32 xh;
    s32 yl;
    s32 yh;

    fh = tex->h;
    k = (fh - 1.0f) / fh;
    ta = t0 * k;
    tb = t1 * k;
    dx = x1 - x0;
    if (dx <= 0.0f) {
        return;
    }
    dy = y1 - y0;
    if (dy <= 0.0f) {
        return;
    }
    fw = tex->w;
    s = fw * s0 * 32.0f;
    t = fh * ta * 32.0f * (dy / (dy + 1.0f));
    ds = s1 - s0;
    if (ds >= 0.0f) {
        dx += 1.0f;
    }
    dsdx = fw * 1024.0f * ds / dx;
    dtdy = fh * 1024.0f * (ta - tb) / dy;
    xl = x0 * 4.0f;
    xh = (x1 + 1.0f) * 4.0f;
    yl = (D_800F3298 - y1) * 4.0f;
    yh = (D_800F3298 - (y0 - 1.0f)) * 4.0f;
    {
        Gfx800B8414 *_g = D_800F36A4++;
        _g->w0 = 0xE3000C00;
        _g->w1 = 0;
    }
    {
        Gfx800B8414 *_g = D_800F36A4++;
        _g->w0 = (_SHIFTL(0xE4, 24, 8) | _SHIFTL(MAX((s16)(xh), 0), 12, 12) | _SHIFTL(MAX((s16)(yh), 0), 0, 12));
        _g->w1 = (_SHIFTL(1, 24, 3) | _SHIFTL(MAX((s16)(xl), 0), 12, 12) | _SHIFTL(MAX((s16)(yl), 0), 0, 12));
    }
    {
        Gfx800B8414 *_g = D_800F36A4++;
        _g->w0 = 0xE1000000;
        _g->w1 = (_SHIFTL(((s) - (((s16)(xl) < 0) ? (((s16)(dsdx) < 0) ? (MAX((((s16)(xl) * (s16)(dsdx)) >> 7), 0)) : (MIN((((s16)(xl) * (s16)(dsdx)) >> 7), 0))) : 0)), 16, 16) |
                  _SHIFTL(((t) - (((yl) < 0) ? (((s16)(-dtdy) < 0) ? (MAX((((s16)(yl) * (s16)(-dtdy)) >> 7), 0)) : (MIN((((s16)(yl) * (s16)(-dtdy)) >> 7), 0))) : 0)), 0, 16));
    }
    {
        Gfx800B8414 *_g = D_800F36A4++;
        _g->w0 = 0xF1000000;
        _g->w1 = (_SHIFTL((dsdx), 16, 16) | _SHIFTL((-dtdy), 0, 16));
    }
}
