/* cflags: -fexpensive-optimizations */
/* NON_MATCHING: aln 0.953. Equivalent C; the address of the sp18 guard object is CSEd into s5 here (game: `addiu a0,sp,0x18` at each of its 3 calls). */
/* Z3: best draft 238/241 (C, -fexpensive-optimizations; same score as X1's C++ draft, but linkable). Left: the guard
   object sp18 (func_8008BB50 init / func_8008B490 add / func_8008BB2C(this, 2) = g++-style destructor call) has its
   address CSEd into $s5 (game: `addiu a0,sp,0x18` at each of the 3 calls). Without -fexpensive-optimizations the
   address is recomputed like the game, but the two float args of func_800A773C become two mfc1 (game: a0 first,
   mfc1 a1, then a2 = a1): 237/241. Tried (Z3): aggregate sp18, static-inline wrappers for the 3 guard calls,
   inline scale helper for the float pair, C++ with ~Guard() __asm__("func_8008BB2C") (call vanishes; a default
   ctor with an asm label is a cc1plus "tree_list" error). */
#include "common.h"

typedef struct {
    u8 pad0[0x2C];
    char *name; /* 0x2C */
    u8 pad30[0x124];
} Entry3C9A0;

typedef struct {
    u8 pad0[8];
    u8 f8;
    u8 pad9[0xB];
} Ent14_3C9A0;

s32 func_800057E4(void *, char *, char *);      /* extern */
s32 func_80039500();                            /* extern */
s32 func_8003A69C(void *);                   /* extern */
s32 func_8003A8B4(void *);                   /* extern */
s32 func_8003CD64(void *);                      /* extern */
s32 func_8003DBA8(s32, s32);                    /* extern */
s32 func_8003E1C8();                            /* extern */
s32 func_8003FE90(u8, u8);                          /* extern */
s32 func_8008B490(void *, void *, s32);  /* extern */
s32 func_8008BB2C(void *, s32);          /* extern */
s32 func_8008BB50(void *);                   /* extern */
s32 func_800A5F10(void *);                      /* extern */
s32 func_800A62C4(void *, s32, s32, s32, s32); /* extern */
s32 func_800A72C0(void *);                      /* extern */
s32 func_800A73EC(void *, s32);             /* extern */
s32 func_800A773C(void *, f32, f32);            /* extern */
s32 func_800A7AF8(void *, s32, s32, s32, s32); /* extern */
s32 func_800A7B10(void *, s32, s32, s32, s32); /* extern */
s32 func_800B198C(void *);                      /* extern */
s32 func_800B1A80(void *, s32);             /* extern */
extern char D_8001A1E4[];
extern s32 D_8001A2D0;
extern s32 D_800D3F34;
extern s32 D_800D4760;
extern Entry3C9A0 D_800D4D80[];
extern Ent14_3C9A0 D_800DE9F4[];
extern f32 D_800EA9B0;
extern f32 D_800ECEF0;
extern s32 D_800F3294;
extern s32 D_800F3298;

