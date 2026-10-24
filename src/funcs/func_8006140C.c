/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct Trig {
    void *data;
    s8 unk4;
    s8 unk5;
    s8 unk6;
    s8 unk7;
    s16 unk8;
    s16 unkA;
    s32 unkC;
    struct Trig *hash;
    struct Trig *next;
} Trig;

void *func_8005EAB4(s32, s32, s32);
void func_8005F2F8(s32);
u16 *func_800617B8(void *, s32);
void func_8006A224(s32, u16, s32);
void func_80073A40(s32);
s32 func_8009E30C(s32);
extern s16 **D_800DACB0;
extern s32 D_800DACB4;
extern s32 D_800DACBC;
extern Trig *D_800DACC0;
extern s32 D_800DACC8;
extern void *D_800DACD0[];
extern s32 D_800DE524;
extern Trig *D_800FB750[];

static inline u8 has_one(s16 *p) {
    u8 *s; u8 c; s = (u8 *)(p[3] * 2 + (s32)p); s = s + 8; c = s[0];

    while (c != 0xFF) {
        if (c == 1) {
            return 1;
        }
        s++;
        c = *s;
    }
    return 0;
}

static inline void add_trig(s32 i, s32 val, void *data) {
    Trig *t = func_8005EAB4(0x18, 0, 1);
    Trig **slot;

    t->next = D_800DACC0;
    D_800DACC0 = t;
    slot = &D_800FB750[val & 0xFF];
    t->hash = *slot;
    *slot = t;
    t->unk4 = 0;
    t->unk5 = 0;
    t->unkA = i;
    t->data = data;
    t->unkC = val;
    t->unk7 = 0;
    t->unk6 = 0;
    t->unk8 = 0;
}

static inline void clear_(void **a, s32 j) {
    for (; j >= 0; j--) {
        a[j] = 0;
    }
}

void func_8006140C(void) {
    s32 sp10[4];
    s16 *p;
    s32 i;
    void **pp;
    s32 k;

    i = 0;
    while (1) {
        if (i >= D_800DACB4) {
            break;
        }
        p = D_800DACB0[i];
        switch (*p) {
        case 7:
            has_one(p);
            break;
        case 1:
            if (has_one(p)) {
                func_8005F2F8(i);
            }
            break;
        case 5:
            if (*func_800617B8(sp10, i) == 1) {
                func_8005F2F8(i);
            }
            break;
        case 6:
            p++;
            p = (s16 *)((u8 *)p + (*p * 2 + 2));
            if ((s32)p & 2) {
                p++;
            }
            add_trig(i, *(s32 *)p, p + 2);
            break;
        case 2:
        case 9:
            p++;
            p = (s16 *)((u8 *)p + (*p * 2 + 2));
            if ((s32)p & 2) {
                p++;
            }
            add_trig(i, *(s32 *)p, &D_800DACC8);
            break;
        case 500:
            func_800617B8(sp10, i);
            D_800DE524 = 1;
            break;
        case 12:
        case 14:
            func_8006A224(func_8009E30C(0x14), i, 0);
            break;
        case 13:
            func_80073A40(i);
            break;
        }
        i++;
    }
    clear_(D_800DACD0, 0x27);
    D_800DACBC = 0;
    k = 0;
    while (1) {
        if (k >= D_800DACB4) {
            break;
        }
        if (*D_800DACB0[k] == 8) {
            pp = (void *)((u8 *)func_800617B8(sp10, k) + 6);
            D_800DACD0[D_800DACBC++] = pp;
        }
        k++;
    }
}
