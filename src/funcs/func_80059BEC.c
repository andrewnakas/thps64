/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-no-m4100 */
#include "common.h"

typedef struct {
    s32 x, y, z;
} V3_59BEC;

typedef struct {
    V3_59BEC start;
    V3_59BEC end;
    u8 pad18[0x88 - 0x18];
    s8 unk88;
    u8 pad89[0x100 - 0x89];
} R_59BEC;

typedef struct {
    u8 pad0[0x1C];
    s32 x1C;
    u8 pad20[0x28 - 0x20];
    u32 unk28;
    u8 pad2C[0x154 - 0x2C];
} Row59BEC;

typedef struct {
    s32 w[11];
} Rec63F8_59BEC;

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0x78 - 0x10];
} Rec5C1C_59BEC;

typedef struct {
    s32 w[8];
} M32_59BEC;

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
} Ev59BEC;

s32 func_80022E54(void *, void *);
s32 func_800233B8(s32);
void func_80039E60(s32, s32, s32);
void func_8004641C(s32, u8 *);
void func_80046DAC(void *, void *, s32 *);
void func_80046F58(void *, void *, s32 *);
void func_80046FBC(void *, void *, void *);
s32 func_8004706C(void *, void *);
void func_800472C0(void *, void *);
void func_80049C20(void *, void *);
void func_8004A204(u8 *, s32, s32, s32, s32);
void func_8004C4A4(u8 *, s32, s32);
void func_8004C63C(u8 *, s32, s32, s32, s32);
void func_8004C774(u8 *);
void func_8004CACC(u8 *, s32, s32, s32, s32);
void func_8004D048(u8 *, s32, s32);
void func_8004D2D4(u8 *);
void func_8004D718(u8 *, V3_59BEC, char *);
void func_8004E0B0(u8 *);
void func_8004F13C(u8 *);
void func_8004FD90(u8 *);
void func_80050D68(u8 *);
void func_80052828(u8 *);
void func_800543F8(u8 *);
void func_80055570(u8 *);
void func_80055A14(u8 *);
void func_80055D24(u8 *);
void func_80056B14(u8 *);
void func_80057EAC(u8 *);
void func_80058E3C(u8 *);
void func_80059AA0(u8 *);
void func_8005BDA8(u8 *);
void func_8005CCD8(R_59BEC *, s32);
void func_8005DF8C(R_59BEC *, s32);
void func_80061E34(s32);
void func_80061E7C(s32);
void func_80082660(void);
extern char D_8001BCEC[];
extern s32 D_800C0E20;
extern Row59BEC D_800D4D80[];
extern Rec5C1C_59BEC D_800D5C1C[];
extern u8 *D_800D61A0;
extern s16 D_800D62BC[];
extern Rec63F8_59BEC D_800D62F0[];
extern Rec63F8_59BEC D_800D6374[];
extern Rec63F8_59BEC D_800D63F8[];
extern s32 D_800D6F90;
extern s32 D_800D6F94;
extern s32 D_800D6F98;
extern s32 D_800D6FC8;
extern V3_59BEC D_800D6FCC;
extern s32 D_800D71CC;
extern s32 D_800D723C;
extern s32 D_800D7240;
extern s32 D_800DE7A0;
extern u8 *D_800DE7A8;
extern s32 D_800DE7B0;
extern s32 D_800DE804;
extern s32 D_800DE86C;
extern s32 D_800DE994;
extern s32 D_800DE99C;
extern s32 D_800DE9AC;
extern V3_59BEC D_800FA980;

#define I32(o) (*(s32 *)(c + (o)))
#define S16(o) (*(s16 *)(c + (o)))
#define U16(o) (*(u16 *)(c + (o)))
#define U8(o) (*(u8 *)(c + (o)))
#define S8(o) (*(s8 *)(c + (o)))
#define V3(o) (*(V3_59BEC *)(c + (o)))
#define PAD(o) ((*(u8 **)(c + 0x964))[o])

