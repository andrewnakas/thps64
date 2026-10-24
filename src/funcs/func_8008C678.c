#include "common.h"

typedef struct {
    u8 hdr[0x14];
    s32 text;
    s16 w;
    u8 pad6[4];
    s16 maxW;
    u8 gap;
    u8 visible;
    u8 flag;
    u8 r;
    u8 g;
    u8 b;
    u8 r2;
    u8 g2;
    u8 b2;
    u8 fade;
} Item8008C678;

typedef struct {
    u8 font;
    u8 pad1;
    u8 sel;
    u8 pad3[2];
    u8 count;
    u8 pad6[2];
    s32 x;
    s32 y;
    s32 spacing;
} Menu8008C678;

extern void func_8006DF40(s32, s32, s32, s32, s32, s32, s32);
extern void func_8006F1A8(s32, s32, s32, s32);
extern void func_8006F1F8(s32);
extern void func_8006F23C(s32);
extern void func_8006F274(s32);

void func_8008C678(Menu8008C678 *arg0) {
    Item8008C678 *it;
    s32 y;
    s32 i;
    s32 m;

    i = 0;
    func_8006F274(arg0->font);
    y = arg0->y;
    m = 0x80;
    it = (Item8008C678 *)arg0;
    while (1) {
        if (i >= arg0->count) break;
        y += it->gap;
        if (it->visible != 0) {
            if (it->w > 0) {
                func_8006F23C(it->w);
                if (i == arg0->sel) {
                    func_8006F1A8(it->r, it->g, it->b, 0);
                    it->fade = 0;
                } else {
                    if (it->flag != 0) {
                        it->fade = m;
                    } else {
                        it->fade = 0x40;
                    }
                    func_8006F1A8((it->r2 * it->fade) >> 7 & 0xFF, (it->g2 * it->fade) >> 7 & 0xFF,
                                  (it->b2 * it->fade) >> 7 & 0xFF, 0);
                    it->fade += 0x3C;
                    if (it->fade > 0x80) {
                        it->fade = m;
                    }
                }
                if (it->w > it->maxW) {
                    func_8006F1F8(0);
                } else {
                    func_8006F1F8(1);
                }
                func_8006DF40(arg0->x, y, it->text, 0, 0, 0, 0);
            }
            y += arg0->spacing;
        }
        it = (Item8008C678 *)((u8 *)it + 0x18);
        i++;
    }
}
