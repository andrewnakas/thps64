/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx8BD8;

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
    u8 pad44[0x58 - 0x44];
    u32 img;
} Tex8BD8;

#define _SHIFTL(v, s, w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define gDPSetTextureImage(pkt, f, s, w, i) { Gfx8BD8 *_g = (Gfx8BD8 *)(pkt); \
    _g->w0 = _SHIFTL(0xFD, 24, 8) | _SHIFTL(f, 21, 3) | _SHIFTL(s, 19, 2) | _SHIFTL((w) - 1, 0, 12); \
    _g->w1 = (u32)(i); }
#define gDPLoadBlock(pkt, tile, uls, ult, lrs, dxt) { Gfx8BD8 *_g = (Gfx8BD8 *)(pkt); \
    _g->w0 = _SHIFTL(0xF3, 24, 8) | _SHIFTL(uls, 12, 12) | _SHIFTL(ult, 0, 12); \
    _g->w1 = _SHIFTL(tile, 24, 3) | _SHIFTL(((lrs) < 0x7FF ? (lrs) : 0x7FF), 12, 12) | _SHIFTL(dxt, 0, 12); }

s32 func_800B89C4(u16);

void func_800B8BD8(Tex8BD8 *t, s32 tmem, s32 arg2, Gfx8BD8 **pp) {
    Gfx8BD8 *g;
    u8 unused[16]; /* the game frame holds 16 bytes of unreferenced locals */
    s32 bpp;
    s32 masks;
    s32 maskt;
    s32 cms;
    s32 cmt;
    s32 n;
    s32 cnt;
    s32 fmt;
    s32 sz;

    g = *pp;
    bpp = 8;
    if (t->siz >= 9) {
        bpp = t->siz;
    }
    masks = func_800B89C4(t->w);
    maskt = func_800B89C4(t->h);
    cmt = t->cmt;
    cms = t->cms;
    n = t->w * bpp;
    if (t->siz == 4) {
        s32 pad;
        s32 q;

        n = t->w * t->siz;
        pad = 0;
        if (n & 0x3F) {
            pad = 0x40 - n % 0x40;
        }
        q = (n + pad) / 8;
        cnt = q / 2 * t->h;
    } else {
        s32 pad;

        pad = 0;
        if (n & 0x3F) {
            pad = (0x40 - n % 0x40) / bpp;
        }
        cnt = (t->w + pad) * t->h;
    }
    cnt = cnt - 1;
    if (cnt >= 0x800) {
        cnt = 0x7FF;
    }
    sz = 2;
    if (t->siz == 8 && tmem != 0) {
        sz = 1;
    }
    fmt = t->fmt;
    gDPSetTextureImage(g++, fmt, sz, 1, t->img);
    {
        Gfx8BD8 *_g = g++;
        u32 w;

        _g->w0 = _SHIFTL(0xF5, 24, 8) | _SHIFTL(fmt, 21, 3) | _SHIFTL(sz, 19, 2) | _SHIFTL(tmem >> 3, 0, 9);
        w = 0x07000000 | ((cmt & 3) << 18);
        _g->w1 = w | ((maskt & 0xF) << 14) | ((cms & 3) << 8) | ((masks & 0xF) << 4);
    }
    gDPLoadBlock(g++, 7, 0, 0, cnt, 0);
    *pp = g;
}
