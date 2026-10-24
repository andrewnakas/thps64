#include "common.h"

typedef struct { s32 x, y, z; } Vec3i;
typedef struct { s16 x, y, z, w; } Vec4s;

s32 func_80022E14(s32, s32);
s32 func_80022E54(Vec3i *, Vec3i *);
s32 func_800233B8(s32);
void func_80046E04(Vec3i *, Vec3i *, s32 *);
void func_80046F58(Vec3i *, Vec3i *, s32 *);

static __inline__ s32 dot_(Vec3i *p, Vec3i *q) {
    return func_80022E54(p, q);
}

void func_8004D5B0(Vec3i *arg0, Vec4s *arg1, Vec3i *arg2) {
    s32 unused[4];
    union { Vec3i v; struct { s32 pad; Vec4s r; } s; } u;
    Vec3i a;
    s32 d;
    s32 t;
    s32 sp40;
    s32 sp44;
    Vec3i *pa;
    Vec3i *pu;

    sp40 = func_800233B8(func_80022E54(arg0, arg0)) << 6;
    *arg2 = *arg0;
    u.s.r = *arg1;
    {
        s32 x = u.s.r.x, y = u.s.r.y, z = u.s.r.z;
        a.x = x;
        a.y = y;
        a.z = z;
    }
    d = dot_(arg2, &a);
    arg2->x -= func_80022E14(d, u.s.r.x);
    arg2->y -= func_80022E14(d, u.s.r.y);
    arg2->z -= func_80022E14(d, u.s.r.z);
    sp44 = t = func_800233B8(func_80022E54(arg2, arg2)) << 6;
    sp40 >>= 8;
    sp44 = t >> 8;
    pu = &u.v;
    pa = &a;
    func_80046F58(pa, arg2, &sp40);
    func_80046E04(pu, pa, &sp44);
    *arg2 = u.v;
}