/* func_80057EAC's SET_RANGE */
#define RANGE_59BEC(dst, G)                                     \
    {                                                           \
        s32 t_;                                                 \
        s32 w_;                                                 \
        s32 v_;                                                 \
        s32 x_;                                                 \
        if ((w_ = D_800D6FC8) == 0) {                           \
            x_ = D_800D4D80[I32(0x3E0)].x1C;                    \
            v_ = (*(u8 **)(c + 0x290))[1];                      \
            if (I32(0x34C) != 0 || D_800DE86C != 0) {          \
                t_ = G - 10;                                    \
                v_ += 3;                                        \
                w_ = x_ + v_;                                   \
            } else {                                            \
                t_ = G - 10;                                    \
                w_ = x_ + v_;                                   \
            }                                                   \
        } else {                                                \
            t_ = G - 10;                                        \
        }                                                       \
        dst = (((t_ + w_) << 12) * 3 * 15) / 28;                \
    }

static inline s32 stat_59BEC(u8 *c, s32 base) {
    s32 x;
    s32 v;

    if (D_800D6FC8 != 0) {
        return D_800D6FC8 + base;
    }
    x = D_800D4D80[I32(0x3E0)].x1C;
    v = (*(u8 **)(c + 0x290))[1];
    if (I32(0x34C) != 0 || D_800DE86C != 0) {
        return x + (v += 3) + base;
    }
    return x + v + base;
}

static inline s32 maxspd_59BEC(u8 *c) {
    return ((stat_59BEC(c, 50) << 12) * 3 * 15) / 28;
}

static inline void clampv_59BEC(s32 *p, s32 len, u8 *c) {
    s32 v = *p;
    s32 q;
    s32 l2 = len >> 12;

    do {
        q = v * (maxspd_59BEC(c) >> 12) / l2;
    } while (0);
    *p = q;
}

#define DAMP_59BEC(o, sh)                                       \
    {                                                           \
        s32 a_ = I32(o);                                        \
                                                                \
        I32(o) = a_ - (((a_ >> (sh)) * D_800DE99C) >> 8);       \
    }

#define DAMP3_59BEC(sh)    \
    DAMP_59BEC(0x84, sh)   \
    DAMP_59BEC(0x88, sh)   \
    DAMP_59BEC(0x8C, sh)

