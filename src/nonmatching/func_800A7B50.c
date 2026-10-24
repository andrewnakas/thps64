/* cflags: -O2 */
/* NON_MATCHING: aln ratio 0.717 (581 vs 588 insns); frame layout, float register allocation, argument spills and texture-rectangle scheduling differ. Texture rectangles use tile 1 like the game (tile 0 garbled all text when booted, 2026-10-24). Reviewed for equivalence 2026-10-24: yl/yoff are s16 so the t-clamp test is (s16)yl + (s16)yoff < 0 as in the game. */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} GfxA7B50;

typedef struct {
    u8 pad0[0x3A];
    u16 h;
} TexA7B50;

typedef struct {
    u8 pad0[8];
    s16 off;
    u8 padA[2];
    void (*fn)(void *, f32, f32);
} VtA7B50;

typedef struct {
    f32 scale;
    f32 th;
    s32 space;
    s32 count;
    u8 pad10[8];
    f32 kern;
    u8 pad1C[8];
    s16 right[64];
    s16 left[64];
    u8 pad124[0x224 - 0x124];
    u8 prim[4];
    u8 env[4];
    TexA7B50 *tex;
    u8 pad230[4];
    f32 offx;
    f32 offy;
    VtA7B50 *vt;
} FontA7B50;

s32 func_800A781C(FontA7B50 *, s32, s32 *, s32 *, s32 *, s32 *);
void func_800A8480(FontA7B50 *, u8 *, f32 *, f32 *);
void func_800B9D48(TexA7B50 *);
s32 func_800B9DE0(TexA7B50 *);
void func_800BFC3C(s32, s32, s32, s32);
extern f32 D_800EA9B0;
extern s32 D_800F3298;
extern f32 D_800F329C;
extern GfxA7B50 *D_800F36A4;

#define _SHIFTL(v, s, w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define gImmp1(pkt, c, p0)                \
    {                                     \
        GfxA7B50 *_g = (GfxA7B50 *)(pkt); \
        _g->w0 = _SHIFTL(c, 24, 8);       \
        _g->w1 = (u32)(p0);               \
    }

#define gSPScisTextureRectangle(pkt, xl, yl, xh, yh, tile, s, t, dsdx, dtdy)                                       \
    {                                                                                                              \
        GfxA7B50 *_g = (GfxA7B50 *)(pkt);                                                                          \
        _g->w0 = (_SHIFTL(0xE4, 24, 8) | _SHIFTL(MAX((s16)(xh), 0), 12, 12) | _SHIFTL(MAX((s16)(yh), 0), 0, 12)); \
        _g->w1 = (_SHIFTL((tile), 24, 3) | _SHIFTL(MAX((s16)(xl), 0), 12, 12) | _SHIFTL(MAX((s16)(yl), 0), 0, 12)); \
        gImmp1(pkt, 0xE1,                                                                                          \
               (_SHIFTL(((s) - (((s16)(xl) < 0) ? (((s16)(dsdx) < 0) ? (MAX((((s16)(xl) * (s16)(dsdx)) >> 7), 0))  \
                                                                     : (MIN((((s16)(xl) * (s16)(dsdx)) >> 7), 0))) \
                                                : 0)),                                                             \
                        16, 16) |                                                                                  \
                _SHIFTL(((t) - (((yl) < 0) ? (((s16)(dtdy) < 0) ? (MAX((((s16)(yl) * (s16)(dtdy)) >> 7), 0))      \
                                                                : (MIN((((s16)(yl) * (s16)(dtdy)) >> 7), 0)))      \
                                           : 0)),                                                                  \
                        0, 16)));                                                                                  \
        gImmp1(pkt, 0xF1, (_SHIFTL((dsdx), 16, 16) | _SHIFTL((dtdy), 0, 16)));                                     \
    }

#define gDPNoParam(pkt, cmd)              \
    {                                     \
        GfxA7B50 *_g = (GfxA7B50 *)(pkt); \
        _g->w0 = _SHIFTL(cmd, 24, 8);     \
        _g->w1 = 0;                       \
    }

#define gDPSetColor(pkt, c, d)            \
    {                                     \
        GfxA7B50 *_g = (GfxA7B50 *)(pkt); \
        _g->w0 = _SHIFTL(c, 24, 8);       \
        _g->w1 = (u32)(d);                \
    }

#define RGBA(r, g, b, a) (_SHIFTL(r, 24, 8) | _SHIFTL(g, 16, 8) | _SHIFTL(b, 8, 8) | _SHIFTL(a, 0, 8))

