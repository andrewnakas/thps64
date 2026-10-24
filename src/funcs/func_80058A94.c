/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-no-m4100 */
#include "common.h"

typedef struct {
    s16 x, y, z, pad;
} Vec3s_80058A94;

typedef struct {
    s32 x, y, z;
} Vec3i_80058A94;

typedef struct {
    s32 x, y, z, pad;
} Vec4i_80058A94;

typedef struct {
    u8 pad0[0x84];
    Vec3i_80058A94 pos;
    u8 pad90[0x400 - 0x90];
    s32 unk400;
    s32 unk404;
    u8 pad408[0x42C - 0x408];
    s32 unk42C;
    u8 pad430[0x450 - 0x430];
    s32 unk450;
    u8 pad454[0x8D0 - 0x454];
    Vec3i_80058A94 unk8D0;
    u8 pad8DC[0x8F4 - 0x8DC];
    Vec3i_80058A94 vel;
    s32 unk900;
    Vec3s_80058A94 nrm;
} Obj_80058A94;

void func_80022964(Vec4i_80058A94 *);
s32 func_80022E14(s32, s32);
s32 func_80022E54(void *, void *);
s32 func_800233B8(s32);
void func_80042C70(void);
void func_80043264(Vec4i_80058A94 *);
void func_8004356C(Vec4i_80058A94 *);
void func_80043590(Vec4i_80058A94 *);
extern s32 D_800DE994;

static inline s32 muldiv(s32 a, s32 b, s32 c) {
    return a * b / c;
}

static inline void setv(Vec4i_80058A94 *v, s32 x, s32 y, s32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

void func_80058A94(Obj_80058A94 *arg0, s32 arg1) {
    Vec4i_80058A94 r;
    Vec4i_80058A94 v;
    Vec4i_80058A94 w;
    struct {
        Vec4i_80058A94 p;
        s32 unk;
        Vec3s_80058A94 n;
    } u;
    Vec4i_80058A94 nn;
    s32 a;
    s32 b;
    s32 k;
    s32 d;
    s32 c;
    void *q;
    s32 t;

    arg0->unk900 = 0;
    if (arg0->unk450 != 0) {
        return;
    }
    q = &arg0->pos;
    a = func_800233B8(func_80022E54(q, q)) << 6;
    q = &arg0->vel;
    b = func_800233B8(func_80022E54(q, q)) << 6;
    k = b / 260;
    t = k * b;
    k = t / 13000;
    c = arg0->unk42C;
    if (c < a) {
        a = c;
    }
    k = muldiv(k, (arg1 << 12) + c - a, c);
    if (k == 0) {
        return;
    }
    if (arg0->unk404 + 10 < D_800DE994) {
        arg0->unk400 = 0;
    }
    arg0->unk404 = D_800DE994;
    *(Vec3i_80058A94 *)&v = arg0->vel;
    func_80022964(&v);
    setv(&w, arg0->nrm.x, arg0->nrm.y, arg0->nrm.z);
    func_80043590(&w);
    func_8004356C(&v);
    func_80042C70();
    func_80043264(&r);
    *(Vec3i_80058A94 *)&u.p = arg0->unk8D0;
    u.n = arg0->nrm;
    setv(&nn, u.n.x, u.n.y, u.n.z);
    d = func_80022E54(&u.p, &nn);
    u.p.x -= func_80022E14(d, u.n.x);
    u.p.y -= func_80022E14(d, u.n.y);
    u.p.z -= func_80022E14(d, u.n.z);
    func_80022E54(&u.p, &v);
    c = func_80022E54(&arg0->unk8D0, &r);
    if (c >= 0x2A) {
        if (arg0->unk400 != 2) {
            arg0->unk900 = -k;
            arg0->unk400 = 1;
        }
    } else if (c < -0x29) {
        if (arg0->unk400 != 1) {
            arg0->unk900 = k;
            arg0->unk400 = 2;
        }
    } else {
        arg0->unk400 = 0;
    }
}
