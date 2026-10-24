/* cflags: -O2 -Wa,-no-m4100 */
#include "common.h"

typedef struct {
    u8 pad0[0x38];
    u16 w;
    u16 h;
    u8 pad3C[2];
    u8 fmt;
    u8 siz;
    u8 pad40[0x54 - 0x40];
    u16 *tlut;
    u16 *img;
} Tex8770;

void func_800B8770(Tex8770 *t, s32 s, s32 tc, f32 *r, f32 *g, f32 *b, f32 *a) {
    s32 row;
    s32 w;
    u16 v;

    row = t->w * t->siz;
    if (row & 0x3F) {
        w = row / 64 * 64 + 64;
    } else {
        w = row;
    }
    /* Divide the rounded row width by 16 with truncation toward zero. */
    row = (w < 0 ? w + 15 : w) >> 4;
    w = s * t->siz;
    v = t->img[tc * row + w / 16];
    if (t->siz == 8) {
        v = (v >> ((s & 1) * 8)) & 0xFF;
    } else if (t->siz == 4) {
        v = (v >> ((s & 3) * 4)) & 0xF;
    }
    if (t->fmt == 4) {
        if (t->siz == 8) {
            *r = v;
        } else if (t->siz == 4) {
            *r = v / 15.0f * 255.0f;
        }
        *g = *b = *a = *r;
    } else if (t->fmt == 3) {
        if (t->siz == 8) {
            *r = (v >> 4) / 15.0f * 255.0f;
            *a = (v & 0xF) / 15.0f * 255.0f;
        } else if (t->siz == 4) {
            *r = (v >> 1) / 7.0f * 255.0f;
            *a = (v & 1) * 255.0f;
        }
        *g = *b = *r;
    } else {
        if (t->fmt == 2) {
            v = t->tlut[v];
        }
        *r = ((u16)v >> 11) * 8.225806236267089f;
        *g = (((u16)v >> 6) & 0x1F) * 8.225806236267089f;
        *b = (((u16)v >> 1) & 0x1F) * 8.225806236267089f;
        *a = (v & 1) * 255.0f;
    }
}
