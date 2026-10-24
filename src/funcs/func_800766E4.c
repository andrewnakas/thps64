/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    s32 x, y, z;
} V3_800766E4;

typedef struct {
    s32 x, y, z, w;
} Q_800766E4;

typedef struct {
    s16 x, y, z;
} SV_800766E4;

typedef struct {
    s32 pad0[0x5F4 / 4];
    s16 pad5F4;
    SV_800766E4 rot;
} Rot_800766E4;

typedef struct {
    u8 pad0[0xE];
    u16 unkE;
} Inp_800766E4;

f32 func_80001CA0(f32);
void func_80046D54(void *, void *, s32 *);
void func_80046E04(void *, void *, s32 *);
void func_80047014(void *, void *, void *);
s32 func_800470A8(void *, void *);
void func_80047D40(void *, void *, void *);
void func_800673B0(void *, void *, void *);
void func_800676D0(void *, s32);
void func_800677F8(void *, s32);
void func_80067920(void *, s32);
void func_8006F280(s32, s32, s32, s32, s32, s32, s32);
void func_8006F9F8(s32, s32, char *, s32, s32, s32, s32);
void func_80073EA0(u8 *);
void func_80075694(u8 *, s32);
void func_80077584(u8 *);
void func_80077A60(u8 *);
void func_80077EFC(u8 *);
extern char D_8001DEC4[];
extern char D_8001DEC8[];
extern char D_8001DECC[];
extern char D_8001DED0[];
extern char D_8001DED4[];
extern u8 D_800D49E0[];
extern u8 D_800D4A30;
extern u8 D_800D4AD0;
extern Inp_800766E4 *D_800D8434;
extern s32 D_800DE0C0;
extern s32 D_800DE0C4;
extern s32 D_800DE0C8;
extern s32 D_800DE12C;
extern s32 D_800DE130;
extern V3_800766E4 D_800DE134;
extern s32 D_800DE148;
extern s32 D_800DE188;
extern s32 D_800DE18C;
extern s32 D_800DE190;
extern s32 D_800DE194;
extern s32 D_800DE198;
extern s32 D_800DE19C;
extern s32 D_800DE808;
extern s32 D_800DE820;
extern s32 D_800DE868;
extern s32 D_800E9038;
extern s32 D_800FBBA0;
extern s32 D_800FBBA4;
extern s32 D_800FBBA8;

#define I32(o) (*(s32 *)(c + (o)))
#define U32(o) (*(u32 *)(c + (o)))
#define S16(o) (*(s16 *)(c + (o)))
#define U16(o) (*(u16 *)(c + (o)))
#define U8(o) (*(u8 *)(c + (o)))
#define V3(o) (*(V3_800766E4 *)(c + (o)))
#define R ((Rot_800766E4 *)c)
#define TGT (*(u8 **)(c + 0x4B4))

static inline s32 rsin_800766E4(s32 a) {
    s32 t;
    s32 r;

    t = a & 0xFFF;
    if (t == 0) {
        r = 0;
    } else {
        t %= 4096;
        r = func_80001CA0((f32)t * 0.000244140625f * 6.283185) * 4096.0f;
    }
    return r;
}

