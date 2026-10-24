/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 *hdr;
    s32 base;
} Rd_800385A4;

typedef struct {
    u16 a;
    u16 b;
} Pair_800385A4;

typedef struct {
    Pair_800385A4 *ents;
    s32 *cnt;
} Tab_800385A4;


typedef struct {
    u8 pad0[2];
    s16 idx;
    u16 *unk4;
    s32 *unk8;
    u8 padC[0x3C - 0xC];
    u8 unk3C;
} Ent_800385A4;

typedef struct {
    u8 pad0[4];
    s32 **unk4;
    u8 pad8[4];
    Ent_800385A4 **list;
    s32 n;
} Obj_800385A4;

s32 func_80039328(Rd_800385A4 *, s32);
void func_8003934C(Rd_800385A4 *, s32);

static inline s32 rd_at(Rd_800385A4 *r, s32 i) {
    return r->base + func_80039328(r, i);
}

static inline void rd_open(Rd_800385A4 *r, s32 x) {
    func_8003934C(r, x);
}

void func_800385A4(Obj_800385A4 *arg0) {
    Rd_800385A4 r0;
    Rd_800385A4 r1;
    Rd_800385A4 r2;
    Tab_800385A4 t;
    s32 u;
    Rd_800385A4 *pr0;
    Ent_800385A4 *e;
    s32 *fl;
    u16 *h;
    s32 acc;
    s32 mask;
    s32 i, j, k;
    s32 n;
    s32 b;
    s32 nk;
    s32 o;
    Pair_800385A4 *pu;

    i = 0;
    pr0 = &r0;
    pu = (Pair_800385A4 *)&u;
    while (1) {
        if (i >= arg0->n) break;
        e = arg0->list[i];
        fl = e->unk8;
        h = e->unk4;
        acc = 0;
        mask = -1;
        func_8003934C(pr0, (*arg0->unk4)[e->idx]);
        func_8003934C(&r1, r0.base + func_80039328(pr0, 1));
        n = *r1.hdr;
        e->unk3C = 0;
        j = 0;
        while (1) {
            if (j >= n) break;
            rd_open(&r2, rd_at(&r1, j));
            if (*(s32 *)(rd_at(&r2, 0) + 4) & 0x8000) {
                acc |= 0x80;
            } else {
                t.cnt = (s32 *)rd_at(&r2, 2);
                t.ents = (Pair_800385A4 *)(t.cnt + 1);
                nk = *t.cnt;
                k = 0;
                while (1) {
                    if (k >= nk) break;
                    o = k << 2;
                    u = ((Pair_800385A4 *)((u8 *)t.ents + o))->a;
                    b = ((Pair_800385A4 *)((u8 *)t.ents + o))->b;
                    if (b & 0x2000) {
                        e->unk3C |= 1;
                    }
                    if (b & 0x4000) {
                        e->unk3C |= 2;
                    }
                    ((u16 *)&u)[0] <<= 3;
                    if (!(b & 0x40)) {
                        b ^= 0x80;
                    }
                    ((Pair_800385A4 *)((u8 *)t.ents + o))->a = pu->b;
                    ((Pair_800385A4 *)((u8 *)t.ents + o))->b = b;
                    acc |= b;
                    mask &= u;
                    k++;
                }
            }
            j++;
        }
        if (mask & 1) {
            *fl |= 0x10;
        }
        if (!(acc & 0xC0)) {
            *fl |= 0x20;
        }
        if (acc & 0x1000) {
            *fl |= 0x40;
        }
        if (acc & 4) {
            *fl |= 4;
        }
        if (*fl & 0x10) {
            *h |= 0x20;
        }
        if (*fl & 0x20) {
            *h |= 0x1000;
        }
        i++;
    }
}
