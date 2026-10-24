/* cflags: -Wa,-no-m4100 -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* NON_MATCHING: 376/1426 positional instructions agree (target1422); temporary/spill frame layout, wave divisions and switch-tail scheduling differ. */
#include "common.h"

typedef struct {
    s32 x, y, z;
} V3_80050D68;

typedef struct {
    s16 x, y, z;
} V3s_80050D68;

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    u8 pad10[0x24 - 0x10];
    s32 unk24;
    u8 pad28[0x154 - 0x28];
} R_80050D68;

void func_80022598(V3s_80050D68 *, void *);
void func_80022964(V3_80050D68 *);
s32 func_80022E14(s32, s32);
s32 func_80022E54(V3_80050D68 *, V3_80050D68 *);
void func_80022FCC(void *, void *);
void func_80024B88(void *, s32, s32, s32);
void func_80024B98(void *, s32, s32, s32);
void func_80024BA8(void *);
void func_80039E60(s32, s32, s32);
void func_80042C70(void);
void func_80043264(V3_80050D68 *);
void func_8004356C(V3_80050D68 *);
void func_80043590(V3_80050D68 *);
void func_8004638C(u8 *, s32);
V3_80050D68 func_80046D28(V3_80050D68 *);
void func_80046DAC(V3_80050D68 *, V3_80050D68 *, s32 *);
void func_80046E04(V3_80050D68 *, V3_80050D68 *, s32 *);
void func_80046F58(V3_80050D68 *, V3_80050D68 *, s32 *);
V3_80050D68 func_80046FBC(V3_80050D68 *, V3_80050D68 *);
void func_80047014(V3_80050D68 *, V3_80050D68 *, V3_80050D68 *);
void func_800472C0(V3_80050D68 *, V3_80050D68 *);
s32 func_800474C8(V3_80050D68 *);
s32 func_80049D60(s32);
void func_8004A204(u8 *, s32, s32, s32, s32);
void func_8004D048(u8 *, s32, s32);
void func_8004D2D4(u8 *);
void func_8004D398(u8 *, s32);
void func_80058594(u8 *, s32, s32, s32);
void func_8005BE00(u8 *);
void func_8005BE8C(u8 *);
void func_8005BED8(u8 *);
void func_800617B8(V3_80050D68 *, s32);
u16 *func_80061904(s32);
u16 func_80068F60(u16 *);
void func_8007D6B8(V3s_80050D68 *);
void func_8007D6E0(void *);
void func_800B36D8(s32, f32, f32);

typedef struct {
    u8 pad0[0x520];
    u32 unk520[1];
} A520_80050D68;

extern R_80050D68 D_800D4D80[];
extern u16 D_800D6F7C[];
extern s32 D_800D6FC8;
extern s32 D_800DC618;
extern s32 D_800DC6D8;
extern s32 D_800DE520;
extern s32 D_800DE524;
extern s32 D_800DE7A0;
extern s32 D_800DE840;
extern s32 D_800DE86C;
extern s32 D_800DE994;
extern s32 D_800DE99C;
extern s32 D_800DE9A0;
extern s32 D_800DE9C4;
extern struct {
    u8 pad0[0x988];
    s32 unk988[1];
} D_800DE9F4;
extern f32 D_800F5668;

#define I32(o) (*(s32 *)(c + (o)))
#define U32(o) (*(u32 *)(c + (o)))
#define S16(o) (*(s16 *)(c + (o)))
#define U16(o) (*(u16 *)(c + (o)))
#define U8(o) (*(u8 *)(c + (o)))
#define S8(o) (*(s8 *)(c + (o)))
#define V3(o) (*(V3_80050D68 *)(c + (o)))
#define ABS_80050D68(x) ((x) < 0 ? -(x) : (x))
#define TBL D_800D4D80[I32(0x3E0)]
#define STATX_80050D68                                                                  \
    (D_800D6FC8 != 0 ? D_800D6FC8                                                       \
                     : (sx = TBL.unk24, sv = (*(u8 **)(c + 0x290))[3],                  \
                        sx + ((I32(0x34C) != 0 || D_800DE86C != 0) ? sv + 3 : sv)))

