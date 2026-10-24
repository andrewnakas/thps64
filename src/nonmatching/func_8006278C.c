/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* NON_MATCHING: aln 0.799. Equivalent C; the slot-copy destination is recomputed each pass (game: pointer giv), plus register choice in the name/suffix strcat block. */
/* Z3 near-miss 171/193 (from D8 162). Change: the slot copy indexes name[n] / D_800DAF98[slot].name[n] (count-up
   for loop with the n >= 0x11 break): the game's name pointer is a strength-reduced giv and the body reloads name[n]
   like the game. Left: the destination D_800DAF98[slot].name + n is recomputed each pass (game: pointer giv v1 set up
   before the loop, and the break path's `beql ... sb zero` store), and the strcat block's register choice (game c=a1
   with its %hi set first, name copy pointer a2, dst v0). Pointer forms for the destination (b[n], *b++, e->name[n])
   score 159-171. D8 notes: the strcat loops as while (*a) / while (*c). */
#include "common.h"

typedef struct {
    u8 name[0x48];
} Ent_8006278C;

typedef struct {
    u8 name[0x15];
    u8 used;
    u8 mode;
    u8 slot;
    u8 unk18;
} Cache_8006278C;

extern Ent_8006278C D_800DAF98[];
extern Cache_8006278C D_800DADA4[];
extern s32 D_800DAD98;
extern u8 D_8001CA84[];
s32 func_80049034(u8 *, u8 *, s32);

s32 func_8006278C(u8 *name, s32 mode, s32 arg2) {
    s32 i;
    u8 *a;
    u8 *b;
    s32 slot;
    s32 n;

    {
        s32 k;
        for (k = 0; k < 40; k++) {
            if (D_800DAF98[k].name[0] != 0 && func_80049034(name, D_800DAF98[k].name, -1)) {
                return k;
            }
        }
    }
    i = 0;
    while (1) {
        if (i >= 20) {
            break;
        }
        if (D_800DADA4[i].used) {
            u8 *t = D_800DADA4[i].name;
            u8 *s = name;
            s32 eq = 1;
            while (*s) {
                if (*s != *t) {
                    eq = 0;
                    break;
                }
                s++;
                t++;
            }
            if (eq && *t != '.') {
                eq = 0;
            }
            if (eq) {
                return D_800DADA4[i].slot;
            }
        }
        i++;
    }
    slot = -1;
    {
        s32 k;
        for (k = 0; k < 40; k++) {
            if (D_800DAF98[k].name[0] == 0) {
                slot = k;
                break;
            }
        }
    }
    if (mode == 0 || mode == 2) {
        for (n = 0; name[n] != 0; n++) {
            if (n >= 0x11) {
                break;
            }
            D_800DAF98[slot].name[n] = name[n];
        }
        D_800DAF98[slot].name[n] = 0;
    }
    {
        u8 *c = D_8001CA84;

        a = name;
        b = D_800DADA4[D_800DAD98].name;
        while (*a) {
            *b++ = *a++;
        }
        while (*c) {
            *b++ = *c++;
        }
        *b = 0;
    }
    if (mode != 2) {
        D_800DADA4[D_800DAD98].mode = mode != 0;
    } else {
        D_800DADA4[D_800DAD98].mode = mode;
    }
    D_800DADA4[D_800DAD98].slot = slot;
    D_800DADA4[D_800DAD98].used = 1;
    D_800DADA4[D_800DAD98].unk18 = arg2;
    D_800DAD98 = (D_800DAD98 + 1) % 20;
    return slot;
}
