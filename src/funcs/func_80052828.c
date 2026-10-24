/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-O0 */
#include "common.h"

typedef struct {
    s32 x, y, z;
} V3_52828;

typedef struct {
    s16 x, y, z, w;
} N_52828;

typedef struct {
    s16 x, y, z;
} S3_52828;

typedef struct {
    u32 w0;
    u8 pad4[8];
    union {
        u32 w;
        u16 h;
        u8 b;
    } fC;
} F_52828;

typedef struct {
    u8 pad0[0x1B];
    u8 unk1B;
} H_52828;

typedef struct {
    V3_52828 start;
    V3_52828 end;
    u8 pad18[0x40 - 0x18];
    s32 unk40;
    u8 pad44[0x68 - 0x44];
    H_52828 *hit;
    V3_52828 pos;
    N_52828 n;
    F_52828 *face;
    u8 pad84[0x100 - 0x84];
} R_52828;

typedef struct {
    u8 pad0[0x1C];
    s32 unk1C;
    u8 pad20[0x48 - 0x20];
} T_52828;

s32 func_80022964(void *);
s32 func_80022E14(s32, s32);
s32 func_80022E54(void *, void *);
s32 func_800233B8(s32);
void func_80024B88(void *, s32, s32, s32);
void func_80024B98(void *, s32, s32, s32);
void func_80024BA8(void *);
void func_80042C70(void);
void func_80043264(void *);
void func_8004356C(void *);
void func_80043590(void *);
void func_80046DAC(void *, void *, s32 *);
void func_80046E04(void *, void *, s32 *);
void func_80046F58(void *, void *, s32 *);
void func_80046FBC(void *, void *, void *);
void func_80047014(void *, void *, void *);
s32 func_8004706C(void *, void *);
void func_80047288(void *, void *);
void func_800472C0(void *, void *);
s32 func_800474C8(void *);
void func_8004A204(u8 *, s32, s32, s32, s32);
void func_8004BD2C(u8 *);
void func_8004C3D8(u8 *);
void func_8004C9E8(u8 *);
void func_8004D048(u8 *, s32, s32);
void func_8004D2D4(u8 *);
void func_8004D5B0(void *, void *, void *);
void func_8004EBFC(u8 *, N_52828);
s32 func_800523A0(u8 *, s32);
void func_80058594(u8 *, s32, s32, s32);
void func_80058804(u8 *, N_52828, s32);
void func_80058A94(u8 *, s32);
void func_800598B8(u8 *);
void func_8005BE00(u8 *);
void func_8005BE8C(u8 *);
void func_8005BED8(u8 *);
void func_8005CCD8(R_52828 *, s32);
void func_8005DF8C(R_52828 *, s32);
void func_800654C8(void);
void func_8007D68C(s32, s32, s32);
void func_8007D6A4(s32);
void func_8007D6B8(void *);
void func_8007D6E0(void *);
void func_800B36D8(s32, f32, f32);
extern u8 D_800D6188[];
extern s32 D_800D71F4;
extern s32 D_800D71F8;
extern s32 D_800D71FC;
extern s32 D_800D7200;
extern s32 D_800D7204;
extern T_52828 D_800DAF98[];
extern s32 D_800DC618;
extern s32 D_800DC6D8;
extern s32 D_800DE520;
extern s32 D_800DE524;
extern s32 D_800DE7A0;
extern s32 D_800DE994;
extern s32 D_800DE99C;
extern s32 D_800DE9A0;
extern s32 D_800DE9C4;
typedef struct {
    u8 pad0[0x980];
    s32 f980[2];
    s32 f988[2];
} G9F4_52828;
extern G9F4_52828 D_800DE9F4;
extern f32 D_800F5668;

#define I32(o) (*(s32 *)(c + (o)))
#define S16(o) (*(s16 *)(c + (o)))
#define U16(o) (*(u16 *)(c + (o)))
#define U8(o) (*(u8 *)(c + (o)))
#define V3(o) (*(V3_52828 *)(c + (o)))
#define PAD(o) ((*(u8 **)(c + 0x964))[o])

