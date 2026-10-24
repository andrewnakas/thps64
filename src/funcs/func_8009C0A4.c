/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0x10];
    f32 val;
    f32 min;
    f32 max;
    f32 def;
    f32 step;
    s32 i24;
    s32 i28;
} ItemC0A4;

typedef struct {
    u8 pad0[0x10];
    u8 used;
    u8 pad11[3];
    s32 cur;
    s32 count;
    ItemC0A4 items[8];
    u8 pad[0x17C - 0x1C - 8 * 0x2C];
} SlotC0A4;

typedef struct {
    u8 pad0[0x240];
    SlotC0A4 slots[8];
    u8 pad[0xE20 - 0x240 - 8 * 0x17C];
    s16 count;
    s16 padId;
    s16 sel;
    s16 edit;
} MgrC0A4;

s32 func_800B4264(s32, s32);
s32 func_800B4240(s32, s32);
void func_8009BF80(MgrC0A4 *);

void func_8009C0A4(MgrC0A4 *m) {
    s32 up;
    s32 down;
    s32 dec;
    s32 inc;
    SlotC0A4 *s;
    ItemC0A4 *e;

    if (m->padId < 0 || m->count == 0) {
        return;
    }
    up = func_800B4264(m->padId, 0x200);
    down = func_800B4264(m->padId, 0x100);
    dec = func_800B4264(m->padId, 0x800);
    inc = func_800B4264(m->padId, 0x400);
    if (func_800B4240(m->padId, 0x2000) != 0) {
        up = func_800B4240(m->padId, 0x200);
        down = func_800B4240(m->padId, 0x100);
    }
    if (m->edit == 0) {
        if (up) {
            do {
                m->sel--;
                m->sel = (m->sel + 8) % 8;
            } while (m->slots[m->sel].used == 0);
        }
        if (down) {
            do {
                m->sel++;
                m->sel = (m->sel + 8) % 8;
            } while (m->slots[m->sel].used == 0);
        }
        if (inc) {
            m->edit = 1;
        }
    } else {
        s = &m->slots[m->sel];
        if (inc) {
            s->cur++;
        }
        if (dec) {
            s->cur--;
        }
        if (s->cur < 0) {
            s->cur = 0;
            m->edit = 0;
            return;
        }
        if (s->count - 1 < s->cur) {
            s->cur = s->count - 1;
        }
        e = &s->items[s->cur];
        if (up) {
            e->val -= e->step;
        }
        if (down) {
            e->val += e->step;
        }
        if (e->val < e->min) {
            e->val = e->min;
        } else if (e->max < e->val) {
            e->val = e->max;
        }
        func_8009BF80(m);
    }
}
