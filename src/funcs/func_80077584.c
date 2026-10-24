#include "common.h"

typedef struct {
    s32 x, y, z;
} V3_80077584;

typedef struct {
    s32 x, y, z, w;
} Q_80077584;

void func_80042F58(void);
void func_80043264(void *);
void func_8004356C(void *);
void func_80043590(void *);
void func_80046D28(void *, void *);
void func_80046D54(void *, void *, s32 *);
void func_80046DAC(void *, void *, s32 *);
void func_80046FBC(void *, void *, void *);
void func_80047014(void *, void *, void *);
s32 func_800470A8(void *, void *);
s32 func_800474C8(void *);
void func_80047980(void *, s32, void *);
void func_80047D40(void *, void *, void *);
s32 func_80022E54(void *, void *);
void func_800673B0(void *, void *, void *);
void func_800677F8(void *, s32);
void func_80067B44(void *, void *);
extern s16 D_800DE2F0[];
extern u8 *D_800DE7A8;

#define I32(o) (*(s32 *)(c + (o)))
#define U32(o) (*(u32 *)(c + (o)))
#define S16(o) (*(s16 *)(c + (o)))
#define V3(o) (*(V3_80077584 *)(c + (o)))
#define Q(o) (*(Q_80077584 *)(c + (o)))
#define TGT (*(u8 **)(c + 0x4B4))

static inline s32 absdot_80077584(void *a, void *b) {
    if (func_80022E54(a, b) >= 0) {
        return func_80022E54(a, b);
    }
    return -func_80022E54(a, b);
}

void func_80077584(u8 *c) {
    V3_80077584 v10;
    Q_80077584 q20;
    s16 a30[4];
    V3_80077584 v38;
    s32 i1;
    s32 i2;
    s32 i3;
    s32 d;
    s32 e;
    s32 r;
    u8 *t;
    u8 *p564;
    Q_80077584 *pC8;
    Q_80077584 *pD8;
    u8 *t0;
    u8 *p678;
    V3_80077584 *p78;
    V3_80077584 *p88;
    V3_80077584 *p98;
    s32 k;
    s16 *pc;
    V3_80077584 *pd;
    V3_80077584 *pa;
    V3_80077584 *pb;

    func_80046FBC(&v38, c + 0x4D0, c + 0x4C0);
    t0 = TGT;
    pb = &v10;
    v10 = *(V3_80077584 *)(t0 + 0x8E8);
    {
    V3_80077584 v48;
    V3_80077584 v58;
    V3_80077584 v68;
    V3_80077584 v78;
    V3_80077584 v88;
    V3_80077584 v98;
    V3_80077584 vA8;
    V3_80077584 vB8;
    Q_80077584 qC8;
    Q_80077584 qD8;

    {
        s32 one = 0x1000;

        v48.x = 0;
        v48.y = one;
        v48.z = 0;
    }
    v58.x = 0;
    v58.y = 0;
    v58.z = 0;

    pa = &v48;
    d = func_80022E54(pa, pb) >= 0 ? func_80022E54(pa, pb) : -func_80022E54(pa, pb);
    pc = a30;
    func_80047D40(pc, &v58, &v38);
    pd = &v68;
    func_80047980(pd, 0x1000, pc);
    e = func_80022E54(pd, &v10) >= 0 ? func_80022E54(pd, &v10) : -func_80022E54(pd, &v10);
    I32(0x69C)++;
    if (d < 0xDF4 && ((k = *(s32 *)((t = TGT) + 0x82C)) == 2 || k == 8)) {
        if (I32(0x688) == 0 && *(s32 *)(t + 0x838) != 0) {
            (*(s32 *)(t + 0x33C))++;
        }
        if (++I32(0x6C0) >= 4) {
            s32 big = 0x1000000;

            v78.x = 0;
            v78.y = big;
            v78.z = 0;
            V3(0x6C4) = v78;
        } else {
            func_80047980(c + 0x6C4, 0x1000, a30);
        }
        I32(0x688) = 1;
        I32(0x69C) = 0;
    } else {
        if ((e >> 12) >= 0x7D1) {
            I32(0x6C0) = 0;
        } else if (func_800474C8(&v38) < 5) {
            I32(0x6C0) = 0;
        } else {
            I32(0x6C0) = 0;
            func_80047980(c + 0x6C4, 0x1000, a30);
        }
        if (d < 0xDF4 && I32(0x688) == 1) {
            I32(0x69C) = 0;
        }
        I32(0x688) = 0;
    }
    p678 = c + 0x678;
    V3(0x678) = V3(0x66C);
    r = func_800470A8(c + 0x4D0, c + 0x4C0);
    p78 = &v78;
    if (r) {
        V3(0x66C) = V3(0x678);
    } else {
        p88 = &v88;
        func_80047014(p88, p678, c + 0x6C4);
        i1 = 1;
        func_80046DAC(p78, p88, &i1);
        V3(0x66C) = v78;
    }
    p78 = &v78;
    if (U32(0x610) < 12) {
        p98 = &v98;
        func_80046D28(p98, D_800DE7A8 + 0x8D0);
        i2 = 12;
        func_80046D54(p78, p98, &i2);
        V3(0x66C) = v78;
        V3(0x678) = V3(0x66C);
        V3(0x6C4) = V3(0x678);
    }
    V3(0x6C4) = V3(0x66C);
    i3 = 12;
    func_80046DAC(&vB8, c + 0x6C4, &i3);
    vA8 = vB8;
    v88.x = -v10.x;
    v88.y = -v10.y;
    v88.z = -v10.z;
    func_80043590(&v88);
    func_8004356C(&vA8);
    func_80042F58();
    func_80043264(&v78);
    v78.x >>= 12;
    v78.y >>= 12;
    v78.z >>= 12;
    func_80043590(&v78);
    func_8004356C(&v88);
    func_80042F58();
    func_80043264(&vA8);
    vA8.x >>= 12;
    vA8.y >>= 12;
    vA8.z >>= 12;
    D_800DE2F0[0] = v78.x;
    D_800DE2F0[3] = v78.y;
    D_800DE2F0[6] = v78.z;
    D_800DE2F0[1] = v88.x;
    D_800DE2F0[4] = v88.y;
    D_800DE2F0[7] = v88.z;
    D_800DE2F0[2] = vA8.x;
    D_800DE2F0[5] = vA8.y;
    D_800DE2F0[8] = vA8.z;
    p564 = c + 0x564;
    func_80067B44(D_800DE2F0, p564);
    pC8 = &qC8;
    pD8 = &qD8;
    func_800677F8(pD8, S16(0x66A));
    func_800673B0(pC8, p564, pD8);
    Q(0x564) = qC8;
    }
}
