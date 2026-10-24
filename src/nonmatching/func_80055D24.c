/* compiler: cc1plus */
/* cflags: -Wa,-no-m4100 -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* NON_MATCHING: ratio 0.993 (aln); only the C++ frame (stack-slot offsets) differs from the game; unused frame-padding arrays removed. Best original draft872/892, cleaned draft648/892 instructions agree. */
#include "common.h"

typedef struct {
    s32 x, y, z;
} V3_80055D24;

typedef struct {
    s16 x, y, z, w;
} N_80055D24;

typedef struct {
    u32 w0;
    u8 pad4[8];
    union {
        u32 w;
        u16 h;
        u8 b;
    } fC;
} F_80055D24;

typedef struct {
    V3_80055D24 start;
    V3_80055D24 end;
    u8 pad18[0x40 - 0x18];
    s32 unk40;
    u8 pad44[0x68 - 0x44];
    u8 *hit;
    V3_80055D24 pos;
    N_80055D24 n;
    F_80055D24 *face;
    u8 pad84[0x100 - 0x84];
} R_80055D24;

typedef struct {
    u8 pad0[0x1C];
    s32 unk1C;
    u8 pad20[0x48 - 0x20];
} T_80055D24;

extern "C" s32 func_80022964(void *);
extern "C" s32 func_80022E14(s32, s32);
extern "C" s32 func_80022E54(void *, void *);
extern "C" s32 func_800233B8(s32);
extern "C" void func_80042C70(void);
extern "C" void func_80043264(void *);
extern "C" void func_8004356C(void *);
extern "C" void func_80043590(void *);
extern "C" V3_80055D24 func_80046DAC(const V3_80055D24 &, const long &);
extern "C" V3_80055D24 func_80046E04(const V3_80055D24 &, const long &);
extern "C" V3_80055D24 func_80046F58(const V3_80055D24 &, const long &);
extern "C" V3_80055D24 func_80046FBC(const V3_80055D24 &, const V3_80055D24 &);
extern "C" V3_80055D24 func_80047014(const V3_80055D24 &, const V3_80055D24 &);
extern "C" s32 func_8004706C(void *, void *);
extern "C" void func_800472C0(void *, const void *);
extern "C" void func_8004A204(u8 *, s32, s32, s32, s32);
extern "C" void func_8004C3D8(u8 *);
extern "C" void func_8004C9E8(u8 *);
extern "C" void func_8004D048(u8 *, s32, s32);
extern "C" s32 func_8004D2D4(u8 *);
extern "C" void func_8004D5B0(void *, void *, void *);
extern "C" void func_80058594(u8 *, s32, s32, s32);
extern "C" void func_80058804(u8 *, N_80055D24, s32);
extern "C" void func_80058A94(u8 *, s32);
extern "C" void func_800598B8(u8 *);
extern "C" void func_8005BE8C(u8 *);
extern "C" void func_8005BED8(u8 *);
extern "C" void func_8005CCD8(R_80055D24 *, s32);
extern "C" void func_8005DF8C(R_80055D24 *, s32);
extern u8 D_800D6188[];
extern s32 D_800D71F4;
extern s32 D_800D71F8;
extern s32 D_800D71FC;
extern s32 D_800D7200;
extern s32 D_800D7204;
extern T_80055D24 D_800DAF98[];
extern s32 D_800DE994;
extern long D_800DE99C;
extern long D_800DE9A0;

#define I32(o) (*(s32 *)(c + (o)))
#define U32(o) (*(u32 *)(c + (o)))
#define S16(o) (*(s16 *)(c + (o)))
#define U16(o) (*(u16 *)(c + (o)))
#define U8(o) (*(u8 *)(c + (o)))
#define V3(o) (*(V3_80055D24 *)(c + (o)))

static inline s32 vlen_80055D24(void *v) {
    return func_800233B8(func_80022E54(v, v));
}

#define COPYN(d0, d1, d2, cast) \
    { \
        s32 nx = q.n.x; \
        s32 ny = q.n.y; \
        s32 nz = q.n.z; \
        d0 = cast nx; \
        d1 = cast ny; \
        d2 = cast nz; \
    }

static inline void call58804_80055D24(N_80055D24 n, u8 *c) {
    func_80058804(c, n, 200);
}

