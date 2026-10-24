/* cflags: -O2 */
#include "common.h"
#include "gfx_helpers.h"

extern s32 D_800F3294;
extern s32 D_800F3298;
extern s32 D_800F3698;

#define _SHIFTL(v, s, w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))

/* gDPFillRectangle (G_FILLRECT = 0xF6) */
#define DPFILLRECT(pkt, ulx, uly, lrx, lry)                                                              \
    {                                                                                                    \
        Gfx *_g = (Gfx *)(pkt);                                                                          \
        _g->w0 = (_SHIFTL(0xF6, 24, 8) | _SHIFTL((lrx), 14, 10) | _SHIFTL((lry), 2, 10));                \
        _g->w1 = (_SHIFTL((ulx), 14, 10) | _SHIFTL((uly), 2, 10));                                       \
    }

#define DPSCISSOR(ulx, uly, lrx, lry)                                                                    \
    {                                                                                                    \
        Gfx *_g = D_800F36A4++;                                                                          \
        _g->w0 = _SHIFTL(0xED, 24, 8) | _SHIFTL((int)((float)(ulx) * 4.0F), 12, 12) |                   \
                 _SHIFTL((int)((float)(uly) * 4.0F), 0, 12);                                             \
        _g->w1 = _SHIFTL(0, 24, 2) | _SHIFTL((int)((float)(lrx) * 4.0F), 12, 12) |                       \
                 _SHIFTL((int)((float)(lry) * 4.0F), 0, 12);                                             \
    }

void func_800BF4AC(void) {
    s32 b;

    GFX_PUSH(0xE7000000, 0);
    GFX_PUSH(0xE3000A01, 0x300000);
    GFX_PUSH(0xE200001C, 0x0F0A4000);
    DPSCISSOR(0, 0, D_800F3294 - 1, D_800F3298 - 1);
    GFX_PUSH(0xF7000000, 0x10001);
    DPFILLRECT(D_800F36A4++, 0, 0, D_800F3294, D_800F3698);
    b = D_800F3698 + 1;
    DPFILLRECT(D_800F36A4++, 0, D_800F3298 - b, D_800F3294, D_800F3298);
    GFX_PUSH(0xE7000000, 0);
    GFX_PUSH(0xE3000A01, 0x100000);
    DPSCISSOR(D_800F3698, D_800F3698, D_800F3294 - b, D_800F3298 - b);
}
