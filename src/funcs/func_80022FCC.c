#include "common.h"

typedef struct {
    f32 m[4][4];
} MtxF;

void func_80041EC0(s32, MtxF *);
void func_80041F80(MtxF *, s32);
void func_8009C8EC(MtxF *, MtxF *);
void func_8009C914(MtxF *, MtxF *, MtxF *);

static __inline__ void mtx_mul_(MtxF *dst, MtxF *x, MtxF *y) {
    MtxF d;

    func_8009C914(&d, x, y);
    func_8009C8EC(dst, &d);
}

s32 func_80022FCC(s32 arg0, s32 arg1) {
    MtxF a;
    MtxF b;
    MtxF c;
    MtxF *pa;
    MtxF *pb;

    func_80041F80(&a, arg0);
    pb = &b;
    func_80041F80(pb, arg1);
    pa = &a;
    mtx_mul_(pa, pa, pb);
    func_8009C8EC(&c, pa);
    func_80041EC0(arg0, pa);
    return arg0;
}
