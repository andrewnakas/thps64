/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx800BF6AC;

extern s32 D_800F3298;
extern Gfx800BF6AC *D_800F36A4;

#define GSET(a, b)                            \
    {                                         \
        Gfx800BF6AC *_g = D_800F36A4++;       \
        _g->w0 = (a);                         \
        _g->w1 = (b);                         \
    }

#define SHL(v, s, w) (((u32)(v) & ((1 << (w)) - 1)) << (s))
#define MAX0(a) ((a) > 0 ? (a) : 0)

#define SCISRECT(xl, yl, xh, yh)                                                                   \
    {                                                                                              \
        Gfx800BF6AC *_g = D_800F36A4++;                                                            \
        u32 _w0;                                                                                   \
        u32 _w1;                                                                                   \
        _w0 = SHL(0xE4, 24, 8) | SHL(MAX0((s16)(xh)), 12, 12) | SHL(MAX0((s16)(yh)), 0, 12);       \
        _g->w0 = _w0;                                                                              \
        _w1 = SHL(1, 24, 3) | SHL(MAX0((s16)(xl)), 12, 12) | SHL(MAX0((s16)(yl)), 0, 12);          \
        _g->w1 = _w1;                                                                              \
    }                                                                                              \
    GSET(0xE1000000, 0)                                                                            \
    GSET(0xF1000000, 0)

void func_800BF6AC(s32 x0, s32 x1, s32 y0, s32 y1, u8 r, u8 g, u8 b, u8 a, s32 flag) {
    s32 l;
    s32 rt;
    s32 t;
    s32 bt;

    GSET(0xE7000000, 0);
    GSET(0xE3000A01, 0);
    if (flag) {
        GSET(0xE200001C, 0x504240);
    } else {
        GSET(0xE200001C, 0x504340);
    }
    GSET(0xFCFFFFFF, 0xFFFDF6FB);
    GSET(0xFA000000, SHL(r, 24, 8) | SHL(g, 16, 8) | SHL(b, 8, 8) | SHL(a, 0, 8));
    l = x0 << 2;
    bt = (D_800F3298 - y1) << 2;
    rt = x1 << 2;
    t = (D_800F3298 - y0) << 2;
    SCISRECT(l, bt, rt, t);
    if (!flag) {
        GSET(0xE7000000, 0);
        GSET(0xE200001C, 0x504240);
    }
    GSET(0xFA000000, 0);
    SCISRECT(l - 4, bt - 4, rt + 4, bt + 4);
    SCISRECT(l - 4, t - 4, rt + 4, t + 4);
    SCISRECT(l - 4, bt - 4, l + 4, t + 4);
    SCISRECT(rt - 4, bt - 4, rt + 4, t + 4);
    GSET(0xE7000000, 0);
    GSET(0xE3000A01, 0x100000);
}
