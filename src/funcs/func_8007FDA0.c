/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0;
    u8 chr[0xF];
    u32 timer;
    u8 pad14[0xC];
    s32 done;
    u8 pad24[0x54 - 0x24];
    u8 order[10];
    u16 score[10][3];
    u16 total[10];
    u8 round;
    u8 padAF[0x114 - 0xAF];
    s32 player;
} State_8007FDA0;

typedef struct {
    u8 pad0[0x2C];
    char *name;
    u8 pad30[0x154 - 0x30];
} Skater_8007FDA0;

extern void func_800057E4(char *, char *, ...);
extern void func_80039E60(s32, s32, s32);
extern void func_8006DF40(s32, s32, char *, s32, s32, s32, s32);
extern void func_8006EEF0(void);
extern void func_8006F1A8(s32, s32, s32, s32);
extern void func_8006F23C(s32);
extern void func_8006F274(s32);
extern void func_80095870(s32);
extern char D_8001E654[];
extern char D_8001E66C[];
extern char D_8001E67C[];
extern char D_8001E6A4[];
extern char D_8001E6A8[];
extern char D_8001E6B0[];
extern Skater_8007FDA0 D_800D4D80[];
extern s32 D_800DDE04;
extern State_8007FDA0 D_800DE640;

void func_8007FDA0(void) {
    char buf[0x30];
    u8 j;
    State_8007FDA0 *g;
    u8 i;
    s32 k;
    u8 a;
    u32 s0;
    u32 s1;
    u32 s2;
    u32 t0;
    u32 t1;
    u32 t2;
    s32 flash;
    s32 min;
    u8 c;
    u16 v;

    g = &D_800DE640;
    func_8006EEF0();
    func_8006F23C(0x100);
    func_8006F274(0);
    func_8006F1A8(0xB6, 0x84, 0x24, 0);
    func_800057E4(buf, D_8001E654);
    func_8006DF40(0x100, 0x28, buf, 0, 0, 0x100, 0);
    func_8006F274(1);
    func_8006F23C(0x78);
    func_800057E4(buf, D_8001E66C);
    func_8006DF40(0x104, 0x32, buf, 0, 0, 0x100, 0);
    func_800057E4(buf, D_8001E67C);
    func_8006DF40(0x104, 0x3C, buf, 0, 0, 0x100, 0);
    func_8006F23C(0xA0);
    for (i = 0; i < 10; i++) {
        func_800057E4(buf, D_8001E6A4, D_800D4D80[g->chr[g->order[i]]].name);
        if (g->order[i] == g->player) {
            func_8006F1A8(0xB6, 0x84, 0x24, 0);
        } else {
            func_8006F1A8(0x7A, 0x7A, 0x7A, 0);
        }
        func_8006DF40(0x5A, i * 14 + 0x46, buf, 0, 0, 0x100, 0);
    }
    j = 0;
    while (1) {
        if (j >= 3) {
            break;
        }
        i = 0;
        while (1) {
            if (i >= 10) {
                break;
            }
            if (i * 20 < g->timer) {
                if (g->timer == i * 20 + 1) {
                    func_80039E60(0x34, 10000, 0);
                }
                if (g->round == 0) {
                    g->total[g->order[i]] = g->score[g->order[i]][0];
                } else {
                    s0 = g->score[g->order[i]][0];
                    s1 = g->score[g->order[i]][1];
                    s2 = g->score[g->order[i]][2];
                    if (s0 < s1 && s0 < s2) {
                        g->total[g->order[i]] = s1 + s2;
                    } else if (s1 < s0 && s1 < s2) {
                        g->total[g->order[i]] = s0 + s2;
                    } else {
                        g->total[g->order[i]] = s0 + s1;
                    }
                }
            }
            if (i != 0 && i * 20 < g->timer) {
                k = i;
            loop:
                if (g->total[g->order[k]] > g->total[g->order[k - 1]]) {
                    a = g->order[k - 1];
                    g->order[k - 1] = g->order[k];
                    g->order[k] = a;
                    k--;
                    if (k > 0) {
                        goto loop;
                    }
                }
            }
            flash = 0;
            if (g->round == 2) {
                if (g->timer < (i + 1) * 20) {
                    if (g->timer >= i * 20) {
                        flash = (g->timer % 20) * 4;
                    }
                } else if (g->timer >= i * 20) {
                    flash = 100;
                }
            }
            t0 = g->score[g->order[i]][0];
            t1 = g->score[g->order[i]][1];
            t2 = g->score[g->order[i]][2];
            min = 0;
            if (t1 < t0 || t2 < t0) {
                min = 2;
                if (t0 >= t1 && t2 >= t1) {
                    min = 1;
                }
            }
            if (j == min) {
                c = 0x7A - flash;
                func_8006F1A8(c, c, c, 0);
            } else if (g->order[i] == g->player) {
                func_8006F1A8(0xB6, 0x84, 0x24, 0);
            } else {
                func_8006F1A8(0x7A, 0x7A, 0x7A, 0);
            }
            if (j < g->round) {
                v = g->score[g->order[i]][j];
                func_800057E4(buf, D_8001E6A8, (u16)(v / 10), (u16)(v % 10));
                func_8006DF40(j * 60 + 0xFA, i * 14 + 0x46, buf, 0, 0, 0x100, 0);
            }
            if (j == g->round) {
                if (i * 20 < g->timer) {
                    v = g->score[g->order[i]][j];
                    func_800057E4(buf, D_8001E6A8, (u16)(v / 10), (u16)(v % 10));
                } else {
                    if (g->order[i] == g->player) {
                        func_8006F1A8(0xB6, 0x84, 0x24, 0);
                    } else {
                        func_8006F1A8(0x7A, 0x7A, 0x7A, 0);
                    }
                    func_800057E4(buf, D_8001E6B0);
                }
                func_8006DF40(j * 60 + 0xFA, i * 14 + 0x46, buf, 0, 0, 0x100, 0);
                if (g->order[i] == g->player) {
                    func_8006F1A8(0xB6, 0x84, 0x24, 0);
                } else {
                    func_8006F1A8(0x7A, 0x7A, 0x7A, 0);
                }
                if (i * 20 < g->timer || g->round != 0) {
                    v = g->total[g->order[i]];
                    func_800057E4(buf, D_8001E6A8, (u16)(v / 10), (u16)(v % 10));
                } else {
                    func_800057E4(buf, D_8001E6B0);
                }
                func_8006DF40(0x1C2, i * 14 + 0x46, buf, 0, 0, 0x100, 0);
            }
            if (g->round < j) {
                func_800057E4(buf, D_8001E6B0);
                func_8006DF40(j * 60 + 0xFA, i * 14 + 0x46, buf, 0, 0, 0x100, 0);
            }
            i++;
        }
        j++;
    }
    if (g->timer > 200) {
        g->done = 1;
    } else {
        g->done = 0;
    }
    func_8006F23C(0x100);
    if (g->done != 0) {
        func_80095870(D_800DDE04);
    }
}
