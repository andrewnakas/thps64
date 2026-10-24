/* cflags: -O2 */
/* NON_MATCHING: aln ratio 0.840; flags v1/v0 + bltz slot, f0/f2 convert, e v1/a0, best 84/100. Equivalent C; only register allocation / scheduling / loop-invariant placement differ. */
/* Z2 near-miss 84/100 (K16 draft, unchanged). Left: flags pseudo v1 (game v0) with the 0x80000000 lui in the bltz
 * slot (ours fills it with the arg1 copy), the first int->float convert in f0 (game f2), the second convert before
 * the *f reload, and e in v1 (game a0). Tried `0x80000000 | flags` and a block-local flags copy: no change. */
#include "common.h"

typedef struct {
    u32 addr;
    u8 pad4[4];
    u8 isStatic;
    u8 done;
    u8 padA[2];
    u32 ptrC;
    u32 ptr10;
} Ent800AD9B8;

typedef struct {
    u8 pad0[0x10];
    s32 flags;
    u8 pad14[0x20 - 0x14];
    s32 count;
    u8 *keys;
    f32 *vals;
    Ent800AD9B8 **ents;
} Bank800AD9B8;

extern void func_8000CAD0(void);
extern void func_800ADEBC(void *, void *, s32);

void func_800AD9B8(Bank800AD9B8 *arg0, s32 arg1) {
    Bank800AD9B8 *b;
    s32 i;
    s32 v;
    u8 c;
    f32 *f;
    Ent800AD9B8 *e;

    b = arg0;
    if (b->flags < 0) {
        return;
    }
    b->flags |= 0x80000000;
    func_800ADEBC(&b->keys, arg0, 3);
    func_800ADEBC(b->ents, arg0, b->count);
    for (i = 0; i < b->count; i++) {
        f = &b->vals[i];
        c = *(u8 *)f;
        if (c & 0x80) {
            v = c - 0x100;
        } else {
            v = c;
        }
        *f = v;
        *f = *f / 100.0;
        c = b->keys[i] - 0x30;
        if (c & 0x80) {
            v = c - 0x100;
        } else {
            v = c;
        }
        *f = *f + (f32)v;
        e = b->ents[i];
        if (e->done == 0) {
            if ((e->addr & 0xFF000000) != 0xFF000000) {
                e->addr += arg1;
            }
            b->ents[i]->done = 1;
            e = b->ents[i];
            if (e->ptrC != 0) {
                e->ptrC += (u32)arg0;
            }
            e = b->ents[i];
            if (e->isStatic == 0) {
                e->ptr10 += (u32)arg0;
            }
        }
    }
    func_8000CAD0();
}
