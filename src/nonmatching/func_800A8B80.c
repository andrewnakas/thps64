/* cflags: -O2 -fno-schedule-insns */
/* NON_MATCHING: 116/124 instructions agree; argument-register copy and y-update scheduling differ. */
#include "common.h"

typedef struct {
    u8 pad0[0x3A];
    u16 height;
} Font_800A8B80;

typedef struct {
    u8 pad0[4];
    f32 scale;
    u8 pad8[0x224];
    Font_800A8B80 *font;
} Txt_800A8B80;

s32 func_8000574C(u8 *);
void func_800A8678(Txt_800A8B80 *, u8 *, f32, f32, s32, s32, f32, s32, s32, s32, s32, f32, s32, s32);

void func_800A8B80(Txt_800A8B80 *o, u8 *s, f32 x, f32 y, f32 scale, s32 a5, s32 align, f32 a7, u8 a8, u8 a9, s32 a10, s32 a11, f32 a12) {
    s32 n;
    s32 i;
    s32 len;
    f32 h;
    f32 tot;
    u8 *q;
    u8 *p;
    u8 c;
    u8 nl;

    n = 1;
    len = func_8000574C(s);
    for (i = 0; i < len; i++) {
        if (s[i] == '\n') {
            n++;
        }
    }
    h = scale * o->font->height * o->scale;
    tot = n * h;
    switch (align) {
    case 1:
        y += tot;
        break;
    case 2:
        y += tot * 0.5f;
        break;
    case 0:
        break;
    }
    p = s;
    nl = '\n';
loop:
    {
        if (*p == 0) {
            return;
        }
        q = p;
    inner:
        if (*q != nl) {
            q++;
            if (*q != 0) {
                goto inner;
            }
        }
        c = *q;
        *q = 0;
        func_800A8678(o, p, x, y, a5, 0, a7, a8, a9, a10, a11, a12, 0, 0);
        y -= h;
        p = q;
        *p = c;
        if (c != 0) {
            p++;
        }
        goto loop;
    }
}
