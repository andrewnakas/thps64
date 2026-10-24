/* cflags: -O2 */
/* NON_MATCHING: sched: pool constant hoisted by sched2 + lh au before av copy; best 358/364. Equivalent C; only register allocation / scheduling / delay-slot choice differ. */
/* Z1: using the rodata word as a plain `extern f32 D_80022090` stops sched2 hoisting the constant (fixes the first
 * diff) but loads it via lui v1 instead of li.s's at, so it stays a literal; the lh au vs av-copy order (sched1 sees
 * sp+0x26 / sp+0x28 as disjoint) is unchanged. */
/* G15 near-miss 358/364 (regions.py, -O2). From K18's draft: moving m->unk60/unk74/unk80 stores after g[1] fixes the
 * color-combiner word (all 10 loads first, t0-t4 busy) and with it the movstr scratch regs (t5-t8). Left: 2 scheduling
 * diffs in the anim block - our sched2 hoists the li.s 0.001953125f into the load-delay slot after the first
 * lw 0x7C(s2), and sched1 puts au's lh/mul before the av copy (game: both RD copies, then lh au, l.s, mul). The
 * game behaves as if the constant load and lh au depended on the earlier stores; s16 uv[2] / a struct for the five
 * RD shorts give that order but move the stack slots or the zero/x1 store. */
/* NEARLY func_800BA1B8 (-O2, 187/364): block-move scratch regs t1-t4 vs target t5-t8; scheduling of combiner stores and K constant load. */
#include "common.h"

typedef struct {
    u8 b[2];
} B2_A1B8;

typedef struct {
    u8 b[4];
} B4_A1B8;

typedef struct {
    u8 b[16];
} B16_A1B8;

typedef struct {
    u8 b[32];
} B32_A1B8;

typedef struct {
    s32 unk0;
    s32 unk4;
    f32 unk8;
    f32 unkC;
    s32 unk10;
} Scroll_A1B8;

typedef struct {
    f32 x0;
    f32 x1;
    f32 x2;
    f32 x3;
    s32 x4;
} Sub_A1B8;

typedef struct {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s32 unk4;
    Sub_A1B8 sub;
} Anim_A1B8;

typedef struct {
    u8 pad0[0x64];
    u16 unk64;
} Tex_A1B8;

typedef struct {
    u8 pad0[4];
    Tex_A1B8 *unk4;
} TexEnt_A1B8;

typedef struct {
    u8 pad0[0x18];
    u8 unk18[0x20];
    u8 unk38[2];
    u8 unk3A[2];
    u8 unk3C;
    u8 unk3D;
    u8 unk3E;
    u8 unk3F;
    u8 unk40;
    u8 unk41;
    u8 unk42;
    u8 unk43;
    u8 unk44[4];
    u8 unk48[4];
    u8 unk4C;
    u8 pad4D;
    u8 unk4E;
    u8 unk4F;
    u8 pad50[4];
    void *unk54;
    void *unk58;
    u8 unk5C[4];
    s32 unk60;
    u16 unk64;
    u8 pad66[2];
    u32 unk68;
    u32 unk6C;
    u8 pad70[4];
    s32 unk74;
    Scroll_A1B8 *unk78;
    Anim_A1B8 *unk7C;
    Tex_A1B8 *unk80;
} Mat_A1B8;

void func_80005720(void *, u8 *, s32);
void *func_8009E6B4(void *, s32, s32);
void func_800B8E98(Mat_A1B8 *, s32);
void func_800B9460(Mat_A1B8 *, s32);
TexEnt_A1B8 *func_800BAB04(void *, u16);
void func_800BAC04(void *, u16);
extern u8 D_800EA110[];
extern u8 D_800EECF0[];

#define RD(dst, T)                    \
    {                                 \
        *(T *)&(dst) = *(T *)p;       \
        p += sizeof(T);               \
    }