#define SETN_52828(d, nn)        \
    {                            \
        s32 nx_ = (nn).x;        \
        s32 ny_ = (nn).y;        \
        s32 nz_ = (nn).z;        \
                                 \
        (d).x = nx_;             \
        (d).y = ny_;             \
        (d).z = nz_;             \
    }

#define SETN3_52828(d0, d1, d2, nn) \
    {                               \
        s32 nx_ = (nn).x;           \
        s32 ny_ = (nn).y;           \
        s32 nz_ = (nn).z;           \
                                    \
        d0 = nx_;                   \
        d1 = ny_;                   \
        d2 = nz_;                   \
    }

#define FLAGS_52828(q)                                         \
    {                                                          \
        D_800D71F4 = (q).face->fC.h & 0x40;                    \
        D_800D71F8 = ((q).face->fC.b ^ 1) & 1;                 \
        D_800D71FC = (((q).face->fC.w >> 23) ^ 1) & 1;         \
        D_800D7200 = (q).face->w0 & 0x80;                      \
        D_800D7204 = ((q).face->fC.h & 0x1E00) >> 9;           \
    }

static inline void pre_52828(u8 *c, s32 len) {
    S3_52828 s;
    s32 k;
    s32 k2;

    V3_52828 t1B8;
    V3_52828 t1C8;
    V3_52828 t1D8;
    V3_52828 t1E8;
    V3_52828 t1F8;
    V3_52828 t208;
    s32 i1;
    s32 i2;
    s32 i3;
    V3_52828 *p1B8;
    V3_52828 *p1C8;
    V3_52828 *p1D8;
    V3_52828 *p1E8;
    V3_52828 *p1F8;
    V3_52828 *p208;

    if ((I32(0x824) == 5 || I32(0x824) == 6 || I32(0x824) == 3) && D_800DE520 < 200) {
        func_8005BE00(c);
        func_8007D6E0(c + 0x10);
        k = 0x200;
        k2 = 0x1000;
        goto L0;
    L0:
        s.x = k;
        s.y = k2;
        s.z = 0;
        func_8007D6B8(&s);
        func_8007D6A4(1);
        if (len > 0x10000) {
            u8 *p = c + 0x22D0;

            func_80024BA8(p);
            switch (I32(0x824)) {
            case 5:
                func_8007D68C(2, 0xA0, 0x20);
                func_80024B98(p, 2, 0xA0, 0x20);
                break;
            case 6:
                func_8007D68C(0xA0, 0xA0, 0xA0);
                func_80024B98(p, 0xA0, 0xA0, 0xA0);
                break;
            case 3:
                func_8007D68C(0x80, 0x40, 0x20);
                func_80024B98(p, 0x80, 0x40, 0x20);
                break;
            }
            func_80024B88(p, 0, 0, 0);
            D_800DE524 = 1;
        }
    }
    if (len > 0x10000) {
        switch (I32(0x824)) {
        case 0:
        case 1:
        case 2:
        case 4:
            break;
        case 5: {
                f32 f = D_800F5668 * 8.0f;
                s32 idx = I32(0x968);

                if (D_800DE7A0 == 7) {
                    idx ^= D_800DE9C4;
                }
                if (D_800DE9F4.f988[idx] != 0 && D_800DC618 != 2 && D_800DC6D8 != 2) {
                    func_800B36D8(idx, f, 0.5f);
                }
                break;
            }
        case 6: {
                f32 f = D_800F5668 * 8.0f;
                s32 idx = I32(0x968);

                if (D_800DE7A0 == 7) {
                    idx ^= D_800DE9C4;
                }
                if (D_800DE9F4.f988[idx] != 0 && D_800DC618 != 2 && D_800DC6D8 != 2) {
                    func_800B36D8(idx, f, 0.3f);
                }
                break;
            }
        case 3: {
                f32 f = D_800F5668 * 8.0f;
                s32 idx = I32(0x968);

                if (D_800DE7A0 == 7) {
                    idx ^= D_800DE9C4;
                }
                if (D_800DE9F4.f988[idx] != 0 && D_800DC618 != 2 && D_800DC6D8 != 2) {
                    func_800B36D8(idx, f, 0.6f);
                }
                break;
            }
        }
    }
    p1B8 = &t1B8;
    p1C8 = &t1C8;
    p1D8 = &t1D8;
    goto L1;
L1:
    func_80046F58(p1D8, c + 0x84, &D_800DE99C);
    i1 = 8;
    func_80046DAC(p1C8, p1D8, &i1);
    p1E8 = &t1E8;
    p1F8 = &t1F8;
    p208 = &t208;
    goto L2;
L2:
    func_80046F58(p208, c + 0x9C, &D_800DE9A0);
    i2 = 8;
    func_80046DAC(p1F8, p208, &i2);
    i3 = 2;
    func_80046E04(p1E8, p1F8, &i3);
    func_80047014(p1B8, p1C8, p1E8);
    func_800472C0(c + 4, p1B8);
}

