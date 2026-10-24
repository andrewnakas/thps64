/* cflags: -O2 */
/* NON_MATCHING: aln 0.665. Equivalent C; -O2 scheduling and register allocation of the 7 cached Gfx pointers differ, as do the x0 spill to its arg home and the D_800F3298 load order. */
/* NEAR-MISS C5 (move cflags line to top when testing): ~64% paired. Fixed: the 0xFFF mask needs an explicit s32 sign-extension ((x << 16) >> 16) so fold does not narrow it to 0xFFC, plus the CL cond-expr macro for the scissor words. Remaining: -O2 scheduling/register allocation of the 7 Gfx pointers (game s0,t7,t6,s2,s3,s1), x0 spilled to its arg home, D_800F3298 load order. Permuter 15 min: no valid improvement. */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx800BE7D0;

typedef union {
    s32 w;
    struct {
        s16 hi;
        u16 lo;
    } h;
} Dim800BE7D0;

extern s32 D_800F3294;
extern Dim800BE7D0 D_800F3298;
extern s32 D_800F3698;
extern Gfx800BE7D0 *D_800F36A4;
extern s32 D_800F36B8;

#define GSET(a, b)                            \
    {                                         \
        Gfx800BE7D0 *_g = D_800F36A4++;       \
        _g->w0 = (a);                         \
        _g->w1 = (b);                         \
    }

#define S16(x) (((x) << 16) >> 16)
#define CL(v, sh) ((v) > 0 ? (((v) & 0xFFF) << (sh)) : 0)
#define FX(v) ((s32)((f32)(v) * 4.0f) & 0xFFF)

void func_800BE7D0(s32 x0, s32 x1, s32 y0, s32 y1, u8 r, u8 g, u8 b, u8 a) {
    GSET(0xE7000000, 0);
    GSET(0xED000000, (FX(D_800F3294 - 1) << 12) | FX(D_800F3298.w - 1));
    GSET(0xFF100000 | ((D_800F3294 - 1) & 0xFFF), D_800F36B8);
    GSET(0xE3000A01, 0);
    GSET(0xE200001C, 0x504340);
    GSET(0xFA000000, (r << 24) | (g << 16) | (b << 8) | a);
    GSET(0xFCFFFFFF, 0xFFFDF6FB);
    GSET((0xE4000000 | CL(S16(x1 << 2), 12)) | CL(S16((D_800F3298.h.lo - y0) << 2), 0),
         (0x01000000 | CL(S16(x0 << 2), 12)) | CL(S16((D_800F3298.h.lo - y1) << 2), 0));
    GSET(0xE1000000, 0);
    GSET(0xF1000000, 0);
    GSET(0xE7000000, 0);
    GSET(0xE3000A01, 0x100000);
    GSET(0xED000000 | (FX(D_800F3698) << 12) | FX(D_800F3698),
         (FX(D_800F3294 - (D_800F3698 + 1)) << 12) | FX(D_800F3298.w - (D_800F3698 + 1)));
}
