/* cflags: -fexpensive-optimizations */
/* NON_MATCHING: aln 0.742. Equivalent C (w2_/h2_ are the same inline as w_/h_, written to force a shared register); cross-jump/fold shape of the repeated width/height inlines differs. */
/* NEARLY (G16) 243/297 (was G5 202). Findings: the game's "b += 3" bnel/beql shape (W2, W3, H2) is the same inline as the
   "t = b + 3" shape after cross-jumping, when t, b and the result share one hard reg (v1); here forced with a w2_/h2_ variant.
   Binary ops with a ternary operand get distributed by fold (10 - (c ? a : b)); inline-function wrappers (WID2) avoid that
   but preexpand_calls then hoists W3/H2 before t-18 and the 0x840 load (game evaluates them in place).
   'k = S32(arg0, 0x840);' as its own statement gives the game's 840-load-before-t-18 order with plain macros (55570j, 218). */
#include "common.h"

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Vec3i_80055570;

typedef struct {
    u8 pad0[0x18];
    s32 x18;
    u8 pad1C[4];
    s32 x20;
    u8 pad24[0x154 - 0x24];
} Row80055570;

void func_8004CACC(u8 *, s32, char *, s32, s32);
void func_8004D048(u8 *, s32, s32);
void func_80046D28(Vec3i_80055570 *, void *);
s32 func_800474C8(void *);
void func_80046F58(Vec3i_80055570 *, Vec3i_80055570 *, s32 *);
extern char D_8001BBBC[];
extern Row80055570 D_800D4D80[];
extern s32 D_800D6FC8;
extern s32 D_800DE86C;

#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
static inline s32 w_(u8 *p) {
    s32 x;
    s32 b;
    s32 t;

    x = D_800D4D80[S32(p, 0x3E0)].x18;
    b = (*(u8 **)(p + 0x290))[0];
    if (S32(p, 0x34C) != 0 || D_800DE86C != 0) {
        t = b + 3;
        return x + t;
    }
    return x + b;
}

static inline s32 h_(u8 *p) {
    s32 x;
    s32 b;
    s32 t;

    x = D_800D4D80[S32(p, 0x3E0)].x20;
    b = (*(u8 **)(p + 0x290))[2];
    if (S32(p, 0x34C) != 0 || D_800DE86C != 0) {
        t = b + 3;
        return x + t;
    }
    return x + b;
}

static inline s32 w2_(u8 *p) {
    s32 x;
    s32 b;

    x = D_800D4D80[S32(p, 0x3E0)].x18;
    b = (*(u8 **)(p + 0x290))[0];
    if (S32(p, 0x34C) != 0 || D_800DE86C != 0) {
        b += 3;
    }
    return x + b;
}

static inline s32 h2_(u8 *p) {
    s32 x;
    s32 b;

    x = D_800D4D80[S32(p, 0x3E0)].x20;
    b = (*(u8 **)(p + 0x290))[2];
    if (S32(p, 0x34C) != 0 || D_800DE86C != 0) {
        b += 3;
    }
    return x + b;
}
static inline s32 WID2(u8 *p) { return D_800D6FC8 != 0 ? D_800D6FC8 : w2_(p); }
static inline s32 HGT2(u8 *p) { return D_800D6FC8 != 0 ? D_800D6FC8 : h2_(p); }
static inline s32 WID(u8 *p) { return D_800D6FC8 != 0 ? D_800D6FC8 : w_(p); }
static inline s32 HGT(u8 *p) { return D_800D6FC8 != 0 ? D_800D6FC8 : h_(p); }

void func_80055570(u8 *arg0) {
    Vec3i_80055570 a;
    Vec3i_80055570 b;
    s32 c;
    Vec3i_80055570 *pos;
    s32 *p88;
    s32 w;
    s32 t;
    s32 r;

    func_8004CACC(arg0, 0x41, D_8001BBBC, 100, 0);
    {
        s32 *dst = (s32 *)(arg0 + 0x840);
        *dst = 15 - ((D_800D6FC8 != 0 ? D_800D6FC8 : w_(arg0)) + (D_800D6FC8 != 0 ? D_800D6FC8 : h_(arg0))) / 2;
    }
    func_8004D048(arg0, 1, 0x17B8);
    S32(arg0, 0x838) = 1;
    pos = (Vec3i_80055570 *)(arg0 + 0x84);
    func_80046D28(&b, arg0 + 0x8D0);
    c = func_800474C8(pos);
    func_80046F58(&a, &b, &c);
    *(Vec3i_80055570 *)(arg0 + 0x84) = a;
    S32(arg0, 0x84) += S32(arg0, 0x8D0) * 5;
    S32(arg0, 0x8C) += S32(arg0, 0x8D8) * 5;
    p88 = (s32 *)(arg0 + 0x88);
    w = D_800D6FC8 != 0 ? D_800D6FC8 : w_(arg0);
    t = 32 - (10 - WID2(arg0)) / 2;
    r = (S32(arg0, 0x840) * ((t - 18 + (10 - WID2(arg0)) / 3) << 10)) / (15 - (w + HGT2(arg0)) / 2);
    *p88 = S32(arg0, 0x88) - (((32 - (10 - WID(arg0)) / 2) << 10) + r) * 3;
}
