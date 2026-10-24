/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx800B233C;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} Arg800B233C;

extern s32 D_800F3294;
extern s32 D_800F3298;
extern Gfx800B233C *D_800F36A4;

#define GSET(a, b)                            \
    {                                         \
        Gfx800B233C *_g = D_800F36A4++;       \
        _g->w0 = (a);                         \
        _g->w1 = (b);                         \
    }

#define FX(v) ((s32)((f32)(v) * 4.0f) & 0xFFF)

void func_800B233C(Arg800B233C *arg0) {
    GSET(0xE7000000, 0);
    GSET(0xE3000A01, 0);
    GSET(0xE3000C00, 0);
    if (arg0->unk8 != 0 && arg0->a != 0xFF) {
        GSET(0xE200001C, 0x504240);
    } else {
        GSET(0xE200001C, 0x0F0A7008);
    }
    GSET(0xED000000, (FX(D_800F3294 - 1) << 12) | FX(D_800F3298 - 1));
    if (arg0->unk8 != 0) {
        GSET(0xFC129A25, 0xFF37FFFF);
        GSET(0xFB000000, (arg0->r << 24) | (arg0->g << 16) | (arg0->b << 8) | arg0->a);
    } else {
        GSET(0xFCFFFFFF, 0xFFFCF279);
    }
    if (arg0->unk4 != 0) {
        GSET(0xE3001201, 0x2000);
    } else {
        GSET(0xE3001201, 0);
    }
}
