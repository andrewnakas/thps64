/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x3A];
    u16 unk3A;
} Font8678;

typedef struct {
    f32 unk0;
    f32 unk4;
    u8 pad8[0x224 - 0x8];
    u8 unk224;
    u8 unk225;
    u8 unk226;
    u8 unk227;
    u8 unk228;
    u8 unk229;
    u8 unk22A;
    u8 unk22B;
    Font8678 *unk22C;
    u8 pad230[4];
    f32 unk234;
    f32 unk238;
} Txt8678;

void func_800A773C(Txt8678 *, f32, f32);
void func_800A7B50(Txt8678 *, f32, f32, s32, s32, s32, s32);
void func_800A8480(Txt8678 *, s32, f32 *, f32 *);
void func_800BFC3C(s32, s32, s32, s32);

#define DRAW_OFFSET(t, x, y, str, amt, dx, dy, arg13)                         \
    {                                                                        \
        u8 c0 = (t)->unk224;                                                 \
        u8 c1 = (t)->unk225;                                                 \
        u8 c2 = (t)->unk226;                                                 \
        u8 c3 = (t)->unk227;                                                 \
        u8 c4 = (t)->unk228;                                                 \
        u8 c5 = (t)->unk229;                                                 \
        u8 c6 = (t)->unk22A;                                                 \
        u8 c7 = (t)->unk22B;                                                 \
        (t)->unk224 = (t)->unk225 = (t)->unk226 = (t)->unk228 = (t)->unk229 = (t)->unk22A = 0; \
        (t)->unk234 += dx;                                                   \
        (t)->unk238 -= dy;                                                   \
        (t)->unk227 = (t)->unk22B = (amt * c3) / 255;                        \
        func_800A7B50(t, x, y, str, 0, 0, arg13);                            \
        (t)->unk224 = c0;                                                    \
        (t)->unk225 = c1;                                                    \
        (t)->unk226 = c2;                                                    \
        (t)->unk227 = c3;                                                    \
        (t)->unk228 = c4;                                                    \
        (t)->unk229 = c5;                                                    \
        (t)->unk22A = c6;                                                    \
        (t)->unk22B = c7;                                                    \
        (t)->unk234 -= dx;                                                   \
        (t)->unk238 += dy;                                                   \
    }

void func_800A8678(Txt8678 *t, s32 str, f32 x, f32 y, s32 halign, s32 valign, f32 off, u8 shadow, u8 outline8,
                   s32 clip, s32 snap, f32 maxw, s32 arg12, s32 arg13) {
    f32 w;
    f32 h;
    u8 outline;
    s32 scaled;
    f32 oldScale;
    f32 a;
    f32 b;
    f32 m;
    f32 px;
    f32 py;

    outline = outline8;
    if (valign == 2 && (t->unk22C->unk3A & 1)) {
        y += 0.5f;
    }
    func_800A8480(t, str, &w, &h);
    scaled = 0;
    if (maxw > 0.0f && maxw < w) {
        oldScale = t->unk0;
        scaled = 1;
        func_800A773C(t, oldScale * maxw / w, t->unk4);
        func_800A8480(t, str, &w, &h);
    }
    switch (halign) {
    case 0:
        break;
    case 1:
        x -= w;
        break;
    case 2:
        if (snap && t->unk0 == 1.0f) {
            x -= (f32)(s32)(w * 0.5f);
        } else {
            x -= w * 0.5f;
        }
        break;
    }
    switch (valign) {
    case 0:
        break;
    case 1:
        y += h;
        break;
    case 2:
        y += h * 0.5f;
        break;
    }
    if (clip) {
        a = 0.0f;
        if (outline) {
            a = 1.0f;
        }
        b = 0.0f;
        if (shadow) {
            b = off;
        }
        m = b;
        if (m < a) {
            m = a;
        }
        px = x + t->unk234;
        py = y + t->unk238;
        func_800BFC3C(px + -1.0f, px + m + w + 1.0f, py - m - h + -1.0f, py + 1.0f);
    }
    if (shadow) {
        DRAW_OFFSET(t, x, y, str, shadow, off, off, arg13);
    }
    func_800A7B50(t, x, y, str, 0, arg12, arg13);
    if (outline) {
        DRAW_OFFSET(t, x, y, str, outline, t->unk0, t->unk4, arg13);
    }
    if (scaled) {
        func_800A773C(t, oldScale, t->unk4);
    }
}
