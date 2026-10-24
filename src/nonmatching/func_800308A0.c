/* NON_MATCHING: a2=a1 copy needs optimize_reg_copy_1/reload_cse; k always gets a hard reg; best 383/385. Equivalent C; only register allocation / scheduling / delay-slot choice differ. */
/* Z1: reload_cse_simplify_set only rewrites a SET whose source is a MEM/constant (never a register), and CSE
   prefers the pseudo (cost 0) over a1 for `a2 = k`; so the game's move a2,a1 needs k without a hard reg. Setting
   `one = 1.0f` earlier (before calls) only puts it in f20 (sdc1 save, 377/385). */
/* D1 NEARLY func_800308A0 383/385 (-O1): static inline scale(p,k){func_800A773C(p,k,k);} called with an f32 local gives lwc1 f0 + mfc1 a1 like the game; only diff: game sets a2 by 'move a2,a1' (jal slot) after 'move a0,s0', ours 'mfc1 a2,f0' and move a0 in the slot.
   Diagnosis (RTL dumps): a2=a1 is local-alloc optimize_reg_copy_1, which only runs with -fexpensive-optimizations (seen in func_8003AF00 -O2 lreg). With -fexpensive, calls.c precomputes every &buf arg into a pseudo and CSE merges them into one pseudo living 211 insns -> extra s-reg (s4), 235/385. Untried idea: get reload_cse_regs (runs at -O1) to do it, i.e. make the 1.0 pseudo get no hard reg so reload substitutes the constant and reload_cse finds a1. */
#include "common.h"

void func_80039500(void);
void func_8003A69C(void *);
void func_8003A8B4(void *);
void func_800242CC(void);
void func_800334C4(u8 *);
void func_80033400(u8 *);
void func_8008B490(void *, void *, s32);
void func_8008BB2C(void *, s32);
void func_8008BB50(void *);
void func_800A72C0(void *);
void func_800A73EC(void *, s32);
void func_800A773C(void *, f32, f32);
void func_800A7AF8(void *, s32, s32, s32, s32);
void func_800A7B10(void *, s32, s32, s32, s32);
void func_800B198C(void *);
void func_800B1A80(void *, s32);

typedef struct {
    u16 x0;
    u16 x2;
    u8 pad4[4];
    u8 x8;
    u8 pad9[0x17];
} Sub800308A0;

typedef struct {
    u8 pad0[0x54];
    Sub800308A0 e[8];
} Row800308A0;

typedef struct {
    u8 pad0[8];
    u8 x8;
    u8 pad9[0x14 - 9];
} Ent800308A0;

extern s32 D_80019C38[];
extern u16 D_80019C44[];
extern u8 D_80019C10[];
extern u8 D_8001A2F0[];
extern u8 D_800D0FC0[];
extern s32 D_800D36C0;
extern u8 D_800D3F34[];
extern u8 D_800D4770[];
extern u8 D_800D4778[];
extern Row800308A0 D_800D4D80[];
extern u8 D_800DE9F4[];
extern f32 D_800EA9B0;
extern f32 D_800ECEF0;

#define ENT(g, i) (((Ent800308A0 *)(g))[i])
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))