static inline V3_52828 *sub_52828(void *a, void *b) {
    V3_52828 r;

    func_80046FBC(&r, a, b);
    return &r;
}

static inline void proj_52828(V3_52828 *v, N_52828 n) {
    V3_52828 t;
    s32 d;

    {
        s32 nx = n.x;
        s32 ny = n.y;
        s32 nz = n.z;

        t.x = nx;
        t.y = ny;
        t.z = nz;
    }
    d = func_80022E54(v, &t);
    v->x -= func_80022E14(d, n.x);
    v->y -= func_80022E14(d, n.y);
    v->z -= func_80022E14(d, n.z);
}

static inline void proj8D0_52828(u8 *c, N_52828 n) {
    V3_52828 t;
    s32 d;

    SETN_52828(t, n);
    d = func_80022E54(c + 0x8D0, &t);
    I32(0x8D0) -= func_80022E14(d, n.x);
    I32(0x8D4) -= func_80022E14(d, n.y);
    I32(0x8D8) -= func_80022E14(d, n.z);
}

static inline void call58804_52828(N_52828 n, u8 *c, s32 k) {
    func_80058804(c, n, k);
}

static inline void callEBFC_52828(N_52828 n, u8 *c) {
    func_8004EBFC(c, n);
}

static inline void stick_52828(N_52828 n, u8 *c, s32 len) {
    I32(0x84) -= func_80022E14(n.x, len / 4);
    I32(0x8C) -= func_80022E14(n.z, len / 4);
}

static inline void land_52828(u8 *c) {
    func_8004D048(c, 1, 0x1037);
    func_8004C9E8(c);
    I32(0x420) = 0;
    I32(0x424) = 0;
    I32(0x454) = 0;
    I32(0x838) = 1;
    if (I32(0x450) == 0) {
        I32(0x228) = 0x10000;
        if (I32(0x834) != 0) {
            func_8004D2D4(c);
            func_8004A204(c, 0x1A, 0, -1, -1);
        } else {
            func_8004D2D4(c);
            func_8004A204(c, 0x1B, 0, -1, -1);
        }
    }
}