void *func_8003C9A0(u8 *arg0) {
    s32 sp18;
    void *sp1C;
    void *sp20;
    void *sp24;
    void *sp28;
    void *sp2C;
    void *sp30;
    f32 temp_f0;
    f32 f;
    char *str;
    s32 *q;
    void *temp_fp;
    void *temp_s2;
    void *temp_s3;
    void *temp_s4;
    void *temp_s5;
    void *temp_s6;
    void *temp_s7;
    void *temp_t0;
    void *temp_t0_2;
    void *temp_t0_3;
    void *temp_t0_4;
    void *temp_t0_5;
    void *temp_t0_6;

    func_80039500();
    (*(void **)((u8 *)(arg0) + 0x2C)) = &D_8001A2D0;
    temp_s5 = arg0 + 0x38;
    func_800B198C(temp_s5);
    temp_s2 = arg0 + 0x4C;
    func_800A72C0(temp_s2);
    temp_s3 = arg0 + 0x28C;
    func_800A72C0(temp_s3);
    temp_s6 = arg0 + 0x4F8;
    func_800A5F10(temp_s6);
    temp_s7 = arg0 + 0x51C;
    func_800B198C(temp_s7);
    temp_fp = arg0 + 0x530;
    func_800B198C(temp_fp);
    temp_t0 = arg0 + 0x544;
    sp1C = temp_t0;
    func_800B198C(temp_t0);
    temp_t0_2 = arg0 + 0x558;
    sp20 = temp_t0_2;
    func_800B198C(temp_t0_2);
    temp_s4 = arg0 + 0x56C;
    func_800A72C0(temp_s4);
    temp_t0_3 = arg0 + 0x7B8;
    sp24 = temp_t0_3;
    func_800B198C(temp_t0_3);
    temp_t0_4 = arg0 + 0x7CC;
    sp28 = temp_t0_4;
    func_800B198C(temp_t0_4);
    temp_t0_5 = arg0 + 0x7E0;
    sp2C = temp_t0_5;
    func_800B198C(temp_t0_5);
    temp_t0_6 = arg0 + 0x7F4;
    sp30 = temp_t0_6;
    func_800B198C(temp_t0_6);
    q = &D_800D3F34;
    func_8003A69C(q);
    func_8003A8B4(q);
    temp_f0 = (f32) D_800D4760;
    D_800ECEF0 = temp_f0;
    D_800EA9B0 = temp_f0;
    func_800B1A80(temp_s5, 0x13);
    func_800A62C4(temp_s6, 0, D_800F3294 - 1, 0, D_800F3298 - 1);
    func_8003E1C8();
    func_8003CD64(arg0);
    (*(s32 *)((u8 *)(arg0) + 0x4F4)) = func_8003DBA8(0, (*(s32 *)((u8 *)(arg0) + 0x30)));
    func_8008BB50(&sp18);
    func_800A73EC(temp_s2, 0x501);
    func_8008B490(&sp18, temp_s2, 0x501);
    func_800A7AF8(temp_s2, 0x87, 0xC2, 0xF3, 0xFF);
    func_800A7B10(temp_s2, 0x87, 0xC2, 0xF3, 0xFF);
    (*(s16 *)((u8 *)(arg0) + 0x4EC)) = 0x8C;
    (*(s32 *)((u8 *)(arg0) + 0x4F0)) = 0;
    func_800A73EC(temp_s3, 1);
    func_800A7AF8(temp_s3, 0x87, 0xC2, 0xF3, 0xFF);
    func_800A7B10(temp_s3, 0x87, 0xC2, 0xF3, 0xFF);
    func_800A773C(temp_s3, f = 1.0f, f);
    str = D_8001A1E4;
    func_800057E4(arg0 + 0x4CC, str, D_800D4D80[*(s32 *)((u8 *)arg0 + 0x30)].name);
    (*(s16 *)((u8 *)(arg0) + 0x7AC)) = 0xE9;
    func_800A73EC(temp_s4, 1);
    f = 1.8f;
    func_800A773C(temp_s4, f, f);
    func_800A7AF8(temp_s4, 0x87, 0xC2, 0xF3, 0xFF);
    func_800A7B10(temp_s4, 0x87, 0xC2, 0xF3, 0xFF);
    (*(s8 *)((u8 *)(arg0) + 0x57C)) = 0;
    func_800B1A80(temp_s7, 0xA3);
    (*(s32 *)((u8 *)(arg0) + 0x520)) = 1;
    func_800B1A80(temp_fp, 0xA2);
    (*(s32 *)((u8 *)(arg0) + 0x534)) = 1;
    func_800B1A80(sp1C, 0xA1);
    (*(s32 *)((u8 *)(arg0) + 0x548)) = 1;
    func_800B1A80(sp20, 0x9D);
    (*(s32 *)((u8 *)(arg0) + 0x55C)) = 1;
    func_800B1A80(sp24, 0x8F);
    (*(s32 *)((u8 *)(arg0) + 0x7BC)) = 1;
    func_800B1A80(sp28, 0x8D);
    (*(s32 *)((u8 *)(arg0) + 0x7D0)) = 1;
    func_800B1A80(sp2C, 0x8E);
    (*(s32 *)((u8 *)(arg0) + 0x7E4)) = 1;
    func_800B1A80(sp30, 0x94);
    (*(s32 *)((u8 *)(arg0) + 0x7F8)) = 1;
    (*(s32 *)((u8 *)(arg0) + 0x7B4)) = func_8003FE90((*(u8 *)((u8 *)(arg0) + 0x33)), D_800DE9F4[*(s32 *)((u8 *)arg0 + 0x30)].f8);
    (*(s32 *)((u8 *)(arg0) + 0x518)) = 0;
    func_8008BB2C(&sp18, 2);
    return arg0;
}
