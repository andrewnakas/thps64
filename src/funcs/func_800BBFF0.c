/* cflags: -O2 */
#include "common.h"

typedef struct {
    s32 a, b, c;
} ListA;

typedef struct {
    s32 a, b, c, d, e, f, g;
} ListB;

typedef struct {
    u8 pad0[0x1C4];
    void *vt;
    ListA l0;
    ListA l1;
    ListA l2;
    ListB m0;
    ListB m1;
    ListB m2;
    ListB m3;
    u8 pad25C[0x2050];
    s32 unk22AC;
    s32 unk22B0;
    u8 pad22B4[0x28];
    s32 unk22DC;
    s32 unk22E0;
    u8 pad22E4[0x2C];
    f32 unk2310;
    s32 unk2314;
} Sched;

Sched *func_8009FF00(Sched *);
extern u8 D_800220F8[];

static inline void ListA_ctor(ListA *p) {
    p->a = 0;
    p->c = 0;
    p->b = 0;
}

static inline void ListB_ctor(ListB *p) {
    p->a = 0;
    p->c = 0;
    p->b = 0;
    p->g = 0;
    p->f = 0;
    p->e = 0;
    p->d = 0;
}

static inline Sched *Sched_init(Sched *t) {
    t->vt = D_800220F8;
    ListA_ctor(&t->l0);
    ListA_ctor(&t->l1);
    ListA_ctor(&t->l2);
    ListB_ctor(&t->m0);
    ListB_ctor(&t->m1);
    ListB_ctor(&t->m2);
    ListB_ctor(&t->m3);
    t->unk2314 = 0;
    t->unk22DC = 0;
    t->unk22E0 = 0;
    t->unk22B0 = 0;
    t->unk22AC = 0;
    t->unk2310 = 1.0f;
    return t;
}

Sched *func_800BBFF0(Sched *arg0) {
    func_8009FF00(arg0);
    return Sched_init(arg0);
}
