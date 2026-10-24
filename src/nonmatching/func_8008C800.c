/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* NON_MATCHING: aln 0.968. Equivalent C; the game has a dead duplicate lui/addiu of &D_800D49E0 at the start of the first inner button test that this C does not produce. Otherwise the same code. */
/* Z3 near-miss 201/203 (from K16 165). Rewritten from K16: plain while loop for the first selection skip, items
   indexed as arg0->items[arg0->sel] everywhere (no `it` pointer), the two button blocks re-test via the global,
   and the final loop as two sequential ifs (jump threading gives the game's beql to i++); -O2 nosched.
   Left: the game has a dead duplicate `lui v0,%hi(D_800D49E0); addiu v1,v0,%lo(D_800D49E0)` at the start of the
   first inner button test (after the D_800E9044 repeat-timer check). Not reproduced by: a block-local pad pointer,
   an inline btn2(pad, a, b) helper, local copies / reorders of the D_800E9044 condition. */
#include "common.h"

typedef struct {
    s16 cur;
    s16 tgt;
    u16 on;
    u16 off;
    u8 pad8;
    u8 enabled;
    u8 selectable;
    u8 padB[0x18 - 0xB];
} Item8008C800;

typedef struct {
    u8 pad0[2];
    u8 sel;
    u8 pad3[2];
    u8 count;
    u8 pad6[0x18 - 0x6];
    Item8008C800 items[1];
} Menu8008C800;

extern void func_80039E60(s32, s32, s32);
extern u8 D_800D49E0[];
extern s32 D_800E9044;

void func_8008C800(Menu8008C800 *arg0) {
    s32 i;
    s32 j;
    s32 n;

    n = arg0->count;
    for (j = 0; j < n; j++) {
    }
    while (arg0->items[arg0->sel].enabled == 0) {
        arg0->items[arg0->sel].tgt = arg0->items[arg0->sel].off;
        arg0->items[arg0->sel].cur = arg0->items[arg0->sel].off;
        if (++arg0->sel >= arg0->count) {
            arg0->sel = 0;
        }
        arg0->items[arg0->sel].tgt = arg0->items[arg0->sel].on;
        arg0->items[arg0->sel].cur = arg0->items[arg0->sel].off;
    }
    if (D_800D49E0[0xA0] != 0 || D_800D49E0[0xB0] != 0 || D_800D49E0[0x22C] != 0 || D_800D49E0[0x23C] != 0) {
        if (D_800E9044 == 0 || (D_800E9044 >= 0x10 && (D_800E9044 & 3) == 0)) {
            if (D_800D49E0[0xA0] != 0 || D_800D49E0[0x22C] != 0) {
                arg0->items[arg0->sel].tgt = arg0->items[arg0->sel].off;
                do {
                    if (arg0->sel != 0) {
                        arg0->sel--;
                    } else {
                        arg0->sel = arg0->count - 1;
                    }
                } while (arg0->items[arg0->sel].enabled == 0 || arg0->items[arg0->sel].selectable == 0);
                arg0->items[arg0->sel].tgt = arg0->items[arg0->sel].on;
                func_80039E60(0x90, 0x2710, 0);
            }
            if (D_800D49E0[0xB0] != 0 || D_800D49E0[0x23C] != 0) {
                arg0->items[arg0->sel].tgt = arg0->items[arg0->sel].off;
                do {
                    if (++arg0->sel >= arg0->count) {
                        arg0->sel = 0;
                    }
                } while (arg0->items[arg0->sel].enabled == 0 || arg0->items[arg0->sel].selectable == 0);
                arg0->items[arg0->sel].tgt = arg0->items[arg0->sel].on;
                func_80039E60(0x90, 0x2710, 0);
            }
        }
        D_800E9044++;
    } else {
        D_800E9044 = 0;
    }
    for (i = 0; i < arg0->count; i++) {
        if (arg0->items[i].cur < arg0->items[i].tgt) {
            arg0->items[i].cur += 40;
            if (arg0->items[i].cur > arg0->items[i].tgt) {
                arg0->items[i].cur = arg0->items[i].tgt;
            }
        }
        if (arg0->items[i].cur > arg0->items[i].tgt) {
            arg0->items[i].cur -= 40;
            if (arg0->items[i].cur < arg0->items[i].tgt) {
                arg0->items[i].cur = arg0->items[i].tgt;
            }
        }
    }
}
