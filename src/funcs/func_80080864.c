/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0;
    u8 ids[10];
    u8 padB[0x14 - 0xB];
    s32 flag14;
    u8 pad18[0x25 - 0x18];
    u8 mods[5][5];
    u8 pad3E[0x4A - 0x3E];
    u8 kind[20];
    u16 vals[10][3];
    u16 tot[10];
    u8 padAE;
    u8 base;
    u8 padB0[0];
} Hdr80080864;

typedef struct {
    u8 pad0[0x18];
    s16 off;
    u8 pad1A[2];
    void (*fn)(void *);
} Vt80080864;

typedef struct {
    u8 pad0[0x48];
    Vt80080864 *vt;
    u8 pad4C[0x214 - 0x4C];
    s32 unk214;
} Obj80080864;

typedef struct {
    u8 pad0[0xAE];
    u8 base;
    u8 padAF;
    s32 unkB0;
    Obj80080864 *obj;
    u8 padB8[0x114 - 0xB8];
    s32 skip;
    s32 unk118;
} Tail80080864;

typedef struct {
    u8 pad0[0x2C];
    char *name;
    u8 pad30[0x154 - 0x30];
} Player80080864;

typedef struct {
    u8 pad0[0xC];
    u8 f[8];
} Ent80080864;

void func_800057E4(char *, char *, ...);
void func_80039E60(s32, s32, s32);
s32 func_80049D60(s32);
void func_80066310(s32, s32);
void func_8006DF40(s32, s32, char *, s32, s32, s32, s32);
void func_8006EEF0(void);
void func_8006F1A8(s32, s32, s32, s32);
void func_8006F23C(s32);
Obj80080864 *func_80082010(s32, s32, s32, s32, f32, s32);
void func_80095870(s32);
extern char D_8001E5D4[];
extern char D_8001E5E8[];
extern char D_8001E5FC[];
extern char D_8001E610[];
extern char D_8001E61C[];
extern char D_8001E62C[];
extern char D_8001E63C[];
extern char D_8001E64C[];
extern s32 D_800C0E20;
extern Player80080864 D_800D4D80[];
extern s32 D_800DDE04;
extern char *D_800DE610[9];
extern u16 D_800DE636;
extern u16 D_800DE638;
extern u16 D_800DE63A;
extern u16 D_800DE63C;
extern u8 D_800DE640[];
extern u8 *D_800DE7A8;
typedef struct {
    Ent80080864 e[125];
    s32 v[8];
} Big80080864;

extern Big80080864 D_800DE9F4;

#define HDR ((Hdr80080864 *)s)
#define TL ((Tail80080864 *)s)

static inline s32 done80080864(Obj80080864 *o) {
    s32 r = 1;
    if (o != NULL) {
        r = o->unk214 >= 40;
    }
    return r;
}

