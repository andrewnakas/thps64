/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* NON_MATCHING: aln 0.959. Equivalent C; only the script loop differs: the game has a dead `lw v0,0x2A8(s3)` before `li s0,0x4100` and an extra `andi a1,v1,0xFFFF` on the loaded u16. */
/* Z3: best draft 206/209 (C4's, -O2 nosched; the K17 draft listed in ENDGAME is 119/209). Only the script loop
   differs: the game has a dead `lw v0,0x2A8(s3)` before `li s0,0x4100` and compares `andi a1,v1,0xFFFF` (combine did
   not know the loaded u16 is zero-extended). Tried (Z3): u16 *s local, s32 c with (u16)c, c reused for the wait
   counter (c--), volatile script pointer / pointee, while((c = *o->script) != 0x4100) (rotated loop, 198), all flag
   sets (-O1 cse-follow/skip-blocks + expensive-opts 205). */
#include "common.h"

typedef struct {
    s32 x, y, z;
} V241C;

typedef struct {
    s16 off;
    s16 pad;
    s32 (*fn)(void *);
} VE241C;

typedef struct {
    u8 pad0[0x10];
    VE241C e2;
    u8 pad18[0x40 - 0x18];
    VE241C e8;
    VE241C e9;
} VT241C;

typedef struct {
    u8 pad0[0x4C];
    V241C *out;
    V241C pos;
} Sub241C;

typedef struct {
    u8 pad0[0xC];
    Sub241C *sub;
} Ent241C;

typedef struct {
    u16 flags;
    u8 pad2[2];
    V241C pos;
    u8 pad10[0x48 - 0x10];
    VT241C *vt;
    u8 pad4C[4];
    u16 unk50;
    u8 pad52[0x294 - 0x52];
    u8 running;
    u8 pad295[3];
    u8 count;
    u8 pad299[3];
    u16 unk29C;
    u8 pad29E[0x2A8 - 0x29E];
    u16 *script;
    u8 pad2AC[0x2F4 - 0x2AC];
    u16 wait;
    u8 pad2F6[0x318 - 0x2F6];
    u16 nEnt;
    u8 pad31A[2];
    Ent241C *ents;
    u8 pad320[4];
    s32 unk324;
    s32 period;
    s32 scale;
} Obj241C;

typedef struct {
    u8 pad0[4];
    V241C pos;
    u8 pad10[0x124 - 0x10];
    s32 limit;
} Cam241C;

void func_8003A0CC(s32, V241C *, s32);
void func_800472C0(V241C *, Ent241C *);
s32 func_80049D60(s32);
void func_80047014(V241C *, void *, void *);
void func_80046FBC(void *, V241C *, Ent241C *);
void func_80046DAC(void *, void *, s32 *);
extern s32 D_800DE808;
extern s32 D_800E8EE8;
extern Cam241C *D_800D61A8;
extern u8 *D_800DE144;

void func_8007241C(Obj241C *o) {
    V241C v;
    V241C a;
    V241C t;
    s32 m40[4];
    s32 m50[4];
    s32 one;
    s32 lim;
    s32 i;
    Ent241C *e;
    V241C *p;
    V241C *res;
    u16 c;
    u16 w;
    s32 save;

    o->flags |= 1;
    o->unk29C = o->unk50;
    if (o->unk29C & 1) {
        o->count++;
        o->unk50 &= ~1;
    }
    if (o->running != 0) {
        w = o->wait;
        if (w != 0) {
            o->wait = w - 1;
        } else {
            while (1) {
                c = *o->script;
                if (c == 0x4100) break;
                o->script++;
                if (c & 0x4000) {
                    if (o->vt->e8.fn((u8 *)o + o->vt->e8.off) == 0) {
                        goto done;
                    }
                } else if (c & 0x2000) {
                    o->vt->e9.fn((u8 *)o + o->vt->e9.off);
                }
            }
            o->running = 0;
        done:;
        }
    } else {
        o->vt->e2.fn((u8 *)o + o->vt->e2.off);
    }
    if (o->period != -1 && D_800DE808 % o->period == 0) {
        save = D_800E8EE8;
        D_800E8EE8 = save * o->scale / 100;
        func_8003A0CC(o->unk324, &o->pos, 0);
        D_800E8EE8 = save;
    }
    if (o->ents != NULL) {
        lim = D_800D61A8->limit;
        i = 0;
        while (1) {
            if (i >= o->nEnt) break;
            e = &o->ents[i];
            v = e->sub->pos;
            func_800472C0(&v, e);
            if (lim < v.y) {
                s32 x, y, z;
                x = (func_80049D60(0x960) - 0x4B0) << 12;
                y = (func_80049D60(0x190) - 0x4B0) << 12;
                z = (func_80049D60(0x960) - 0x4B0) << 12;
                a.x = x;
                a.y = y;
                a.z = z;
                func_80047014(&t, &D_800D61A8->pos, &a);
                v = t;
            }
            e->sub->pos = v;
            res = &a;
            p = e->sub->out;
            func_80046FBC(m40, &v, e);
            one = 1;
            func_80046DAC(m50, D_800DE144 + 0x84, &one);
            func_80047014(res, m40, m50);
            *p = a;
            i++;
        }
    }
}
