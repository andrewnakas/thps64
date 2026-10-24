#include "common.h"

typedef struct {
    s32 x, y, z;
} V3i_6FD98;

typedef struct {
    f32 x, y, z;
} V3f_6FD98;

typedef struct {
    f32 m[4][4];
} Mtx_6FD98;

typedef struct {
    u8 pad0[4];
    s32 pos[3];
    s16 rot[3];
    u8 pad16[0x3A - 0x16];
    u16 type;
    u8 pad3C[0x84 - 0x3C];
    s32 vel[3];
} Obj_6FD98;

typedef struct {
    u8 pad0[4];
    s32 pos[3];
    u8 pad10[0x84 - 0x10];
    s32 vel[3];
    u8 pad90[0x16C - 0x90];
    s32 prev[3];
    u8 pad178[0x298 - 0x178];
    Obj_6FD98 *unk298;
    u8 pad29C[0x450 - 0x29C];
    s32 unk450;
    u8 pad454[0x82C - 0x454];
    s32 unk82C;
} Sk_6FD98;

u32 func_80047C34(s32 *, s32 *);
void func_80023058(V3f_6FD98 *, Mtx_6FD98 *);
Mtx_6FD98 *func_8009C8EC(Mtx_6FD98 *, Mtx_6FD98 *);
s32 func_8009CCC8(Mtx_6FD98 *, Mtx_6FD98 *);
void func_8005C690(Sk_6FD98 *, s32, s32, s32);
void func_8004C3D8(Sk_6FD98 *);
void func_80039E60(s32, s32, s32);
void func_8004CACC(Sk_6FD98 *, s32, s32, s32, s32);
void func_8005BE00(Sk_6FD98 *);
void func_8007D6E0(void *);
void func_8007D6B8(s16 *);
s32 func_80049D60(s32);
void func_8004D398(Sk_6FD98 *, s32);
void func_8004C4A4(Sk_6FD98 *, s32, s32);
extern s32 D_800DDD40;
extern s32 D_800DE520;
extern s32 D_800DE524;