static inline s32 wave_80050D68(s32 h, s32 t, s32 d, s32 m) {
    s32 x = t / d % m;
    if (x > h) {
        x = m - x;
    }
    return x;
}

static inline void anim_80050D68(u8 *c, s32 id, s32 lo) {
    func_8004D2D4(c);
    func_8004A204(c, id, lo, -1, -1);
}

static inline s32 stat_80050D68(u8 *c) {
    s32 w = D_800D6FC8;
    if (w == 0) {
        s32 x = TBL.unk24;
        s32 v = (*(u8 **)(c + 0x290))[3];
        if (I32(0x34C) != 0 || D_800DE86C != 0) {
            v += 3;
        }
        w = x + v;
    }
    return w;
}

#define FAIL_80050D68(code)                                      \
    {                                                            \
        func_8004D048(c, 1, code);                               \
        I32(0x804) = 5;                                          \
        I32(0x228) = 0x10000;                                    \
        func_8004D2D4(c);                                        \
        func_8004A204(c, 0xE, 0, -1, -1);                        \
        I32(0x7D4) = 0;                                          \
        I32(0x7D8) = 0;                                          \
        I32(0x838) = 1;                                          \
        I32(0x454) = 0;                                          \
        rem = 0;                                                 \
        if (I32(0x308) == 1 && I32(0x3E4) == 0) {                \
            func_80039E60(0x10, 10000, 0);                       \
        }                                                        \
    }

