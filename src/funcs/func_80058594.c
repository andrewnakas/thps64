/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s16 m[3][3];
    s16 pad;
    s32 t[3];
} MtxS58594;

typedef struct {
    s32 x, y, z;
} IVec58594;

typedef struct {
    s16 x, y, z;
} SVec58594;

s32 func_8004706C(void *, void *);
void func_80022598(SVec58594 *, MtxS58594 *);
void func_80022FCC(MtxS58594 *, MtxS58594 *);
void func_8005BED8(void *);
s32 func_80022E54(IVec58594 *, IVec58594 *);
s32 func_800233B8(s32);
void func_800230A8(MtxS58594 *, MtxS58594 *);
void func_80046F58(IVec58594 *, IVec58594 *, s32 *);
void func_80046E04(IVec58594 *, IVec58594 *, s32 *);
extern u8 D_800D6188[];

void func_80058594(u8 *o, s32 ang, s32 flag, s32 ang2) {
    MtxS58594 m10;
    SVec58594 r;
    MtxS58594 m38;
    MtxS58594 m58;
    IVec58594 old;
    IVec58594 v;
    IVec58594 res;
    IVec58594 a;
    IVec58594 b;
    s32 len0;
    s32 len1;
    IVec58594 *pos;
    IVec58594 *pa;
    IVec58594 *pb;

    if (ang == 0) {
        return;
    }
    if (*(s32 *)(o + 0x450) != 0) {
        return;
    }
    if (func_8004706C(o + 0x90C, D_800D6188) != 0) {
        return;
    }
    r.z = 0;
    r.x = 0;
    r.y = ang & 0xFFF;
    func_80022598(&r, &m10);
    func_80022FCC((MtxS58594 *)(o + 0x884), &m10);
    func_8005BED8(o);
    if (flag == 0) {
        return;
    }
    pos = (IVec58594 *)(o + 0x84);
    len0 = func_800233B8(func_80022E54(pos, pos)) << 6;
    func_800230A8((MtxS58594 *)(o + 0x864), &m58);
    r.z = 0;
    r.x = 0;
    r.y = (ang - ang2) & 0xFFF;
    func_80022598(&r, &m10);
    func_80022FCC(&m58, &m10);
    m38 = *(MtxS58594 *)(o + 0x864);
    func_80022FCC(&m38, &m58);
    old = *pos;
    v.x = m38.m[0][0];
    v.y = m38.m[0][1];
    v.z = m38.m[0][2];
    res.x = func_80022E54(&v, pos);
    v.x = m38.m[1][0];
    v.y = m38.m[1][1];
    v.z = m38.m[1][2];
    res.y = func_80022E54(&v, pos);
    v.x = m38.m[2][0];
    v.y = m38.m[2][1];
    v.z = m38.m[2][2];
    res.z = func_80022E54(&v, pos);
    *pos = res;
    len1 = func_800233B8(func_80022E54(pos, pos)) << 6;
    len0 >>= 8;
    len1 >>= 8;
    pa = &a;
    pb = &b;
    func_80046F58(pb, pos, &len0);
    func_80046E04(pa, pb, &len1);
    *pos = *pa;
}
