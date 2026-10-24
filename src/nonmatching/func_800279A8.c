/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -ffast-math */
/* NON_MATCHING: global-alloc order &p vs %hi(D_800F6560) s3/s5; best 239/246. Equivalent C; only register allocation / scheduling / delay-slot choice differ. */
/* Z1: the swap is global-alloc order of two near-equal priorities: pseudo 106 (&p, 5 refs/120 insns) vs 105
 * (%hi(D_800F6560), 4 refs/98 insns). Moving `t = D_800F6560` or storing through D_800F6560 directly: no gain. */
/* near-miss 239/246 (C1, from C3 draft): permuter do{}while(0) around the middle block fixed most s-reg rotation; left: HIGH(D_800F6560) and &p swapped (s3<->s5). 9-min permuter from here found nothing. */
#include "common.h"

typedef struct {
    s16 a;
    s16 b;
    s16 c;
    s16 d;
    f32 e;
    f32 f;
} View800279A8;

typedef struct {
    View800279A8 v[2];
} ViewPair800279A8;

void func_8009E0F0(void *, s32, s32);
extern s32 D_800F3294;
extern s32 D_800F3298;
extern View800279A8 D_800F6560[3][2];
extern View800279A8 D_800F65C0;

void func_800279A8(void) {
    View800279A8 a;
    ViewPair800279A8 p;
    View800279A8 *g;
    View800279A8 (*t)[2];
    s32 w;
    s32 h;

    g = &D_800F65C0;
    func_8009E0F0(&a, 0, sizeof(a));
    a.b = D_800F3294;
    a.d = D_800F3298;
    a.e = 1.17809725f;
    a.f = (D_800F3298 * 1.17809725f) / D_800F3294;
    *g = a;
    t = D_800F6560;

    func_8009E0F0(&p.v[0], 0, sizeof(p.v[0]));
    h = D_800F3294;
    p.v[0].b = h / 2;
    p.v[0].d = D_800F3298;
    do {
    p.v[0].e = 0.697433591f;
    p.v[0].f = (D_800F3298 * 0.697433591f) / (h * 0.5f);
    func_8009E0F0(&p.v[1], 0, sizeof(p.v[1]));
    h = D_800F3294;
    p.v[1].a = h / 2;
    p.v[1].b = D_800F3294;
    p.v[1].d = D_800F3298;
    p.v[1].e = 0.697433591f;
    p.v[1].f = (D_800F3298 * 0.697433591f) / (h * 0.5f);
    *(ViewPair800279A8 *)D_800F6560[0] = p;

    func_8009E0F0(&a, 0, sizeof(a));
    w = D_800F3294;
    a.b = w / 2;
    h = D_800F3298;
    a.c = h / 2;
    a.d = D_800F3298;
    a.e = 1.39486718f;
    a.f = (h * 1.39486718f) / w;
    func_8009E0F0(&p.v[0], 0, sizeof(p.v[0]));
    w = D_800F3294;
    p.v[0].a = w / 2;
    p.v[0].b = D_800F3294;
    h = D_800F3298;
    p.v[0].d = h / 2;
    } while (0);
    p.v[0].e = 1.39486718f;
    p.v[0].f = (h * 1.39486718f) / w;
    t[1][0] = a;
    t[1][1] = p.v[0];

    func_8009E0F0(&a, 0, sizeof(a));
    a.b = D_800F3294;
    h = D_800F3298;
    a.c = h / 2;
    a.d = D_800F3298;
    a.e = 1.39486718f;
    a.f = (h * 0.697433591f) / D_800F3294;
    func_8009E0F0(&p.v[0], 0, sizeof(p.v[0]));
    p.v[0].b = D_800F3294;
    h = D_800F3298;
    p.v[0].d = h / 2;
    p.v[0].e = 1.39486718f;
    p.v[0].f = (h * 0.697433591f) / D_800F3294;
    t[2][0] = a;
    t[2][1] = p.v[0];
}
