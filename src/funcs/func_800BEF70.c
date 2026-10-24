/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx800BEF70;

extern s32 D_800F3294;
extern s32 D_800F3298;
extern s32 D_800F3698;
extern Gfx800BEF70 *D_800F36A4;

#define SHIFTL(v, s, w) ((u32)(((u32)(v) & ((0x01 << (w)) - 1)) << (s)))
#define GSET(a, b)                            \
    {                                         \
        Gfx800BEF70 *_g = D_800F36A4++;       \
        _g->w0 = (a);                         \
        _g->w1 = (b);                         \
    }
#define SCISSOR(ulx, uly, lrx, lry)                                                                   \
    GSET(SHIFTL(0xED, 24, 8) | SHIFTL((int)((float)(ulx) * 4.0F), 12, 12) |                         \
             SHIFTL((int)((float)(uly) * 4.0F), 0, 12),                                               \
         SHIFTL(0, 24, 2) | SHIFTL((int)((float)(lrx) * 4.0F), 12, 12) |                             \
             SHIFTL((int)((float)(lry) * 4.0F), 0, 12))
#define FILLRECT(ulx, uly, lrx, lry)                                                                  \
    GSET(SHIFTL(0xF6, 24, 8) | SHIFTL((lrx), 14, 10) | SHIFTL((lry), 2, 10),                         \
         SHIFTL((ulx), 14, 10) | SHIFTL((uly), 2, 10))
static inline void fillrect(u32 cmd, s32 ulx, s32 uly, s32 lrx, s32 lry) {
    Gfx800BEF70 *_g = D_800F36A4++;
    _g->w0 = SHIFTL(lrx, 14, 10) | (SHIFTL(lry, 2, 10) | SHIFTL(cmd, 24, 8));
    _g->w1 = SHIFTL(ulx, 14, 10) | SHIFTL(uly, 2, 10);
}
#define PACK(r, g, b, a) ((((r) << 8) & 0xF800) | (((g) << 3) & 0x7C0) | (((b) >> 2) & 0x3E) | ((a) & 1))

void func_800BEF70(u32 r, u32 g, u32 b) {
    s32 m;
    f32 edge;

    GSET(0xE7000000, 0);
    GSET(0xE3000A01, 0x300000);
    GSET(0xE200001C, 0x0F0A4000);
    GSET(0xF7000000, (PACK(r, g, b, 1) << 16) | PACK(r, g, b, 1));
    SCISSOR(0, 0, D_800F3294 - 1, D_800F3298 - 1);
    fillrect(0xF6, 0, 0, D_800F3294, D_800F3298);
    GSET(0xE7000000, 0);
    GSET(0xF7000000, 0x10001);
    edge = D_800F3698;
    fillrect(0xF6, 0, 0, D_800F3294, D_800F3698);
    fillrect(0xF6, 0, D_800F3298 - D_800F3698, D_800F3294, D_800F3298);
    GSET(0xE7000000, 0);
    GSET(0xE3000A01, 0x100000);
    m = D_800F3698 + 1;
    SCISSOR(edge, edge, D_800F3294 - m, D_800F3298 - m);
}
