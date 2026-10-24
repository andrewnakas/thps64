/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-O0 */
/* NON_MATCHING: ratio 0.952 (aln), 839/1250 positional instructions agree (target1254); speed/statistic temporary registers, operand order and clamp scheduling differ (the game tail-duplicates one stat sum with a j). */
#include "common.h"

typedef struct {
    s32 x, y, z;
} V3_56B14;

typedef struct {
    u8 pad0[0x18];
    s32 st[4];
    u8 pad28[0x154 - 0x28];
} Row56B14;

s32 func_80022E54(void *, void *);
s32 func_800233B8(s32);
s32 func_80022E14(s32, s32);
void func_80022964(void *);
void func_80039E60(s32, s32, s32);
void func_80042C70(void);
void func_80043264(void *);
void func_8004356C(void *);
void func_80043590(void *);
s32 func_80046004(void *);
void func_80046384(u8 *);
void func_80046F58(void *, void *, s32 *);
void func_800472C0(void *, void *);
void func_8004A204(u8 *, s32, s32, s32, s32);
void func_8004C9E8(u8 *);
void func_8004CACC(u8 *, s32, char *, s32, s32);
void func_8004CC10(u8 *);
void func_8004D048(u8 *, s32, s32);
void func_8004D2D4(u8 *);
void func_8004D398(u8 *, s32);
void func_80058594(u8 *, s32, s32, s32);
void func_8005BE8C(u8 *);
void func_800B36D8(s32, f32, f32);
extern char D_8001BBC8[];
extern char D_8001BBD4[];
extern Row56B14 D_800D4D80[];
extern s32 D_800D6FC8;
extern s32 D_800DC618;
extern s32 D_800DC6D8;
extern s32 D_800DE7A0;
extern s32 D_800DE86C;
extern s32 D_800DE994;
extern s32 D_800DE9AC;
extern s32 D_800DE9C4;
extern struct {
    u8 pad0[0x988];
    s32 unk988[1];
} D_800DE9F4;
extern f32 D_800F5668;

#define I32(o) (*(s32 *)(c + (o)))
#define S16(o) (*(s16 *)(c + (o)))
#define U16(o) (*(u16 *)(c + (o)))
#define U8(o) (*(u8 *)(c + (o)))
#define S8(o) (*(s8 *)(c + (o)))
#define V3(o) (*(V3_56B14 *)(c + (o)))
#define PAD(o) ((*(u8 **)(c + 0x964))[o])

static inline s32 stat_56B14(u8 *c, s32 i) {
    s32 x;
    s32 v;

    if (D_800D6FC8 == 0) {
        x = D_800D4D80[I32(0x3E0)].st[i];
        v = (*(u8 **)(c + 0x290))[i];
        if (I32(0x34C) != 0 || D_800DE86C != 0) {
            s32 v3 = v + 3;

            return x + v3;
        }
        return x + v;
    }
    return D_800D6FC8;
}

static inline s32 stati_56B14(u8 *c, s32 i) {
    s32 x;
    s32 v;

    if (D_800D6FC8 == 0) {
        x = D_800D4D80[I32(0x3E0)].st[i];
        v = (*(u8 **)(c + 0x290))[i];
        if (I32(0x34C) != 0 || D_800DE86C != 0) {
            v += 3;
            return x + v;
        }
        return x + v;
    }
    return D_800D6FC8;
}

#define STATI(w, c, i)                                          \
    (w) = D_800D6FC8;                                           \
    if (D_800D6FC8 == 0) {                                      \
        s32 x_ = D_800D4D80[I32(0x3E0)].st[i];                  \
        s32 v_ = (*(u8 **)((c) + 0x290))[i];                    \
                                                                \
        if (I32(0x34C) != 0 || D_800DE86C != 0) {               \
            v_ += 3;                                            \
            (w) = x_ + v_;                                      \
        } else {                                                \
            (w) = x_ + v_;                                      \
        }                                                       \
    }

#define STAT(w, c, i)                                           \
    (w) = D_800D6FC8;                                           \
    if (D_800D6FC8 == 0) {                                      \
        s32 x_ = D_800D4D80[I32(0x3E0)].st[i];                  \
        s32 v_ = (*(u8 **)((c) + 0x290))[i];                    \
                                                                \
        if (I32(0x34C) != 0 || D_800DE86C != 0) {               \
            s32 v3_ = v_ + 3;                                   \
                                                                \
            (w) = x_ + v3_;                                     \
        } else {                                                \
            (w) = x_ + v_;                                      \
        }                                                       \
    }

#define SET_MAXRUN(c)                                           \
    {                                                           \
        s32 *q_ = &I32(0x840);                                  \
        s32 w_;                                                 \
                                                                \
        STAT(w_, c, 0);                                         \
        *q_ = 15 - (w_ + stat_56B14(c, 2)) / 2;                 \
    }

