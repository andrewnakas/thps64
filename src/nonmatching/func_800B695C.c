/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* NON_MATCHING: aln 0.773. Equivalent C; the order of the second colour word vs the w0 store and the zero test on the raw lbu differ (game tests the loaded byte before masking). */
/* F6 107/137: hi/lo byte temps (game loads both bytes before shifting). Game computes the 2nd colour word AFTER the w0 store (pack15-like inline in the w1 arg gives that order, 105, but its b&0x1F andi sits 2nd in the game, unexplained). Earlier: F5 near-miss 106/137 (from G4 93): testing the raw *p before c = *p (u8) moves the c==0 test off the andi'd value, but CSE reuses the QI load so the test still sees the zero_extend. Game: lbu t2; beqz t2 (raw); andi 0x80; andi 0xFF only before c<<8. Wide temp (s32 v; c = v) removes the andi entirely (86); whole-body inline with u8 param puts p in memory. */
#include "common.h"

typedef struct {
    u32 w0;
    u32 w1;
} Gfx;

#define GW(gp, a, b) { Gfx *_g = (gp)++; _g->w0 = (a); _g->w1 = (b); }

void func_800B695C(s32 arg0, u8 *p, Gfx *gfx) {
    u32 a, b;
    s32 r, g, bl, n;

    for (;;) {
        u8 c;
        if (*p == 0) {
            break;
        }
        c = *p;
        if (c & 0x80) {
            s32 lo;
            p++;
            lo = *p++;
            a = (c << 8) | lo;
            r = (a >> 10) & 0x1F;
            g = (a >> 5) & 0x1F;
            bl = a & 0x1F;
            if (*p & 0x80) {
                s32 hi = *p++;
                s32 lo2 = *p++;
                b = (hi << 8) | lo2;
                GW(gfx, (r << 17) | (g << 9) | (bl << 1) | 0x06000000,
                   (((b >> 9) & 0x3E) << 16) | ((b << 4) & 0x3E00) | ((b & 0x1F) << 1));
            } else {
                GW(gfx, (r << 17) | (g << 9) | (bl << 1) | 0x05000000, 0);
            }
        } else {
            switch (c & 0x60) {
            case 0x20:
                {
                    s32 m;
                    s32 hi = *p++;
                    s32 lo = *p++;
                    a = (hi << 8) | lo;
                    n = a & 0x1F;
                    m = (a >> 5) & 0x1F;
                    if (n == 0) {
                        n = 0x20;
                    }
                    GW(gfx, (n << 12) | (0x01000000 | ((m + n) << 1)), n);
                }
                break;
            case 0x40:
                p++;
                n = *p++;
                GW(gfx, 0xDA380003, (n << 6) + 0x01000000);
                break;
            case 0x60:
                p++;
                {
                    s32 b0 = *p++;
                    s32 b1 = *p++;
                    s32 b2 = *p++;
                    s32 b3 = *p++;
                    GW(gfx, ((c & 0x1F) << 1) | 0x02140000, (b0 << 24) | (b1 << 16) | (b2 << 8) | b3);
                }
                break;
            }
        }
    }
    GW(gfx, 0xDF000000, 0);
}