void func_80050D68(u8 *c) {
    V3_80050D68 A;
    V3_80050D68 B;
    V3_80050D68 d;
    s32 last;
    s32 len;
    s32 first;
    s32 pos;
    s32 spd;
    s32 next;
    s32 rem;
    s32 axis;
    V3_80050D68 *p8D0;
    V3_80050D68 *p8DC;
    V3_80050D68 *p8E8;

    first = 1;
    if (U8(0x227) != 0) {
        switch (U16(0x21E)) {
        case 0x29:
        case 0x44: {
            s32 k = TBL.unkC;
            if (k == 0 || k == 0x6000) {
                anim_80050D68(c, 0x29, 0);
            } else {
                anim_80050D68(c, 0x29, 5);
            }
            break;
        }
        case 0x28:
        case 0x43: {
            s32 k = TBL.unkC;
            if (k == 0 || k == 0x6000) {
                anim_80050D68(c, 0x28, 0);
            } else {
                anim_80050D68(c, 0x28, 3);
            }
            break;
        }
        case 0x46:
            anim_80050D68(c, 0x2A, 0);
            break;
        case 0x11:
            if (S16(0x21C) >= 0x10) {
                anim_80050D68(c, 0x27, 0);
            } else {
                anim_80050D68(c, 0x25, 0);
            }
            break;
        case 0x25:
            anim_80050D68(c, 0x26, 0);
            break;
        case 0x39:
            S16(0x21C) = wave_80050D68(2, D_800DE994, 4, 4) + 8;
            break;
        case 0x3A:
            S16(0x21C) = wave_80050D68(2, D_800DE994, 4, 4) + 6;
            break;
        case 0x3E:
        case 0x3F:
        case 0x40:
            switch (TBL.unkC) {
            case 0x2000:
                S16(0x21C) = wave_80050D68(2, D_800DE994, 4, 4) + 0x17;
                break;
            case 0x4000:
                S16(0x21C) = wave_80050D68(12, D_800DE994, 3, 24) + 6;
                break;
            case 0x5000:
                S16(0x21C) = wave_80050D68(2, D_800DE994, 4, 4) + 0xE;
                break;
            case 0x6000:
                S16(0x21C) = wave_80050D68(2, D_800DE994, 4, 4) + 0x15;
                break;
            case 0x8000:
                S16(0x21C) = wave_80050D68(2, D_800DE994, 4, 4) + 0xA;
                break;
            }
            break;
        default: {
            u16 s = U16(0x21E);
            anim_80050D68(c, s, 0);
            break;
        }
        }
    }
    {
        f32 f = D_800F5668 * 2.0f;
        s32 n = I32(0x968);
        if (D_800DE7A0 == 7) {
            n ^= D_800DE9C4;
        }
        if (D_800DE9F4.unk988[n] != 0 && D_800DC618 != 2 && D_800DC6D8 != 2) {
            func_800B36D8(n, f, 0.5f);
        }
    }
    if (I32(0x3E4) == 0) {
        s32 st = U16(0x21E);
        if (st < 0x41) {
            if (st >= 0x3E) {
                switch (TBL.unkC) {
                case 0x2000:
                case 0x5000:
                case 0x6000:
                    goto skip;
                }
            }
        }
        if (D_800DE520 < 200) {
            V3s_80050D68 r48;
            V3_80050D68 v50;
            s32 i;

            func_8005BE00(c);
            func_8007D6E0(c + 0x10);
            {
                s16 x = 0x1C2;
                s16 y = 0x384;
                r48.x = x;
                r48.y = y;
                r48.z = 0;
            }
            func_8007D6B8(&r48);
            D_800DE524 = 0;
            v50.z = 0;
            v50.x = 0;
            v50.y = 0x19000;
            i = 8;
            while (--i >= 0) {
            }
            D_800DE524 = 1;
            func_80024BA8(c + 0x22D0);
            func_80024B98(c + 0x22D0, 0xFF, 0xFF, 0);
            func_80024B88(c + 0x22D0, 0xFF, 0, 0);
        }
    }
skip:
    I32(0x9C) = 0;
    I32(0xA0) = 0;
    I32(0xA4) = 0;
    {
    V3_80050D68 t48;
    V3_80050D68 k60;
    t48 = func_80046FBC(&V3(0x4), &V3(0x9D0));
    if (func_800474C8(&t48) >= 0x1F) {
        u16 *base = D_800D6F7C;
        s32 i = I32(0x9EC);
        u16 *pp = &base[i];
        s32 j = i + 0x42;
        s32 v = *pp;
        switch (((A520_80050D68 *)c)->unk520[j]) {
        case 0:
        case 1:
            break;
        case 2:
            v = v * 75 / 100;
            break;
        case 3:
            v = v / 2;
            break;
        case 4:
            v = v / 4;
            break;
        default:
            v = v / 10;
            break;
        }
        func_8004638C(c, v / 5);
        V3(0x9D0) = V3(0x4);
    }
    {
        s32 y = 0x32C8;
        k60.x = 0;
        k60.y = y;
        k60.z = 0;
    }
    do {
        V3_80050D68 t70;
        V3_80050D68 t80;
        V3_80050D68 t90;
        V3_80050D68 tA0;
        V3_80050D68 tB0;
        V3_80050D68 tC0;
        s32 kD0;
        s32 kD4;
        s32 kD8;

        next = func_80068F60(func_80061904(I32(0x7E4))) & 0xFFFF;
        func_800617B8(&A, I32(0x7E4));
        func_800617B8(&B, next);
        t70 = func_80046FBC(&B, &A);
        d = t70;
        func_80022964(&d);
        spd = func_80022E54(&d, &V3(0x84));
        if (first != 0) {
            first = 0;
            func_800472C0(&V3(0x9C), &k60);
            if (spd == 0) {
                spd = 1000;
            }
            if ((spd < 0 ? -spd : spd) < 60000) {
                if (d.y > 0) {
                    spd += 2000;
                } else if (d.y < 0) {
                    spd -= 2000;
                } else {
                    spd = spd * 5 / 4;
                }
            }
        }
        {
            s32 t = func_80022E54(&d, &V3(0x9C));
            I32(0x9C) = func_80022E14(d.x, t);
            I32(0xA0) = func_80022E14(d.y, t);
            I32(0xA4) = func_80022E14(d.z, t);
        }
        I32(0x84) = func_80022E14(d.x, spd);
        I32(0x88) = func_80022E14(d.y, spd);
        I32(0x8C) = func_80022E14(d.z, spd);
        {
            s32 ay = d.y >= 0 ? d.y : -d.y;
            s32 ax = d.x >= 0 ? d.x : -d.x;
            s32 big;
            axis = 0;
            if (ax < ay) {
                axis = 1;
                big = ay < (d.z >= 0 ? d.z : -d.z);
            } else {
                big = ax < ABS_80050D68(d.z);
            }
            if (big) {
                axis = 2;
            }
        }
        switch (axis) {
        case 0:
            len = (B.x - A.x) / d.x << 12;
            pos = (I32(0x4) - A.x) / d.x << 12;
            break;
        case 1:
            len = (B.y - A.y) / d.y << 12;
            pos = (I32(0x8) - A.y) / d.y << 12;
            break;
        case 2:
            len = (B.z - A.z) / d.z << 12;
            pos = (I32(0xC) - A.z) / d.z << 12;
            break;
        }
        pos += spd;
        last = spd;

        if (pos >= 0 && pos <= len) {
            func_80046F58(&t90, &V3(0x84), &D_800DE99C);
            kD0 = 8;
            func_80046DAC(&t80, &t90, &kD0);
            func_80046F58(&tC0, &V3(0x9C), &D_800DE9A0);
            kD4 = 8;
            func_80046DAC(&tB0, &tC0, &kD4);
            kD8 = 2;
            func_80046E04(&tA0, &tB0, &kD8);
            func_80047014(&t70, &t80, &tA0);
            func_800472C0(&V3(0x4), &t70);
            rem = 0;
        } else if (pos < 0) {
            s32 prev = -1;
            s32 n = I32(0x7E0);
            while (n != I32(0x7E4)) {
                prev = n;
                n = func_80068F60(func_80061904(prev)) & 0xFFFF;
            }
            if (prev == -1) {
                FAIL_80050D68(0xEFE);
            } else {
                s32 nn = func_80068F60(func_80061904(prev)) & 0xFFFF;
                func_800617B8(&t70, prev);
                func_800617B8(&t80, nn);
                tA0 = func_80046FBC(&t80, &t70);
                t90 = tA0;
                func_80022964(&t90);
                if (func_80022E54(&d, &t90) < 0xA49) {
                    FAIL_80050D68(0xF25);
                } else {
                    I32(0x7E4) = prev;
                    V3(0x4) = A;
                    rem = pos;
                    I32(0x8) += -0x19000;
                }
            }
        } else {
            if (*func_80061904(next) == 0) {
                FAIL_80050D68(0xF4A);
            } else {
                s32 nn = func_80068F60(func_80061904(next)) & 0xFFFF;
                func_800617B8(&t70, next);
                func_800617B8(&t80, nn);
                tA0 = func_80046FBC(&t80, &t70);
                t90 = tA0;
                func_80022964(&t90);
                if (func_80022E54(&d, &t90) < 0xA49) {
                    FAIL_80050D68(0xF72);
                } else {
                    I32(0x7E4) = next;
                    rem = pos - len;
                    V3(0x4) = B;
                    I32(0x8) += -0x19000;
                }
            }
        }
    } while (rem != 0);
    if (last >= 0) {
        V3(0x7F8) = func_80046D28(&d);
        if (I32(0x3E4) != 0) {
            I32(0x8D0) = -d.z;
            I32(0x8D4) = -d.y;
            I32(0x8D8) = d.x;
        } else {
            I32(0x8D0) = -d.x;
            I32(0x8D4) = -d.y;
            I32(0x8D8) = -d.z;
        }
    } else {
        V3(0x7F8) = d;
        if (I32(0x3E4) != 0) {
            I32(0x8D0) = d.z;
            I32(0x8D4) = d.y;
            I32(0x8D8) = -d.x;
        } else {
            I32(0x8D0) = d.x;
            I32(0x8D4) = d.y;
            I32(0x8D8) = d.z;
        }
    }
    if (I32(0x7D4) == 0) {
        if (last >= 0) {
            V3(0x8D0) = func_80046D28(&d);
        } else {
            V3(0x8D0) = d;
        }
    }
    p8E8 = &V3(0x8E8);
    {
        s32 y = -0x1000;
        I32(0x8E8) = 0;
        I32(0x8EC) = y;
        I32(0x8F0) = 0;
    }
    p8D0 = &V3(0x8D0);
    func_80043590(p8D0);
    func_8004356C(p8E8);
    p8DC = &V3(0x8DC);
    func_80042C70();
    func_80043264(p8DC);
    func_80022964(p8DC);
    func_80043590(p8DC);
    func_8004356C(p8D0);
    func_80042C70();
    func_80043264(p8E8);
    func_8005BE8C(c);
    func_80058594(c, I32(0x418), 0, 0);
    if (I32(0x3E4) == 2) {
        V3_80050D68 t;
        t = func_80046D28(p8D0);
        *p8D0 = t;
        t = func_80046D28(p8DC);
        *p8DC = t;
        func_8005BE8C(c);
    }
    {
        s32 a = I32(0x9DC);
        s32 m = I32(0x9E8) + 60;
        s32 *p = &I32(0x9DC);
        *p = a + a / (stat_80050D68(c) * 3 + 28) * m / 80;
        I32(0x9DC) += I32(0x9E0) * (I32(0x9E8) + 60) / 80;
    }
    if (D_800DE840 != 0) {
        I32(0x9DC) = 0;
    }
    if ((*(u8 **)(c + 0x964))[0x80] == 0 && S8(0x98C) >= -40 && (*(u8 **)(c + 0x964))[0x90] == 0 &&
        S8(0x98C) < 41) {
        I32(0x2FC) = 1;
    }
    if (((*(u8 **)(c + 0x964))[0x80] != 0 || S8(0x98C) < -40) && I32(0x2FC) != 0) {
        I32(0x9E0) -= 20;
    } else if (((*(u8 **)(c + 0x964))[0x90] != 0 || S8(0x98C) >= 41) && I32(0x2FC) != 0) {
        I32(0x9E0) += 20;
    } else {
        s32 a = I32(0x9E0) >= 0 ? I32(0x9E0) : -I32(0x9E0);
        s32 sx;
        s32 sv;
        if (a < 20 - stat_80050D68(c)) {
            s32 *q = &I32(0x9E0);
            *q = func_80049D60(80 - STATX_80050D68 * 3) - (80 - STATX_80050D68 * 3) / 2;
        }
    }
    if ((I32(0x9DC) < 0 ? -I32(0x9DC) : I32(0x9DC)) > 4000) {
        func_8004D398(c, 0);
        I32(0x31C)++;
    }
    {
        s32 m[8];
        V3s_80050D68 r;
        r.y = 0;
        if (I32(0x3E4) == 0) {
            r.x = 0;
            r.z = (I32(0x9DC) / 10) & 0xFFF;
        } else {
            if (I32(0x3E4) == 1) {
                r.x = -(I32(0x9DC) / 10) & 0xFFF;
            } else {
                r.x = (I32(0x9DC) / 10) & 0xFFF;
            }
            r.z = 0;
        }
        func_80022598(&r, m);
        func_80022FCC(c + 0x884, m);
    }
    func_8005BED8(c);
    }
}