#define STATN(w, c, i)                                          \
    (w) = D_800D6FC8;                                           \
    if (D_800D6FC8 == 0) {                                      \
        s32 x_ = D_800D4D80[I32(0x3E0)].st[i];                  \
        s32 v_ = (*(u8 **)((c) + 0x290))[i];                    \
                                                                \
        if (I32(0x34C) == 0 && D_800DE86C == 0) {               \
            (w) = x_ + v_;                                      \
        } else {                                                \
            s32 v3_ = v_ + 3;                                   \
                                                                \
            (w) = x_ + v3_;                                     \
        }                                                       \
    }

#define JUMP_56B14(d, c, i, FIN)                                     \
    {                                                           \
        s32 s0;                                                 \
        s32 st2;                                                \
        s32 st3;                                                \
        s32 r;                                                  \
                                                                \
        STAT(s0, c, 0);                                         \
        g = 32 - (10 - stati_56B14(c, i)) / 2;                  \
        do {                                                    \
            n = I32(0x840);                                     \
        } while (0);                                            \
        st = D_800D6FC8;                                        \
        if (D_800D6FC8 == 0) {                                  \
            s32 x_ = D_800D4D80[I32(0x3E0)].st[i];              \
            s32 v_ = (*(u8 **)((c) + 0x290))[i];                \
                                                                \
            if (I32(0x34C) != 0 || D_800DE86C != 0) {           \
                h = g - 18;                                     \
                v_ += 3;                                        \
                st = x_ + v_;                                   \
            } else {                                            \
                h = g - 18;                                     \
                st = x_ + v_;                                   \
            }                                                   \
        } else {                                                \
            h = g - 18;                                         \
        }                                                       \
        h += (10 - st) / 3;                                     \
        h <<= 10;                                               \
        q = n * h;                                              \
        if (D_800D6FC8 != 0) {                                  \
            st2 = s0 + D_800D6FC8;                              \
        } else {                                                \
            s32 x_ = D_800D4D80[I32(0x3E0)].st[2];              \
            s32 v_ = (*(u8 **)((c) + 0x290))[2];                \
                                                                \
            if (I32(0x34C) != 0 || D_800DE86C != 0) {           \
                v_ += 3;                                        \
            }                                                   \
            v_ = x_ + v_;                                       \
            st2 = s0 + v_;                                      \
        }                                                       \
        r = q / (15 - st2 / 2);                                 \
        FIN(st3, c, i);                                         \
        d = (r + ((32 - (10 - st3) / 2) << 10)) * -3;           \
    }

static inline void bail_56B14(u8 *c, s32 e, s32 b) {
    func_8004D2D4(c);
    func_8004A204(c, 8, b, 0x1A, e);
}

