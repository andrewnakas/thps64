#include "common.h"

typedef struct Elem8005E500 {
    u8 pad0[0x1B];
    s8 unk1B;
    struct Elem8005E500 *next;
    u8 pad20[4];
} Elem8005E500;

typedef struct {
    u8 pad0[8];
    s32 count;
    Elem8005E500 elems[1];
} List8005E500;

typedef struct {
    u8 pad0[0x1C];
    List8005E500 *list;
    u8 pad20[0x3A - 0x20];
    s8 unk3A;
    u8 pad3B[0x48 - 0x3B];
} Ent8005E500;

extern s32 D_800DA670;
extern s32 D_800DA674;
extern s32 D_800DA678;
extern s32 D_800DA67C;
extern Ent8005E500 D_800DAF98[];

void func_8005E500(s32 arg0, s32 arg1, s32 arg2) {
    Ent8005E500 *base;
    Ent8005E500 *e;
    List8005E500 *l;
    Elem8005E500 *p;
    u8 *q;
    s32 n;
    s32 i;
    s32 m;
    s32 last;

    if (D_800DA670 != -1) {
        m = 0x12;
        if (D_800DA670 == m) {
            D_800DA674 = 0;
            D_800DA678 = 1;
            D_800DA67C = 2;
        } else {
            D_800DA674 = 0x10;
            D_800DA678 = 0x11;
            D_800DA67C = m;
        }
    }
    base = D_800DAF98;
    e = &base[arg0];
    e->unk3A = arg2;
    l = e->list;
    n = l->count;
    p = l->elems;
    i = 0;
    if (i < n) {
        last = n - 1;
        q = (u8 *)&p->unk1B;
        do {
            if (i < last) {
                *(Elem8005E500 **)(q + 1) = p + 1;
            } else {
                *(Elem8005E500 **)(q + 1) = NULL;
            }
            *q = arg0;
            i++;
            q += sizeof(Elem8005E500);
            p++;
        } while (i < n);
    }
}
