/* cflags: -fcse-skip-blocks */
/* NON_MATCHING: aln ratio 0.898; game's once-used lui s2 HIGH needs a pseudo live across a call whose other uses vanish after allocation; C++/prototypes/reload_cse ruled out, best 228/241. Equivalent C; only register allocation / scheduling / loop-invariant placement differ. */
/* Z2 near-miss 228/241 (B3 draft, unchanged). Only difference: the game loads the first D_800DE7A0 read through
 * lui $s2 (callee-saved, used exactly once), so p/show/x/y sit one s-register higher (x s3, y s4; ours x s2, y s3).
 * The HIGH pseudo must have been live across a call at global-alloc time with its later uses gone after allocation
 * (no call lies between its lui and its single lw). Ruled out (Z2): C++ (identical), reload_cse_regs (it only turns a
 * lui into a move or deletes no-op sets; it forgets values at labels), callee prototypes (all checked against matched
 * callees). CSE keeps a HIGH as a constant, so later reads never share it. */
#include "common.h"

typedef struct {
    u8 pad0[0xC];
    s32 vC;
    u8 pad10[0x44 - 0x10];
    u32 v44;
    u32 v48;
    u8 pad4C[0x78 - 0x4C];
} Lvl4438C;

typedef struct {
    u8 pad0[0x5B0];
    s32 v5B0;
} Cam4438C;

typedef struct {
    u8 pad0[0x2D0];
    Cam4438C *cam;
    u8 pad2D4[0x2E8 - 0x2D4];
    s32 v2E8;
    u8 pad2EC[0x348 - 0x2EC];
    s32 v348;
    s32 v34C;
    u8 pad350[0xA20 - 0x350];
    u32 score;
    u16 hA24;
    u8 padA26[0xB5C - 0xA26];
    u32 pending;
    u8 padB60[0xF10 - 0xB60];
    s32 vF10;
} Sk4438C;

void func_800057E4(char *, char *, ...);
void func_80045870(s32);
s32 func_8006648C(s32);
void func_8006EB3C(s32);
void func_8006F178(s32, s32, char *, s32, s32, s32);
void func_8006F1A8(s32, s32, s32, s32);
void func_8006F23C(s32);
void func_8006F274(s32);
void func_8008720C(s32, f32, f32, s32, s32, s32);
void func_8008C000(void *);
extern char D_8001B1C0[];
extern char D_8001B1C8[];
extern s32 D_800C0E20;
extern s32 D_800D1E88;
extern Lvl4438C D_800D5C1C[];
extern u32 D_800D613C;
extern s32 D_800DC618;
extern s32 D_800DDC70;
extern s32 D_800DE7A0;
extern Sk4438C *D_800DE7A8;
extern s32 D_800DE86C;
extern s32 D_800DE9B8;
extern s32 D_800DE9C0;
extern s32 D_800DE9D8;

void func_8004438C(Sk4438C *p, u16 x, u16 y) {
    char buf[16];
    s32 show;
    u32 v;
    u32 n;
    char *fmt;

    if (D_800DE7A8->cam->v5B0 == 0x17) {
        return;
    }
    show = D_800DC618 != 2;
    if (D_800DE86C != 0) {
        p->v34C = 0x2EE;
        p->v348 = 0x2EE;
    }
    if (D_800DE7A0 == 7) {
        if (D_800DE86C == 0) {
            p->v34C = 0;
            p->v348 = -1;
        }
        func_8008C000(&D_800DE9D8);
        return;
    }
    func_8006EB3C(D_800DE9C0);
    func_8008720C(D_800D1E88, x, y, p->v348, p->v34C, p->hA24);
    if (show) {
        D_800DDC70 = 1;
    }
    if (D_800DE7A0 != 7 && (v = p->pending) != 0 && p->vF10 == 0) {
        if (D_800DE7A0 == 8) {
            p->pending = 0;
        } else if (v > 10000) {
            p->score += 250;
            p->pending -= 250;
        } else if (v > 2000) {
            p->score += 100;
            p->pending -= 100;
        } else if (v > 25) {
            p->score += 25;
            p->pending -= 25;
        } else {
            p->score += v;
            p->pending = 0;
        }
    }
    if (show) {
        if (D_800DE7A0 == 1 && D_800D5C1C[D_800C0E20].vC == 0) {
            if (p->score >= D_800D5C1C[D_800C0E20].v44 && func_8006648C(0) == 0) {
                func_80045870(0);
            }
            if (p->score >= D_800D5C1C[D_800C0E20].v48 && func_8006648C(4) == 0) {
                func_80045870(4);
            }
        }
        if (show) {
            if (p->score > 999999) {
                fmt = D_8001B1C0;
                func_800057E4(buf, fmt, p->score);
                func_8006F1A8(((D_800D613C % 20) * 12) & 0xFC, 100, 100, 0);
            } else {
                func_8006F1A8(0x80, 0x80, 0x80, 0);
                n = p->score;
                if (D_800DE7A0 == 8) {
                    n = p->v2E8;
                    if (p == D_800DE7A8) {
                        func_8006F1A8(0x50, 0x50, 0x80, 0);
                    } else {
                        func_8006F1A8(0x80, 0x50, 0x50, 0);
                    }
                }
                fmt = D_8001B1C8;
                func_800057E4(buf, fmt, n);
            }
            func_8006F274(2);
            func_8006F23C(0x100);
            func_8006F178(x + 0x7D, y - 4, buf, 0, 0, 0x100);
        }
    }
    func_8006EB3C(D_800DE9B8);
}
