/* cflags: */
/* NON_MATCHING: aln ratio 0.787; loop.c hoists the temp 2 of b==2: non-user temps are always movable, game kept it in the loop, best 82/103 clean / 95 with xori. Equivalent C; only register allocation / scheduling / loop-invariant placement differ. */
/* Z2 near-miss 82/103 (X2 draft). Left: loop.c hoists the constant 2 of `b == 2` into an extra s-register; the game
 * keeps `li v0,2` inside the loop. scan_loop/move_movables: the temp is non-user so it is always movable, and with a
 * call in the loop threshold (1+n_non_fixed_regs, -3 per earlier move) far exceeds the 39-insn loop, so it only stays
 * if the reg is a user variable set after a jump/label in the body (maybe_never) and used in another block.
 * `(b ^ 2) == 0` stops the hoist (95/103, B3b) but emits xori. Also the preheader lui order differs. */
#include "common.h"

typedef struct {
    u8 b0;
    u8 b1;
    u16 h2;
    s16 h4;
    s16 h6;
} Ent8;

typedef struct {
    s16 a;
    s16 b;
} Ent4;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s16 **unkC;
} Tbl;

extern s32 D_800DE9A8;
extern s32 D_800D36D4;
extern s32 D_800D3C2C[];
extern Ent8 D_800D3C94[];
extern Ent4 D_800D3D7C[];
extern Tbl D_800FA350;
u16 *func_800352A4(s32);
void func_800B65A8(s32, s32, s32, s32);
void func_800B6494(s32, s32);

void func_80033BD4(void) {
    s32 i;
    s32 n;
    Ent8 *e;
    Ent4 *f;
    Tbl *t;

    if (D_800DE9A8 == 2 && D_800D36D4 == 20) {
        s32 *q = D_800D3C2C;
        while (1) {
            s32 a = *q;
            u16 *r;
            if (a == 0) {
                break;
            }
            q++;
            r = func_800352A4(a);
            if (r != NULL) {
                *r |= 0x41;
            }
        }
    }
    n = 0x1D;
    i = 0;
    e = D_800D3C94;
    t = &D_800FA350;
    while (1) {
        if (!(i < n)) {
            break;
        }
        if (e->b0 == D_800D36D4) {
            s32 a3 = e->h2;
            s16 *v = t->unkC[a3];
            s32 b = e->b1;
            if (b == 2) {
                u16 *w = *(u16 **)(v + 2);
                *w &= ~(u16)e->h6;
            } else {
                if (b == 0) {
                    a3 = v[1];
                }
                func_800B65A8(t->unk4, e->h4, e->h6, a3);
            }
        }
        e++;
        i++;
    }
    n = 8;
    i = 0;
    f = D_800D3D7C;
    t = &D_800FA350;
    while (1) {
        if (!(i < n)) {
            break;
        }
        if (f->a == D_800D36D4) {
            func_800B6494(t->unk4, t->unkC[f->b][1]);
        }
        f++;
        i++;
    }
}