void func_800766E4(u8 *c) {
    Q_800766E4 a;
    Q_800766E4 b;
    Q_800766E4 m;
    Q_800766E4 d;
    Q_800766E4 e;
    Q_800766E4 f;
    Q_800766E4 g;
    s32 i1;
    s32 i2;
    s32 i3;
    s32 i4;
    s32 s;
    s16 amt;

    D_800DE148 = U16(0x208);
    if (I32(0x4BC) != 0) {
        V3(0x4C0) = V3(0x4D0);
        if (I32(0x4CC) != 0) {
            V3(0x4D0) = *(V3_800766E4 *)(TGT + 4);
        } else {
            Q_800766E4 *pb;
            Q_800766E4 *pm;
            u8 *src;

            pb = &b;
            pm = &m;
            src = TGT;
            i1 = 1;
            func_80046D54(pm, src + 4, &i1);
            func_80047014(pb, pm, c + 0x4C0);
            i2 = 3;
            func_80046E04(&a, pb, &i2);
            V3(0x4D0) = *(V3_800766E4 *)&a;
        }
    }
    if (I32(0x4F0) != 0) {
        V3(0x4F4) = V3(0x500);
        if (I32(0x4CC) != 0) {
            V3(0x500) = *(V3_800766E4 *)(*(u8 **)(c + 0x4EC) + 4);
        } else {
            Q_800766E4 *pb;
            Q_800766E4 *pm;
            u8 *src;

            pb = &b;
            pm = &d;
            src = *(u8 **)(c + 0x4EC);
            i3 = 1;
            func_80046D54(pm, src + 4, &i3);
            func_80047014(pb, pm, c + 0x4F4);
            i4 = 3;
            func_80046E04(&a, pb, &i4);
            V3(0x500) = *(V3_800766E4 *)&a;
        }
    }
    if (D_800D4AD0 != 0) {
        if (D_800DE198 != 0) {
            D_800DE194 = 1;
        }
        D_800DE198 = 0;
    } else {
        D_800DE198 = 1;
    }
    if (D_800DE868 != 0 && D_800DE194 != 0 && D_800D49E0[0xF0] != 0) {
        D_800DE188 ^= 1;
        D_800D49E0[0x1ED] = 0;
        D_800D49E0[0x1FD] = 0;
        D_800DE18C = 0;
        D_800D49E0[0x51] = 0;
        D_800DE194 = 0;
        D_800D49E0[0xF1] = 0;
        D_800D49E0[0xE1] = 0;
        D_800DE820 = D_800DE188;
        if (D_800DE188 != 0) {
            D_800FBBA0 = D_800DE0C8;
            D_800FBBA4 = D_800DE0C0;
            D_800FBBA8 = D_800DE0C4;
            D_800DE190 = I32(0x51C);
        }
    }
    if (D_800DE188 != 0) {
        if (D_800DE18C != 0) {
            func_8006F9F8(0x46, 0xB4, D_8001DEC4, 0, 0x64, 0, 0);
            func_8006F280(0x46, 0xBE, D_800DE0C8, 0x64, 0x64, 0x64, 0);
            func_8006F9F8(0x78, 0xB4, D_8001DEC8, 0, 0x64, 0, 0);
            func_8006F280(0x78, 0xBE, D_800DE0C4, 0x64, 0x64, 0x64, 0);
            func_8006F9F8(0xAA, 0xB4, D_8001DECC, 0, 0x64, 0, 0);
            func_8006F280(0xAA, 0xBE, D_800DE0C0, 0x64, 0x64, 0x64, 0);
            func_8006F9F8(0xDC, 0xB4, D_8001DED0, 0, 0x64, 0, 0);
            func_8006F280(0xDC, 0xBE, I32(0x51C), 0x64, 0x64, 0x64, 0);
            func_8006F9F8(0x10E, 0xB4, D_8001DED4, 0, 0x64, 0, 0);
            func_8006F280(0x10E, 0xBE, I32(0x668), 0x64, 0x64, 0x64, 0);
        } else {
            D_800DE820 = 1;
            if (++D_800DE19C >= 11) {
                D_800DE19C = 0;
                if (D_800D4A30 != 0) {
                    D_800DE820 = 0;
                }
            }
        }
        if (D_800D49E0[0x26C] != 0) {
            D_800DE0C8 = D_800FBBA0;
            D_800DE0C0 = D_800FBBA4;
            D_800DE0C4 = D_800FBBA8;
            I32(0x51C) = D_800DE190;
        }
        if (D_800D49E0[0x10] != 0) {
            I32(0x51C)--;
        }
        if (D_800D49E0[0x20] != 0) {
            I32(0x51C)++;
        }
        if (D_800D49E0[0] != 0) {
            I32(0x51C) = 0x100;
        }
        if (D_800D49E0[0x19C] != 0) {
            I32(0x668) -= 10;
        }
        if (D_800D49E0[0x1AC] != 0) {
            I32(0x668) += 10;
        }
        if (D_800D49E0[0x20C] != 0) {
            D_800DE0C0 = D_800D49E0[0x27C] != 0 ? D_800DE0C0 - 0x20 : D_800DE0C0 - 8;
        }
        if (D_800D49E0[0x21C] != 0) {
            D_800DE0C0 = D_800D49E0[0x27C] != 0 ? D_800DE0C0 + 0x20 : D_800DE0C0 + 8;
        }
        if (D_800D49E0[0x22C] != 0) {
            D_800DE0C4 = D_800D49E0[0x27C] != 0 ? D_800DE0C4 - 0x20 : D_800DE0C4 - 8;
        }
        if (D_800D49E0[0x23C] != 0) {
            D_800DE0C4 = D_800D49E0[0x27C] != 0 ? D_800DE0C4 + 0x20 : D_800DE0C4 + 8;
        }
        D_800DE0C4 &= 0xFFF;
        if (D_800D49E0[0x1CC] != 0) {
            D_800DE0C8 = D_800D49E0[0x27C] != 0 ? D_800DE0C8 - 0x20 : D_800DE0C8 - 8;
        }
        if (D_800D49E0[0x1DC] != 0) {
            D_800DE0C8 = D_800D49E0[0x27C] != 0 ? D_800DE0C8 + 0x20 : D_800DE0C8 + 8;
        }
    }
    D_800DE130 = D_800DE0C0;
    D_800DE12C = D_800DE0C4;
    D_800DE134.x = 0;
    D_800DE134.y = D_800DE0C8 << 12;
    D_800DE134.z = 0;
    if (D_800E9038 != 0) {
        if (D_800DE188 != 0) {
            func_80077584(c);
            func_80075694(c, 0x137);
        }
        return;
    }
    U32(0x610)++;
    if (U16(0x520) != 0) {
        I32(0x51C) += I32(0x524);
        U16(0x520)--;
    }
    D_800D8434->unkE = U16(0x51E);
    func_80047D40(c + 0x10, c + 4, c + 0x500);
    if (TGT != NULL && *(u16 *)(TGT + 0x9F6) != 0 && S16(0x546) != 0) {
        if (*(s32 *)(TGT + 0x88) < 0) {
            I32(0x6A4)++;
        } else {
            I32(0x6A4)--;
        }
        I32(0x6A0) += (-*(s32 *)(TGT + 0x88) >> 12) * S16(0x546);
        if (I32(0x6A4) > 0) {
            I32(0x4D4) += I32(0x6A0);
        }
    } else {
        I32(0x6A0) = 0;
        I32(0x6A4) = 0;
    }
    amt = S16(0x544);
    if (amt != 0) {
        if (TGT != NULL) {
            if (*(s32 *)(TGT + 0x88) < 0) {
                D_800DE12C -= amt;
            }
            if (*(s32 *)(TGT + 0x88) > 0) {
                D_800DE12C -= S16(0x544) >> 1;
            }
        }
        D_800DE12C &= 0xFFF;
    }
    switch (I32(0x5B0)) {
    case 1:
        func_80077584(c);
        break;
    case 2:
        func_80077EFC(c);
        break;
    case 23:
        func_80077A60(c);
        goto done;
    }
    if (TGT != NULL && *(s32 *)(TGT + 0x450) == 0) {
        if (func_800470A8(c + 0x4D0, c + 0x4C0) != 0) {
            func_80075694(c, 0x97);
        } else if (U32(0x6D0) < 4) {
            func_80075694(c, 0x97);
        } else if (*(s32 *)(TGT + 0x82C) != 1) {
            func_80075694(c, 0x137);
        } else if (U32(0x610) < 0x12) {
            func_80075694(c, 0x137);
        } else {
            func_80075694(c, 0x97);
        }
    } else {
        func_80075694(c, 0x137);
    }
    func_80047D40(c + 0x10, c + 4, c + 0x500);
    if (R->rot.x != 0 || R->rot.y != 0 || R->rot.z != 0) {
        Q_800766E4 *q;
        Q_800766E4 *pb;
        Q_800766E4 *pm;
        Q_800766E4 *pe;

        q = (Q_800766E4 *)(c + 0x554);
        pb = &b;
        pm = &m;
        pe = &e;
        s = rsin_800766E4(S16(0x602) * D_800DE808);
        func_800677F8(pe, (s16)((S16(0x5F8) * s) / 4096));
        func_800673B0(pm, &e, c + 0x554);
        pm = &m;
        pe = &f;
        s = rsin_800766E4(S16(0x600) * D_800DE808);
        func_800676D0(pe, (s16)((S16(0x5F6) * s) / 4096));
        func_800673B0(pb, pm, &f);
        pm = &b;
        pe = &g;
        s = rsin_800766E4(S16(0x604) * D_800DE808);
        func_80067920(pe, (s16)((S16(0x5FA) * s) / 4096));
        func_800673B0(&a, pm, &g);
        *q = a;
        *(SV_800766E4 *)&a = R->rot;
        if (S16(0x5F6) < 0) {
            S16(0x5F6) += U8(0x5FC);
        } else {
            S16(0x5F6) -= U8(0x5FC);
        }
        if (S16(0x5F8) < 0) {
            S16(0x5F8) += U8(0x5FD);
        } else {
            S16(0x5F8) -= U8(0x5FD);
        }
        if (S16(0x5FA) < 0) {
            S16(0x5FA) += U8(0x5FE);
        } else {
            S16(0x5FA) -= U8(0x5FE);
        }
        if ((((SV_800766E4 *)&a)->x ^ S16(0x5F6)) & 0x8000) {
            S16(0x5F6) = 0;
        }
        if ((((SV_800766E4 *)&a)->y ^ S16(0x5F8)) & 0x8000) {
            S16(0x5F8) = 0;
        }
        if ((((SV_800766E4 *)&a)->z ^ S16(0x5FA)) & 0x8000) {
            S16(0x5FA) = 0;
        }
    }
done:
    func_80073EA0(c);
}
