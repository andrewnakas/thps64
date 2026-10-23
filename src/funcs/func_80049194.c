#include "common.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3i;

f32 func_80001CA0(f32);
void func_80046E04(Vec3i *, Vec3i *, s32 *);
void func_80046F58(Vec3i *, Vec3i *, s32 *);
void func_80046FBC(Vec3i *, Vec3i *, Vec3i *);
void func_80047014(Vec3i *, Vec3i *, Vec3i *);

void func_80049194(Vec3i *arg0, Vec3i *arg1, Vec3i *arg2, s32 arg3) {
    Vec3i r;
    Vec3i a;
    Vec3i b;
    Vec3i c;
    Vec3i d;
    Vec3i e;
    s32 s;
    s32 x;
    s32 one1;
    s32 one2;
    s32 k;
    s32 *ps;
    Vec3i *pa;
    Vec3i *pb;
    Vec3i *pc;
    Vec3i *pd;
    Vec3i *pe;

    x = arg3;
    if (arg3 == 0) {
        s = 0;
    } else {
        arg3 = x - arg3 / 4096 * 4096;
        s = func_80001CA0((f32)(arg3 * 0.000244140625f * 6.283185)) * 4096.0f;
    }
    pa = &a;
    pb = &b;
    pc = &c;
    pd = &d;
    pe = &e;
    func_80046FBC(pe, arg2, arg1);
    ps = &s;
    func_80046F58(pd, pe, ps);
    k = 0x1000;
    one1 = k;
    func_80046E04(pc, pd, &one1);
    func_80046F58(pb, pc, ps);
    one2 = k;
    func_80046E04(pa, pb, &one2);
    func_80047014(&r, arg1, pa);
    *arg0 = r;
}