void func_80052828(u8 *c) {
    u8 pad18[0x30];
    V3_52828 v48;
    V3_52828 v58;
    u8 pad64[0x38];
    R_52828 q;
    V3_52828 v1A0;
    V3_52828 *p48;
    V3_52828 *p48a;
    s32 gnd;
    s32 fpv;
    s32 len;
    s32 r;
    s32 k;

    gnd = I32(0x82C) == 2;
    if (D_800DE7A0 != 7) {
        fpv = D_800DE9F4.f980[I32(0x968)];
    } else {
        fpv = D_800DE9F4.f980[I32(0x968) ^ D_800DE9C4];
    }
    {
        s32 x_ = 0;
        s32 y_ = 0x1964;
        s32 z_ = 0;

        v1A0.x = x_;
        v1A0.y = y_;
        v1A0.z = z_;
    }
    if (I32(0x82C) == 0) {
        I32(0x81C) = 0;
    }
    len = func_800233B8(func_80022E54(c + 0x84, c + 0x84)) << 6;
    { pre_52828(c, len); }
    func_800654C8();
    if (!gnd && I32(0x450) == 0) {
        func_8004BD2C(c);
    }
    { *(p48a = &v48) = *sub_52828(c + 4, c + 0x16C); }
    func_800233B8(func_80022E54(p48a, &v48));
    r = I32(0x930) >> 12;
    I32(0x900) = 0;
    {
        s32 t;

        if (I32(0x818) == 0 && I32(0x41C) == 0 && (t = I32(0x2F4)) != 0 && I32(0x37C) == 0) {
            if (r == 0) {
                func_80058A94(c, 40);
            } else if (PAD(0x10) != 0 || PAD(0x20) != 0) {
                I32(0x2F4) = t - 1;
            } else {
                I32(0x2F4) = t - 3;
                if (I32(0x2F4) < 0) {
                    I32(0x2F4) = 0;
                }
            }
            r += I32(0x900);
        } else {
            I32(0x2F4) = 0;
        }
    }
    func_80022E14(r, 0xC00);
    func_80058594(c, (r * D_800DE99C) >> 8, gnd ^ 1, 0);
    {
        s32 t = I32(0x420) + ((r * D_800DE99C) >> 8);

        I32(0x420) = t;
        if (t >= 0x800) {
            I32(0x420) = t - 0x800;
            if (I32(0x380) == 0) {
                I32(0x424)++;
            }
        }
    }
    if (I32(0x420) < -0x7FF) {
        I32(0x420) += 0x800;
        if (I32(0x380) == 0) {
            I32(0x424)++;
        }
    }
    {
        s32 x1 = V3(0x16C).x;
        s32 y1 = V3(0x16C).y;
        s32 z1 = V3(0x16C).z;

        q.start.x = x1;
        q.start.y = y1;
        q.start.z = z1;
    }
    {
        s32 x2 = V3(0x4).x;
        s32 y2 = V3(0x4).y;
        s32 z2 = V3(0x4).z;

        q.end.x = x2;
        q.end.y = y2;
        q.end.z = z2;
    }
    { *(p48 = &v48) = *sub_52828(c + 4, c + 0x16C); }
    if (func_8004706C(p48, D_800D6188) == 0) {
        goto after;
    }
    len = func_800233B8(func_80022E54(p48, &v48)) << 6;
    if (I32(0x450) != 0 ? len <= 0x63FFF : len <= 0x1DFFF) {
        if (len < 0x800) {
            len = 0x800;
        }
        q.end.x = V3(0x16C).x + ((v48.x * (I32(0x450) != 0 ? 100 : 30) / len) << 12);
        q.end.y = V3(0x16C).y + ((v48.y * (I32(0x450) != 0 ? 100 : 30) / len) << 12);
        q.end.z = V3(0x16C).z + ((v48.z * (I32(0x450) != 0 ? 100 : 30) / len) << 12);
    }
    func_8005CCD8(&q, 0);
    func_8005DF8C(&q, 1);
    if (q.hit == NULL) {
        goto after;
    }
    FLAGS_52828(q);
    if (D_800D71F8 == 0 && D_800D71FC == 0 && D_800D71F4 == 0) {
        V3(0x4) = V3(0x16C);
        k = 0;
        if (U16(0x21E) != 0xC && I32(0x450) == 0 && I32(0x460) == 0) {
            V3_52828 t;

            SETN_52828(t, q.n);
            if (func_80022E54(&t, c + 0x8D0) >= 0xB51) {
                I32(0x228) = 0x10000;
                func_8004D2D4(c);
                func_8004A204(c, 0xC, 0, -1, -1);
                k = 200;
                func_8004C3D8(c);
            }
        }
        { call58804_52828(q.n, c, k); }
        goto after;
    }
    if (q.hit == NULL) {
        goto after;
    }
    if (D_800D71F4 != 0 && D_800D7200 == 0) {
        goto after;
    }
    {
        V3_52828 t;
        u8 *p8E8;

        SETN_52828(t, q.n);
        p8E8 = c + 0x8E8;
        {
            s32 d = func_80022E54(&t, p8E8);

            if (d > -0x800 && d < 0x800) {
                s32 ny = -q.n.y;
                s32 x = q.n.x;
                s32 ax = __builtin_abs(x);
                s32 az;

                if (ax < ny) {
                    az = q.n.z;
                    if (az < 0) {
                        az = -az;
                    }
                    if (az < ny) {
                        I32(0x4) = q.pos.x + q.n.x * 30;
                        I32(0x8) = q.pos.y + q.n.y * 30;
                        I32(0xC) = q.pos.z + q.n.z * 30;
                        I32(0x918) = 0;
                        SETN3_52828(S16(0x100), S16(0x102), S16(0x104), q.n);
                        func_800598B8(c);
                        if (I32(0x82C) == 2) {
                            u8 *p8D0;

                            SETN3_52828(S16(0x100), S16(0x102), S16(0x104), q.n);
                            SETN3_52828(I32(0x91C), I32(0x920), I32(0x924), q.n);
                            I32(0x918) = 0x19;
                            p8D0 = c + 0x8D0;
                            { proj8D0_52828(c, q.n); }
                            func_80022964(p8D0);
                            SETN3_52828(I32(0x8E8), I32(0x8EC), I32(0x8F0), q.n);
                            func_80043590(p8D0);
                            func_8004356C(p8E8);
                            func_80042C70();
                            func_80043264(c + 0x8DC);
                            func_8005BE8C(c);
                        }
                        func_8004D048(c, 0, 0x1230);
                        goto after;
                    }
                }
                V3(0x4) = V3(0x16C);
                {
                    V3_52828 u;

                    u = V3(0x84);
                    k = 0;
                    if (U16(0x21E) != 0xC && func_800474C8(&u) >= 7 && I32(0x450) == 0 && I32(0x460) == 0) {
                        V3_52828 w;

                        SETN_52828(w, q.n);
                        if (func_80022E54(&w, c + 0x8D0) >= 0xB51) {
                            I32(0x228) = 0x10000;
                            func_8004D2D4(c);
                            func_8004A204(c, 0xC, 0, -1, -1);
                            func_8004C3D8(c);
                            k = 200;
                        }
                    }
                    { call58804_52828(q.n, c, k); }
                }
                I32(0x90C) = 0;
                I32(0x910) = 0;
                I32(0x914) = 0;
                goto after;
            }
        }
    }
    if ((len >> 12) >= q.unk40) {
        I32(0x4) = q.pos.x + q.n.x * 30;
        I32(0x8) = q.pos.y + q.n.y * 30;
        I32(0xC) = q.pos.z + q.n.z * 30;
        if (*(s32 *)&q.n.x == I32(0x100) && q.n.z == S16(0x104)) {
            I32(0x918)++;
        } else {
            I32(0x918) = 0;
            SETN3_52828(S16(0x100), S16(0x102), S16(0x104), q.n);
        }
        func_800598B8(c);
    }
after:
    len = func_800233B8(func_80022E54(c + 0x84, c + 0x84)) << 6;
    if (I32(0x42C) < len) {
        I32(0x3FC) = 1;
    } else {
        I32(0x3FC) = 0;
    }
    {
        V3_52828 save;

        save = V3(0x4);
        if (func_800523A0(c, -1) != 0) {
            if (func_800523A0(c, 1) != 0) {
                V3(0x4) = save;
            }
        } else if (func_800523A0(c, 1) != 0) {
            if (func_800523A0(c, -1) != 0) {
                V3(0x4) = save;
            }
        }
        func_8005BED8(c);
        {
            s32 x = I32(0x4) + I32(0x8E8) * 70;
            s32 y;
            s32 z;

            q.start.x = x;
            y = I32(0x8) + I32(0x8EC) * 70;
            q.start.y = y;
            z = I32(0xC) + I32(0x8F0) * 70;
            q.start.z = z;
            q.end.x = x - (I32(0x8E8) << 8);
            q.end.y = y - (I32(0x8EC) << 8);
            q.end.z = z - (I32(0x8F0) << 8);
        }
        func_8005CCD8(&q, 0);
        func_8005DF8C(&q, 1);
        if (q.hit == NULL) {
            goto nohit;
        }
        FLAGS_52828(q);
        I32(0x824) = D_800D7204;
        if (q.hit == NULL) {
            goto nohit;
        }
        if (D_800D71F8 == 0 && D_800D71FC == 0 && D_800D71F4 == 0) {
            func_8004D048(c, 1, 0x12DA);
            goto tail;
        }
        if (q.hit == NULL) {
            goto nohit;
        }
        {
            s32 lim;
            s32 h = q.unk40;

            if (I32(0x82C) == 2) {
                I32(0x30C) = 20;
                lim = 0xA0;
            } else {
                lim = I32(0x30C) + 0x74;
            }
            if (lim < h) {
                goto far;
            }
        }
        I32(0x860) = q.face->fC.h & 0x20;
        {
            V3_52828 save;

            save = V3(0x4);
            I32(0x4) = q.pos.x + I32(0x8E8) * 30;
            I32(0x8) = q.pos.y + I32(0x8EC) * 30;
            I32(0xC) = q.pos.z + I32(0x8F0) * 30;
            {
                V3_52828 dv;

                func_80046FBC(&dv, &save, c + 4);
                if (func_80022E54(&dv, &dv) < 0x1000) {
                    V3(0x4) = save;
                }
                if (D_800D71F4 != 0) {
                    if (D_800D7200 == 0 && I32(0x2F0) != 0 && D_800DE994 - I32(0x2F0) >= 5 && I32(0x450) == 0) {
                        if (I32(0x82C) == 2) {
                            goto skid;
                        }
                        { stick_52828(q.n, c, len); }
                        I32(0x88) /= 2;
                        if (I32(0x82C) == 0) {
                            I32(0x424) = 0;
                            I32(0x420) = 0;
                        }
                        func_8004D048(c, 1, 0x1342);
                        func_8004C9E8(c);
                        I32(0x860) = 0;
                        I32(0x228) = 0x10000;
                        func_8004D2D4(c);
                        func_8004A204(c, 0xE, 0, -1, -1);
                        I32(0x838) = 1;
                    } else {
                        if (I32(0x82C) != 2) {
                            if (I32(0x838) == 0 && I32(0x450) == 0) {
                                I32(0x228) = 0x10000;
                                func_8004D2D4(c);
                                func_8004A204(c, 0xE, 0, -1, -1);
                                I32(0x838) = 1;
                            }
                            if (I32(0x82C) != 2) {
                                func_8004C9E8(c);
                                I32(0x420) = 0;
                                I32(0x424) = 0;
                            }
                        }
                    skid:
                        func_8004D048(c, 2, 0x1358);
                    }
                } else if (D_800D71F8 != 0) {
                    if (I32(0x82C) != 0) {
                        { callEBFC_52828(q.n, c); }
                    }
                    if (I32(0x82C) == 0) {
                        V3_52828 a;
                        V3_52828 b;
                        s32 d;

                        SETN_52828(a, q.n);
                        {
                            s32 bx = S16(0x100);
                            s32 by = S16(0x102);
                            s32 bz = S16(0x104);

                            b.x = bx;
                            b.y = by;
                            b.z = bz;
                        }
                        d = func_80022E54(&b, &a);
                        if (func_80022E54(c + 0x8D0, &a) < 0 && I32(0x88) <= 0 && d > 0 && d < 3000) {
                            if (I32(0x82C) == 2) {
                                func_8004D048(c, 1, 0x1031);
                            } else {
                                land_52828(c);
                            }
                        }
                    } else {
                        func_8004D048(c, 0, 0x1399);
                    }
                    if (!gnd) {
                        I32(0x510) = (s32)q.hit;
                        I32(0x514) = D_800DAF98[q.hit->unk1B].unk1C;
                    }
                } else if (I32(0x82C) == 2) {
                    func_8004D048(c, 1, 0x1031);
                } else {
                    land_52828(c);
                }
            }
        }
        if (I32(0x82C) == 1) {
            goto nohit2;
        }
        if (*(s32 *)&q.n.x == I32(0x100) && q.n.z == S16(0x104)) {
            I32(0x918)++;
        } else {
            I32(0x918) = 0;
            SETN3_52828(S16(0x100), S16(0x102), S16(0x104), q.n);
        }
        func_800598B8(c);
        goto tail;
    far:
        I32(0x860) = q.face->fC.h & 0x20;
        if (I32(0x82C) == 2) {
            func_8004D048(c, 1, 0x1031);
        } else {
            land_52828(c);
        }
        goto tail;
    nohit:
        if (I32(0x82C) == 2) {
            func_8004D048(c, 1, 0x1031);
        } else {
            land_52828(c);
        }
    tail:
        if (I32(0x82C) != 1 && q.hit != NULL) {
            if (I32(0x82C) == 2) {
                v58 = V3(0x2C0);
            } else {
                s32 x_ = 0;
                s32 y_ = 0x1964;
                s32 z_ = 0;

                v58.x = x_;
                v58.y = y_;
                v58.z = z_;
            }
            { proj_52828(&v58, q.n); }
            func_800472C0(c + 0x9C, &v58);
            if (I32(0x82C) != 2) {
                V3(0x8F4) = v58;
            }
            *(N_52828 *)(c + 0x904) = q.n;
            func_8004D5B0(c + 0x84, &q.n, c + 0x84);
        } else {
        nohit2:
            func_800472C0(c + 0x9C, &v1A0);
        }
        if (I32(0x82C) != 2 && I32(0x450) == 0) {
            V3_52828 a;
            V3_52828 b;
            s32 d;

            d = func_80022E54(c + 0x84, c + 0x8DC);
            a.x = func_80022E14(d, I32(0x8DC));
            a.y = func_80022E14(d, I32(0x8E0));
            a.z = func_80022E14(d, I32(0x8E4));
            func_80047288(c + 0x84, &a);
            d = func_80022E54(c + 0x84, c + 0x8D0);
            b.x = func_80022E14(d, I32(0x8D0));
            b.y = func_80022E14(d, I32(0x8D4));
            b.z = func_80022E14(d, I32(0x8D8));
            if (I32(0x3FC) == 0) {
                if (fpv != 0) {
                    I32(0x9C) -= func_80022E14(8, b.x);
                    I32(0xA0) -= func_80022E14(8, b.y);
                    I32(0xA4) -= func_80022E14(8, b.z);
                }
            } else {
                I32(0x9C) -= func_80022E14(0x52, b.x);
                I32(0xA0) -= func_80022E14(0x52, b.y);
                I32(0xA4) -= func_80022E14(0x52, b.z);
            }
            if (I32(0x824) == 5) {
                I32(0x9C) -= func_80022E14(0x78, b.x);
                I32(0xA0) -= func_80022E14(0x78, b.y);
                I32(0xA4) -= func_80022E14(0x78, b.z);
            }
            if (I32(0x824) == 6) {
                I32(0x9C) -= func_80022E14(0x78, b.x);
                I32(0xA0) -= func_80022E14(0x78, b.y);
                I32(0xA4) -= func_80022E14(0x78, b.z);
            }
            if (I32(0x824) == 3) {
                I32(0x9C) -= func_80022E14(0xB4, b.x);
                I32(0xA0) -= func_80022E14(0xB4, b.y);
                I32(0xA4) -= func_80022E14(0xB4, b.z);
            }
        }
    }
}