void func_80059BEC(u8 *c) {
    u8 pad18[0x150];
    V3_59BEC v168;
    V3_59BEC v178;
    V3_59BEC v188;
    R_59BEC q;
    V3_59BEC v298;
    V3_59BEC t2A8;
    V3_59BEC t2B8;
    s32 i2C8;
    s32 i2CC;
    s32 run;
    s32 l;
    V3_59BEC *pos;
    V3_59BEC *p16C;
    s32 len;
    s32 b;

    {
        s32 x_ = 0;
        s32 y_ = 0x32C8;
        s32 z_ = 0;

        v168.x = x_;
        v168.y = y_;
        v168.z = z_;
    }
    {
        V3_59BEC *g = &D_800D6FCC;
        s32 x_ = 0;
        s32 y_ = -0x1000;
        s32 z_ = 0;

        g->x = x_;
        g->y = y_;
        g->z = z_;
    }
    I32(0x2C0) = 0;
    I32(0x2C4) = 0x32C8;
    I32(0x2C8) = 0;
    run = 1;
    switch (D_800D4D80[I32(0x3E0)].unk28) {
    case 0:
        D_800D63F8[9] = D_800D62F0[1];
        D_800D63F8[10] = D_800D62F0[2];
        D_800D63F8[6] = D_800D62F0[0];
        break;
    case 1:
        D_800D63F8[9] = D_800D6374[1];
        D_800D63F8[10] = D_800D6374[2];
        D_800D63F8[6] = D_800D6374[0];
        break;
    case 2:
        D_800D63F8[9] = D_800D62F0[0];
        D_800D63F8[10] = D_800D62F0[2];
        D_800D63F8[6] = D_800D6374[0];
        break;
    case 3:
        D_800D63F8[9] = D_800D62F0[1];
        D_800D63F8[10] = D_800D6374[2];
        D_800D63F8[6] = D_800D62F0[0];
        break;
    case 4:
        D_800D63F8[9] = D_800D62F0[1];
        D_800D63F8[10] = D_800D6374[2];
        D_800D63F8[6] = D_800D62F0[0];
        break;
    }
    if (I32(0x30C) != 0) {
        I32(0x30C) -= 5;
        if (I32(0x30C) < 0) {
            I32(0x30C) = 0;
        }
    }
    if (I32(0x348) != 0) {
        I32(0x348) -= 2;
        if (I32(0x348) <= 0) {
            I32(0x348) = 0;
        }
    }
    if (I32(0x34C) != 0) {
        I32(0x34C) -= 2;
        if (I32(0x34C) <= 0) {
            I32(0x34C) = 0;
            func_8004C63C(c, 0, 0, 0, 5);
        }
    }
    if ((PAD(0xA0) != 0 || S8(0x98D) < -40) && PAD(0x80) == 0 && PAD(0x90) == 0 && S8(0x98C) == 0) {
        if (I32(0x2F0) == 0) {
            I32(0x2F0) = D_800DE994;
        }
    } else {
        I32(0x2F0) = 0;
    }
    V3(0x29C) = V3(0x84);
    D_800D723C = 1;
    D_800D7240 = 0;
    func_8004641C(0, c);
    if (D_800DE7A0 != 2) {
        s32 t = I32(0x428) - D_800DE994;

        if (D_800DE7B0 != 0) {
            t = 100 - D_800DE994;
        }
        if (t < 0 && D_800DE9AC == 0) {
            if (D_800DE7B0 != 0) {
                D_800DE804 = 8;
            } else {
                if (D_800DE7A0 == 1 && D_800D5C1C[D_800C0E20].unkC != 0) {
                    func_80039E60(0xA0, 10000, 0);
                }
                func_80082660();
            }
        }
    }
    if (I32(0x818) != 0) {
        s32 o = I32(0x81C);

        I32(0x81C) = o + ((I32(0x820) * D_800DE99C) >> 8);
        if ((I32(0x81C) ^ o) & 0x1000) {
            if (--I32(0x818) == 0) {
                I32(0x81C) = 0;
                I32(0x820) = 0;
            }
        }
    }
    {
        s32 a = S16(0x888);
        s32 b2 = S16(0x88E);
        s32 c2 = S16(0x894);

        I32(0x8D0) = a;
        I32(0x8D4) = b2;
        I32(0x8D8) = c2;
    }
    {
        s32 a = S16(0x884);
        s32 b2 = S16(0x88A);
        s32 c2 = S16(0x890);

        I32(0x8DC) = a;
        I32(0x8E0) = b2;
        I32(0x8E4) = c2;
    }
    {
        s32 a = S16(0x886);
        s32 b2 = S16(0x88C);
        s32 c2 = S16(0x892);

        I32(0x8E8) = a;
        I32(0x8EC) = b2;
        I32(0x8F0) = c2;
    }
    func_8004FD90(c);
    if (I32(0x82C) != 1) {
        I32(0x298) = 0;
    }
    I32(0xA4) = 0;
    I32(0xA0) = 0;
    I32(0x9C) = 0;
    func_80057EAC(c);
    func_80056B14(c);
    if (I32(0x82C) != 5 && U8(0x227) != 0) {
        switch (U16(0x21E)) {
        case 0x23:
        case 0x24:
            I32(0x228) = 0x10000;
            if (I32(0x82C) == 0) {
                func_8004D2D4(c);
                func_8004A204(c, 0, 0, -1, -1);
            } else {
                func_8004D2D4(c);
                func_8004A204(c, 0xE, 0, -1, -1);
            }
            break;
        }
    }
    func_8004F13C(c);
    b = 0;
    if ((PAD(0xB0) != 0 && PAD(0x80) == 0 && PAD(0x90) == 0) || (S8(0x98D) > 0 && S8(0x98C) == 0)) {
        b = 1;
    }
    if (I32(0x82C) == 7 && b == 0) {
        func_8004D048(c, 0, 0x20F2);
    }
    if (I32(0x82C) == 0 && b != 0 && I32(0x450) == 0) {
        s32 lim;
        s32 a = -(S16(0x906) << 12) >> 12;

        if (a < 0x300) {
            a = 0x300;
        }
        lim = 0x1000 - a;
        lim = lim * 0x1800 / 208;
        if (lim <= 0x9FFF) {
            lim = 0xA000;
        }
        if (lim < func_800233B8(func_80022E54(c + 0x84, c + 0x84)) << 6) {
            if (U16(0x21E) != 0x31) {
                I32(0x228) = 0x20000;
                func_80039E60(2, 10000, 0);
                func_8004D2D4(c);
                func_8004A204(c, 0x31, 0, -1, -1);
            }
            if (S8(0x98D) > 0) {
                {
                    s32 a_ = I32(0x84);

                    I32(0x84) = a_ - (((a_ * (S8(0x98D) / 16) / 128) * D_800DE99C) >> 8);
                }
                I32(0x88) -= ((I32(0x88) * (S8(0x98D) / 16) / 128) * D_800DE99C) >> 8;
                I32(0x8C) -= ((I32(0x8C) * (S8(0x98D) / 16) / 128) * D_800DE99C) >> 8;
            } else {
                DAMP3_59BEC(4)
            }
        } else if (lim <= 0xA000) {
            func_8004D048(c, 7, 0x2128);
            I32(0x84) = 0;
            I32(0x88) = 0;
            I32(0x8C) = 0;
            if (U16(0x21E) == 0x31) {
                func_8004D2D4(c);
                func_8004A204(c, 0, 0, -1, -1);
            }
        }
        I32(0x938) = 2;
    } else if (U16(0x21E) == 0x31) {
        I32(0x228) = 0x10000;
        func_8004D2D4(c);
        func_8004A204(c, 0, 0, -1, -1);
    }
    if (U8(0x227) != 0) {
        switch (U16(0x21E)) {
        case 0xB:
        case 0xC:
            if (I32(0x834) != 0) {
                I32(0x228) = 0x10000;
                {
                    s32 k = 0x13;

                    func_8004D2D4(c);
                    func_8004A204(c, 8, k, 0x1A, k);
                }
            } else {
                I32(0x228) = 0x10000;
                func_8004D2D4(c);
                func_8004A204(c, 0, 0, -1, -1);
            }
            break;
        }
    }
    I32(0x830) = I32(0x82C);
    *(M32_59BEC *)(c + 0x864) = *(M32_59BEC *)(c + 0x884);
    V3(0x2A8) = V3(0x16C);
    V3(0x16C) = V3(0x4);
    I32(0x90C) = 0;
    I32(0x910) = 0;
    I32(0x914) = 0;
    func_80058E3C(c);
    if (I32(0x834) != 0) {
        s32 *q430 = (s32 *)(c + 0x430);

        RANGE_59BEC(*q430, D_800D6F94)
    }
    if (I32(0x434) != 0) {
        l = func_800233B8(func_80022E54(c + 0x84, c + 0x84)) << 6;

        if (l < 0x1000) {
            l = 0x1000;
        }
        l >>= 12;
        I32(0x9C) += I32(0x84) / l;
        I32(0xA0) += I32(0x88) / l;
        I32(0xA4) += I32(0x8C) / l;
        I32(0x434)--;
    }
    l = func_800233B8(func_80022E54(c + 0x84, c + 0x84)) << 6;
    if (I32(0x42C) < l) {
        I32(0x3FC) = 1;
    } else {
        I32(0x3FC) = 0;
    }
    if (I32(0x438) > 0) {
        I32(0x438)--;
    } else if (I32(0x43C) > 0) {
        I32(0x43C)--;
    } else {
        s32 r;
        s32 cur;

        I32(0x43C) = 30;
        cur = I32(0x42C);
        RANGE_59BEC(r, D_800D6F90)
        if (r < cur) {
            I32(0x42C) -= 0x1000;
        }
        cur = I32(0x430);
        RANGE_59BEC(r, D_800D6F98)
        if (r < cur) {
            I32(0x430) -= 0x1000;
        }
    }
    pos = &V3(0x4);
    v178 = V3(0x4);
    func_8004D718(c, v178, D_8001BCEC);
    V3(0x2B4) = V3(0x4);
    func_8004706C(pos, c + 0x16C);
    if (I32(0x450) == 0) {
        func_8004C774(c);
    }
    if (I32(0x82C) != 8) {
        func_8004E0B0(c);
    }
    if (I32(0x450) != 0 && U16(0x21E) == 0x2E && S16(0x21C) == D_800D62BC[I32(0x3E0)]) {
        func_8004C4A4(c, 0, 0x32);
    }
    I32(0x9E8)++;
    switch (I32(0x82C)) {
    case 0:
        I32(0x9DC) = 0;
        I32(0x9E0) = 0;
        I32(0x9E4) = 0;
        I32(0x9E8) = 0;
        I32(0x304) = 0;
        I32(0x3D4) = 0;
        I32(0x3D8) = 0;
        V3(0x2D4) = V3(0x4);
        func_80052828(c);
        break;
    case 7:
        func_80052828(c);
        V3(0x4) = V3(0x16C);
        break;
    case 4: {
        Ev59BEC *e = *(Ev59BEC **)(c + 0x3D8);
        s32 i;

        if (e != NULL) {
            func_8004CACC(c, 0x4D, e->unk4, -e->unk2, 0);
            func_80039E60(0xA1, 10000, 0);
            *(Ev59BEC **)(c + 0x3D8) = NULL;
        }
        for (i = 0; i < 10; i++) {
            if (((s32 *)(c + 0x3AC))[i] < 10000) {
                ((s32 *)(c + 0x384))[i] = 12345;
            }
        }
        func_80050D68(c);
        break;
    }
    case 8:
        func_80055A14(c);
        break;
    case 6:
        func_80055570(c);
        func_800543F8(c);
        break;
    case 1:
        func_800543F8(c);
        break;
    case 5:
        func_80055D24(c);
        break;
    case 3:
        func_800543F8(c);
        if (I32(0x82C) == 3 && D_800DE994 - I32(0x2E0) >= 26) {
            func_8004D048(c, 1, 0x2276);
        }
        break;
    case 2:
        func_80052828(c);
        break;
    }
    if (I32(0x450) != 0) {
        I32(0x9C) = 0;
        I32(0xA4) = 0;
        I32(0x83C) = 0;
        I32(0x838) = 0;
        if ((I32(0x294) == 0 || I32(0x82C) == 2) && I32(0x88) < 0) {
            I32(0x88) = 0;
        }
        switch (I32(0x344)) {
        case 1:
            if (S16(0x21C) >= 15 && I32(0x814) == 0 && I32(0x82C) == 0) {
                func_80039E60(0x26, 10000, 0);
                func_8004C4A4(c, 0, 0x32);
                DAMP3_59BEC(2)
                I32(0x814) = 1;
            }
            if (S16(0x21C) >= 16 && I32(0x82C) == 0) {
                DAMP3_59BEC(5)
            }
            if (U8(0x227) != 0 && I32(0x82C) == 0) {
                if (U16(0x21E) != 0x2E) {
                    I32(0x344) = 2;
                } else {
                    I32(0x344) = 4;
                }
            }
            break;
        case 6:
            if (S16(0x21C) >= 15 && I32(0x814) == 0 && I32(0x82C) == 0) {
                func_80039E60(0x26, 10000, 0);
                func_8004C4A4(c, 0, 0x32);
                DAMP3_59BEC(2)
                I32(0x814) = 1;
            }
            if (S16(0x21C) >= 16 && I32(0x82C) == 0) {
                DAMP3_59BEC(5)
            }
            if (U8(0x227) != 0 && I32(0x82C) == 0) {
                if (U16(0x21E) != 0x2E) {
                    func_8004D2D4(c);
                    func_8004A204(c, 0x37, 0, -1, -1);
                    I32(0x344) = 7;
                } else {
                    I32(0x344) = 4;
                }
            }
            break;
        case 7:
            if (I32(0x82C) == 0) {
                I32(0x84) = 0;
                I32(0x88) = 0;
                I32(0x8C) = 0;
            }
            if (U8(0x227) != 0 && I32(0x82C) == 0) {
                func_8004D2D4(c);
                func_8004A204(c, 0x36, 0x63, -1, -1);
                I32(0x344) = 4;
            }
            break;
        case 2:
            if (I32(0x82C) == 0) {
                DAMP3_59BEC(5)
            }
            I32(0x228) = 0x10000;
            func_8004D2D4(c);
            func_8004A204(c, 0x36, 0x1E, -1, -1);
            I32(0x344) = 3;
            break;
        case 5:
            if (S16(0x21C) >= 0x1A && I32(0x82C) == 0) {
                DAMP3_59BEC(2)
            } else if (S16(0x21C) >= 0x22 && I32(0x82C) == 0) {
                I32(0x84) = 0;
                I32(0x88) = 0;
                I32(0x8C) = 0;
            }
            if (U8(0x227) != 0 && I32(0x82C) == 0) {
                I32(0x344) = 4;
            }
            break;
        case 3:
            if (S16(0x21C) >= 0x33 && I32(0x82C) == 0) {
                DAMP3_59BEC(2)
            }
            if (U8(0x227) != 0 && I32(0x82C) == 0) {
                I32(0x344) = 4;
            }
            break;
        case 8:
            if (S16(0x21C) < 0x12) {
                DAMP3_59BEC(4)
                I32(0xA0) = 0;
            }
            if (U8(0x227) != 0 && I32(0x82C) == 0) {
                func_8004D2D4(c);
                func_8004A204(c, 0x36, 0x4C, -1, -1);
                I32(0x344) = 4;
            }
            break;
        case 9:
            if (S16(0x21C) >= 0x1D && I32(0x82C) == 0) {
                DAMP3_59BEC(2)
            }
            if (U8(0x227) != 0 && I32(0x82C) == 0) {
                func_8004D2D4(c);
                func_8004A204(c, 0x2E, 0x24, -1, -1);
                I32(0x344) = 4;
            }
            break;
        case 4:
            if (I32(0x82C) == 0) {
                I32(0x84) = 0;
                I32(0x88) = 0;
                I32(0x8C) = 0;
            }
            if (S16(0x21C) >= 0x70) {
                func_8004C774(c);
            }
            if (U8(0x227) != 0) {
                I32(0x938) = 4;
                I32(0x228) = 0x10000;
                if (I32(0x834) != 0 && PAD(0x10) != 0) {
                    s32 k = 0x13;

                    func_8004D2D4(c);
                    func_8004A204(c, 8, 0, 0x1A, k);
                } else {
                    I32(0x834) = 0;
                    func_8004D2D4(c);
                    func_8004A204(c, 0, 0, -1, -1);
                }
                I32(0x450) = 0;
                I32(0x8C) = 0;
                I32(0x88) = 0;
                I32(0x84) = 0;
                func_8004C774(c);
            }
            break;
        }
    }
    pos = &V3(0x4);
    v178 = V3(0x4);
    func_80059AA0(c);
    p16C = &V3(0x16C);
    if (D_800D71CC == 0) {
        D_800D71CC = 1;
    }
    func_80046FBC(&v188, pos, p16C);
    if ((v188.x | v188.y | v188.z) != 0) {
        s32 who;
        V3_59BEC *p298;
        V3_59BEC *p2A8;
        V3_59BEC *p2B8;
        R_59BEC *pq;

        D_800FA980 = v188;
        p298 = &v298;
        goto L1;
    L1:
        func_80049C20(p298, &D_800FA980);
        p2A8 = &t2A8;
        p2B8 = &t2B8;
        goto L2;
    L2:
        i2C8 = 0x10;
        func_80046F58(p2B8, p298, &i2C8);
        func_80046FBC(p2A8, p16C, p2B8);
        {
            s32 x1 = t2A8.x;
            s32 y1 = t2A8.y;
            s32 z1 = t2A8.z;

            q.start.x = x1;
            q.start.y = y1;
            q.start.z = z1;
        }
        {
            s32 x2 = I32(0x4);
            s32 y2 = I32(0x8);
            s32 z2 = I32(0xC);

            q.end.x = x2;
            q.end.y = y2;
            q.end.z = z2;
        }
        pq = &q;
        goto L3;
    L3:
        func_8005CCD8(pq, 0);
        q.unk88 = 1;
        who = 2;
        if (c == D_800DE7A8) {
            who = 1;
        }
        func_80061E7C(who);
        D_800D61A0 = c;
        func_8005DF8C(pq, 1);
        func_80061E34(who);
        D_800D61A0 = NULL;
    }
    if (I32(0x82C) < 4) {
        if (I32(0x82C) > 0) {
            if (I32(0x3F8) == 0) {
                I32(0x3F8) = D_800DE994;
            }
        } else {
            I32(0x3F8) = 0;
        }
    } else {
        I32(0x3F8) = 0;
    }
    {
        V3_59BEC *a = &q.start;
        V3_59BEC *d = (V3_59BEC *)((u8 *)&q + 0x10);

        func_80046F58(d, c + 0x9C, &D_800DE99C);
        i2CC = 8;
        func_80046DAC(a, d, &i2CC);
        func_800472C0(c + 0x84, a);
    }
    len = func_800233B8(func_80022E54(c + 0x84, c + 0x84)) << 6;
    if (maxspd_59BEC(c) < len) {
        clampv_59BEC(&I32(0x84), len, c);
        clampv_59BEC(&I32(0x88), len, c);
        clampv_59BEC(&I32(0x8C), len, c);
        len = func_800233B8(func_80022E54(c + 0x84, c + 0x84)) << 6;
    }
    if (run == 0) {
        if (__builtin_abs(len) <= 0xFFFF) {
            I32(0x84) -= I32(0x84) / 32;
            I32(0x88) -= I32(0x88) / 32;
            I32(0x8C) -= I32(0x8C) / 32;
        }
        if (__builtin_abs(len) < 0x2000) {
            s32 v;

            v = I32(0x84) - I32(0x84) / 4;
            I32(0x84) = v;
            if ((v < 0 ? -v : v) < 0x10) {
                I32(0x84) = 0;
            }
            v = I32(0x88) - I32(0x88) / 4;
            I32(0x88) = v;
            if ((v < 0 ? -v : v) < 0x10) {
                I32(0x88) = 0;
            }
            v = I32(0x8C) - I32(0x8C) / 4;
            I32(0x8C) = v;
            if ((v < 0 ? -v : v) < 0x10) {
                I32(0x8C) = 0;
            }
        }
        if ((I32(0x84) | I32(0x88) | I32(0x8C)) == 0 && I32(0x82C) == 0) {
            func_8004D048(c, 7, 0x2401);
        }
    }
    func_8005BDA8(c);
}
