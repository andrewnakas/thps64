/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 *hdr;
    s32 base;
} Rd_800379B0;

typedef struct {
    s16 x, y, z, pad;
    s32 unk8;
    s32 unkC;
} Vtx_800379B0;

typedef struct {
    Vtx_800379B0 *verts;
    s32 *cnt;
} Arr_800379B0;

typedef struct {
    f32 x, y, z;
} V3_800379B0;

typedef struct {
    u8 pad0[2];
    s16 idx;
    u8 pad4[0xC - 4];
    V3_800379B0 min;
    V3_800379B0 max;
    V3_800379B0 off;
    f32 unk30;
    f32 unk34;
} Obj_800379B0;

typedef struct {
    u8 pad0[4];
    s32 **tbl;
} Lib_800379B0;

s32 func_80039328(Rd_800379B0 *, s32);
void func_8003934C(Rd_800379B0 *, s32);

static inline s32 vlt(V3_800379B0 *a, V3_800379B0 *b) {
    return a->x > b->x;
}

void func_800379B0(Lib_800379B0 *arg0, Obj_800379B0 *arg1) {
    Rd_800379B0 rd;
    Arr_800379B0 a;
    V3_800379B0 t;
    Rd_800379B0 *prd;
    u8 *q;
    s32 o;
    s32 n;
    s32 i;
    Vtx_800379B0 *vp;
    V3_800379B0 *mn;
    V3_800379B0 *mx;

    o = (*arg0->tbl)[arg1->idx];
    prd = &rd;
    func_8003934C(prd, o);
    q = (u8 *)rd.base + func_80039328(prd, 0);
    arg1->unk30 = *(f32 *)(q + 0x18);
    arg1->unk34 = *(f32 *)(q + 0x1C);
    a.cnt = (s32 *)((u8 *)rd.base + func_80039328(prd, 2));
    vp = a.verts = (Vtx_800379B0 *)(a.cnt + 2);
    n = *a.cnt;
    mn = &arg1->min;
    mx = &arg1->max;
    t.z = t.y = t.x = 1000000.0f;
    *mn = t;
    t.z = t.y = t.x = -1000000.0f;
    *mx = t;
    i = 0;
    while (1) {
        if (i >= n) {
            break;
        }
        if ((f32)vp[i].x < mn->x) {
            mn->x = vp[i].x;
        }
        if (mx->x < (f32)vp[i].x) {
            mx->x = vp[i].x;
        }
        if ((f32)vp[i].y < mn->y) {
            mn->y = vp[i].y;
        }
        if (mx->y < (f32)vp[i].y) {
            mx->y = vp[i].y;
        }
        if ((f32)vp[i].z < mn->z) {
            mn->z = vp[i].z;
        }
        if (mx->z < (f32)vp[i].z) {
            mx->z = vp[i].z;
        }
        i++;
    }
    *(volatile f32 *)&mn->x;
    *(volatile f32 *)&mn->y;
    *(volatile f32 *)&mn->z;
    *(volatile f32 *)&mx->x;
    *(volatile f32 *)&mx->y;
    *(volatile f32 *)&mx->z;
    t.x = arg1->off.x;
    t.y = arg1->off.y;
    t.z = arg1->off.z;
    mn->x += t.x;
    mn->y += t.y;
    mn->z += t.z;
    t.x = arg1->off.x;
    t.y = arg1->off.y;
    t.z = arg1->off.z;
    mx->x += t.x;
    mx->y += t.y;
    mx->z += t.z;
    if (vlt(mn, mx)) {
        t.z = 0.0f;
        t.y = 0.0f;
        t.x = 0.0f;
        *mx = t;
        *mn = *mx;
    }
}
