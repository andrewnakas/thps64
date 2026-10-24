/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-no-m4100 */
#include "common.h"

typedef struct {
    u8 held;
    u8 pressed;
    u8 pad[14];
} Btn4FD90;

typedef struct {
    Btn4FD90 b[12];
} Pad4FD90;

typedef struct {
    u8 pad0[4];
    u8 unk4;
} Unk290;

typedef struct {
    u8 pad0[0x84];
    s32 unk84;
    s32 unk88;
    s32 unk8C;
    u8 pad90[0x9C - 0x90];
    s32 unk9C;
    s32 unkA0;
    s32 unkA4;
    u8 padA8[0x208 - 0xA8];
    s32 unk208;
    u8 pad20C[0x21C - 0x20C];
    s16 unk21C;
    u16 unk21E;
    u8 pad220[0x228 - 0x220];
    s32 unk228;
    u8 pad22C[0x290 - 0x22C];
    Unk290 *unk290;
    u8 pad294[0x350 - 0x294];
    s32 unk350;
    u8 pad354[0x37C - 0x354];
    s32 unk37C;
    s32 unk380;
    u8 pad384[0x410 - 0x384];
    s32 unk410;
    s32 unk414;
    u8 pad418[4];
    s32 unk41C;
    s32 unk420;
    s32 unk424;
    u8 pad428[0x82C - 0x428];
    s32 unk82C;
    u8 pad830[4];
    s32 unk834;
    u8 pad838[0x92C - 0x838];
    s32 unk92C;
    s32 unk930;
    s32 unk934;
    u8 pad938[0x964 - 0x938];
    Pad4FD90 *unk964;
    u8 pad968[0x98C - 0x968];
    s8 unk98C;
    s8 unk98D;
} Sk4FD90;

s32 func_80022E54(void *, void *);
s32 func_800233B8(s32);
void func_8004A204(Sk4FD90 *, s32, s32, s32, s32);
void func_8004D2D4(Sk4FD90 *);
void func_80058594(Sk4FD90 *, s32, s32, s32);
extern Pad4FD90 D_800D49E0;
extern s32 D_800DE994;
extern s32 D_800DE99C;

/* inlined func_8005C0AC(o->unk21C, n) */
/* inlined func_8005C0AC(o->unk21C, n) */
#define STEP4FD90(n)                            \
    {                                           \
        s32 c_ = o->unk21C;                     \
        s32 s_;                                 \
        s32 v_;                                 \
        if (c_ == n) {                          \
            v_ = n;                             \
        } else {                                \
            n -= c_;                            \
            s_ = (n < 0) ? -1 : 1;              \
            if (n <= -1) {                      \
                n = -n;                         \
            }                                   \
            if (n >= 13) {                      \
                v_ = c_ + s_ * 5;               \
            } else if (n >= 4) {                \
                v_ = c_ + s_ * 3;               \
            } else {                            \
                v_ = c_ + s_;                   \
            }                                   \
        }                                       \
        o->unk21C = v_;                         \
    }

#define STEP4FD90_C(n)                          \
    {                                           \
        s32 c_ = o->unk21C;                     \
        s32 s_;                                 \
        s32 v_;                                 \
        if (c_ == n) {                          \
            v_ = c_;                            \
        } else {                                \
            n -= c_;                            \
            s_ = (n < 0) ? -1 : 1;              \
            if (n <= -1) {                      \
                n = -n;                         \
            }                                   \
            if (n >= 13) {                      \
                v_ = c_ + s_ * 5;               \
            } else if (n >= 4) {                \
                v_ = c_ + s_ * 3;               \
            } else {                            \
                v_ = c_ + s_;                   \
            }                                   \
        }                                       \
        o->unk21C = v_;                         \
    }