f32 func_800A7B50(FontA7B50 *f, f32 x, f32 y, u8 *str, s32 measure, u8 *colors, s16 *offs) {
    f32 w;
    f32 h;
    s32 flipS;
    s32 flipT;
    s32 hl;
    s32 wide;
    f32 sx;
    f32 px;
    f32 th;
    u16 a3E;
    u16 a46;
    u16 a4E;
    u16 a56;
    u16 a5E;
    u16 yl0;
    u16 yh0;
    u16 yh;
    u16 xh;
    s16 yl;
    s32 xl;
    s32 c;
    s32 idx;
    s32 s1;
    s32 s3;
    s32 s;
    u16 t;
    s16 dsdx;
    s16 dtdy;
    s32 xoff;
    s16 yoff;
    f32 k;
    f32 z;
    f32 four;
    u16 hh;
    u8 *p;
    u8 *cp;
    s16 *op;

    sx = f->scale * D_800F329C;
    px = (x + D_800EA9B0) * D_800F329C;
    if (f->tex != NULL) {
        px += f->offx;
        y += f->offy;
        if (measure != 0) {
            func_800A8480(f, str, &w, &h);
            func_800BFC3C((s32)(px + -1.0f), (s32)(px + w + 1.0f), (s32)(y - h + -1.0f), (s32)(y + 1.0f));
        }
        if (func_800B9DE0(f->tex) == 0) {
            gDPNoParam(D_800F36A4++, 0xE7);
            {
                GfxA7B50 *_g = D_800F36A4++;
                _g->w0 = 0xE3000A01;
                _g->w1 = 0x100000;
            }
            func_800B9D48(f->tex);
        }
        {
            GfxA7B50 *_g = D_800F36A4++;
            _g->w0 = 0xE200001C;
            _g->w1 = 0x0C184240;
        }
        {
            GfxA7B50 *_g = D_800F36A4++;
            _g->w0 = 0xE3000C00;
            _g->w1 = 0;
        }
        if (colors == NULL) {
            gDPSetColor(D_800F36A4++, 0xFA, RGBA(f->prim[0], f->prim[1], f->prim[2], f->prim[3]));
            gDPSetColor(D_800F36A4++, 0xFB, RGBA(f->env[0], f->env[1], f->env[2], f->env[3]));
        }
        th = f->th;
        z = 0.0f;
        four = 4.0f;
        a3E = (s32)(th * -20.0f);
        y = (f32)D_800F3298 - y;
        hh = f->tex->h;
        a46 = (s32)((z / th) * 32.0f);
        p = str;
        a56 = (s32)((1.0f / sx) * 1024.0f);
        a5E = (s32)((1.0f / th) * 1024.0f);
        cp = colors;
        op = offs;
        a4E = hh << 5;
        yl = yl0 = (s32)((y - z) * four);
        yh = yh0 = (s32)((y + hh * th + z) * four);
        while (1) {
            c = *p++;
            if (c == 0) {
                break;
            }
            idx = func_800A781C(f, c, &flipS, &flipT, &hl, &wide);
            if (f->count < idx) {
                idx = -1;
            }
            if (idx < 0) {
                if (idx == -1) {
                    px += sx * (f32)f->space;
                }
            } else {
                s1 = f->left[idx] - 1;
                s3 = f->right[idx] - s1 + 2;
                xl = (s32)((px - z) * four);
                xh = (s32)((px + s3 * sx + z) * four);
                if (colors != NULL) {
                    gDPNoParam(D_800F36A4++, 0xE7);
                    gDPSetColor(D_800F36A4++, 0xFA, RGBA(cp[0], cp[1], cp[2], f->prim[3]));
                    gDPSetColor(D_800F36A4++, 0xFB, RGBA(cp[0], cp[1], cp[2], f->prim[3]));
                } else if (hl != 0) {
                    gDPNoParam(D_800F36A4++, 0xE7);
                    gDPSetColor(D_800F36A4++, 0xFB, RGBA(f->prim[0], f->prim[1], f->prim[2], f->prim[3]));
                }
                f->vt->fn((u8 *)f + f->vt->off, px, y);
                gDPNoParam(D_800F36A4++, 0xE8);
                gImmp1(D_800F36A4++, 0xF2,
                       0x01000000 | _SHIFTL((s32)((s1 + s3 - 1) * four), 12, 12) |
                           _SHIFTL((s32)((f->tex->h - 1) * four), 0, 12));
                if (flipS != 0) {
                    s = (s32)(((z / sx) + s1 + s3) * 32.0f);
                    dsdx = -a56;
                } else {
                    dsdx = a56;
                    s = (s32)(((z / sx) + s1) * 32.0f);
                }
                if (flipT != 0) {
                    t = a4E;
                    dtdy = -a5E;
                } else {
                    t = a46;
                    dtdy = a5E;
                }
                if (wide != 0) {
                    s32 d;
                    yoff = a3E;
                    d = 12 - s3;
                    k = sx * four;
                    if (d >= 0) {
                        xoff = k * d;
                    } else {
                        xoff = k * z;
                    }
                } else {
                    xoff = 0;
                    yoff = 0;
                }
                if (offs != NULL) {
                    s32 o = *op++ * 4;
                    yl = yl0 + o;
                    yh = yh0 + o;
                }
                gSPScisTextureRectangle(D_800F36A4++, xl + xoff, yl + yoff, xh + xoff, yh + yoff, 1, s, t, dsdx, dtdy);
                if (hl != 0) {
                    gDPNoParam(D_800F36A4++, 0xE7);
                    gDPSetColor(D_800F36A4++, 0xFB, RGBA(f->env[0], f->env[1], f->env[2], f->env[3]));
                }
                if (wide == 0) {
                    px += (s3 - 1) * sx;
                    if (*p != 0) {
                        px += f->kern;
                    }
                }
            }
            if (colors != NULL) {
                cp += 3;
            }
        }
    }
    return px;
}
