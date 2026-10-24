/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} GfxEB0C;

extern GfxEB0C *D_800F36A4;
extern s32 D_800F3294;
extern s32 D_800F3298;
extern s32 D_800F3698;
extern s32 D_800F36B8;

#define _SHIFTL(v, s, w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define GPACK_RGBA5551(r, g, b, a) ((((r) << 8) & 0xF800) | (((g) << 3) & 0x7C0) | (((b) >> 2) & 0x3E) | ((a) & 0x1))
#define gDPNoParam(pkt, cmd) { GfxEB0C *_g = (GfxEB0C *)(pkt); _g->w0 = _SHIFTL(cmd, 24, 8); _g->w1 = 0; }
#define gDPSetOtherMode2(pkt, w0v, w1v) { GfxEB0C *_g = (GfxEB0C *)(pkt); _g->w0 = (w0v); _g->w1 = (w1v); }
#define gDPSetColorImage(pkt, f, s, w, i) { GfxEB0C *_g = (GfxEB0C *)(pkt); \
    _g->w0 = _SHIFTL(0xFF, 24, 8) | _SHIFTL(f, 21, 3) | _SHIFTL(s, 19, 2) | _SHIFTL((w) - 1, 0, 12); _g->w1 = (u32)(i); }
#define gDPSetFillColor(pkt, d) { GfxEB0C *_g = (GfxEB0C *)(pkt); _g->w0 = _SHIFTL(0xF7, 24, 8); _g->w1 = (u32)(d); }
#define gDPSetScissor(pkt, mode, ulx, uly, lrx, lry) { GfxEB0C *_g = (GfxEB0C *)(pkt); \
    _g->w0 = _SHIFTL(0xED, 24, 8) | _SHIFTL((int)((float)(ulx) * 4.0F), 12, 12) | _SHIFTL((int)((float)(uly) * 4.0F), 0, 12); \
    _g->w1 = _SHIFTL(mode, 24, 2) | _SHIFTL((int)((float)(lrx) * 4.0F), 12, 12) | _SHIFTL((int)((float)(lry) * 4.0F), 0, 12); }
#define gDPFillRectangle(pkt, ulx, uly, lrx, lry) { GfxEB0C *_g = (GfxEB0C *)(pkt); \
    _g->w0 = (_SHIFTL(0xF6, 24, 8) | _SHIFTL((lrx), 14, 10) | _SHIFTL((lry), 2, 10)); \
    _g->w1 = (_SHIFTL((ulx), 14, 10) | _SHIFTL((uly), 2, 10)); }

void func_800BEB0C(s32 x0, s32 x1, s32 y0, s32 y1, u8 r, u8 g, u8 b) {
    gDPNoParam(D_800F36A4++, 0xE7);
    gDPSetColorImage(D_800F36A4++, 0, 2, D_800F3294, D_800F36B8);
    if (r != 0 || g != 0 || b != 0) {
        s32 left;
        s32 right;
        s32 ty;
        s32 by;

        gDPSetOtherMode2(D_800F36A4++, 0xE3000A01, 0x300000);
        gDPSetOtherMode2(D_800F36A4++, 0xE200001C, 0x0F0A4000);
        gDPSetFillColor(D_800F36A4++, (GPACK_RGBA5551(r, g, b, 1) << 16) | GPACK_RGBA5551(r, g, b, 1));
        if (x0 >= D_800F3698) {
            if (x0 <= D_800F3294 - D_800F3698) {
                left = x0;
            } else {
                left = D_800F3294 - D_800F3698;
            }
        } else {
            left = D_800F3698;
        }
        if (x1 >= D_800F3698) {
            if (x1 <= D_800F3294 - D_800F3698) {
                right = x1;
            } else {
                right = D_800F3294 - D_800F3698;
            }
        } else {
            right = D_800F3698;
        }
        ty = D_800F3298 - y1;
        by = D_800F3298 - y0;
        {
            s32 c;
            if (ty >= D_800F3698) {
                if (ty <= D_800F3298 - D_800F3698) {
                    c = ty;
                } else {
                    c = D_800F3298 - D_800F3698;
                }
            } else {
                c = D_800F3698;
            }
            ty = c;
        }
        {
            s32 c;
            if (by >= D_800F3698) {
                if (by <= D_800F3298 - D_800F3698) {
                    c = by;
                } else {
                    c = D_800F3298 - D_800F3698;
                }
            } else {
                c = D_800F3698;
            }
            by = c;
        }
        gDPFillRectangle(D_800F36A4++, left, ty, right, by);
        gDPNoParam(D_800F36A4++, 0xE7);
        gDPSetOtherMode2(D_800F36A4++, 0xE3000A01, 0x100000);
    } else {
        s32 t;

        gDPSetScissor(D_800F36A4++, 0, 0, 0, D_800F3294 - 1, D_800F3298 - 1);
        gDPSetOtherMode2(D_800F36A4++, 0xE3000A01, 0x300000);
        gDPSetOtherMode2(D_800F36A4++, 0xE200001C, 0x0F0A4000);
        gDPSetFillColor(D_800F36A4++, 0x10001);
        gDPFillRectangle(D_800F36A4++, x0, D_800F3298 - y1, x1, D_800F3298 - y0);
        gDPNoParam(D_800F36A4++, 0xE7);
        gDPSetOtherMode2(D_800F36A4++, 0xE3000A01, 0x100000);
        gDPSetScissor(D_800F36A4++, 0, D_800F3698, D_800F3698, D_800F3294 - (t = D_800F3698 + 1), D_800F3298 - t);
    }
}
