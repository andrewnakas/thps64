/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} GfxA483C;

typedef struct {
    s16 x, y, z;
    s16 pad6;
    s16 s, t;
    u8 r, g, b, a;
} VtxA483C;

typedef struct {
    f32 x, y, z;
} Pt;

typedef struct {
    u8 pad0[0x2A8];
    s32 n;
    Pt pts[(0x6D8 - 0x2AC) / 0xC];
    VtxA483C *vtx;
} Shadow;

VtxA483C *func_8009E6B4(void *, s32, s32);
void func_800C0070(void);
extern u8 D_800EA110[];
extern GfxA483C *D_800F36A4;

void func_800A483C(Shadow *o) {
    s32 i;
    s32 j;
    GfxA483C *g;
    GfxA483C *h;

    if (o->vtx == NULL) {
        o->vtx = func_8009E6B4(D_800EA110, 0x50, 0x10);
    }
    {
        GfxA483C *_g = D_800F36A4++;
        _g->w0 = 0xE7000000;
        _g->w1 = 0;
    }
    {
        GfxA483C *_g = D_800F36A4++;
        _g->w0 = 0xD7000000;
        _g->w1 = 0xFFFFFFFF;
    }
    {
        GfxA483C *_g = D_800F36A4++;
        _g->w0 = 0xFCFFFFFF;
        _g->w1 = 0xFFFE7838;
    }
    {
        GfxA483C *_g = D_800F36A4++;
        _g->w0 = 0xE200001C;
        _g->w1 = 0x0C1841C8;
    }
    {
        GfxA483C *_g = D_800F36A4++;
        _g->w0 = 0xD9FCFFFE;
        _g->w1 = 0;
    }
    for (i = 0; i < o->n; i++) {
        o->vtx[i].x = o->pts[i].x;
        o->vtx[i].y = 0;
        o->vtx[i].z = o->pts[i].z;
        o->vtx[i].r = 0xFF;
        o->vtx[i].g = 0xFF;
        o->vtx[i].b = 0xFF;
        o->vtx[i].a = 0x40;
    }
    func_800C0070();
    {
        GfxA483C *_g = D_800F36A4++;
        _g->w0 = 0x01000000 | ((o->n & 0xFF) << 12) | ((o->n & 0x7F) << 1);
        _g->w1 = (u32)o->vtx;
    }
    j = 0;
    while (1) {
        if (j >= o->n - 2) break;
        {
            GfxA483C *_g = D_800F36A4++;
            _g->w0 = ((((j + 1) * 2 & 0xFF) << 8) | ((j + 2) * 2 & 0xFF)) | 0x05000000;
            _g->w1 = 0;
        }
        j++;
    }
}
