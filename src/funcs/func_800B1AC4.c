/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx800B1AC4;

typedef struct {
    s32 *offsets;
    u8 *base;
} Res800B1AC4;

typedef struct {
    u8 unk0;
    u8 bpp;
    u8 fmt;
    u8 pad3;
    u8 unk4;
    u8 pad5[3];
    s32 width;
    s32 height;
    u8 pad10[4];
    u32 stride;
} Img800B1AC4;

typedef struct {
    s16 pad0;
    s16 pad2;
    s16 pad4;
    s16 pad6;
    s16 off;
    s16 padA;
    void (*fn)(void *);
} VEnt800B1AC4;

typedef struct {
    u8 *res;
    s32 flip;
    u8 pad8[8];
    VEnt800B1AC4 *vt;
} Spr800B1AC4;

extern Gfx800B1AC4 *D_800F36A4;
extern f32 D_800ECEF0;
extern f32 D_800F329C;
extern s32 D_800EECE8;
s32 func_800B2830(Res800B1AC4 *, s32);
void func_800B2040(Spr800B1AC4 *, Img800B1AC4 *, u8 *, s32, s32);

#define _SHIFTL(v, s, w) ((u32)(((u32)(v) & ((1 << (w)) - 1)) << (s)))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

static inline u8 *get800B1AC4(Spr800B1AC4 *spr, s32 k) {
    Res800B1AC4 *r = (Res800B1AC4 *)(spr->res + 8);
    return r->base + func_800B2830(r, k);
}

void func_800B1AC4(Spr800B1AC4 *spr, f32 x, f32 y, f32 sx, f32 sy) {
    Img800B1AC4 *img;
    u8 *pal;
    u8 *tex;
    u8 *p;
    s32 ci;
    s32 rows;
    s32 left;
    s32 n;
    s32 w;
    s32 row;
    s32 dsdx;
    s32 dtdy;
    s32 xl;
    s32 xh;
    s32 yl;
    s32 yh;
    s32 lineBytes;
    f32 x0;
    f32 xs;

    x0 = x + D_800ECEF0;
    xs = sx * D_800F329C;
    x0 = x0 * D_800F329C;
    D_800EECE8 = -1;
    spr->vt->fn((u8 *)spr + spr->vt->off);
    img = (Img800B1AC4 *)get800B1AC4(spr, 0);
    if (img->stride == 0) {
        return;
    }
    ci = 0;
    switch (img->fmt) {
    case 4:
            pal = get800B1AC4(spr, 1);
            if (img->unk4 == 3) {
                Gfx800B1AC4 *_g = D_800F36A4++;
                _g->w0 = 0xE3001001;
                _g->w1 = 0x8000;
            }
            {
                Gfx800B1AC4 *_g = D_800F36A4++;
                _g->w0 = 0xFD100000;
                _g->w1 = (u32)pal;
            }
            {
                Gfx800B1AC4 *_g = D_800F36A4++;
                _g->w0 = 0xE8000000;
                _g->w1 = 0;
            }
            {
                Gfx800B1AC4 *_g = D_800F36A4++;
                _g->w0 = 0xF5000100;
                _g->w1 = 0x07000000;
            }
            {
                Gfx800B1AC4 *_g = D_800F36A4++;
                _g->w0 = 0xE6000000;
                _g->w1 = 0;
            }
            {
                Gfx800B1AC4 *_g = D_800F36A4++;
                _g->w0 = 0xF0000000;
                _g->w1 = 0x073FC000;
            }
            {
                Gfx800B1AC4 *_g = D_800F36A4++;
                _g->w0 = 0xE7000000;
                _g->w1 = 0;
            }
            ci = 1;
        break;
    case 0:
            {
                Gfx800B1AC4 *_g = D_800F36A4++;
                _g->w0 = 0xE3001001;
                _g->w1 = 0;
            }
        break;
    }
    tex = get800B1AC4(spr, 2);
    {
        s32 sz = 0x1000;
        if (ci) {
            sz = 0x800;
        }
        rows = sz / img->stride;
    }
    if (rows == 12) {
        rows = 8;
    }
    w = img->width;
    if (spr->flip) {
        w--;
    }
    xh = (x0 + w * xs) * 4.0f;
    dsdx = 1.0f / xs * 1024.0f;
    dtdy = 1.0f / sy * 1024.0f;
    xl = x0 * 4.0f;
    if (spr->flip) {
        xh++;
    }
    row = 0;
    p = tex;
    left = img->height;
    lineBytes = (img->stride * 8) / img->bpp;
    while (1) {
        if (left == 0) {
            break;
        }
        n = left;
        if (rows < n) {
            n = rows;
        }
        func_800B2040(spr, img, p, lineBytes, n);
        yl = (y + row * sy) * 4.0f;
        {
            s32 h = n;
            if (spr->flip && n == left) {
                h = n - 1;
            }
            yh = (y + (row + h) * sy) * 4.0f;
        }
        if (spr->flip) {
            if (n < left) {
                n--;
            } else {
                yh++;
            }
        }
        {
            Gfx800B1AC4 *_g = D_800F36A4++;
            u32 _w;
            _w = (_SHIFTL(0xE4, 24, 8) | _SHIFTL(MAX((s16)(xh), 0), 12, 12) | _SHIFTL(MAX((s16)(yh), 0), 0, 12));
            _g->w0 = _w;
            _w = (_SHIFTL(0, 24, 3) | _SHIFTL(MAX((s16)(xl), 0), 12, 12) | _SHIFTL(MAX((s16)(yl), 0), 0, 12));
            _g->w1 = _w;
        }
        {
            Gfx800B1AC4 *_g = D_800F36A4++;
            u32 _w;
            _g->w0 = 0xE1000000;
            _w = (_SHIFTL((0 - (((s16)(xl) < 0) ? (((s16)(dsdx) < 0) ? (MAX((((s16)(xl) * (s16)(dsdx)) >> 7), 0)) : (MIN((((s16)(xl) * (s16)(dsdx)) >> 7), 0))) : 0)), 16, 16) |
                      _SHIFTL((0 - (((yl) < 0) ? (((s16)(dtdy) < 0) ? (MAX((((s16)(yl) * (s16)(dtdy)) >> 7), 0)) : (MIN((((s16)(yl) * (s16)(dtdy)) >> 7), 0))) : 0)), 0, 16));
            _g->w1 = _w;
        }
        {
            Gfx800B1AC4 *_g = D_800F36A4++;
            _g->w0 = 0xF1000000;
            _g->w1 = (_SHIFTL((dsdx), 16, 16) | _SHIFTL((dtdy), 0, 16));
        }
        p += n * img->stride;
        left -= n;
        row += n;
    }
}
