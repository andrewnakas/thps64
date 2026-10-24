/* cflags: -fexpensive-optimizations */
/* NON_MATCHING: aln 0.756. Equivalent C; the stack temp chain differs: the game reads p.y/p.z directly at sp+0x1C/0x20, this C goes through a copy of &p, swapping arg0/&p between s1 and s2. */
/* D3 near-miss 140/197 (from A3 106): C++-style inlines reproduce the game frame (0x70: n copy 0x2C, q 0x38, r 0x48, tmp 0x38, w 0x28 field-copied). Left: game accesses p.y/p.z at sp+0x1C/0x20 while ours goes through the inline param copy of &p (s1+4); arg0/&p s1/s2 swap follows from that. */
#include "common.h"

typedef struct {
    s16 x, y, z, w;
} V3S;

typedef struct {
    s32 x, y, z;
} V3;

void func_8002248C(void *, void *);
s32 func_80022E14(s32, s32);
s32 func_80022E54(void *, void *);
s32 func_800233B8(s32);
void func_80042C70(void);
void func_80043264(s32 *);
void func_8004356C(s32 *);
void func_80043590(s32 *);
void func_80046FBC(V3 *, u8 *, u8 *);
void func_8004A204(u8 *, s32, s32, s32, s32);
void func_8004BD2C(u8 *);
void func_8004D2D4(u8 *);
void func_8004D398(u8 *, s32);
void func_8005BE8C(u8 *);

static inline void project_(V3 *p, V3S n) {
    V3 q;
    s32 d;

    {
        s32 x = n.x;
        s32 y = n.y;
        s32 z = n.z;

        q.x = x;
        q.y = y;
        q.z = z;
    }
    d = func_80022E54(p, &q);
    p->x -= func_80022E14(d, n.x);
    p->y -= func_80022E14(d, n.y);
    p->z -= func_80022E14(d, n.z);
}

static inline V3 vsub_(u8 *a, u8 *b) {
    V3 r;

    func_80046FBC(&r, a, b);
    return r;
}

static inline void setdir_(u8 *arg0, V3 *src) {
    V3 w;

    w.x = src->x;
    w.y = src->y;
    w.z = src->z;
    if (__builtin_abs(w.x) + __builtin_abs(w.y) + __builtin_abs(w.z) > 0x8000) {
        w.x = w.x >> 4;
        w.y = w.y >> 4;
        w.z = w.z >> 4;
    }
    func_8002248C(&w, &w);
    *(s32 *)(arg0 + 0x8D0) = -w.x;
    *(s32 *)(arg0 + 0x8D4) = -w.y;
    *(s32 *)(arg0 + 0x8D8) = -w.z;
}

void func_8004EBFC(u8 *arg0, V3S v) {
    V3 p;
    s32 d;
    s32 len;
    s32 t;
    s32 *a;
    s32 *b;
    s32 *c;

    p = *(V3 *)(arg0 + 0x84);
    project_(&p, v);
    len = func_800233B8(func_80022E54(&p, &p)) << 6;
    a = (s32 *)(arg0 + 0x8D0);
    if (len > 0x1E000) {
        t = (func_80022E54(&p, a) << 6) / (len >> 6);
        if (t < 0) {
            t = -t;
        }
        if (t < 0x666) {
            func_8004BD2C(arg0);
            b = (s32 *)(arg0 + 0x8DC);
            d = func_80022E54(&p, b);
            func_8004D398(arg0, 0);
            *(s32 *)(arg0 + 0x314) += 1;
            {
                V3 tmp;

                tmp = vsub_(arg0 + 0x16C, arg0 + 0x2A8);
                setdir_(arg0, &tmp);
            }
            c = (s32 *)(arg0 + 0x8E8);
            {
                s32 vx = v.x;
                s32 vy = v.y;
                s32 vz = v.z;

                *(s32 *)(arg0 + 0x8E8) = vx;
                *(s32 *)(arg0 + 0x8EC) = vy;
                *(s32 *)(arg0 + 0x8F0) = vz;
            }
            func_80043590(a);
            func_8004356C(c);
            func_80042C70();
            func_80043264(b);
            func_80043590(c);
            func_8004356C(b);
            func_80042C70();
            func_80043264(a);
            func_8005BE8C(arg0);
            if (*(s32 *)(arg0 + 0x208) & 2) {
                d = -d;
            }
            if (d <= 0) {
                *(s32 *)(arg0 + 0x228) = 0x10000;
                func_8004D2D4(arg0);
                func_8004A204(arg0, 0x2E, 0, -1, -1);
                *(s32 *)(arg0 + 0x344) = 5;
            }
        }
    }
}
