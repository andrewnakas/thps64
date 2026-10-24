/* cflags: -fcse-follow-jumps -fcse-skip-blocks */
#include "common.h"

typedef struct {
    u8 r, g, b;
} Col62F4;

typedef struct {
    char text[0x80];
    f32 sx;
    f32 sy;
    s32 type;
    s32 special;
    s32 extra;
    s32 font;
    Col62F4 col;
    u8 pad9B;
    f32 x;
    f32 y;
    f32 x0;
    f32 y0;
} Txt62F4;

typedef struct {
    u16 count;
    u8 pad2[0x1388 - 2];
    s32 used;
    char pool[16][0x100];
    Txt62F4 e[1];
} Mgr62F4;

void func_8009E0F0(void *, s32, s32);
void func_8009FD60(char *, char *);
s32 func_8000574C(char *);
s32 func_80086E18(Mgr62F4 *, s32);
void func_80005720(void *, void *, s32);

void func_800862F4(Mgr62F4 *o, char *s, f32 x, f32 y, f32 scale, s32 font, s32 type, Col62F4 *col, u16 *extra) {
    s32 len;
    u8 *p;
    u8 c;

    func_8009E0F0(o->e[o->count].text, 0, 0x80);
    func_8009FD60(o->e[o->count].text, s);
    len = func_8000574C(s);
    o->e[o->count].x = x;
    o->e[o->count].y = y;
    o->e[o->count].x0 = x;
    o->e[o->count].y0 = y;
    o->e[o->count].sx = scale * 0.75f * 0.00390625;
    o->e[o->count].sy = scale * 0.00390625;
    o->e[o->count].type = type;
    o->e[o->count].font = func_80086E18(o, font);
    o->e[o->count].col = *col;
    o->e[o->count].extra = 0;
    o->e[o->count].special = 0;
    if (extra != NULL) {
        func_80005720((char *)((o->used << 8) + (s32)o) + 0x138C, extra, len * 2);
        o->e[o->count].extra = o->used + 1;
        o->used++;
    }
    if (type != 5 && type != 6) {
        p = (u8 *)s;
        c = *p;
        while (c != 0) {
            if (c == '[' || c == '{' || c == '<') {
                o->e[o->count].special = 1;
                break;
            }
            p++;
            c = *p;
        }
    }
    o->count++;
}