void func_80080864(void) {
    u8 *s;
    u8 i;
    u8 k;
    s32 kind;
    s32 v;
    u8 *m;
    s32 t;
    s32 c2;
    s32 n;
    s32 q;
    s32 r;
    s32 w;
    s32 j;
    s32 place;
    s32 p1;
    s32 p2;
    s32 p3;
    char buf[0x28];

    s = D_800DE640;
    func_8006EEF0();
    while (1) {
        if (TL->base >= 3) {
            break;
        }
        i = 0;
        while (1) {
            if (i >= 10) {
                break;
            }
            if (i != TL->skip) {
                kind = HDR->kind[i];
                if (kind == 0) {
                    v = D_800DE636;
                } else if (kind == 1) {
                    v = D_800DE638;
                } else if (kind == 2) {
                    v = D_800DE63A;
                } else {
                    v = D_800DE63C + func_80049D60(D_800DE63A - D_800DE63C);
                }
                v -= func_80049D60(0x12);
                for (k = 0; k < 5; k++) {
                    m = s + k * 5;
                    if (i == m[0x25]) {
                        v += m[0x26];
                    }
                    if (i == m[0x27]) {
                        v -= m[0x28];
                    }
                }
                HDR->vals[i][TL->base] = v;
            }
            i++;
        }
        TL->base++;
        c2 = 0;
        while (1) {
            u32 a, b, c;
            if (c2 >= 10) {
                break;
            }
            a = HDR->vals[c2][0];
            b = HDR->vals[c2][1];
            c = HDR->vals[c2][2];
            if (a < b && a < c) {
                HDR->tot[c2] = b + c;
            } else if (b < a && b < c) {
                HDR->tot[c2] = a + c;
            } else {
                HDR->tot[c2] = a + b;
            }
            c2++;
        }
    }
    for (n = 0; n < 10; n++) {
        HDR->kind[n] = n;
    }
    t = 1;
    while (1) {
        if (t >= 10) {
            break;
        }
        j = t;
        do {
            u8 x;
            u8 y;
            if (!(HDR->tot[HDR->kind[j]] > HDR->tot[HDR->kind[j - 1]])) {
                break;
            }
            x = HDR->kind[j];
            y = HDR->kind[j - 1];
            HDR->kind[j - 1] = x;
            HDR->kind[j] = y;
            j--;
        } while (j > 0);
        t++;
    }
    func_8006F23C(0x100);
    func_8006F1A8(0x7A, 0x7A, 0x7A, 0);
    c2 = 0;
    for (q = 0; q < 10; q++) {
        if (HDR->kind[q] == TL->skip) {
            place = q;
        }
    }
    switch (place) {
    case 0:
        func_8006DF40(0x100, 0x28, D_8001E5D4, 0, 0, 0x100, 0);
        if (TL->obj == NULL) {
            func_80066310(D_800C0E20, 5);
            TL->obj = func_80082010(5, 0xA0, 0x91, 0x8C, 0.8f, 10);
        }
        if (HDR->flag14 == 0) {
            func_80039E60(0x2D, 10000, 0);
            func_80039E60(0x30, 10000, 0);
            HDR->flag14 = 1;
        }
        break;
    case 1:
        func_8006DF40(0x100, 0x28, D_8001E5E8, 0, 0, 0x100, 0);
        if (TL->obj == NULL) {
            func_80066310(D_800C0E20, 6);
            TL->obj = func_80082010(6, 0xA0, 0x91, 0x8C, 0.8f, 10);
        }
        if (HDR->flag14 == 0) {
            func_80039E60(0x30, 10000, 0);
            HDR->flag14 = 1;
        }
        break;
    case 2:
        func_8006DF40(0x100, 0x28, D_8001E5FC, 0, 0, 0x100, 0);
        if (TL->obj == NULL) {
            func_80066310(D_800C0E20, 7);
            TL->obj = func_80082010(7, 0xA0, 0x91, 0x8C, 0.8f, 10);
        }
        if (HDR->flag14 == 0) {
            func_80039E60(0x2D, 10000, 0);
            HDR->flag14 = 1;
        }
        break;
    default:
        if (HDR->flag14 == 0) {
            func_80039E60(0x2F, 10000, 0);
            HDR->flag14 = 1;
        }
        func_8006DF40(0x100, 0x28, D_8001E610, 0, 0, 0x100, 0);
        for (r = 0; r < 10; r++) {
            if (HDR->kind[0] == r) {
                p1 = r;
            }
            if (HDR->kind[11] == r) {
                p2 = r;
            }
            if (HDR->kind[12] == r) {
                p3 = r;
            }
        }
        func_8006F1A8(0xB6, 0x84, 0x24, 0);
        func_8006F23C(0xA0);
        func_800057E4(buf, D_8001E61C, D_800D4D80[HDR->ids[p1]].name);
        func_8006DF40(0x100, 0x3C, buf, 0, 0, 0x100, 0);
        func_800057E4(buf, D_8001E62C, D_800D4D80[HDR->ids[p2]].name);
        func_8006DF40(0x100, 0x46, buf, 0, 0, 0x100, 0);
        func_800057E4(buf, D_8001E63C, D_800D4D80[HDR->ids[p3]].name);
        func_8006DF40(0x100, 0x50, buf, 0, 0, 0x100, 0);
        func_8006F1A8(0x7A, 0x7A, 0x7A, 0);
        func_800057E4(buf, D_8001E64C, place + 1);
        func_8006F23C(0x180);
        func_8006DF40(0x100, 0x78, D_800D4D80[HDR->ids[TL->skip]].name, 0, 0, 0x100, 0);
        func_8006DF40(0x100, 0x96, buf, 0, 0, 0x100, 0);
        break;
    }
    if (TL->obj != NULL) {
        Obj80080864 *o = TL->obj;
        o->vt->fn((u8 *)o + o->vt->off);
        TL->unkB0 = 0;
        if (D_800DE9F4.e[*(s32 *)(D_800DE7A8 + 0x3E0)].f[D_800C0E20] & 0xE0) {
            TL->unkB0 = 1 << D_800C0E20;
        }
        func_8006F23C(0x100);
        func_8006F1A8(0x7A, 0x7A, 0x7A, 0);
        w = D_800DE9F4.v[*(s32 *)(D_800DE7A8 + 0x3E0)];
        if (w == 0x148) {
            if (D_800DE610[6] != NULL) {
                func_8006DF40(0x100, 0x9B, D_800DE610[6], 0, 0, 0x100, 0);
            }
            if (D_800DE610[7] != NULL) {
                func_8006DF40(0x100, 0xAF, D_800DE610[7], 0, 0, 0x100, 0);
            }
            if (D_800DE610[8] != NULL) {
                func_8006DF40(0x100, 0xC3, D_800DE610[8], 0, 0, 0x100, 0);
            }
        } else {
            switch ((w & TL->unkB0) ^ TL->unkB0) {
            case 8:
                if (D_800DE610[0] != NULL) {
                    func_8006DF40(0x100, 0x9B, D_800DE610[0], 0, 0, 0x100, 0);
                }
                if (D_800DE610[1] != NULL) {
                    func_8006DF40(0x100, 0xAF, D_800DE610[1], 0, 0, 0x100, 0);
                }
                if (D_800DE610[2] != NULL) {
                    func_8006DF40(0x100, 0xC3, D_800DE610[2], 0, 0, 0x100, 0);
                }
                break;
            case 0x40:
                if (D_800DE610[3] != NULL) {
                    func_8006DF40(0x100, 0x9B, D_800DE610[3], 0, 0, 0x100, 0);
                }
                if (D_800DE610[4] != NULL) {
                    func_8006DF40(0x100, 0xAF, D_800DE610[4], 0, 0, 0x100, 0);
                }
                if (D_800DE610[5] != NULL) {
                    func_8006DF40(0x100, 0xC3, D_800DE610[5], 0, 0, 0x100, 0);
                }
                break;
            case 0x100:
                if (D_800DE610[6] != NULL) {
                    func_8006DF40(0x100, 0x9B, D_800DE610[6], 0, 0, 0x100, 0);
                }
                if (D_800DE610[7] != NULL) {
                    func_8006DF40(0x100, 0xAF, D_800DE610[7], 0, 0, 0x100, 0);
                }
                if (D_800DE610[8] != NULL) {
                    func_8006DF40(0x100, 0xC3, D_800DE610[8], 0, 0, 0x100, 0);
                }
                break;
            }
        }
        if (!done80080864(TL->obj)) {
            return;
        }
    }
    if (TL->unk118 == 0) {
        func_80095870(D_800DDE04);
    }
}
