/* cflags: -Wa,-no-m4100 -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 x, y, z;
} V3_800543F8;

typedef struct {
    s16 x, y, z, w;
} N_800543F8;

typedef struct {
    u32 w0;
    u8 pad4[8];
    union {
        u32 w;
        u16 h;
        u8 b;
    } fC;
} F_800543F8;

typedef struct {
    V3_800543F8 start;
    V3_800543F8 end;
    u8 pad18[0x40 - 0x18];
    s32 unk40;
    u8 pad44[0x68 - 0x44];
    u8 *hit;
    V3_800543F8 pos;
    N_800543F8 n;
    F_800543F8 *face;
    u8 pad84[0x100 - 0x84];
} R_800543F8;

typedef struct {
    u8 pad0[0x1C];
    s32 unk1C;
    u8 pad20[0x48 - 0x20];
} T_800543F8;

s32 func_80022964(void *);
s32 func_80022E14(s32, s32);
s32 func_80022E54(void *, void *);
s32 func_800233B8(s32);
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
void func_800472C0(void *, void *);
void func_8004A204(u8 *, s32, s32, s32, s32);
void func_8004C3D8(u8 *);
void func_8004C9E8(u8 *);
void func_8004D048(u8 *, s32, s32);
s32 func_8004D2D4(u8 *);
void func_8004D5B0(void *, void *, void *);
void func_80058594(u8 *, s32, s32, s32);
void func_80058804(u8 *, N_800543F8, s32);
void func_80058A94(u8 *, s32);
void func_800598B8(u8 *);
void func_8005BE8C(u8 *);
void func_8005BED8(u8 *);
void func_8005CCD8(R_800543F8 *, s32);
void func_8005DF8C(R_800543F8 *, s32);
extern u8 D_800D6188[];
extern s32 D_800D71F4;
extern s32 D_800D71F8;
extern s32 D_800D71FC;
extern s32 D_800D7200;
extern s32 D_800D7204;
extern T_800543F8 D_800DAF98[];
extern s32 D_800DE994;
extern s32 D_800DE99C;
extern s32 D_800DE9A0;

void func_800654C8(void);
void func_800230FC(void *, void *);
void func_800226A0(void *, void *, void *);
void func_80022598(void *, void *);
void func_80022FCC(void *, void *);
s32 func_800470A8(void *, void *);
void func_80058D54(u8 *);
void func_8004D398(u8 *, s32);
void func_800696B0(s32, u8 *);
void func_8004BD2C(u8 *);
void func_80039E60(s32, s32, s32);
s32 func_80049D60(s32);
void func_8004EBFC(u8 *, N_800543F8);
void func_8005427C(u8 *, N_800543F8);
extern s32 D_800D7240;
extern s32 D_800C0E20;
extern u8 D_800D6FCC[];
typedef struct {
    u8 pad0[0x18];
    s32 unk18;
    u8 pad1C[0x2C - 0x1C];
} M_800543F8;
extern M_800543F8 D_800D63F8[];

#define I32(o) (*(s32 *)(c + (o)))
#define U32(o) (*(u32 *)(c + (o)))
#define S16(o) (*(s16 *)(c + (o)))
#define U16(o) (*(u16 *)(c + (o)))
#define U8(o) (*(u8 *)(c + (o)))
#define S8(o) (*(s8 *)(c + (o)))
#define V3(o) (*(V3_800543F8 *)(c + (o)))

#define COPYN(d0, d1, d2, cast) \
    { \
        s32 nx = QN.x; \
        s32 ny = QN.y; \
        s32 nz = QN.z; \
        d0 = cast nx; \
        d1 = cast ny; \
        d2 = cast nz; \
    }

#define FLAGS_800543F8()                                       \
    {                                                          \
        D_800D71F4 = q.face->fC.h & 0x40;                      \
        D_800D71F8 = (q.face->fC.b ^ 1) & 1;                   \
        D_800D71FC = ((q.face->fC.w >> 23) ^ 1) & 1;           \
        D_800D7200 = q.face->w0 & 0x80;                        \
        D_800D7204 = (q.face->fC.h & 0x1E00) >> 9;             \
    }

static inline void callEBFC_800543F8(N_800543F8 n, u8 *c) {
    func_8004EBFC(c, n);
}

static inline void call427C_800543F8(N_800543F8 n, u8 *c) {
    func_8005427C(c, n);
}

static inline void call58804_800543F8(N_800543F8 n, u8 *c) {
    func_80058804(c, n, 0);
}

static inline void step_800543F8(u8 *c, s32 *m, s16 *g) {
    V3_800543F8 t1B0;
    V3_800543F8 t1C0;
    V3_800543F8 t1D0;
    V3_800543F8 t1E0;
    V3_800543F8 t1F0;
    V3_800543F8 t200;
    s32 i1;
    s32 i2;
    s32 i3;
    V3_800543F8 *p1B0;
    V3_800543F8 *p1C0;
    V3_800543F8 *p1D0;
    V3_800543F8 *p1E0;
    V3_800543F8 *p1F0;
    V3_800543F8 *p200;
    s32 *pk;

    p1B0 = &t1B0;
    p1C0 = &t1C0;
    p1D0 = &t1D0;
    goto L1;
L1:
    pk = &D_800DE99C;
    func_80046F58(p1D0, c + 0x84, pk);
    i1 = 8;
    func_80046DAC(p1C0, p1D0, &i1);
    p1E0 = &t1E0;
    p1F0 = &t1F0;
    p200 = &t200;
    goto L2;
L2:
    pk = &D_800DE9A0;
    func_80046F58(p200, c + 0x9C, pk);
    i2 = 8;
    func_80046DAC(p1F0, p200, &i2);
    i3 = 2;
    func_80046E04(p1E0, p1F0, &i3);
    func_80047014(p1B0, p1C0, p1E0);
    func_800472C0(c + 4, p1B0);
    func_800654C8();
    if (I32(0x92C) != 0) {
        u8 *p884 = c + 0x884;
        s32 *pm;
        s32 k;

        t1B0.z = 0;
        t1B0.y = 0;
        t1B0.x = 0;
        func_800230FC(p884, p1B0);
        pm = m;
        goto L3;
    L3:
        func_800230FC(pm, p1B0);
        t1C0.x = 0;
        k = 0x46000;
        goto L4;
    L4:
        t1C0.y = k;
        t1C0.z = 0;
        func_800226A0(p884, p1C0, p1D0);
        g[2] = 0;
        g[1] = 0;
        g[0] = U16(0x92E) & 0xFFF;
        func_80022598(g, pm);
        func_80022FCC(p884, pm);
        func_800226A0(p884, p1C0, p1E0);
        I32(0x4) = I32(0x4) + t1D0.x - t1E0.x;
        I32(0x8) = I32(0x8) + t1D0.y - t1E0.y;
        I32(0xC) = I32(0xC) + t1D0.z - t1E0.z;
    }
}

static inline V3_800543F8 *sub_800543F8(void *a, void *b) {
    V3_800543F8 r;

    func_80046FBC(&r, a, b);
    return &r;
}

static inline void proj_800543F8(V3_800543F8 *v, N_800543F8 n) {
    V3_800543F8 t;
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

static inline void proj84_800543F8(u8 *o, N_800543F8 n) {
    V3_800543F8 t;
    s32 d;

    {
        s32 nx = n.x;
        s32 ny = n.y;
        s32 nz = n.z;

        t.x = nx;
        t.y = ny;
        t.z = nz;
    }
    d = func_80022E54(o + 0x84, &t);
    *(s32 *)(o + 0x84) -= func_80022E14(d, n.x);
    *(s32 *)(o + 0x88) -= func_80022E14(d, n.y);
    *(s32 *)(o + 0x8C) -= func_80022E14(d, n.z);
}

static inline void proj8D0_800543F8(u8 *o, N_800543F8 n) {
    V3_800543F8 t;
    s32 d;

    {
        s32 nx = n.x;
        s32 ny = n.y;
        s32 nz = n.z;

        t.x = nx;
        t.y = ny;
        t.z = nz;
    }
    d = func_80022E54(o + 0x8D0, &t);
    *(s32 *)(o + 0x8D0) -= func_80022E14(d, n.x);
    *(s32 *)(o + 0x8D4) -= func_80022E14(d, n.y);
    *(s32 *)(o + 0x8D8) -= func_80022E14(d, n.z);
}


static inline void fix92C_800543F8(u8 *c, s32 *m, s16 *g) {
    V3_800543F8 z;
    V3_800543F8 o;
    V3_800543F8 r1;
    V3_800543F8 r2;

    z.z = 0;
    z.y = 0;
    z.x = 0;
    func_800230FC(c + 0x884, &z);
    func_800230FC(m, &z);
    o.x = 0;
    o.y = 0x46000;
    o.z = 0;
    func_800226A0(c + 0x884, &o, &r1);
    g[2] = 0;
    g[1] = 0;
    g[0] = U16(0x92E) & 0xFFF;
    func_80022598(g, m);
    func_80022FCC(c + 0x884, m);
    func_800226A0(c + 0x884, &o, &r2);
    I32(0x4) = I32(0x4) + r1.x - r2.x;
    I32(0x8) = I32(0x8) + r1.y - r2.y;
    I32(0xC) = I32(0xC) + r1.z - r2.z;
}

static inline s32 bonus_800543F8(u8 *c, s32 sum, s32 n) {
    if (I32(0x424) < 3) {
        return sum * (n + I32(0x424)) / 2;
    } else {
        s32 t = n - 2;
        return sum * (t + I32(0x424) * 2) >> 1;
    }
}

#define QN qp->n
static inline void grind_800543F8(u8 *c, R_800543F8 *qp) {
    s32 ge;
    s32 d;
    s32 a;
    s32 f;
    s32 id;
    s32 sum;
    s32 i;
    s32 n2;
    s32 b;
    V3_800543F8 *p8D0;
    u8 *p8E8;
    u8 *p84;
    V3_800543F8 u;
    V3_800543F8 w;
    V3_800543F8 *pu;
    V3_800543F8 *pw;

    ge = !(qp->n.y < 0xCCE);
    pu = &u;
    goto G1;
G1:
    u = V3(0x84);
    u.y = 0;
    func_80022964(pu);
    w.x = qp->n.x;
    w.y = 0;
    w.z = qp->n.z;
    pw = &w;
    goto G2;
G2:
    func_80022964(pw);
    d = func_80022E54(pw, pu);
    if (!ge) {
        if (d < 0) {
            d = -d;
        }
        if (d < 0xDDB && D_800DE994 - I32(0x300) >= 41) {
            a = 10000;
            f = I32(0x460);
            id = f & 0xFF;
            if (f & 0x4000) {
                goto aa;
            }
            if (f & 0x2000) {
            aa:
                a = U8(0x226) - D_800D63F8[id].unk18;
            }
            if (I32(0x454) != 0 && I32(0x458) == 0 && S16(0x21C) < a) {
                func_8004D398(c, 0);
                I32(0x318)++;
            } else {
                I32(0x458) = 1;
            }
            if (I32(0x450) != 0) {
                goto L450;
            }
            if (I32(0x510) != 0 && I32(0x514) != 0) {
                i = 0;
                b = I32(0xDA4);
                sum = i;
                if (i < b) {
                    do {
                        sum += *(s32 *)(c + i * 0x14 + 0xC18);
                        i++;
                    } while (i < b);
                }
                b = bonus_800543F8(c, sum, I32(0xDA4) * 2);
                if (b > 0) {
                    func_800696B0(I32(0x510), c);
                }
            }
            func_8004D048(c, 5, 0x1633);
            I32(0x300) = D_800DE994;
            I32(0x4) = qp->pos.x + qp->n.x * 30;
            I32(0x8) = qp->pos.y + qp->n.y * 30;
            I32(0xC) = qp->pos.z + qp->n.z * 30;
            p8D0 = (V3_800543F8 *)(c + 0x8D0);
            { proj8D0_800543F8(c, qp->n); }
            func_80022964(p8D0);
            {
                s32 nx = qp->n.x;
                s32 ny = qp->n.y;
                s32 nz = qp->n.z;

                p8E8 = c + 0x8E8;
                I32(0x8E8) = nx;
                I32(0x8EC) = ny;
                I32(0x8F0) = nz;
            }
            func_80043590(p8D0);
            func_8004356C(p8E8);
            p84 = c + 0x84;
            func_80042C70();
            func_80043264(c + 0x8DC);
            func_8005BE8C(c);
            func_8004BD2C(c);
            I32(0x918) = 0;
            COPYN(S16(0x100), S16(0x102), S16(0x104), (s16))
            COPYN(I32(0x91C), I32(0x920), I32(0x924), (s32))
            { proj84_800543F8(c, qp->n); }
            func_80043590(D_800D6FCC);
            func_8004356C(p8E8);
            func_80042C70();
            {
            V3_800543F8 x;
            V3_800543F8 *px;

            px = &x;
            goto G3;
        G3:
            func_80043264(px);
            func_8005BE8C(c);
            I32(0x228) = 0x10000;
            if (I32(0x208) & 2) {
                if (func_80022E54(px, p84) < 0) {
                    { func_8004D2D4(c); func_8004A204(c, 0x24, 0, -1, -1); }
                } else {
                    { func_8004D2D4(c); func_8004A204(c, 0x23, 0, -1, -1); }
                }
            } else {
                if (func_80022E54(px, p84) >= 0) {
                    { func_8004D2D4(c); func_8004A204(c, 0x24, 0, -1, -1); }
                } else {
                    { func_8004D2D4(c); func_8004A204(c, 0x23, 0, -1, -1); }
                }
            }
            }
            return;
        }
    }
    goto fail;
L450:
    V3(0x4) = V3(0x16C);
    return;
fail:
    V3(0x4) = V3(0x16C);
    func_8004D398(c, 0);
    return;
}

static inline void stick_800543F8(N_800543F8 n, u8 *c, s32 len) {
    I32(0x84) -= func_80022E14(n.x, len / 4);
    I32(0x8C) -= func_80022E14(n.z, len / 4);
}

#undef QN
#define QN q.n
void func_800543F8(u8 *c) {
    u8 pad18[0x30];
    V3_800543F8 v48;
    u8 pad54[0x20];
    s32 m78[8];
    s16 ang[4];
    R_800543F8 q;
    V3_800543F8 v1A0;
    V3_800543F8 *p48a;
    V3_800543F8 *p48b;
    s32 r;
    s32 len;
    s32 d;
    s32 ge;
    s32 a;
    s32 i;
    s32 n2;
    s32 sum;
    s32 b;
    s32 b2;
    s32 snd;
    s32 anim;
    s32 f;
    s32 id;

    v1A0 = V3(0x2C0);
    { step_800543F8(c, m78, ang); }
    { *(p48a = &v48) = *sub_800543F8(c + 4, c + 0x16C); }
    func_800233B8(func_80022E54(p48a, &v48));
    r = I32(0x930) >> 12;
    func_80022E14(r, 0xC00);
    if (r != 0 && func_800470A8(c + 0x90C, D_800D6188) != 0) {
        ang[2] = 0;
        ang[0] = 0;
        ang[1] = r & 0xFFF;
        func_80022598(ang, m78);
        func_80022FCC(c + 0x884, m78);
        I32(0x420) += r;
        if (I32(0x420) >= 0x800) {
            I32(0x420) -= 0x800;
            if (I32(0x380) == 0) {
                I32(0x424)++;
            }
        }
        if (I32(0x420) < -0x7FF) {
            I32(0x420) += 0x800;
            if (I32(0x380) == 0) {
                I32(0x424)++;
            }
        }
    }
    if (I32(0x82C) != 2) {
        func_80058D54(c);
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
    { *(p48b = &v48) = *sub_800543F8(c + 4, c + 0x16C); }
    len = func_800233B8(func_80022E54(p48b, &v48)) << 6;
    if (len < 0x2E000) {
        if (len < 0x800) {
            len = 0x800;
        }
        q.end.x = V3(0x16C).x + ((v48.x * 46 / len) << 12);
        q.end.y = V3(0x16C).y + ((v48.y * 46 / len) << 12);
        q.end.z = V3(0x16C).z + ((v48.z * 46 / len) << 12);
    }
    func_8005CCD8(&q, 0);
    func_8005DF8C(&q, 1);
    if (q.hit != NULL) {
        FLAGS_800543F8();
    }
    if (D_800D71F4 != 0 && D_800D7200 == 0 && I32(0x82C) != 3) {
        D_800D7240 = 1;
        func_8005CCD8(&q, 0);
        func_8005DF8C(&q, 1);
        if (q.hit != NULL) {
            FLAGS_800543F8();
        }
        D_800D7240 = 0;
    }
    if (q.hit == NULL) {
        goto nohit;
    }
    if ((D_800D71F8 == 0 || (D_800D71F4 != 0 && D_800D7200 != 0)) && D_800D71FC != 0 && I32(0x450) == 0 &&
        ((*(u8 **)(c + 0x964))[0] != 0 || *(s32 *)(*(u8 **)(c + 0x964) + 8) < 20)) {
        { grind_800543F8(c, &q); }
        return;
    }
    if (D_800D71F8 == 0 && (D_800D71F4 == 0 || I32(0x82C) != 3)) {
        switch (D_800D7204) {
        case 7:
            snd = 0x35;
            goto play;
        case 9:
            snd = 0x28;
            if (D_800C0E20 == 8) {
                snd = 0x89;
            }
        play:
            func_80039E60(snd, 10000, 0);
        }
        S16(0x100) = 0;
        S16(0x102) = -0x1000;
        S16(0x104) = 0;
        {
            s32 h0 = S16(0x100);
            s32 h1 = S16(0x102);

            I32(0x91C) = h0;
            I32(0x920) = h1;
        }
        I32(0x924) = 0;
        I32(0x918) = 0;
        func_800598B8(c);
        snd = 15;
        I32(0x2F8) = snd;
        I32(0x4) = q.pos.x + q.n.x;
        I32(0x8) = q.pos.y + q.n.y;
        I32(0xC) = q.pos.z + q.n.z;
        func_8004D048(c, 1, 0x16D9);
        I32(0x838) = 1;
        { call58804_800543F8(q.n, c); }
        {
            s32 t = q.n.x / 4;
            I32(0x84) += t;
        }
        {
            s32 t = q.n.y / 4;
            I32(0x88) += t;
        }
        {
            s32 t = q.n.z / 4;
            I32(0x8C) += t;
        }
        if (func_80049D60(3) == 0) {
            I32(0x84) += -0x2000 + func_80049D60(0x4000);
            I32(0x8C) += -0x2000 + func_80049D60(0x4000);
        }
        return;
    }
    I32(0x4) = q.pos.x + q.n.x * 30;
    I32(0x8) = q.pos.y + q.n.y * 30;
    I32(0xC) = q.pos.z + q.n.z * 30;
    if (I32(0x450) == 0 && D_800D71F4 != 0) {
        if (I32(0x85C) != 0 && (I32(0x2F0) == 0 || D_800DE994 - I32(0x2F0) < 5 || D_800D7200 != 0)) {
            func_8004D048(c, 2, 0x171A);
            goto tail;
        }
        func_8004D048(c, 1, 0x1721);
        if ((*(u8 **)(c + 0x964))[0xA0] != 0 || S8(0x98D) < -40) {
            { stick_800543F8(q.n, c, func_800233B8(func_80022E54(c + 0x84, c + 0x84)) << 6); }
        }
        I32(0x860) = 0;
        if (I32(0x838) == 0 || I32(0x454) == 0) {
            func_8004C9E8(c);
            I32(0x228) = 0x10000;
            { func_8004D2D4(c); func_8004A204(c, 0xE, 0, -1, -1); }
            I32(0x838) = 1;
        }
        goto tail;
    }
    if (I32(0x82C) == 3 && D_800DE994 - I32(0x3F4) < 31) {
        goto tail;
    }
    func_8004D048(c, 0, 0x1754);
    I32(0x824) = D_800D7204;
    if (I32(0x450) != 0) {
        goto tail;
    }
    { callEBFC_800543F8(q.n, c); }
    { call427C_800543F8(q.n, c); }
    if (I32(0x450) != 0) {
        goto tail;
    }
    if (I32(0x454) == 0 && I32(0x818) == 0) {
        goto tail;
    }
    b2 = 0;
    if (I32(0x460) & 0x2000) {
        b2 = (*(u8 **)(c + 0x964))[0x10] != 0;
    }
    b = 0;
    if (I32(0x460) & 0x4000) {
        b = (*(u8 **)(c + 0x964))[0x20] != 0;
    }
    b2 |= b;
    b2 |= I32(0x458) == 0;
    if (I32(0x818) != 0) {
        if (I32(0x820) > 0) {
            if ((I32(0x81C) & 0xFFF) < 0xED4) {
                b2 = 1;
            }
        } else if ((I32(0x81C) & 0xFFF) >= 0x12D) {
            b2 = 1;
        }
    }
    if (b2) {
        func_8004D398(c, 0);
        I32(0x318)++;
    }
tail:
    I32(0x860) = q.face->fC.h & 0x20;
    if (I32(0x82C) == 1) {
        return;
    }
    { proj84_800543F8(c, q.n); }
    {
        s32 nx = q.n.x;
        s32 ny = q.n.y;
        s32 nz = q.n.z;

        S16(0x100) = nx;
        S16(0x102) = ny;
        S16(0x104) = nz;
        {
            s32 h0 = S16(0x100);
            s32 h1 = S16(0x102);

            I32(0x91C) = h0;
            I32(0x920) = h1;
            I32(0x924) = nz;
        }
    }
    I32(0x918) = 0;
    func_800598B8(c);
    return;
nohit:
    func_800472C0(c + 0x9C, &v1A0);
}