static inline void scale(void *p, f32 k) { func_800A773C(p, k, k); }
u8 *func_800308A0(u8 *arg0) {
    s32 buf;
    u8 *cfg;
    u8 *g;
    u8 *q;
    f32 f;
    f32 one;

    func_80039500();
    *(u8 **)(arg0 + 0x2C) = D_80019C10;
    func_800A72C0(arg0 + 0x58);
    func_800A72C0(arg0 + 0x298);
    func_800B198C(arg0 + 0x4F8);
    func_800B198C(arg0 + 0x50C);
    func_800B198C(arg0 + 0x520);
    func_800B198C(arg0 + 0x534);
    func_800B198C(arg0 + 0x548);
    func_800B198C(arg0 + 0x55C);
    *(u8 **)(arg0 + 0x56C) = D_8001A2F0;
    func_800B198C(arg0 + 0x570);
    *(u8 **)(arg0 + 0x580) = D_8001A2F0;
    func_800B198C(arg0 + 0x584);
    *(u8 **)(arg0 + 0x594) = D_8001A2F0;
    func_800B198C(arg0 + 0x598);
    *(u8 **)(arg0 + 0x5A8) = D_8001A2F0;
    func_800B198C(arg0 + 0x5AC);
    *(u8 **)(arg0 + 0x5BC) = D_8001A2F0;
    func_800B198C(arg0 + 0x5C0);
    *(u8 **)(arg0 + 0x5D0) = D_8001A2F0;
    func_800B198C(arg0 + 0x5D4);
    func_800B198C(arg0 + 0x5E8);
    func_800B198C(arg0 + 0x5FC);
    func_800B198C(arg0 + 0x610);
    q = D_800D3F34;
    func_8003A69C(q);
    func_8003A8B4(q);
    f = D_800D36C0;
    D_800ECEF0 = f;
    D_800EA9B0 = f;
    func_800242CC();
    cfg = D_800D0FC0;
    arg0[0x3C] = cfg[0x14];
    arg0[0x3D] = cfg[0x15];
    arg0[0x3E] = 0;
    arg0[0x3F] = 0;
    g = D_800DE9F4;
    S32(arg0, 0x4C) = ENT(g, arg0[0x3C]).x8 >= D_800D4D80[arg0[0x3C]].e[arg0[0x3E]].x8;
    S32(arg0, 0x50) = ENT(g, arg0[0x3D]).x8 >= D_800D4D80[arg0[0x3D]].e[arg0[0x3F]].x8;
    if (S32(arg0, 0x4C)) {
        S16(arg0, 0x54) = D_800D4D80[arg0[0x3C]].e[arg0[0x3E]].x0;
    } else {
        S16(arg0, 0x54) = 0x40;
    }
    if (S32(arg0, 0x50)) {
        S16(arg0, 0x56) = D_800D4D80[arg0[0x3D]].e[arg0[0x3F]].x0;
    } else {
        S16(arg0, 0x56) = 0x40;
    }
    func_800334C4(arg0);
    func_80033400(arg0);
    S32(arg0, 0x34) = 0;
    S32(arg0, 0x38) = 0;
    arg0[0x40] = 0;
    arg0[0x41] = 0;
    arg0[0x42] = 0;
    arg0[0x43] = 0;
    arg0[0x44] = 0;
    arg0[0x45] = 0;
    arg0[0x46] = 1;
    arg0[0x47] = 1;
    arg0[0x48] = D_800D4770[arg0[0x46]];
    arg0[0x49] = D_800D4770[arg0[0x47]];
    arg0[0x4A] = 0;
    arg0[0x4B] = 0;
    func_800B1A80(arg0 + 0x548, 0xF);
    S32(arg0, 0x54C) = 1;
    func_8008BB50(&buf);
    func_800A73EC(arg0 + 0x58, 0x501);
    func_8008B490(&buf, arg0 + 0x58, 0x501);
    arg0[0x68] = 1;
    func_800A7AF8(arg0 + 0x58, 0x87, 0xC2, 0xF3, 0xFF);
    func_800A7B10(arg0 + 0x58, 0x87, 0xC2, 0xF3, 0xFF);
    func_800A773C(arg0 + 0x58, 1.10000002f, 1.20000005f);
    S16(arg0, 0x642) = 0x87;
    S16(arg0, 0x644) = 0x18B;
    S16(arg0, 0x646) = 0;
    S16(arg0, 0x648) = 0;
    func_800A73EC(arg0 + 0x298, 0x501);
    func_8008B490(&buf, arg0 + 0x298, 0x501);
    arg0[0x2A8] = 1;
    func_800A7B10(arg0 + 0x298, 0xFC, 0xD6, 0x85, 0xFF);
    func_800A7AF8(arg0 + 0x298, 0xFC, 0xD6, 0x85, 0xFF);
    one = 1.0f;
    scale(arg0 + 0x298, one);
    func_800B1A80(arg0 + 0x55C, *(u16 *)(arg0 + 0x54));
    S32(arg0, 0x560) = 1;
    func_800B1A80(arg0 + 0x570, *(u16 *)(arg0 + 0x56));
    S32(arg0, 0x574) = 1;
    func_800B1A80(arg0 + 0x5D4, D_80019C44[arg0[0x46]]);
    S32(arg0, 0x5D8) = 1;
    func_800B1A80(arg0 + 0x5E8, D_80019C44[arg0[0x47]]);
    S32(arg0, 0x5EC) = 1;
    func_800B1A80(arg0 + 0x5AC, D_800D4778[arg0[0x44]]);
    S32(arg0, 0x5B0) = 1;
    func_800B1A80(arg0 + 0x5C0, D_800D4778[arg0[0x45]]);
    S32(arg0, 0x5C4) = 1;
    func_800B1A80(arg0 + 0x5FC, D_80019C38[arg0[0x4A]]);
    S32(arg0, 0x600) = 1;
    func_800B1A80(arg0 + 0x610, D_80019C38[arg0[0x4B]]);
    S32(arg0, 0x614) = 1;
    func_800B1A80(arg0 + 0x4F8, 0x8F);
    S32(arg0, 0x4FC) = 1;
    func_800B1A80(arg0 + 0x50C, 0x8D);
    S32(arg0, 0x510) = 1;
    func_800B1A80(arg0 + 0x520, 0x8E);
    S32(arg0, 0x524) = 1;
    func_800B1A80(arg0 + 0x534, 0x94);
    S32(arg0, 0x538) = 1;
    *(f32 *)(arg0 + 0x630) = 0.457379967f;
    S16(arg0, 0x664) = 0xA4;
    S16(arg0, 0x66A) = 0x7F;
    S16(arg0, 0x66C) = 0xDE;
    S16(arg0, 0x66E) = 0xC2;
    S16(arg0, 0x674) = 0x11A;
    S16(arg0, 0x676) = 0xD4;
    S16(arg0, 0x634) = 0xB8;
    S16(arg0, 0x636) = 0x1C2;
    S16(arg0, 0x64A) = S16(arg0, 0x652) = 0x8D;
    S16(arg0, 0x638) = 0xE8;
    S16(arg0, 0x656) = S16(arg0, 0x658) = 0xCA;
    S16(arg0, 0x63C) = 0x12C;
    S16(arg0, 0x640) = S16(arg0, 0x65A) = 0xDF;
    S16(arg0, 0x63E) = 0x231;
    S16(arg0, 0x63A) = 0x1F3;
    S16(arg0, 0x650) = S16(arg0, 0x654) = S16(arg0, 0x64A);
    S16(arg0, 0x64E) = S16(arg0, 0x634);
    S16(arg0, 0x64C) = S16(arg0, 0x636);
    S16(arg0, 0x65C) = S16(arg0, 0x63C);
    S16(arg0, 0x65E) = S16(arg0, 0x63E);
    S16(arg0, 0x660) = S16(arg0, 0x662) = S16(arg0, 0x640);
    S16(arg0, 0x666) = 0x1AE;
    S16(arg0, 0x668) = 0x7F;
    S16(arg0, 0x670) = 0x1E8;
    S16(arg0, 0x672) = 0xC2;
    S16(arg0, 0x678) = 0x225;
    S16(arg0, 0x67A) = 0xD4;
    S32(arg0, 0x624) = 0;
    func_8008BB2C(&buf, 2);
    return arg0;
}
