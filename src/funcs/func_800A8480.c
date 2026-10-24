/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x3A];
    u16 unk3A;
} FontTex;

typedef struct {
    f32 unk0;
    f32 unk4;
    s32 unk8;
    s32 unkC;
    u8 pad10[8];
    f32 unk18;
    u8 pad1C[8];
    s16 unk24[0x40];
    s16 unkA4[0xC4];
    FontTex *unk22C;
} Font;

s32 func_800A781C(Font *, s32, s32 *, s32 *, s32 *, s32 *);

void func_800A8480(Font *arg0, u8 *str, f32 *w, f32 *h) {
    u8 *s;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 g;
    u8 ch;
    f32 x;
    s32 t;
    s32 u;

    x = 0.0f;
    s = str;
    while (1) {
        ch = *s++;
        if (ch == 0) {
            break;
        }
        g = func_800A781C(arg0, ch, &a, &b, &c, &d);
        if (arg0->unkC < g) {
            g = -1;
        }
        if (g < 0) {
            if (g == -1) {
                x += arg0->unk0 * (f32)arg0->unk8;
            }
        } else {
            u = arg0->unkA4[g] - 1;
            t = arg0->unk24[g] - u;
            if (d == 0) {
                x += (f32)(t + 1) * arg0->unk0;
                if (*s != 0) {
                    x += arg0->unk18;
                }
            }
        }
    }
    if (w != NULL) {
        *w = x;
    }
    if (h != NULL) {
        *h = (f32)arg0->unk22C->unk3A * arg0->unk4;
    }
}
