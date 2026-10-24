#include "common.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} V3_80077350;

typedef struct {
    s32 v[4];
} V4_80077350;

typedef struct {
    s16 m[3][3];
    s16 pad;
    s32 t[3];
} Mtx80077350;

typedef struct {
    u8 pad0[0x23C];
    Mtx80077350 mtx;
    u8 pad25C[0x8D0 - 0x25C];
    V3_80077350 pos;
    u8 pad8DC[0x8E8 - 0x8DC];
    V3_80077350 dir;
    V3_80077350 unused[2];
} Ref80077350;

typedef struct {
    u8 pad0[0x4B4];
    Ref80077350 *ref;
    u8 pad4B8[0x564 - 0x4B8];
    V4_80077350 rot;
    u8 pad574[0x66A - 0x574];
    s16 ang;
    V3_80077350 pos;
    V3_80077350 pos2;
    u8 pad684[0x6C4 - 0x684];
    V3_80077350 pos3;
} Obj80077350;

extern void func_80042F58(void);
extern void func_80043264(V3_80077350 *);
extern void func_8004356C(V3_80077350 *);
extern void func_80043590(V3_80077350 *);
extern void func_80046DAC(V3_80077350 *, V3_80077350 *, s32 *);
extern void func_800673B0(V4_80077350 *, V4_80077350 *, V4_80077350 *);
extern void func_800677F8(V4_80077350 *, s16);
extern void func_80067B44(void *, V4_80077350 *);
extern Mtx80077350 D_800DE2F0;

void func_80077350(Obj80077350 *arg0) {
    V3_80077350 dir;
    V3_80077350 unused[2];
    V3_80077350 c;
    V3_80077350 a;
    V3_80077350 b;
    V3_80077350 r;
    V4_80077350 q;
    V4_80077350 aq;
    s32 n;
    V4_80077350 *qp;
    V4_80077350 *ap;

    dir = arg0->ref->dir;
    arg0->pos = arg0->ref->pos;
    arg0->pos2 = arg0->pos;
    arg0->pos3 = arg0->pos;
    n = 0xC;
    func_80046DAC(&r, &arg0->pos3, &n);
    b = r;
    a.x = -dir.x;
    a.y = -dir.y;
    a.z = -dir.z;
    func_80043590(&a);
    func_8004356C(&b);
    func_80042F58();
    func_80043264(&c);
    c.x >>= 12;
    c.y >>= 12;
    c.z >>= 12;
    func_80043590(&c);
    func_8004356C(&a);
    func_80042F58();
    func_80043264(&b);
    b.x >>= 12;
    b.y >>= 12;
    b.z >>= 12;
    D_800DE2F0.m[0][0] = c.x;
    D_800DE2F0.m[1][0] = c.y;
    D_800DE2F0.m[2][0] = c.z;
    D_800DE2F0.m[0][1] = a.x;
    D_800DE2F0.m[1][1] = a.y;
    D_800DE2F0.m[2][1] = a.z;
    D_800DE2F0.m[0][2] = b.x;
    D_800DE2F0.m[1][2] = b.y;
    D_800DE2F0.m[2][2] = b.z;
    func_80067B44(&D_800DE2F0, &arg0->rot);
    func_80067B44(&arg0->ref->mtx, &arg0->rot);
    qp = &q;
    ap = &aq;
    func_800677F8(ap, arg0->ang);
    func_800673B0(qp, &arg0->rot, ap);
    arg0->rot = *qp;
}
