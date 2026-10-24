/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0;
    u8 order[11];
    s32 unkC;
    s32 unk10;
    s32 unk14;
    u8 pad18[0xC];
    u8 dice[5][5];
    u8 pad3D[0xD];
    u8 slots[10];
    u8 idx[10];
    s16 tbl[10][3];
    s16 tbl2[10];
    u8 unkAE;
    u8 padAF[0x65];
    s32 sel;
    s32 unk118;
} Game_8007F1F0;

s32 func_80049D60(s32);
void func_80049DC4(s32);
extern s32 D_800C0E20;
extern s32 D_800D6138;
extern s16 D_800DE634;
extern s16 D_800DE636;
extern s16 D_800DE638;
extern s16 D_800DE63A;
extern s16 D_800DE63C;
extern Game_8007F1F0 D_800DE640;
extern s32 D_800E9290;

void func_8007F1F0(void) {
    Game_8007F1F0 *g = &D_800DE640;
    s32 sel;
    u8 a;
    u8 b;
    u8 c;
    s32 r;
    s32 n;
    s32 k;
    s32 j;

    g->unkC = 0;
    g->unk10 = 0;
    g->unk14 = 0;
    g->unk118 = 0;
    func_80049DC4(D_800D6138);
    {
        s32 i;
        for (i = 0; i < 10; i++) {
            g->order[i] = i;
        }
    }
    sel = D_800E9290;
    g->sel = sel;
    if (sel == 10) {
        g->sel = func_80049D60(10);
        g->order[g->sel] = sel;
    }
    if (D_800C0E20 == 8) {
        D_800DE634 = 0x3CF;
        D_800DE636 = 0x3A7;
        D_800DE638 = 0x38E;
        D_800DE63A = 0x35C;
        D_800DE63C = 0x302;
    } else {
        D_800DE634 = 0x3CF;
        D_800DE636 = 0x398;
        D_800DE638 = 0x366;
        D_800DE63A = 0x334;
        D_800DE63C = 0x208;
    }
    a = 0;
    do {
        g->dice[a][1] = func_80049D60(10);
        g->dice[a][3] = func_80049D60(10);
        g->dice[a][2] = func_80049D60(30);
        g->dice[a][4] = func_80049D60(30);
        a++;
    } while (a < 5);
    b = 0;
    while (1) {
        if (b >= 10) break;
        for (c = 0; c < 3; c++) {
            g->tbl[b][c] = 0;
        }
        g->tbl2[b] = 0;
        g->idx[b] = b;
        b++;
    }
    g->unkAE = 0;
    {
        s32 i;
        for (i = 0; i < 10; i++) {
            g->slots[i] = 0xFF;
        }
    }
    j = 0;
    while (1) {
        if (j >= 10) break;
        r = func_80049D60(10 - j);
        n = 0;
        k = -1;
        while (n <= r) {
            k++;
            if (g->slots[k] == 0xFF) {
                n++;
            }
        }
        g->slots[k] = j;
        j++;
    }
    for (k = 0; k < 10; k++) {
        if (g->slots[k] == 9) {
            g->slots[k] = g->slots[g->sel];
        }
    }
    g->slots[g->sel] = 0xFF;
}
