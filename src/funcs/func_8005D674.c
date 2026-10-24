/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* Vector helpers are C++-style operators: func_80046DAC returns its V3 by value (hidden struct-return pointer to a temp, computed before the nested func_80046FBC call, so &tmp gets its s-register first). */
#include "common.h"

typedef struct {
    s32 x, y, z;
} V3_8005D674;

typedef struct {
    s16 x, y, z;
} S3_8005D674;

s32 func_800233B8(s32);
void func_80042D1C(void);
void func_80042F58(void);
void func_80043254(s32 *);
void func_80043264(V3_8005D674 *);
void func_80043288(void);
void func_800432D4(s32, s32, s32, s32, s32);
void func_80043364(S3_8005D674 *);
void func_800433C0(V3_8005D674 *);
void func_800433E4(V3_8005D674 *);
void func_8004342C(s32);
void func_8004356C(V3_8005D674 *);
void func_80043590(V3_8005D674 *);
V3_8005D674 func_80046DAC(V3_8005D674 *, s32 *);
void func_80046FBC(V3_8005D674 *, V3_8005D674 *, V3_8005D674 *);
void func_80047124(V3_8005D674 *, s32 *);
void func_8004715C(V3_8005D674 *, s32 *);

s32 func_8005D674(V3_8005D674 *a0, V3_8005D674 *a1, V3_8005D674 *b0, V3_8005D674 *b1, V3_8005D674 *outA, s32 *tA,
                  V3_8005D674 *outB, s32 *tB) {
    V3_8005D674 da;
    V3_8005D674 db;
    V3_8005D674 dab;
    V3_8005D674 sa;
    V3_8005D674 sb;
    V3_8005D674 cr;
    V3_8005D674 sq;
    V3_8005D674 c2;
    V3_8005D674 dd;
    S3_8005D674 h;
    V3_8005D674 tmp;
    V3_8005D674 t1;
    V3_8005D674 t2;
    s32 k0;
    s32 k1;
    s32 k2;
    s32 k3;
    s32 k4;
    s32 one;
    s32 n;
    s32 one2;
    s32 res;
    s32 k5;
    s32 one3;
    s32 k6;
    s32 k7;
    s32 m;
    s32 den;

    tmp = func_80046DAC((func_80046FBC(&t1, a1, a0), k0 = 12, &t1), &k0);
    da = tmp;
    tmp = func_80046DAC((func_80046FBC(&t2, b1, b0), k1 = 12, &t2), &k1);
    db = tmp;
    tmp = func_80046DAC((func_80046FBC(&t1, a0, b0), k2 = 12, &t1), &k2);
    dab = tmp;
    k3 = 12;
    tmp = func_80046DAC(a0, &k3);
    sa = tmp;
    k4 = 12;
    tmp = func_80046DAC(b0, &k4);
    sb = tmp;

    func_80043590(&da);
    func_8004356C(&db);
    func_80042F58();
    func_80043264(&cr);
    n = 0;
    while (cr.x < -0x6882 || cr.x > 0x6882 || cr.y > 0x6882 || cr.y < -0x6882 || cr.z > 0x6882 || cr.z < -0x6882) {
        one = 1;
        func_8004715C(&cr, &one);
        n++;
    }
    func_800433E4(&cr);
    func_80043288();
    func_80043264(&sq);

    func_80043590(&db);
    func_8004356C(&dab);
    func_80042F58();
    func_80043264(&c2);
    func_8004715C(&c2, &n);
    m = 0;
    while (c2.x < -0x6882 || c2.x > 0x6882 || c2.y > 0x6882 || c2.y < -0x6882 || c2.z > 0x6882 || c2.z < -0x6882) {
        one2 = 1;
        func_8004715C(&c2, &one2);
        m++;
    }
    func_800433E4(&c2);
    h.x = cr.x >> m;
    h.y = cr.y >> m;
    h.z = cr.z >> m;
    den = (sq.x + sq.y + sq.z) >> (m * 2);
    func_80043364(&h);
    func_800432D4(0, 0, 3, 3, 0);
    func_80043254(&res);
    if (res < 0) {
        *tA = 0;
        *outA = *a0;
    } else if (res >= den) {
        *tA = 0x1000;
        *outA = *a1;
    } else {
        if (den > 0xFFFFF) {
            *tA = res / (den >> 12);
        } else {
            *tA = (res << 12) / den;
        }
        func_800433C0(&sa);
        func_800433E4(&da);
        func_8004342C(*tA);
        func_80042D1C();
        func_80043264(outA);
        k5 = 12;
        func_80047124(outA, &k5);
    }

    func_80043590(&da);
    func_8004356C(&dab);
    func_80042F58();
    func_80043264(&c2);
    func_8004715C(&c2, &n);
    m = 0;
    while (c2.x < -0x6882 || c2.x > 0x6882 || c2.y > 0x6882 || c2.y < -0x6882 || c2.z > 0x6882 || c2.z < -0x6882) {
        one3 = 1;
        func_8004715C(&c2, &one3);
        m++;
    }
    func_800433E4(&c2);
    h.x = cr.x >> m;
    h.y = cr.y >> m;
    h.z = cr.z >> m;
    den = (sq.x + sq.y + sq.z) >> (m * 2);
    func_80043364(&h);
    func_800432D4(0, 0, 3, 3, 0);
    func_80043254(&res);
    if (res < 0) {
        *tB = 0;
        *outB = *b0;
    } else if (res >= den) {
        *tB = 0x1000;
        *outB = *b1;
    } else {
        if (den > 0xFFFFF) {
            *tB = res / (den >> 12);
        } else {
            *tB = (res << 12) / den;
        }
        func_800433C0(&sb);
        func_800433E4(&db);
        func_8004342C(*tB);
        func_80042D1C();
        func_80043264(outB);
        k6 = 12;
        func_80047124(outB, &k6);
    }

    tmp = func_80046DAC((func_80046FBC(&t1, outA, outB), k7 = 12, &t1), &k7);
    dd = tmp;
    func_800433E4(&dd);
    func_80043288();
    func_80043264(&sq);
    return func_800233B8(sq.x + sq.y + sq.z);
}
