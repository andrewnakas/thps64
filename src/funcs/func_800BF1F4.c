/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} GfxF1F4;

extern GfxF1F4 *D_800F36A4;
extern s32 D_800F3294;
extern s32 D_800F3298;
extern s32 D_800F3698;

#define _SHIFTL(v, s, w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define GPACK_RGBA5551(r, g, b, a) ((((r) << 8) & 0xF800) | (((g) << 3) & 0x7C0) | (((b) >> 2) & 0x3E) | ((a) & 0x1))
#define gDPNoParam(pkt, cmd) { GfxF1F4 *_g = (GfxF1F4 *)(pkt); _g->w0 = _SHIFTL(cmd, 24, 8); _g->w1 = 0; }
#define gDPSetOtherMode2(pkt, w0v, w1v) { GfxF1F4 *_g = (GfxF1F4 *)(pkt); _g->w0 = (w0v); _g->w1 = (w1v); }
#define gDPSetFillColor(pkt, d) { GfxF1F4 *_g = (GfxF1F4 *)(pkt); _g->w0 = _SHIFTL(0xF7, 24, 8); _g->w1 = (u32)(d); }
#define gDPSetScissor(pkt, mode, ulx, uly, lrx, lry) { GfxF1F4 *_g = (GfxF1F4 *)(pkt); \
    _g->w0 = _SHIFTL(0xED, 24, 8) | _SHIFTL((int)((float)(ulx) * 4.0F), 12, 12) | _SHIFTL((int)((float)(uly) * 4.0F), 0, 12); \
    _g->w1 = _SHIFTL(mode, 24, 2) | _SHIFTL((int)((float)(lrx) * 4.0F), 12, 12) | _SHIFTL((int)((float)(lry) * 4.0F), 0, 12); }
#define gDPFillRectangle(pkt, ulx, uly, lrx, lry) { GfxF1F4 *_g = (GfxF1F4 *)(pkt); \
    _g->w0 = (_SHIFTL(0xF6, 24, 8) | _SHIFTL((lrx), 14, 10) | _SHIFTL((lry), 2, 10)); \
    _g->w1 = (_SHIFTL((ulx), 14, 10) | _SHIFTL((uly), 2, 10)); }

void func_800BF1F4(u8 r, u8 g, u8 b) {


    gDPNoParam(D_800F36A4++, 0xE7);
    gDPSetOtherMode2(D_800F36A4++, 0xE3000A01, 0x300000);
    gDPSetOtherMode2(D_800F36A4++, 0xE200001C, 0x0F0A4000);
    gDPSetFillColor(D_800F36A4++, (GPACK_RGBA5551(r, g, b, 1) << 16) | GPACK_RGBA5551(r, g, b, 1));
    gDPSetScissor(D_800F36A4++, 0, 0, 0, D_800F3294 - 1, D_800F3298 - 1);
    if (r != 0 || g != 0 || b != 0) {
        s32 t;
        gDPFillRectangle(D_800F36A4++, D_800F3698, D_800F3698, D_800F3294 - (t = D_800F3698 + 2), D_800F3298 - t);
    } else {
        s32 t;
        gDPFillRectangle(D_800F36A4++, 0, D_800F3698, D_800F3294 - 1, D_800F3298 - (t = D_800F3698 + 1));
    }
    gDPNoParam(D_800F36A4++, 0xE7);
    gDPSetOtherMode2(D_800F36A4++, 0xE3000A01, 0x100000);
    {
        s32 t;
        gDPSetScissor(D_800F36A4++, 0, D_800F3698, D_800F3698, D_800F3294 - (t = D_800F3698 + 1), D_800F3298 - t);
    }
}
