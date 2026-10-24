/* cflags: -O2 */
/* NON_MATCHING: aln ratio 0.904; combine_givs: cand=v giv absorbs the DEST_ADDR givs; game bases on v+0x48; C++ accessors worse, best 47/52. Equivalent C; only register allocation / scheduling / loop-invariant placement differ. */
/* Z2 near-miss 47/52 (P3 draft). Left: loop.c giv choice: the game reduces one giv at v+0x48 (&v->sub) and
 * addresses unk4 as -0x44 off it; ours reduces v+0. combine_givs takes givs in bl->giv order (last insn first) and
 * `cand = v` (DEST_REG, last in the body) absorbs all DEST_ADDR givs in its pass 1. Needs a v+0x48 giv after cand
 * or cand not being a giv (set twice in the loop: jump moves the exit-path `cand = v` out of the loop). C++ inline
 * accessors on Sub (this = &v->sub) change the loop shape (35/52). */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 pad8[0x40];
    struct Sub800ADF98 {
        s32 unk0;
        u8 pad4[0x2C];
        s32 unk30;
        u8 pad34[0xB4];
    } sub;
} Voice800ADF98;

typedef struct {
    s32 a;
    s32 b;
} Pair800ADF98;

typedef struct {
    u8 pad0[0x18];
    Pair800ADF98 pairs[16];
} Chan800ADF98;

s32 func_800ADEEC(Voice800ADF98 *, u8 *, s32, s32, s32, s32);
extern s32 D_800FC2F0;
extern Voice800ADF98 *D_800FC2FC;

s32 func_800ADF98(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 prio) {
    s32 i;
    s32 best;
    Voice800ADF98 *v;
    Voice800ADF98 *cand;
    struct Sub800ADF98 *sp;

    if (prio == -1) {
        prio = ((Chan800ADF98 *)arg0)->pairs[arg1].b;
    }
    v = D_800FC2FC;
    best = prio + 1;
    for (i = 4; i < D_800FC2F0; i++, v++) {
        if (v->unk4 == 0) {
            return func_800ADEEC(v, arg0, arg1, arg2, arg3, prio);
        }
        sp = &v->sub;
        if (sp->unk30 != 0 && sp->unk0 < best) {
            best = sp->unk0;
            cand = v;
        }
    }
    if (best < prio) {
        return func_800ADEEC(cand, arg0, arg1, arg2, arg3, prio);
    }
    return 0;
}
