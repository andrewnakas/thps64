/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    f32 x, y, z;
} V3_8007EBE4;

typedef struct {
    f32 m[3][4];
    V3_8007EBE4 t;
    f32 w;
} M_8007EBE4;

typedef struct {
    s16 rot[3];
    s16 pos[3];
} Key_8007EBE4;

typedef struct {
    s32 off;
    u32 n;
} Anim_8007EBE4;

typedef struct {
    u8 pad0[0x18];
    s32 *unk18;
    s32 *unk1C;
    s32 *unk20;
    u16 *unk24;
    u8 pad28[0x48 - 0x28];
} Skel_8007EBE4;

typedef struct {
    u8 pad0[0x1B];
    u8 unk1B;
    u8 pad1C[0x20C - 0x1C];
    u16 *unk20C;
    void *unk210;
    M_8007EBE4 *unk214;
    u16 unk218;
    u8 unk21A;
    s8 unk21B;
    s16 unk21C;
    u16 unk21E;
} Obj_8007EBE4;

extern Skel_8007EBE4 D_800DAF98[];
extern u8 D_800D7450[];
void func_80022C04(M_8007EBE4 *, Key_8007EBE4 *);
void func_8005DE04(Obj_8007EBE4 *);
void *func_8005EAB4(s32, s32, s32);
s16 *func_8007E7A0(s16 *, s16 *, s32, s32);

void *func_8007EBE4(Obj_8007EBE4 *o) {
    Skel_8007EBE4 *sk;
    Skel_8007EBE4 *tbl;
    s32 *base;
    u32 nb;
    s32 stride;
    s32 frame;
    Anim_8007EBE4 *an;
    s32 *e;

    tbl = D_800DAF98;
    sk = &tbl[o->unk1B];
    base = sk->unk20;
    nb = sk->unk18[-1];
    stride = sk->unk1C[2];
    frame = o->unk21C;
    e = (s32 *)(o->unk21E * 8 + (s32)base);
    if ((u32)frame >= e[2]) {
        return o->unk210;
    }
    switch (base[-2]) {
        case 0x2A:
            if ((u32)e[2] >> 16) {
                func_8005DE04(o);
                return D_800D7450;
            }
            return (u8 *)base + e[1] + frame * stride * 24;
        case 0x2C: {
            s32 flag = 0;
            s32 flag2;

            if (o->unk214 == NULL) {
                s32 cnt = base[0];
                s32 *a = base + 1;
                u32 max = 0;
                s32 i;
                u32 j;
                u16 *src;
                u16 *dst;
                s32 left;

                for (i = 0; i < cnt; i++) {
                    a++;
                    if (max < (u32)*a) {
                        max = *a;
                    }
                    a++;
                }
                o->unk214 = func_8005EAB4(nb * 64 + max * nb * 12, 1, 1);
                o->unk20C = func_8005EAB4(nb * 2, 0, 1);
                o->unk218 = 0xFFFF;
                for (j = 0; j < nb; j++) {
                    if (sk->unk24[j] == j) {
                        o->unk218 = j;
                    }
                }
                *o->unk20C = o->unk218;
                src = o->unk20C;
                dst = src + 1;
                left = nb - 1;
                while (1) {
                    u16 *par;

                    if (left == 0) {
                        break;
                    }
                    par = sk->unk24;
                    for (j = 0; j < nb; j++) {
                        if (j != o->unk218 && *par == *src) {
                            *dst++ = j;
                            left--;
                        }
                        par++;
                    }
                    src++;
                }
                flag = 1;
            }
            an = (Anim_8007EBE4 *)((u8 *)base + 4) + o->unk21E;
            flag2 = 0;
            if (o->unk21A != o->unk21E || flag) {
                s32 n = an->n;
                s32 step = nb * 6;
                s16 *p = (s16 *)((u8 *)base + an->off);
                s16 *k = (s16 *)((u8 *)o->unk214 + nb * 64);
                u32 i;

                for (i = 0; i < nb; i++) {
                    p = func_8007E7A0(p, k, step, n);
                    p = func_8007E7A0(p, k + 1, step, n);
                    p = func_8007E7A0(p, k + 2, step, n);
                    p = func_8007E7A0(p, k + 3, step, n);
                    p = func_8007E7A0(p, k + 4, step, n);
                    p = func_8007E7A0(p, k + 5, step, n);
                    k += 6;
                }
                o->unk21A = o->unk21E;
                flag2 = 1;
            }
            if (o->unk21B != o->unk21C || flag2) {
                Key_8007EBE4 *keys = (Key_8007EBE4 *)((u8 *)o->unk214 + nb * 64);
                M_8007EBE4 *m;
                Key_8007EBE4 *key;
                V3_8007EBE4 v;
                V3_8007EBE4 r;
                V3_8007EBE4 w;
                u16 *ord;
                u32 i;
                f32 sc;

                keys += nb * o->unk21C;
                m = &o->unk214[o->unk218];
                key = &keys[o->unk218];
                func_80022C04(m, key);
                {
                    f32 x, y, z;

                    x = key->pos[0];
                    x *= 0.125f;
                    y = key->pos[1];
                    y *= 0.125f;
                    z = key->pos[2];
                    z *= 0.125f;
                    v.x = x;
                    v.y = y;
                    v.z = z;
                    r.x = x;
                    r.y = y;
                    r.z = z;
                    m->t.x += r.x;
                    m->t.y += r.y;
                    m->t.z += r.z;
                }
                ord = o->unk20C + 1;
                i = 1;
                sc = 0.125f;
                while (1) {
                    u16 b;
                    M_8007EBE4 *par;
                    Key_8007EBE4 *kk;
                    f32 x, y, z;
                    f32 rx, ry, rz;

                    if (i >= nb) {
                        break;
                    }
                    b = *ord++;
                    par = &o->unk214[sk->unk24[b]];
                    m = &o->unk214[b];
                    kk = &keys[b];
                    func_80022C04(m, kk);
                    x = kk->pos[0];
                    x *= sc;
                    y = kk->pos[1];
                    y *= sc;
                    z = kk->pos[2];
                    z *= sc;
                    v.x = x;
                    v.y = y;
                    v.z = z;
                    rx = x * par->m[0][0] + y * par->m[1][0] + z * par->m[2][0] + par->t.x;
                    ry = x * par->m[0][1] + y * par->m[1][1] + z * par->m[2][1] + par->t.y;
                    rz = x * par->m[0][2] + y * par->m[1][2] + z * par->m[2][2] + par->t.z;
                    r.x = rx;
                    r.y = ry;
                    r.z = rz;
                    w.x = rx;
                    w.y = ry;
                    w.z = rz;
                    m->t.x += w.x;
                    m->t.y += w.y;
                    m->t.z += w.z;
                    i++;
                }
                o->unk21B = o->unk21C;
            }
            return o->unk210;
        }
    }
}