void func_8006FD98(Obj_6FD98 *o, Sk_6FD98 *sk, s32 arg2, s16 *bb) {
    V3i_6FD98 ia;
    V3i_6FD98 ib;
    Mtx_6FD98 m;
    V3f_6FD98 rot;
    s32 px, py, pz;
    s32 cx, cy, cz;
    s32 x0, x1, y0, y1, z0, z1;
    s32 lim;
    s32 pad;
    s32 iax, iay, iaz, ibx, iby, ibz;
    s32 snd;
    s32 vx, vz, d;

    if (o == sk->unk298) {
        return;
    }
    if (sk->unk450 != 0 && sk->unk82C != 0) {
        return;
    }
    if (func_80047C34(sk->pos, o->pos) >= 500) {
        return;
    }
    px = sk->prev[0] - o->pos[0];
    py = sk->prev[1] - o->pos[1];
    pz = sk->prev[2] - o->pos[2];
    cx = sk->pos[0] - o->pos[0];
    cy = sk->pos[1] - o->pos[1];
    cz = sk->pos[2] - o->pos[2];
    {
        f32 k = 0.001533980831f;
        f32 x = o->rot[0] * k;
        f32 y = o->rot[1] * k;
        f32 z = o->rot[2] * k;
        rot.x = x;
        rot.y = y;
        rot.z = z;
    }
    func_80023058(&rot, &m);
    {
        union {
            Mtx_6FD98 t;
            struct {
                V3f_6FD98 a;
                u8 padA[4];
                V3f_6FD98 ta;
                u8 padB[4];
                V3f_6FD98 b;
                u8 padC[4];
                V3f_6FD98 tb;
            } v;
        } u;
        func_8009C8EC(&u.t, &m);
        func_8009CCC8(&m, &u.t);
        {
            f32 x = px * 0.000244140625f;
            f32 y = py * 0.000244140625f;
            f32 z = pz * 0.000244140625f;
            u.v.a.x = x;
            u.v.a.y = y;
            u.v.a.z = z;
            {
                f32 tx = x * m.m[0][0] + y * m.m[1][0] + z * m.m[2][0] + m.m[3][0];
                f32 ty = x * m.m[0][1] + y * m.m[1][1] + z * m.m[2][1] + m.m[3][1];
                f32 tz = x * m.m[0][2] + y * m.m[1][2] + z * m.m[2][2] + m.m[3][2];
                u.v.ta.x = tx;
                u.v.ta.y = ty;
                u.v.ta.z = tz;
            }
        }
        iax = u.v.ta.x * 4096.0f;
        ia.x = iax;
        iay = u.v.ta.y * 4096.0f;
        ia.y = iay;
        iaz = u.v.ta.z * 4096.0f;
        ia.z = iaz;
        {
            f32 x = cx * 0.000244140625f;
            f32 y = cy * 0.000244140625f;
            f32 z = cz * 0.000244140625f;
            u.v.b.x = x;
            u.v.b.y = y;
            u.v.b.z = z;
            {
                f32 tx = x * m.m[0][0] + y * m.m[1][0] + z * m.m[2][0] + m.m[3][0];
                f32 ty = x * m.m[0][1] + y * m.m[1][1] + z * m.m[2][1] + m.m[3][1];
                f32 tz = x * m.m[0][2] + y * m.m[1][2] + z * m.m[2][2] + m.m[3][2];
                u.v.tb.x = tx;
                u.v.tb.y = ty;
                u.v.tb.z = tz;
            }
        }
        ibx = u.v.tb.x * 4096.0f;
        ib.x = ibx;
        iby = u.v.tb.y * 4096.0f;
        ib.y = iby;
        ibz = u.v.tb.z * 4096.0f;
        ib.z = ibz;

    x0 = iax;
    x1 = ibx;
    if (x1 < x0) {
        x0 = ibx;
        x1 = iax;
    }
    x0 -= 0x14000;
    pad = 0x14000;
    x1 += pad;
    y0 = iay;
    y1 = iby;
    if (y1 < y0) {
        y0 = iby;
        y1 = iay;
    }
    y0 -= pad;
    y1 += pad;
    z0 = iaz;
    z1 = ibz;
    if (z1 < z0) {
        z0 = ibz;
        z1 = iaz;
    }
    z0 -= pad;
    z1 += pad;
    if (x1 < bb[1] << 12) {
        return;
    }
    if (bb[0] << 12 < x0) {
        return;
    }
    if (z1 < bb[5] << 12) {
        return;
    }
    if (bb[4] << 12 < z0) {
        return;
    }
    if (y1 < bb[3] << 12) {
        return;
    }
    if (bb[2] << 12 < y0) {
        return;
    }

    lim = 0;
    if (o->type == 0xD7) {
        lim = 0x46000;
    } else if (o->type == 0xD8) {
        lim = 0x64000;
    }
    if (sk->unk450 == 0) {
        s32 f = sk->unk82C;
        if (f == 1 && lim < o->pos[1] - sk->pos[1]) {
            sk->vel[0] >>= 1;
            sk->vel[1] >>= 1;
            sk->vel[2] >>= 1;
            sk->vel[1] += -0x1E000;
            func_8005C690(sk, 8, 1, 0x96);
            func_8004C3D8(sk);
            func_80039E60(0x28, 0x2710, 0);
            func_8004CACC(sk, 0x4E, D_800DDD40, -0x3E8, 0);
            sk->unk298 = o;
            if (D_800DE520 < 200) {
                s16 v[3];
                func_8005BE00(sk);
                func_8007D6E0((u8 *)sk + 0x10);
                {
                    s16 vx = 0x1C2;
                    s16 vy = 0x384;
                    v[0] = vx;
                    v[1] = vy;
                    v[2] = 0;
                }
                func_8007D6B8(v);
                D_800DE524 = f;
            }
            return;
        }
    }

    switch (func_80049D60(0x10) >> 3) {
        case 0:
            vx = o->vel[0];
            vz = o->vel[2];
            if (__builtin_abs(vx) > __builtin_abs(vz)) {
                vx += vx >> 1;
                d = func_80049D60(vx >> 1) + (vx >> 2);
                if (func_80049D60(0x10) >> 3) {
                    d = -d;
                }
                vz += d;
            } else {
                vz += vz >> 1;
                d = func_80049D60(vz >> 1) + (vz >> 2);
                if (func_80049D60(0x10) >> 3) {
                    d = -d;
                }
                vx += d;
            }
            sk->vel[0] = vx;
            sk->vel[1] = o->vel[1] + -0x16800;
            sk->vel[2] = vz;
            break;
        case 1:
            sk->vel[0] = -o->vel[0] >> 2;
            sk->vel[1] = -0x2D000;
            sk->vel[2] = -o->vel[2] >> 2;
            break;
    }
    sk->unk298 = o;
    func_8004D398(sk, 1);
    func_8004C4A4(sk, 1, 100);
    func_8005C690(sk, 0xC, 1, 0xFF);
    func_8004C3D8(sk);
    func_80039E60(0x72, 0x2710, 0);
    switch (o->type) {
        case 0xD5:
            snd = func_80049D60(4) + 0x73;
            break;
        case 0xD6:
            snd = func_80049D60(4) + 0x7D;
            break;
        case 0xD7:
            snd = 0x83;
            break;
        case 0xD8:
            snd = 0x78;
            break;
        default:
            return;
    }
    func_80039E60(snd, 0x2710, 0);
    }
}
