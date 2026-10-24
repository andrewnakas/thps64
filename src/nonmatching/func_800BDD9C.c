/* cflags: -O2 */
/* NON_MATCHING: aln ratio 0.696; loop.c hoists the step lui; needs maybe_never before the set, best 50/67. Equivalent C; only register allocation / scheduling / loop-invariant placement differ. */
/* Z2 near-miss 50/67 (K14 draft, unchanged). Left: the game keeps `lui s4,0x10` (step, used after the loop) inside
 * the loop; loop.c moves a user var unless a label/jump precedes its set in the body (maybe_never) or it is used before
 * its set. An inner do { step = ...; } while (0) is a phony loop (no label kept): still hoisted. Also s0/s1/s2 order. */
#include "common.h"

s32 func_8009EAE0(void *, s32, s32);
void func_800BDD74(s32);
extern u8 D_800EA110[];
extern s32 D_800F3290;
extern s32 D_800F3294;
extern s32 D_800F3298;
extern s32 D_800F32A8;
extern s32 D_800FC890;
extern s32 D_800FC8A0[];

void func_800BDD9C(void) {
    s32 i;
    s32 size;
    s32 addr;
    s32 *fb;
    s32 p;
    s32 step;

    i = 0;
    addr = 0x804FFFC0;
    fb = D_800FC8A0;
    size = D_800F3294 * D_800F3298 * 2;
    do {
        *fb = func_8009EAE0(D_800EA110, addr - size, size + 0x40);
        func_800BDD74(*fb);
        fb++;
        i++;
        step = 0x100000;
        addr += step;
    } while (i < 3);
    D_800F32A8 = func_8009EAE0(D_800EA110, 0x807FFFC0 - size, size + 0x40);
    func_800BDD74(D_800F32A8);
    step = 0x100000;
    p = func_8009EAE0(D_800EA110, 0x80300000, step);
    func_800BDD74(p);
    D_800F3290 = p;
    D_800FC890 = p + step;
}
