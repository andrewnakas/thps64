/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 b[0x6000];
} Big71E0;

typedef struct {
    s32 a;
    s32 b;
} Pair71E0;

typedef struct {
    u32 unk0;
    Pair71E0 pair[5];
    u8 pad2C[0x2C - 0x2C];
    u16 unk2C;
    u16 unk2E;
    u16 unk30;
    u16 unk32;
    u16 unk34;
    u8 pad36[0x40 - 0x36];
    u32 data[6000];
} Hdr71E0;

typedef struct {
    u8 pad0[4];
    u8 *unk4;
    u8 pad8[0x1C - 0x8];
    u32 unk1C;
    u8 pad20[0x50 - 0x20];
    Pair71E0 pair[5];
} Pl71E0;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} S929C;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} S4818;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
} S47CC;

typedef struct {
    u8 pad0[0x56];
    u16 unk56;
    u8 pad58[0x20 - 0x58 + 0x38];
} Sub4D80;

typedef struct {
    u8 pad0[0x23];
    u8 unk23;
} S0FC0;

typedef struct {
    u8 pad0[0x866];
    u8 unk866;
    u8 pad867;
    u8 unk868;
} S9F4;

typedef struct {
    u8 pad0[0xC];
    s32 unkC;
    S4818 *unk10;
} SECF0;

void func_8003A880(void *, S929C *, Pl71E0 *, S0FC0 *);
Big71E0 *func_8009B7D8(void *, void *, s32, s32);
void func_8009ECF8(void *, Big71E0 *);
extern S0FC0 D_800D0FC0;
extern u8 D_800D3F34[];
extern u16 D_800D4788[];
extern u16 D_800D47A8[];
extern u16 D_800D47CC[][3];
extern s32 D_800D4818[6];
typedef struct {
    u16 x[16];
} Sub71E0;
typedef struct {
    u8 pad[0x56];
    Sub71E0 sub[7];
    u8 pad2[0x154 - 0x56 - 0xE0];
} Ent71E0;
extern Ent71E0 D_800D4D80[];
extern s32 D_800DC614;
extern Pl71E0 D_800DC618;
extern Pl71E0 D_800DC6D8;
extern s32 D_800DE7A0;
extern s32 D_800DE9A8;
extern u8 D_800DE9F4[];
extern s32 D_800DF428;
extern S929C D_800E929C;
extern u8 D_800EA110[];
extern s32 D_800EECF0[];
extern u8 D_800F5684[];

static inline u32 swap32(u32 v) {
    return (v >> 24) | ((v >> 8) & 0xFF00) | ((v & 0xFF00) << 8) | (v << 24);
}

void func_800971E0(u8 *arg0, s32 arg1) {
    s32 n;
    s32 i;
    Hdr71E0 *hdr;
    u16 h;
    Big71E0 *src;
    u32 v;
    u32 *p;
    s32 m;
    s32 cnt;
    S0FC0 *cfg;
    S929C *info;
    s32 *e;

    n = 2;
    switch (*arg0) {
    case 0:
        n = 0;
        break;
    case 1:
        break;
    case 2:
        n = 4;
        break;
    case 3:
        n = 6;
        break;
    }
    D_800DE7A0 = 1;
    *arg0 = *arg0 + 1;
    *arg0 = *arg0 % 4;
    cfg = &D_800D0FC0;
    cfg->unk23 = 4;
    if (arg1 != -1) {
        n = arg1;
        cfg->unk23 = 8;
    }
    D_800DF428 = 1;
    cnt = 6000;
    if (arg1 == -2) {
        hdr = (Hdr71E0 *)(D_800DC618.unk4 + 0x200);
        D_800E929C.unk0 = ((s16 *)D_800DC618.unk4)[0x22C / 2];
        D_800E929C.unk8 = ((s16 *)D_800DC618.unk4)[0x230 / 2];
        D_800E929C.unk4 = ((s16 *)D_800DC618.unk4)[0x22E / 2];
        D_800E929C.unkC = ((s16 *)D_800DC618.unk4)[0x232 / 2];
        D_800E929C.unk10 = ((s16 *)D_800DC618.unk4)[0x234 / 2];
        D_800DC618.unk1C = ((u32 *)D_800DC618.unk4)[0x200 / 4];
        cfg->unk23 = 2;
        func_8003A880(D_800D3F34, &D_800E929C, &D_800DC618, cfg);
    } else {
        hdr = (Hdr71E0 *)(D_800DC618.unk4 + 0x200);
        src = func_8009B7D8(D_800F5684, D_800F5684, n, 8);
        *(Big71E0 *)D_800DC618.unk4 = *src;
        func_8009ECF8(D_800EA110, src);
        h = hdr->unk2C;
        {
            s32 lo = h >> 8;
            s32 hi = (h << 8) & 0xFF00;
            D_800E929C.unk0 = lo | hi;
        }
        h = hdr->unk30;
        D_800E929C.unk8 = (h >> 8) | ((h << 8) & 0xFF00);
        h = hdr->unk2E;
        D_800E929C.unk4 = (h >> 8) | ((h << 8) & 0xFF00);
        h = hdr->unk32;
        D_800E929C.unkC = (h >> 8) | ((h << 8) & 0xFF00);
        h = hdr->unk34;
        D_800E929C.unk10 = (h >> 8) | ((h << 8) & 0xFF00);
        D_800DC618.unk1C = swap32(hdr->unk0);
        p = ((Hdr71E0 *)(D_800DC618.unk4 + 0x200))->data;
        i = 0;
        while (1) {
            if (i >= cnt) {
                break;
            }
            v = *p;
            *p = ((v & 0xFF000000) >> 24) | ((v & 0xFF0000) >> 8) | ((v & 0xFF00) << 8) | (v << 24);
            p++;
            i++;
        }
    }
    info = &D_800E929C;
    m = info->unk0;
    if (m == 0) {
        m = 1;
    }
    D_800DE9A8 = m;
    D_800D4818[0] = D_800D47CC[info->unk4][0];
    D_800D4818[2] = D_800D47CC[info->unk4][1];
    D_800D4818[4] = D_800D47CC[info->unk4][2];
    D_800D4818[1] = D_800D4D80[info->unk4].sub[D_800DE9F4[0x866]].x[0];
    D_800D4818[3] = D_800D4788[D_800DE9F4[0x868]];
    D_800D4818[5] = D_800D47A8[D_800DE9F4[0x868]];
    e = D_800EECF0;
    {
        s32 k = 3;
        e[4] = (s32)D_800D4818;
        e[3] = k;
    }
    for (i = 0; i < 5; i++) {
        D_800DC618.pair[i] = hdr->pair[i];
    }
    if (D_800E929C.unk0 == 2) {
        s32 j;
        u8 *s2;
        u8 *d2;
        D_800DC6D8.unk1C = ((u32 *)D_800DC6D8.unk4)[0x200 / 4];
        j = 0;
        s2 = D_800DC6D8.unk4 + 0x200;
        d2 = (u8 *)&D_800DC6D8;
        for (; j < 5; j++) {
            *(Pair71E0 *)(d2 + 0x50) = *(Pair71E0 *)(s2 + 4);
            s2 += 8;
            d2 += 8;
        }
    }
    D_800E929C.unk0 = -D_800E929C.unk0;
    D_800DC614 = -1;
}