void func_80056B14(u8 *c) {
    s32 mode;

    if (I32(0x450) != 0) {
        return;
    }
    if (I32(0x834) != 0) {
        if (U16(0x21E) == 0) {
            I32(0x228) = 0x10000;
            bail_56B14(c, 0x13, 0);
        }
    } else if (U16(0x21E) == 8) {
        I32(0x228) = 0x10000;
        if (S8(0x223) == -1) {
            if (S16(0x21C) == 0) {
                func_8004D2D4(c);
                func_8004A204(c, 0, 0, -1, -1);
            }
        } else {
            func_8004D2D4(c);
            func_8004A204(c, 8, 0x13, 0, -1);
        }
    }
    if (U8(0x227) != 0) {
        switch (U16(0x21E)) {
        case 8:
            if (S16(0x21C) == 0) {
                I32(0x228) = 0x10000;
                func_8004D2D4(c);
                func_8004A204(c, 0, 0, -1, -1);
            }
            break;
        case 5:
        case 0x19:
            if (I32(0x834) != 0) {
                I32(0x228) = 0x10000;
                bail_56B14(c, 0x13, 0x13);
            } else {
                I32(0x228) = 0x10000;
                func_8004D2D4(c);
                func_8004A204(c, 0, 0, -1, -1);
            }
            break;
        case 4:
        case 13:
            if (I32(0x834) == 0) {
                I32(0x228) = 0x10000;
                func_8004D2D4(c);
                func_8004A204(c, 0xE, 0, -1, -1);
            }
            break;
        case 14:
            I32(0x228) = 0x10000;
            func_8004D2D4(c);
            func_8004A204(c, 0xE, 0, -1, -1);
            break;
        case 0x22:
            I32(0x228) = 0x10000;
            if (I32(0x834) != 0) {
                bail_56B14(c, 0x13, 0x13);
            } else {
                func_8004D2D4(c);
                func_8004A204(c, 8, 0x13, 0, -1);
            }
            break;
        case 0:
            I32(0x228) = 0x10000;
            if (I32(0x834) != 0) {
                bail_56B14(c, 0x13, 0x13);
            } else {
                func_8004D2D4(c);
                func_8004A204(c, 0, 0, -1, -1);
            }
            break;
        }
    }
    if (I32(0x838) != 0 && I32(0x830) != 0 && I32(0x82C) == 0) {
        I32(0x838) = 0;
        I32(0x85C) = 0;
        if (I32(0x450) == 0) {
            f32 f;
            s32 n;

            switch (I32(0x824)) {
            case 2:
                func_80039E60(0x26, 10000, 0);
                break;
            case 10:
            case 12:
                func_80039E60(0x23, 10000, 0);
                break;
            case 6:
                break;
            case 1:
            case 15:
            default:
                func_80039E60(5, 10000, 0);
                break;
            }
            f = D_800F5668 * 3.0f;
            n = I32(0x968);
            if (D_800DE7A0 == 7) {
                n ^= D_800DE9C4;
            }
            if (D_800DE9F4.unk988[n] != 0 && D_800DC618 != 2 && D_800DC6D8 != 2) {
                func_800B36D8(n, f, 0.8f);
            }
            if (I32(0x834) != 0) {
                I32(0x228) = 0x10000;
                func_8004D2D4(c);
                func_8004A204(c, 0x19, 3, -1, -1);
            } else {
                I32(0x228) = 0x10000;
                func_8004D2D4(c);
                func_8004A204(c, 5, 0, -1, -1);
            }
            if (I32(0x450) == 0) {
                if (I32(0x454) != 0 || I32(0x818) != 0) {
                    u32 fl;
                    u32 a;
                    u32 b;

                    fl = I32(0x460);
                    a = 0;
                    if (fl & 0x2000) {
                        a = PAD(0x10) > a;
                    }
                    b = 0;
                    if (fl & 0x4000) {
                        b = PAD(0x20) > b;
                    }
                    a |= b;
                    a |= I32(0x458) == 0;
                    if (I32(0x818) != 0) {
                        do {
                            if (I32(0x820) > 0) {
                                if ((I32(0x81C) & 0xFFF) < 0xED4) {
                                    a = 1;
                                }
                            } else if ((I32(0x81C) & 0xFFF) >= 0x12D) {
                                a = 1;
                            }
                        } while (0);
                    }
                    if (a != 0) {
                        func_8004D398(c, 0);
                        I32(0x318)++;
                    }
                }
                if (I32(0x450) == 0) {
                    u8 *p = c + 0xA1C;
                    s32 t;

                    if (func_80046004(p) / 10 > 20) {
                        t = func_80046004(p) / 100;
                    } else {
                        t = func_80046004(p) / 100;
                    }
                    if (t > 20) {
                        t = 20;
                    }
                    I32(0x434) += t;
                    I32(0x438) = 30;
                    I32(0x43C) = 30;
                    func_80046384(c);
                    func_8004CC10(c);
                }
            }
        }
        I32(0x454) = 0;
    }
    if (PAD(0x30) != 0 && I32(0x450) == 0) {
        I32(0x840)++;
        {
            s32 w;
            s32 m;

            STAT(w, c, 0);
            m = I32(0x840);

            if (15 - (w + stat_56B14(c, 2)) / 2 < m) {
                SET_MAXRUN(c);
            }
        }
        if (I32(0x82C) == 0 && I32(0x408) == 0) {
            I32(0x83C) = 1;
            if (I32(0x834) == 0) {
                s32 v;

                I32(0x228) = 0x10000;
                v = I32(0x930);
                if (v < 0) {
                    v = -v;
                }
                if (v <= 0x9FFF) {
                    I32(0x930) = 0;
                    bail_56B14(c, 0x13, 0);
                }
            }
        } else {
            s32 m = I32(0x82C);

            if (m == 4 && I32(0x408) == 0) {
                I32(0x83C) = 1;
            } else if (m == 5 && I32(0x408) == 0) {
                I32(0x83C) = 1;
            }
        }
        if (I32(0x408) == 0) {
            I32(0x834) = 1;
        }
        return;
    }
    I32(0x408) = 0;
    I32(0x834) = 0;
    if (I32(0x3F8) > 0 && D_800DE994 - I32(0x3F8) >= 21) {
        I32(0x83C) = 0;
    }
    if (I32(0x83C) != 0) {
        u8 *pv;

        if (D_800DE9AC == 1 && I32(0x82C) != 4 && I32(0x82C) != 5) {
            I32(0x83C) = 0;
            func_8004D2D4(c);
            func_8004A204(c, 0, 0, -1, -1);
            I32(0x840) = 0;
            return;
        }
        I32(0x844) = I32(0x840);
        I32(0x83C) = 0;
        I32(0x838) = 1;
        pv = c + 0x84;
        I32(0x3F0) = func_800233B8(func_80022E54(pv, pv)) << 6;
        if (I32(0x7D4) != 0) {
            V3_56B14 *dir;
            V3_56B14 *vel;
            V3_56B14 *up;
            s32 d;
            s32 a1;

            I32(0x804) = 5;
            I32(0x7D4) = 0;
            I32(0x7D8) = 0;
            I32(0x454) = 0;
            dir = &V3(0x8D0);
            vel = &V3(0x7F8);
            *dir = *vel;
            up = &V3(0x8E8);
            {
                s32 ux = 0;
                s32 uy = -0x1000;
                s32 uz = 0;

                I32(0x8E8) = ux;
                I32(0x8EC) = uy;
                I32(0x8F0) = uz;
            }
            func_80043590(dir);
            func_8004356C(up);
            func_80042C70();
            func_80043264(&V3(0x8DC));
            func_80022964(&V3(0x8DC));
            func_80043590(&V3(0x8DC));
            func_8004356C(dir);
            func_80042C70();
            func_80043264(up);
            func_8005BE8C(c);
            d = func_80022E54(vel, pv);
            I32(0x84) = func_80022E14(I32(0x7F8), d);
            I32(0x88) = func_80022E14(I32(0x7FC), d);
            I32(0x8C) = func_80022E14(I32(0x800), d);
            a1 = 0;
            if (PAD(0x80) != 0) {
                a1 = -200;
            }
            if (PAD(0x90) != 0) {
                a1 = 200;
            }
            func_80058594(c, a1, 1, 0);
        }
        I32(0x85C) = I32(0x860);
        I32(0x228) = 0x10000;
        I32(0x84C) = I32(0x82C) == 5;
        mode = I32(0x82C);
        if (mode == 5) {
            V3_56B14 v;
            V3_56B14 r;
            V3_56B14 *pr;
            s32 k;

            SET_MAXRUN(c);
            {
                s32 x = S16(0x904);
                s32 y = S16(0x906);
                s32 z = S16(0x908);

                v.x = x;
                v.y = y;
                v.z = z;
            }
            pr = &r;
            k = 2;
            func_80046F58(pr, &v, &k);
            func_800472C0(c + 0x9C, pr);
            I32(0x88) += -0xF000;
        }
        {
            s32 snd = 6;

            if (I32(0x82C) == 4 && I32(0x3E4) == 0) {
                if (I32(0x308) != 1) {
                    snd = 6;
                } else {
                    snd = 0x10;
                }
            }
            func_80039E60(snd, 10000, 0);
        }
        {
            s32 v = I32(0x8EC);
            s32 d;
            s32 g;
            s32 n;
            s32 st;
            s32 h;
            s32 q;

            if (v < 0) {
                v = -v;
            }
            if (v < 0x9C4) {
                JUMP_56B14(d, c, 2, STATN);
            } else {
                JUMP_56B14(d, c, 0, STAT);
            }
            I32(0x88) += d;
        }
        I32(0x320)++;
        {
            s32 w;
            s32 m;

            STAT(w, c, 0);
            m = I32(0x840);
            if (m < 15 - (w + stat_56B14(c, 2)) / 2) {
                I32(0x324)++;
            }
        }
        I32(0x420) = 0;
        I32(0x424) = 0;
        if (I32(0x82C) != 2) {
            if (I32(0x85C) != 0 && I32(0x82C) == 0) {
                func_8004D048(c, 3, 0x1B3E);
                I32(0x2E0) = D_800DE994;
            } else {
                func_8004D048(c, 1, 0x1B44);
            }
        }
        if (I32(0x460) == 0 || (I32(0x460) & 0xF000) == 0x1000) {
            I32(0x228) = 0x10000;
            if (mode != 5 && I32(0x370) == 1 && D_800DE994 - I32(0x36C) < 20) {
                I32(0x420) = 0;
                I32(0x424) = 0;
                if (I32(0x360) == 1 && D_800DE994 - I32(0x364) < 35) {
                    func_8004C9E8(c);
                    func_8004CACC(c, 0x41, D_8001BBC8, 0xFA, 0);
                    I32(0x88) += -0x5000;
                    func_8004D2D4(c);
                    func_8004A204(c, 0x2D, 0x10, -1, -1);
                } else {
                    func_8004C9E8(c);
                    func_8004CACC(c, 0x4B, D_8001BBD4, 0xC8, 0);
                    func_8004D2D4(c);
                    func_8004A204(c, 0xD, 0, -1, -1);
                }
                I32(0x45C) = 1;
            } else {
                func_8004C9E8(c);
                func_8004D2D4(c);
                func_8004A204(c, 4, 0, -1, -1);
            }
        }
        I32(0x3F4) = D_800DE994;
    }
    I32(0x840) = 0;
}