static inline void proj_80055D24(V3_80055D24 *v, N_80055D24 n) {
    V3_80055D24 t;
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

static inline void proj84_80055D24(u8 *o, N_80055D24 n) {
    V3_80055D24 t;
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

static inline void proj8D0_80055D24(u8 *o, N_80055D24 n) {
    V3_80055D24 t;
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

extern "C" void func_80055D24(u8 *c) {
    V3_80055D24 v48;
    V3_80055D24 v58;
    R_80055D24 q;
    V3_80055D24 v1A0;
    s32 s7;
    s32 lim;
    s32 ge;
    s32 e40;
    s32 m;
    s32 len;

    s32 x, y, z;
    V3_80055D24 *pv;


    V3_80055D24 *p8D0;

    u8 *p8E8;


    R_80055D24 *pq;
    F_80055D24 *face;
    s32 f71F4;
    s32 f7200;

    s7 = I32(0x82C) == 2;
    {
        s32 k = 0x2328;

        v1A0.x = 0;
        v1A0.y = k;
        v1A0.z = 0;
    }
    if (U8(0x227) != 0) {
        if (U16(0x21E) == 0x24) {
            goto doit;
        }
        if (U16(0x21E) == 0x23) {
doit:
            {
                s32 two = 2;
                s32 four;
                s32 a;
                s32 *pd = &D_800DE994;

                four = 4;
                a = (*pd / four) % four;
                if (two < a) {
                    a = four - a;
                }
                S16(0x21C) = a + 7;
            }
        }
    }
    func_800472C0(c + 4, &func_80047014(func_80046DAC(func_80046F58(V3(0x84), D_800DE99C), 8),
                                         func_80046E04(func_80046DAC(func_80046F58(V3(0x9C), D_800DE9A0), 8), 2)));
    v48 = func_80046FBC(V3(4), V3(0x16C));
    func_800233B8(func_80022E54(&v48, &v48));
    m = 0;
    if (I32(0x818) == 0 && I32(0x41C) == 0) {
        func_80058A94(c, 4);
        m = I32(0x900);
    }
    func_80022E14(m, 0xC00);
    func_80058594(c, (m * D_800DE99C) >> 8, s7 ^ 1, 0);
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
    v48 = func_80046FBC(V3(4), V3(0x16C));
    if (func_8004706C(&v48, D_800D6188) != 0) {
        len = func_800233B8(func_80022E54(&v48, &v48)) << 6;
        if (I32(0x450) != 0 ? len < 0x64000 : len < 0x1E000) {
            if (len < 0x800) {
                len = 0x800;
            }
            {
                s32 t = v48.x;
                q.end.x = V3(0x16C).x + (((I32(0x450) != 0 ? t * 100 : t * 30) / len) << 12);
            }
            {
                s32 t = v48.y;
                q.end.y = V3(0x16C).y + (((I32(0x450) != 0 ? t * 100 : t * 30) / len) << 12);
            }
            {
                s32 t = v48.z;
                q.end.z = V3(0x16C).z + (((I32(0x450) != 0 ? t * 100 : t * 30) / len) << 12);
            }
        }
        pq = &q;
        func_8005CCD8(pq, 0);
        func_8005DF8C(pq, 1);
        if (q.hit != NULL) {
                        D_800D71F4 = f71F4 = q.face->fC.h & 0x40;
            D_800D71F8 = (q.face->fC.b ^ 1) & 1;
            D_800D71FC = ((q.face->fC.w >> 23) ^ 1) & 1;
            D_800D7200 = f7200 = q.face->w0 & 0x80;
            D_800D7204 = (q.face->fC.h & 0x1E00) >> 9;
            if (f7200 != 0 || f71F4 == 0) {
                I32(0x4) = q.pos.x + I32(0x8E8) * 30;
                I32(0x8) = q.pos.y + I32(0x8EC) * 30;
                I32(0xC) = q.pos.z + I32(0x8F0) * 30;
                if (!s7) {
                    *(u8 **)(c + 0x510) = q.hit;
                    I32(0x514) = D_800DAF98[q.hit[0x1B]].unk1C;
                }
                if (*(s32 *)&q.n == I32(0x100) && q.n.z == S16(0x104)) {
                    I32(0x918)++;
                } else {
                    I32(0x918) = 0;
                    COPYN(S16(0x100), S16(0x102), S16(0x104), (s16))
                }
                func_800598B8(c);
                if (D_800D71F8 != 0) {
                    func_8004D048(c, 0, 0x18BC);
                    p8D0 = (V3_80055D24 *)(c + 0x8D0);
                    { proj8D0_80055D24(c, q.n); }
                    func_80022964(p8D0);
                    {
                    s32 nx = q.n.x;
                    s32 ny = q.n.y;
                    s32 nz = q.n.z;

                    p8E8 = c + 0x8E8;
                    I32(0x8E8) = nx;
                    I32(0x8EC) = ny;
                    I32(0x8F0) = nz;
                }
                    func_80043590(p8D0);
                    func_8004356C(p8E8);
                    func_80042C70();
                    func_80043264(c + 0x8DC);
                    func_8005BE8C(c);
                    I32(0x918) = 0;
                    COPYN(S16(0x100), S16(0x102), S16(0x104), (s16))
                    COPYN(I32(0x91C), I32(0x920), I32(0x924), (s32))
                    { proj84_80055D24(c, q.n); }
                }
            }
        }
    }
    if (I32(0x42C) < vlen_80055D24(c + 0x84) << 6) {
        I32(0x3FC) = 1;
    } else {
        I32(0x3FC) = 0;
    }
    func_8005BED8(c);
    x = I32(0x4) + I32(0x8E8) * 70;
    q.start.x = x;
    y = I32(0x8) + I32(0x8EC) * 70;
    q.start.y = y;
    z = I32(0xC) + I32(0x8F0) * 70;
    q.start.z = z;
    q.end.x = x - (I32(0x8E8) << 7);
    q.end.y = y - (I32(0x8EC) << 7);
    q.end.z = z - (I32(0x8F0) << 7);
    pq = &q;
    func_8005CCD8(pq, 0);
    func_8005DF8C(pq, 1);
    if (q.hit != NULL) {
                D_800D71F4 = q.face->fC.h & 0x40;
        D_800D71F8 = (q.face->fC.b ^ 1) & 1;
        D_800D71FC = ((q.face->fC.w >> 23) ^ 1) & 1;
        D_800D7200 = q.face->w0 & 0x80;
        D_800D7204 = (q.face->fC.h & 0x1E00) >> 9;
        e40 = q.unk40;
        lim = 0x74;
        if (e40 <= lim) {
            I32(0x860) = q.face->fC.h & 0x20;
            I32(0x4) = q.pos.x + I32(0x8E8) * 30;
            I32(0x8) = q.pos.y + I32(0x8EC) * 30;
            I32(0xC) = q.pos.z + I32(0x8F0) * 30;
            if (!s7) {
                *(u8 **)(c + 0x510) = q.hit;
                I32(0x514) = D_800DAF98[q.hit[0x1B]].unk1C;
            }
            if (*(s32 *)&q.n == I32(0x100) && q.n.z == S16(0x104)) {
                I32(0x918)++;
            } else {
                I32(0x918) = 0;
                COPYN(S16(0x100), S16(0x102), S16(0x104), (s16))
            }
            func_800598B8(c);
            if (D_800D71F8 != 0) {
                func_8004D048(c, 0, 0x192C);
                p8D0 = (V3_80055D24 *)(c + 0x8D0);
                { proj8D0_80055D24(c, q.n); }
                func_80022964(p8D0);
                {
                    s32 nx = q.n.x;
                    s32 ny = q.n.y;
                    s32 nz = q.n.z;

                    p8E8 = c + 0x8E8;
                    I32(0x8E8) = nx;
                    I32(0x8EC) = ny;
                    I32(0x8F0) = nz;
                }
                func_80043590(p8D0);
                func_8004356C(p8E8);
                func_80042C70();
                func_80043264(c + 0x8DC);
                func_8005BE8C(c);
                I32(0x918) = 0;
                COPYN(S16(0x100), S16(0x102), S16(0x104), (s16))
                COPYN(I32(0x91C), I32(0x920), I32(0x924), (s32))
                { proj84_80055D24(c, q.n); }
            } else if (ge = !(q.n.y < 0xCCE)) {
                V3(0x4) = V3(0x16C);
                func_8004D048(c, 1, 0x1951);
                I32(0x838) = 1;
                func_800472C0(c + 0x9C, &v1A0);
                { call58804_80055D24(q.n, c); }
                func_8004C3D8(c);
            }
        }
        pv = &v58;
        v58 = v1A0;
        { proj_80055D24(&v58, q.n); }
        func_800472C0(c + 0x9C, pv);
        V3(0x8F4) = v58;
        *(N_80055D24 *)(c + 0x904) = q.n;
        func_8004D5B0(c + 0x84, &q.n, c + 0x84);
    } else {
        func_8004D048(c, 1, 0x1986);
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
        func_800472C0(c + 0x9C, &v1A0);
    }
}
