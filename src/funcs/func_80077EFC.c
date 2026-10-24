#include "common.h"

typedef struct {
    s32 x, y, z;
} V3_80077EFC;

typedef struct {
    s32 x, y, z, w;
} Q_80077EFC;

void func_80042F58(void);
void func_80043264(void *);
void func_8004356C(void *);
void func_80043590(void *);
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

#define I32(o) (*(s32 *)(c + (o)))
#define S16(o) (*(s16 *)(c + (o)))
#define V3(o) (*(V3_80077EFC *)(c + (o)))
#define Q(o) (*(Q_80077EFC *)(c + (o)))
#define TGT (*(u8 **)(c + 0x4B4))

#define ABS(x) ((x) >= 0 ? (x) : -(x))

void func_80077EFC(u8 *c) {
    V3_80077EFC v10;
    Q_80077EFC unused; /* never referenced: the same unused 16-byte slot at sp+0x20 as matched sibling func_80077584 */
    s16 a30[4];
    V3_80077EFC v38;
    s32 i1;
    s32 i3;
    s32 d;
    s32 e;
    s32 r;
    Q_80077EFC *pC8;
    u8 *p678;
    V3_80077EFC *p78;
    V3_80077EFC *pd;
    V3_80077EFC *pa;

    func_80046FBC(&v38, c + 0x4D0, c + 0x4C0);
    if (TGT != NULL) {
        v10 = *(V3_80077EFC *)(TGT + 0x8E8);
    } else {
        v10.x = 0;
        v10.y = -0x1000;
        v10.z = 0;
    }
    {
    V3_80077EFC v48;
    V3_80077EFC v58;
    V3_80077EFC v68;
    V3_80077EFC v78;
    V3_80077EFC v88;
    V3_80077EFC v98;
    V3_80077EFC vA8;
    V3_80077EFC vB8;
    Q_80077EFC qC8;
    Q_80077EFC qD8;

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
    d = ABS(func_80022E54(pa, &v10));
    func_80047D40(a30, &v58, &v38);
    pd = &v68;
    func_80047980(pd, 0x1000, a30);
    e = ABS(func_80022E54(pd, &v10));
    if ((e >> 12) >= 0x7D1) {
        I32(0x688) = 0;
    } else if (func_800474C8(&v38) < 5) {
        I32(0x688) = 0;
    } else {
        I32(0x688) = 0;
        func_80047980(c + 0x6C4, 0x1000, a30);
    }
    p678 = c + 0x678;
    V3(0x678) = V3(0x66C);
    r = func_800470A8(c + 0x4D0, c + 0x4C0);
    p78 = &v78;
    if (r) {
        V3(0x66C) = V3(0x678);
    } else {
        func_80047014(&v88, p678, c + 0x6C4);
        i1 = 1;
        func_80046DAC(p78, &v88, &i1);
        V3(0x66C) = v78;
    }
    V3(0x6C4) = V3(0x66C);
    i3 = 12;
    func_80046DAC(&vB8, c + 0x6C4, &i3);
    vA8 = vB8;
    v98.x = -v10.x;
    v98.y = -v10.y;
    v98.z = -v10.z;
    func_80043590(&v98);
    func_8004356C(&vA8);
    func_80042F58();
    func_80043264(&v78);
    v78.x >>= 12;
    v78.y >>= 12;
    v78.z >>= 12;
    func_80043590(&v78);
    func_8004356C(&v98);
    func_80042F58();
    func_80043264(&vA8);
    vA8.x >>= 12;
    vA8.y >>= 12;
    vA8.z >>= 12;
    D_800DE2F0[0] = v78.x;
    D_800DE2F0[3] = v78.y;
    D_800DE2F0[6] = v78.z;
    D_800DE2F0[1] = v98.x;
    D_800DE2F0[4] = v98.y;
    D_800DE2F0[7] = v98.z;
    D_800DE2F0[2] = vA8.x;
    D_800DE2F0[5] = vA8.y;
    D_800DE2F0[8] = vA8.z;
    func_80067B44(D_800DE2F0, c + 0x564);
    pC8 = &qC8;
    func_800677F8(&qD8, S16(0x66A));
    func_800673B0(pC8, c + 0x564, &qD8);
    Q(0x564) = qC8;
    }
    I32(0x688) = 0;
}
