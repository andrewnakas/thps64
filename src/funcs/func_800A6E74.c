/* cflags: -O2 */
#include "common.h"

typedef struct {
    f32 x, y, z;
} Vec3;

typedef struct {
    s32 unk0;
    f32 unk4;
    s32 unk8;
} A6E74Ent;

typedef struct {
    A6E74Ent *unk0;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 pad7;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    void (*unk18)(s32);
    void (*unk1C)(s32);
    u8 pad20[0x68 - 0x20];
    s32 unk68;
    s32 unk6C;
    f32 unk70;
    f32 unk74;
    f32 unk78;
    s32 unk7C;
    u8 unk80;
} A6E74Obj;

typedef struct {
    u8 pad0[0x90];
    f32 unk90;
    f32 unk94;
    f32 unk98;
} A6E74Pos;

void func_80001BE8(f32 (*)[4], s32);
void func_8009C8EC(f32 (*)[4], s32);
void func_8009D94C(f32 (*)[4], Vec3 *);
void func_800B4A08(void *, s32, s32, s32, s32, u32, s32);
void func_800B6E3C(s32, s32);
s32 func_800C000C(void *);
extern u8 D_800EA590;
extern f32 D_800EA594;
extern s32 D_800EA598;
extern f32 D_800EA59C;
extern u8 D_800ECFE0[];
extern s32 D_800F36C0;
extern s32 *D_800F36C4[];
extern s32 D_800F5664;

void func_800A6E74(A6E74Obj *arg0, A6E74Pos *arg1, s32 arg2, s32 arg3, s32 arg4) {
    f32 m[4][4];
    Vec3 v;
    Vec3 w;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d;
    f32 f;
    s32 i;
    s32 idx;
    s32 n;
    u32 u;
    u32 alpha;
    u32 t;
    A6E74Ent *e;
    Vec3 *pv;
    Vec3 *pt;
    f32 (*pm)[4];

    dx = arg1->unk90 - arg0->unk70;
    dy = arg1->unk94 - arg0->unk74;
    dz = arg1->unk98 - arg0->unk78;
    d = dx * dx + dy * dy + dz * dz;
    d = d / D_800EA594;
    for (i = 0; i < arg0->unk4; i++) {
        if (d < arg0->unk0[i].unk4) {
            idx = i;
            break;
        }
    }
    n = arg0->unk4;
    if (i == n) {
        arg0->unk7C = 100;
        return;
    }
    if (idx < D_800EA590) {
        idx = n - 1;
        if (D_800EA590 < idx) {
            idx = D_800EA590;
        }
    }
    e = &arg0->unk0[idx];
    if (idx != 0) {
        alpha = 0;
    } else {
        f = (1.0f - d / arg0->unk0[0].unk4) * 765.0f;
        if (f >= 2147483648.0f) {
            goto big;
        }
        alpha = (s32)f;
        goto end;
    big:
        alpha = (s32)(f - 2147483648.0f);
        alpha |= 0x80000000;
    end:
        t = 0xFF;
        if (alpha < 0x100) {
            t = alpha;
        }
        alpha = t;
    }
    if (D_800EA598 != 0) {
        if (arg0->unk80 != 0) {
            func_80001BE8(m, arg0->unk6C);
        } else {
            func_8009C8EC(m, arg0->unk68);
        }
        v.x = 0.0f;
        v.y = -D_800EA59C;
        v.z = 0.0f;
        pv = &v;
        pt = (Vec3 *)m[3];
        w.x = pv->x;
        w.y = pv->y;
        w.z = pv->z;
        pt->x += w.x;
        pt->y += w.y;
        pt->z += w.z;
        pm = m;
        pv->x = 1.0f;
        pv->y = -1.0f;
        pv->z = 1.0f;
        func_8009D94C(pm, pv);
        v.x = 0.0f;
        v.y = D_800EA59C;
        v.z = 0.0f;
        w.x = pv->x;
        w.y = pv->y;
        w.z = pv->z;
        pt->x += w.x;
        pt->y += w.y;
        pt->z += w.z;
        arg0->unkC = func_800C000C(pm);
    } else if (arg0->unkC == 0) {
        if (arg0->unk80 != 0) {
            arg0->unkC = arg0->unk6C;
        } else {
            arg0->unkC = func_800C000C((void *)arg0->unk68);
            D_800F36C4[D_800F36C0++] = &arg0->unkC;
        }
    }
    if (arg0->unk18 != NULL) {
        arg0->unk18(arg0->unk10);
    }
    if (arg0->unk6 != 0) {
        func_800B4A08(D_800ECFE0, e->unk8, arg4, arg0->unkC, arg2, alpha, arg3);
    } else {
        func_800B6E3C(e->unk8, arg4);
    }
    if (arg0->unk1C != NULL) {
        arg0->unk1C(arg0->unk14);
    }
    arg0->unk8 = D_800F5664;
    if (arg0->unk5 != 0) {
        if (i - 100 < arg0->unk7C) {
            arg0->unk7C = i - 100;
        }
        D_800F36C4[D_800F36C0++] = &arg0->unk7C;
    }
    if (D_800EA598 != 0 && arg0->unk80 == 0) {
        arg0->unkC = 0;
    }
}