void func_8004FD90(Sk4FD90 *o) {
    s32 spd;
    s32 lim;
    s32 l;
    s32 r;
    s32 t;
    s32 n;
    s32 v;
    s32 w;
    s32 k;

    if ((u32)(o->unk82C - 1) < 2) {
        if (o->unk37C == 0) {
            if (o->unk964->b[5].pressed != 0) {
                o->unk964->b[5].pressed = 0;
                if (o->unk41C > 0) {
                    o->unk41C = 0;
                }
                o->unk41C--;
            }
            if (o->unk964->b[7].pressed != 0) {
                o->unk964->b[7].pressed = 0;
                if (o->unk41C < 0) {
                    o->unk41C = 0;
                }
                o->unk41C++;
            }
        }
        if (o->unk41C > 0) {
            func_80058594(o, (D_800DE99C * 150) >> 8, 0, 0);
            o->unk420 += (D_800DE99C * 150) >> 8;
            if (o->unk420 >= 0x800) {
                o->unk41C--;
                o->unk420 -= 0x800;
                if (o->unk380 == 0) {
                    o->unk424++;
                }
            }
        }
        if (o->unk41C < 0) {
            func_80058594(o, -((D_800DE99C * 150) >> 8), 0, 0);
            o->unk420 -= (D_800DE99C * 150) >> 8;
            if (o->unk420 < -0x7FF) {
                o->unk41C++;
                o->unk420 += 0x800;
                if (o->unk380 == 0) {
                    o->unk424++;
                }
            }
        }
    } else {
        o->unk41C = 0;
    }
    if (o->unk41C != 0) {
        o->unk930 = 0;
        return;
    }
    o->unk414 = 0;
    if (o->unk82C == 0) {
        switch (o->unk290->unk4) {
        case 3:
            spd = (D_800DE99C * 0x3E00) >> 8;
            break;
        default:
            spd = (D_800DE99C * 15 << 11) >> 8;
            break;
        case 1:
            spd = (D_800DE99C * 5 << 11) >> 8;
            break;
        }
        lim = 0x2D000;
        l = o->unk964->b[8].held;
        r = o->unk964->b[9].held;
        o->unk350 = 0;
        if (o->unk98D >= 31 || o->unk964->b[11].held != 0) {
            o->unk410 = 1;
            spd <<= 1;
            lim = 0x5A000;
            {
                s32 m = (func_800233B8(func_80022E54(&o->unk84, &o->unk84)) << 6) >> 12;
                if (m != 0) {
                    o->unk9C -= o->unk84 / m;
                    o->unkA0 -= o->unk88 / m;
                    o->unkA4 -= o->unk8C / m;
                }
            }
        }
    } else {
        if (D_800D49E0.b[4].held != 0 || D_800D49E0.b[6].held != 0) {
            spd = (D_800DE99C * 0x64000) >> 8;
        } else {
            spd = (D_800DE99C * 0xA000) >> 8;
        }
        lim = 0xA0000;
        l = 0;
        if (o->unk964->b[8].held != 0 || o->unk964->b[4].held != 0) {
            l = 1;
        }
        r = 0;
        if (o->unk964->b[9].held != 0 || o->unk964->b[6].held != 0) {
            r = 1;
        }
        if (l != 0 || r != 0) {
            if (o->unk350 > 0 && D_800DE994 - o->unk350 < 8) {
                l = 0;
                r = 0;
            }
        } else {
            o->unk350 = D_800DE994;
        }
        l |= o->unk964->b[4].held;
        r |= o->unk964->b[6].held;
        if (o->unk37C != 0) {
            l = r = 0;
        }
        if (l == 0 && r == 0 && o->unk98C == 0) {
            o->unk930 = 0;
        }
        o->unk410 = 0;
    }
    if (o->unk98C != 0 && l == 0 && r == 0) {
        t = o->unk98C * lim / 128;
        if (t < -lim) {
            t = -lim;
        }
        if (t > lim) {
            t = lim;
        }
        if (o->unk930 < t) {
            o->unk414 = 1;
            o->unk930 += spd + spd * ((t - o->unk930) >> 12) / (s32)((u32)lim >> 13);
            if (o->unk930 > t) {
                o->unk930 = t;
            }
            o->unk934 += spd;
            if (o->unk934 > t) {
                o->unk934 = t;
            }
        }
        if (o->unk930 > t) {
            o->unk414 = 1;
            o->unk930 -= spd + spd * ((o->unk930 - t) >> 12) / (s32)((u32)lim >> 13);
            if (o->unk930 < t) {
                o->unk930 = t;
            }
            o->unk934 -= spd;
            if (o->unk934 < t) {
                o->unk934 = t;
            }
        }
    } else if (l != 0) {
        o->unk414 = 1;
        o->unk930 -= spd;
        if (o->unk930 < -lim) {
            o->unk930 = -lim;
        }
        if (o->unk934 - spd >= -lim) {
            o->unk934 -= spd;
        }
    } else if (r != 0) {
        o->unk414 = 1;
        o->unk930 += spd;
        if (o->unk930 > lim) {
            o->unk930 = lim;
        }
        if (o->unk934 + spd <= lim) {
            o->unk934 += spd;
        }
    } else {
        if (o->unk410 != 0) {
            o->unk930 -= o->unk930 >> 1;
        } else {
            o->unk930 -= o->unk930 >> 2;
        }
        if (((o->unk930 + 0x800) >> 12) == 0) {
            o->unk930 = 0;
        }
        v = o->unk934 >> 4;
        if (v < 0 && v > -0x400) {
            v = -0x400;
        }
        if (v > 0 && v < 0x400) {
            v = 0x400;
        }
        o->unk934 -= v;
        if (((o->unk934 + 0x800) >> 12) == 0) {
            o->unk934 = 0;
        }
    }
    v = o->unk930;
    o->unk934 = v;
    if (v != 0) {
        if (o->unk834 == 0) {
            switch (o->unk21E) {
            case 0:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
                if (o->unk208 & 2) {
                    if (v < 0) {
                        n = -(v * 22) / lim;
                        if (n > 22) {
                            n = 22;
                        }
                        o->unk228 = 0x10000;
                        if (o->unk21E != 7) {
                            o->unk21C = 0;
                        }
                        STEP4FD90(n);
                        {
                            s32 m = o->unk21C;
                            func_8004D2D4(o);
                            func_8004A204(o, 7, m, m, -1);
                        }
                    } else {
                        n = v * 22 / lim;
                        if (n > 22) {
                            n = 22;
                        }
                        o->unk228 = 0x10000;
                        if (o->unk21E != 6) {
                            o->unk21C = 0;
                        }
                        if (o->unk21C < n) {
                            o->unk21C++;
                        }
                        STEP4FD90(n);
                        {
                            s32 m = o->unk21C;
                            func_8004D2D4(o);
                            func_8004A204(o, 6, m, m, -1);
                        }
                    }
                } else {
                    if (v < 0) {
                        n = -(v * 22) / lim;
                        if (n > 22) {
                            n = 22;
                        }
                        o->unk228 = 0x10000;
                        if (o->unk21E != 6) {
                            o->unk21C = 0;
                        }
                        STEP4FD90(n);
                        {
                            s32 m = o->unk21C;
                            func_8004D2D4(o);
                            func_8004A204(o, 6, m, m, -1);
                        }
                    } else {
                        n = v * 22 / lim;
                        if (n > 22) {
                            n = 22;
                        }
                        o->unk228 = 0x10000;
                        if (o->unk21E != 7) {
                            o->unk21C = 0;
                        }
                        STEP4FD90_C(n);
                        {
                            s32 m = o->unk21C;
                            func_8004D2D4(o);
                            func_8004A204(o, 7, m, m, -1);
                        }
                    }
                }
                break;
            }
        }
        w = o->unk934;
        if (w != 0) {
            if (o->unk834 != 0) {
                switch (o->unk21E) {
                case 0:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                    if (o->unk208 & 2) {
                        if (w < 0) {
                            k = -(w * 12) / lim;
                            if (k > 12) {
                                k = 12;
                            }
                            o->unk228 = 0x10000;
                            if (o->unk21E == 7) {
                                o->unk21E = 10;
                                o->unk21C = k;
                            }
                            if (o->unk21E != 10) {
                                o->unk21C = 0;
                            }
                            STEP4FD90(k);
                            {
                                s32 m = o->unk21C;
                                func_8004D2D4(o);
                                func_8004A204(o, 10, m, m, -1);
                            }
                        } else {
                            k = w * 15 / lim;
                            if (k > 15) {
                                k = 15;
                            }
                            o->unk228 = 0x10000;
                            if (o->unk21E == 6) {
                                o->unk21E = 9;
                                o->unk21C = k;
                            }
                            if (o->unk21E != 9) {
                                o->unk21C = 0;
                            }
                            STEP4FD90(k);
                            {
                                s32 m = o->unk21C;
                                func_8004D2D4(o);
                                func_8004A204(o, 9, m, m, -1);
                            }
                        }
                    } else {
                        if (w < 0) {
                            k = w * -15 / lim;
                            if (k > 15) {
                                k = 15;
                            }
                            o->unk228 = 0x10000;
                            if (o->unk21E == 6) {
                                o->unk21E = 9;
                                o->unk21C = k;
                            }
                            if (o->unk21E != 9) {
                                o->unk21C = 0;
                            }
                            STEP4FD90(k);
                            {
                                s32 m = o->unk21C;
                                func_8004D2D4(o);
                                func_8004A204(o, 9, m, m, -1);
                            }
                        } else {
                            k = w * 12 / lim;
                            if (k > 12) {
                                k = 12;
                            }
                            o->unk228 = 0x10000;
                            if (o->unk21E == 7) {
                                o->unk21E = 10;
                                o->unk21C = k;
                            }
                            if (o->unk21E != 10) {
                                o->unk21C = 0;
                            }
                            STEP4FD90_C(k);
                            {
                                s32 m = o->unk21C;
                                func_8004D2D4(o);
                                func_8004A204(o, 10, m, m, -1);
                            }
                        }
                    }
                    break;
                }
            }
            if (o->unk934 != 0) {
                goto skip;
            }
        }
    }
    switch (o->unk21E) {
    case 6:
    case 7:
        o->unk228 = 0x10000;
        func_8004D2D4(o);
        func_8004A204(o, 0, 0, -1, -1);
        break;
    case 9:
    case 10:
        o->unk228 = 0x10000;
        {
            s32 q = 0x13;
            func_8004D2D4(o);
            func_8004A204(o, 8, q, 0x1A, q);
        }
        break;
    }
skip:
    o->unk92C = 0;
    if (o->unk82C == 1) {
        if (o->unk964->b[1].held == 0 && o->unk964->b[2].held == 0) {
            if (o->unk964->b[10].held != 0 || o->unk98D < -40) {
                o->unk92C = -((D_800DE99C * 20) >> 8);
            }
            if (o->unk964->b[11].held != 0 || o->unk98D > 40) {
                o->unk92C = (D_800DE99C * 20) >> 8;
            }
        }
    }
}
