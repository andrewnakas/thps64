/* cflags: -O2 -Wa,-no-m4100 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx9460;

typedef struct {
    u8 pad0[0x38];
    u16 w;
    u16 h;
    u8 pad3C[2];
    u8 fmt;
    u8 siz;
    u8 pad40[2];
    u8 cms;
    u8 cmt;
    u8 env[4];
    u8 prim[4];
    u8 pad4C[0x50 - 0x4C];
    void *dl;
    u32 pal;
    u32 img;
    u32 flags;
    u32 filter;
    u16 tlutCount;
    u8 pad66[2];
    u32 cmd0;
    u32 cmd1;
} Tex9460;

#define _SHIFTL(v, s, w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define gDPNoParam(pkt, c) { Gfx9460 *_g = (Gfx9460 *)(pkt); _g->w0 = _SHIFTL(c, 24, 8); _g->w1 = 0; }
#define gSPSetOtherMode(pkt, cmd, sft, len, data) { Gfx9460 *_g = (Gfx9460 *)(pkt); \
    _g->w0 = _SHIFTL(cmd, 24, 8) | _SHIFTL(32 - (sft) - (len), 8, 8) | _SHIFTL((len) - 1, 0, 8); \
    _g->w1 = (u32)(data); }

s32 func_800B89C4(u16);
u32 func_800B8E24(Tex9460 *);
void *func_8009E6B4(void *, s32, s32);
void func_80005720(void *, void *, s32);
extern u8 D_800EA110[];

void func_800B9460(Tex9460 *t, Gfx9460 **pp) {
    Gfx9460 buf[48];
    Gfx9460 *g;
    s32 masks;
    s32 maskt;
    s32 lod;
    s32 tmem;
    s32 siz;
    s32 tile;
    s32 tsiz;
    s32 sz;
    s32 fmt;
    s32 i;
    s32 w;
    s32 h;
    s32 n;
    u32 mode;

    if (pp != NULL) {
        g = *pp;
    } else {
        g = buf;
    }
    masks = func_800B89C4(t->w);
    maskt = func_800B89C4(t->h);
    lod = (masks < maskt ? masks : maskt) > 6 ? 6 : (masks < maskt ? masks : maskt);
    tmem = 0;
    siz = t->siz;
    tile = 1;
    tsiz = 2;
    switch (siz) {
        case 4:
            sz = 0;
            break;
        case 8:
            sz = 1;
            break;
        case 16:
            sz = 2;
            break;
    }
    fmt = t->fmt;
    gDPNoParam(g++, 0xE7);
    {
        Gfx9460 *_g = g++;

        _g->w0 = 0xD7000000 | _SHIFTL(lod - 1, 11, 3) | _SHIFTL(tile, 8, 3) | 2;
        _g->w1 = 0xFFFFFFFF;
    }
    gSPSetOtherMode(g++, 0xE3, 20, 2, 0x100000);
    gSPSetOtherMode(g++, 0xE3, 16, 1, 0x10000);
    gSPSetOtherMode(g++, 0xE3, 19, 1, 0x80000);
    gSPSetOtherMode(g++, 0xE3, 12, 2, t->filter);
    if (t->img != 0) {
        gDPNoParam(g++, 0xE6);
        gDPNoParam(g++, 0xE8);
        {
            Gfx9460 *_g = g++;

            _g->w0 = _SHIFTL(0xF5, 24, 8) | _SHIFTL(fmt, 21, 3) | _SHIFTL(tsiz, 19, 2);
            _g->w1 = 0x07000000;
        }
        {
            Gfx9460 *_g = g++;

            _g->w0 = _SHIFTL(0xFD, 24, 8) | _SHIFTL(t->fmt, 21, 3) | _SHIFTL(tsiz, 19, 2);
            _g->w1 = t->img;
        }
        {
            Gfx9460 *_g = g++;

            _g->w0 = 0xF3000000;
            _g->w1 = 0x07000000 | _SHIFTL(t->tlutCount < 0x7FF ? t->tlutCount : 0x7FF, 12, 12);
        }
    }
    if (t->fmt == 2) {
        gSPSetOtherMode(g++, 0xE3, 14, 2, 0x8000);
        {
            Gfx9460 *_g = g++;

            _g->w0 = 0xFD100000;
            _g->w1 = t->pal;
        }
        gDPNoParam(g++, 0xE8);
        {
            Gfx9460 *_g = g++;

            _g->w0 = 0xF5000100;
            _g->w1 = 0x07000000;
        }
        gDPNoParam(g++, 0xE6);
        {
            Gfx9460 *_g = g++;

            _g->w0 = 0xF0000000;
            _g->w1 = 0x07000000 | _SHIFTL((lod << 4) - 1, 14, 10);
        }
        gDPNoParam(g++, 0xE7);
    } else {
        gSPSetOtherMode(g++, 0xE3, 14, 2, 0);
    }
    w = t->w;
    h = t->h;
    i = 0;
    while (1) {
        s32 ss;
        s32 st;
        s32 lw;
        s32 lh;
        s32 bits;

        if (i >= lod) {
            break;
        }
        ss = 0;
        if (t->cms != 2) {
            ss = masks - i;
            if (ss < 0) {
                ss = 0;
            }
        }
        st = 0;
        if (t->cmt != 2) {
            st = maskt - i;
            if (st < 0) {
                st = 0;
            }
        }
        {
            Gfx9460 *_g = g++;

            _g->w0 = _SHIFTL(0xF5, 24, 8) | _SHIFTL(fmt, 21, 3) | _SHIFTL(sz, 19, 2) |
                     _SHIFTL((w * siz + 63) / 64, 9, 9) | _SHIFTL(tmem >> 3, 0, 9);
            _g->w1 = _SHIFTL(i + tile, 24, 3) | _SHIFTL(i, 20, 4) | _SHIFTL(t->cmt, 18, 2) | _SHIFTL(st, 14, 4) |
                     _SHIFTL(i, 10, 4) | _SHIFTL(t->cms, 8, 2) | _SHIFTL(ss, 4, 4) | _SHIFTL(i, 0, 4);
        }
        {
            Gfx9460 *_g = g++;

            _g->w0 = 0xF2000000;
            _g->w1 = _SHIFTL(i + tile, 24, 3) | _SHIFTL((w - 1) << 2, 12, 12) | _SHIFTL((h - 1) << 2, 0, 12);
        }
        bits = w * t->siz;
        lw = w;
        lh = h;
        if (bits & 0x3F) {
            lw = w + (0x40 - bits % 0x40) / t->siz;
        }
        tmem += lw * lh * t->siz / 8;
        w = (w + 1) >> 1;
        h = (h + 1) >> 1;
        i++;
    }
    g->w0 = t->cmd0;
    g->w1 = t->cmd1;
    g++;
    gSPSetOtherMode(g++, 0xE3, 17, 2, 0);
    if (t->flags & 4) {
        Gfx9460 *_g = g++;

        _g->w0 = 0xFB000000;
        _g->w1 = (t->env[0] << 24) | (t->env[1] << 16) | (t->env[2] << 8) | t->env[3];
    }
    if (t->flags & 8) {
        Gfx9460 *_g = g++;

        _g->w0 = 0xFA000000;
        _g->w1 = (t->prim[0] << 24) | (t->prim[1] << 16) | (t->prim[2] << 8) | t->prim[3];
    }
    mode = func_800B8E24(t);
    gSPSetOtherMode(g++, 0xE2, 3, 29, mode | 0xC8000000);
    if (pp != NULL) {
        *pp = g;
    } else {
        gDPNoParam(g++, 0xDF);
        n = (u8 *)g - (u8 *)buf;
        t->dl = func_8009E6B4(D_800EA110, n, 8);
        func_80005720(t->dl, buf, n);
    }
}
