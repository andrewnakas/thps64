/* cflags: -O2 */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx800BFDD4;

extern s32 D_800F3294;
extern s32 D_800F3298;
extern s32 D_800F32A8;
extern s32 D_800F3698;
extern Gfx800BFDD4 *D_800F36A4;
extern s32 D_800F36B8;

#define GSET(a, b)                            \
    {                                         \
        Gfx800BFDD4 *_g = D_800F36A4++;       \
        _g->w0 = (a);                         \
        _g->w1 = (b);                         \
    }

#define FX(v) ((s32)((f32)(v) * 4.0f) & 0xFFF)

void func_800BFDD4(void) {
    s32 d;

    d = D_800F3698;
    GSET(0xED000000 | (FX(0) << 12) | FX(0), (FX(D_800F3294) << 12) | FX(D_800F3298));
    GSET(0xE7000000, 0);
    GSET(0xE200001C, 0x0F0A4000);
    GSET(0xE7000000, 0);
    GSET(0xE3000A01, 0x300000);
    GSET(0xE7000000, 0);
    GSET(0xF7000000, 0xFFFCFFFC);
    GSET(0xE7000000, 0);
    GSET(0xFF100000 | ((D_800F3294 - 1) & 0xFFF), D_800F32A8);
    GSET(0xE7000000, 0);
    GSET(0xF6000000 | (((D_800F3294 - d - 1) & 0x3FF) << 14) | (((D_800F3298 - d - 1) & 0x3FF) << 2),
         ((d & 0x3FF) << 14) | ((d & 0x3FF) << 2));
    GSET(0xE7000000, 0);
    GSET(0xFF100000 | ((D_800F3294 - 1) & 0xFFF), D_800F36B8);
    GSET(0xE7000000, 0);
    GSET(0xE3000A01, 0x100000);
    GSET(0xE7000000, 0);
}
