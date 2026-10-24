/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
/* NON_MATCHING: difflib ratio 0.691. Draws a block of text lines. The game passes the x coordinate to
 * func_8006DF40 in $fp, which this function saves but never sets, so x is whatever the caller left in $fp: the
 * source had an uninitialized local, written here as `x` (undefined in C; our cc1 does not put it in $fp). In the
 * bitmap-font case the game inlines func_8006DB34's height loop (whose width never changes, so it yields 0) and
 * calls nothing; that loop is copied here as line_height_bitmap(). */
#include "common.h"

typedef struct {
    u8 r, g, b;         /* 0x00 */
    u8 pad3;
    s32 size;           /* 0x04 */
    u8 pad8[3];
    u8 alpha;           /* 0x0B */
    s32 spacing;        /* 0x0C */
    u8 text[0x100];     /* 0x10 */
} TextLine;             /* size 0x110 */

typedef struct {
    u8 pad0[4];
    s32 started;        /* 0x04 */
    u8 pad8[0x14 - 0x8];
    TextLine lines[32]; /* 0x14 */
    s32 count;          /* 0x2214 */
    s32 y;              /* 0x2218 */
} TextBox;

typedef struct {
    u8 pad0[0x1A];
    s16 size;           /* 0x1A */
    u8 pad1C[0x24 - 0x1C];
} Font_8006E6DC;

s32 func_8006DA28(u8 *);
s32 func_8006DB34(u8 *);
s32 func_8006DF40(s32, s32, u8 *, s32, s32, s32, s32);
extern s32 D_800DC958;
extern u8 D_800DCAA4;
extern s32 D_800DCAA8;
extern u16 D_800DCAAC;
extern Font_8006E6DC D_800DCAB4[];
extern u8 D_800DCC1E;
extern u8 D_800DD920[];
extern u8 D_800FBB90[];

/* func_8006DB34's bitmap-font (D_800DCC1E == 0) path: the tallest glyph height, which is never updated from 0. */
static inline s32 line_height_bitmap(u8 *s) {
    s32 max = 0;
    s32 h = 0;
    s32 c;

    while (1) {
        c = *s;
        if (c == 0) {
            break;
        }
        c = D_800DD920[c];
        if (c == 0xFE) {
            c = -1;
        }
        if (c == 0xFD) {
            c = -1;
        }
        if (c == 0xFC) {
            c = -1;
        }
        if (c == 0xFB) {
            c = -1;
        }
        if (c == 0xFA) {
            c = -1;
        }
        if (c == 0xFF) {
            c = -1;
        }
        if (c >= 0) {
            if (max < h) {
                max = h;
            }
        }
        s++;
    }
    return (max * D_800DCAAC) >> 8;
}

void func_8006E6DC(TextBox *box) {
    TextLine *line;
    s32 x; /* never set: the game passes the caller's $fp */
    s32 y;
    s32 i;
    s32 w;
    s32 h;
    s32 size;
    u8 r, g, b;

    if (box->started == 0) {
        box->started = 1;
    }
    y = box->y;
    i = 0;
    while (1) {
        if (i >= box->count) {
            break;
        }
        line = &box->lines[i];
        r = line->r;
        g = line->g;
        b = line->b;
        D_800FBB90[0] = r;
        D_800FBB90[1] = g;
        D_800FBB90[2] = b;
        D_800DCAA8 = 0x2C000000 | (b << 16) | (g << 8) | r;
        size = line->size;
        if (D_800DCC1E == 0) {
            D_800DCAAC = size;
        } else {
            D_800DCAB4[D_800DC958].size = size;
        }
        D_800DCAA4 = line->alpha;
        if (D_800DCC1E != 0) {
            w = func_8006DB34(line->text);
        } else {
            w = func_8006DB34(line->text) >> 1;
        }
        func_8006DF40(x, y + w, line->text, 0, 0, 0x100, 0);
        if (D_800DCC1E == 0) {
            h = line_height_bitmap(line->text);
        } else {
            h = func_8006DB34(line->text) + func_8006DA28(line->text);
        }
        y += h + line->spacing;
        i++;
    }
}