void func_800BA1B8(Mat_A1B8 *m, u8 *p) {
    u8 cc[16];
    s16 tex;
    s16 su;
    s16 sv;
    s16 au;
    s16 av;
    s32 n;
    u8 k;
    Anim_A1B8 *an;
    Sub_A1B8 *sub;
    f32 zero;
    u32 *g;

    RD(m->unk18, B32_A1B8);
    RD(m->unk38, B2_A1B8);
    RD(m->unk3A, B2_A1B8);
    m->unk3C = *p++;
    m->unk3D = *p++;
    m->unk3E = *p++;
    m->unk3F = *p++;
    m->unk40 = *p++;
    m->unk41 = *p++;
    RD(m->unk64, B2_A1B8);
    m->unk42 = *p++;
    m->unk43 = *p++;
    m->unk4C = *p++;
    RD(m->unk5C, B4_A1B8);
    RD(m->unk44, B4_A1B8);
    RD(m->unk48, B4_A1B8);
    m->unk4E = *p++;
    m->unk4F = *p++;
    RD(tex, B2_A1B8);
    m->unk58 = func_8009E6B4(D_800EA110, m->unk64, 8);
    func_80005720(m->unk58, p, m->unk64);
    p += m->unk64;
    if (m->unk3E == 2) {
        n = m->unk40 * 2;
        if (m->unk41 != 0) {
            n *= m->unk41;
        }
        m->unk54 = func_8009E6B4(D_800EA110, n, 8);
        func_80005720(m->unk54, p, n);
        p += n;
    } else {
        m->unk54 = NULL;
    }
    RD(su, B2_A1B8);
    RD(sv, B2_A1B8);
    if (su != 0 || sv != 0) {
        m->unk78 = func_8009E6B4(D_800EA110, 0x14, 4);
        m->unk78->unk0 = 0;
        m->unk78->unk4 = 0;
        m->unk78->unk8 = su * 0.00390625f;
        m->unk78->unkC = sv * 0.00390625f;
        m->unk78->unk10 = 0;
    } else {
        m->unk78 = NULL;
    }
    k = *p++;
    if (k != 0) {
        an = func_8009E6B4(D_800EA110, 0x14, 4);
        m->unk7C = an;
        an->unk2 = k;
        m->unk7C->unk3 = 0;
        m->unk7C->unk4 = 0;
        m->unk7C->unk0 = *p++;
        m->unk7C->unk1 = *p++;
        RD(au, B2_A1B8);
        RD(av, B2_A1B8);
        sub = &an->sub;
        zero = 0.0f;
        sub->x1 = zero;
        sub->x2 = au * 0.001953125f;
        sub->x3 = av * 0.001953125f;
        sub->x0 = zero;
        sub->x4 = 0;
    } else {
        m->unk7C = NULL;
    }
    RD(cc, B16_A1B8);
    g = (u32 *)&m->unk68;
    g[0] = ((((cc[0] & 0xF) << 20) | ((cc[2] & 0x1F) << 15) | ((cc[4] & 7) << 12) | ((cc[6] & 7) << 9)) |
                (((cc[8] & 0xF) << 5) | (cc[10] & 0x1F))) |
               0xFC000000;
    g[1] = ((cc[1] << 28) | ((cc[3] & 7) << 15) | ((cc[5] & 7) << 12) | ((cc[7] & 7) << 9)) |
               (((cc[9] & 0xF) << 24) | ((cc[12] & 7) << 21) | ((cc[14] & 7) << 18) | ((cc[11] & 7) << 6) |
                ((cc[13] & 7) << 3) | (cc[15] & 7));
    m->unk60 = 0x2000;
    m->unk74 = 0;
    m->unk80 = NULL;
    if ((u16)tex != 0xFFFF && m->unk41 == 0 && m->unk3F != 0x14 && m->unk7C == NULL) {
        m->unk80 = func_800BAB04(D_800EECF0, tex)->unk4;
        if (m->unk80 != NULL && m->unk80->unk64 + m->unk64 > 0x1000) {
            func_800BAC04(D_800EECF0, tex);
            m->unk80 = NULL;
        }
    }
    if (m->unk41 != 0) {
        func_800B9460(m, 0);
    } else {
        func_800B8E98(m, 0);
    }
}
