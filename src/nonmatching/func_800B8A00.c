/* cflags: -O2 */
/* NON_MATCHING: aln 0.857. Equivalent C; only s3/s4 (tex vs siz) are swapped by a global-alloc priority tie. */
/* D8 NEAR-MISS func_800B8A00 102/118 (regions.py): frame fixed with the 16-byte unreferenced local used by matched sibling func_800B8BD8, shifts masked into new locals ss/st after the two calls, w0 terms in game order (fmt before siz). Only left: s3/s4 swap of tex vs siz. global-alloc priority tie: siz 4 refs/42 insns (uninitialised default path makes it live from entry) = 0.190 vs tex 10 refs/164 = 0.183; the game needs tex first. Moving the siz term later in w0 flips it (o1, 111/118) but changes the or order. Permuter (10 min) only found noise adding 2 tex refs. */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx800B8A00;

typedef struct {
    u8 pad0[0x38];
    u16 width;
    u16 height;
    u8 pad3C[2];
    u8 fmt;
    u8 bits;
    u8 pad40[2];
    u8 cms;
    u8 cmt;
} Tex800B8A00;

extern s32 func_800B89C4(u16);

void func_800B8A00(Tex800B8A00 *tex, s32 tmem, s32 tile, s32 shiftS, s32 shiftT, s32 arg5, s32 arg6,
                   Gfx800B8A00 **gp) {
    Gfx800B8A00 *g;
    u8 unused[16]; /* the game frame holds 16 bytes of unreferenced locals (as in func_800B8BD8) */
    s32 maskS;
    s32 maskT;
    s32 line;
    s32 siz;
    s32 tm;
    s32 ss;
    s32 st;

    g = *gp;
    tm = tmem >> 3;
    maskS = func_800B89C4(tex->width);
    maskT = func_800B89C4(tex->height);
    ss = shiftS & 0xF;
    st = shiftT & 0xF;
    line = (tex->width * tex->bits + 63) / 64;
    switch (tex->bits) {
        case 4:
            siz = 0;
            break;
        case 8:
            siz = 1;
            break;
        case 16:
            siz = 2;
            break;
    }
    {
        Gfx800B8A00 *_g = g++;
        _g->w0 = 0xF5000000 | ((tex->fmt & 7) << 21) | ((siz & 3) << 19) | ((line & 0x1FF) << 9) |
                 (tm & 0x1FF);
        _g->w1 = ((tile & 7) << 24) | ((tex->cmt & 3) << 18) | ((maskT & 0xF) << 14) | (st << 10) |
                 ((tex->cms & 3) << 8) | ((maskS & 0xF) << 4) | ss;
    }
    {
        Gfx800B8A00 *_g = g++;
        _g->w0 = 0xF2000000;
        _g->w1 = ((tile & 7) << 24) | ((((tex->width - 1) << 2) & 0xFFF) << 12) |
                 (((tex->height - 1) << 2) & 0xFFF);
    }
    *gp = g;
}
