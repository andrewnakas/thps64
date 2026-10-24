/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s16 x, y, z, pad;
} Vec3s_80058804;

typedef struct {
    s32 x, y, z;
} Vec3i_80058804;

typedef struct {
    s32 x, y, z, pad;
} Vec4i_80058804;

typedef struct {
    s16 m[3][3];
    s32 t[3];
} Mtx3s_80058804;

typedef struct {
    u8 pad0[0x84];
    Vec3i_80058804 pos;
    u8 pad90[0x884 - 0x90];
    u8 unk884[0x8D0 - 0x884];
    Vec3i_80058804 unk8D0;
    Vec3i_80058804 unk8DC;
    Vec3i_80058804 unk8E8;
} Obj_80058804;

void func_80022598(Vec3s_80058804 *, Mtx3s_80058804 *);
void func_80022964(Vec3i_80058804 *);
s32 func_80022E14(s32, s32);
s32 func_80022E54(Vec3i_80058804 *, Vec4i_80058804 *);
void func_80022FCC(void *, Mtx3s_80058804 *);
s32 func_800233B8(s32);
void func_80042C70(void);
void func_80043264(Vec3i_80058804 *);
void func_8004356C(Vec3i_80058804 *);
void func_80043590(Vec3i_80058804 *);
void func_8005BE8C(void *);
void func_8005BED8(void *);

void func_80058804(Obj_80058804 *arg0, Vec3s_80058804 n, s32 arg3) {
    Vec4i_80058804 v;
    Mtx3s_80058804 m;
    Vec4i_80058804 old;
    Vec3s_80058804 rot;

    s32 e;
    s32 c;
    s32 s;
    s16 cs;
    s32 x, y, z;
    s32 sq;
    Mtx3s_80058804 *pm;

    if (arg3 == 0) {
        arg3 = 0x19;
    }
    *(Vec3i_80058804 *)&old = arg0->pos;
    x = n.x;
    y = n.y;
    z = n.z;
    v.x = x;
    v.y = y;
    v.z = z;
    e = func_80022E54(&arg0->pos, &v);
    if (e < 0) {
        arg0->pos.x -= func_80022E14(n.x, e);
        arg0->pos.y -= func_80022E14(n.y, e);
        arg0->pos.z -= func_80022E14(n.z, e);
        arg0->pos.x += func_80022E14(n.x, 0xCD);
        arg0->pos.y += func_80022E14(n.y, 0xCD);
        arg0->pos.z += func_80022E14(n.z, 0xCD);
    }
    v.x = -n.x;
    v.y = -n.y;
    v.z = -n.z;
    c = func_80022E54(&arg0->unk8D0, &v);
    sq = (s64)c * c;
    if (c < 0) {
        s = func_800233B8(0x1000000 - sq);
        cs = c;
        pm = &m;
        c = func_80022E54(&arg0->unk8DC, &v);
        if (c > 0) {
            s = -s;
        }
        m.m[0][0] = cs;
        m.m[0][1] = 0;
        m.m[0][2] = -s;
        m.m[1][0] = 0;
        m.m[1][1] = 0x1000;
        m.m[1][2] = 0;
        m.m[2][0] = s;
        m.m[2][1] = 0;
        m.m[2][2] = cs;
        func_80022FCC(arg0->unk884, pm);
        rot.z = 0;
        rot.x = 0;
        if (c > 0) {
            rot.y = (arg3 - 0x400) & 0xFFF;
        } else {
            rot.y = (0x400 - arg3) & 0xFFF;
        }
        func_80022598(&rot, &m);
        func_80022FCC(arg0->unk884, &m);
        func_8005BED8(arg0);
        func_80022964(&arg0->unk8D0);
        func_80022964(&arg0->unk8E8);
        func_80043590(&arg0->unk8D0);
        func_8004356C(&arg0->unk8E8);
        func_80042C70();
        func_80043264(&arg0->unk8DC);
        func_80022964(&arg0->unk8DC);
        func_80043590(&arg0->unk8E8);
        func_8004356C(&arg0->unk8DC);
        func_80042C70();
        func_80043264(&arg0->unk8D0);
        func_8005BE8C(arg0);
    }
}
