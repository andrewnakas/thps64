/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 state;
    u8 pad1[0x3F];
} Ent3C354;

typedef struct {
    u8 pad0[0x240];
    s8 sel;
    u8 count;
    u8 pad242[2];
    u8 mode;
    u8 pad245;
    u8 unk246;
    u8 pad247[0x29C - 0x247];
    Ent3C354 ent[1];
} Menu3C354;

s32 func_8003C5BC(Menu3C354 *, s32);
s32 func_8003C648(Menu3C354 *, s32);
s32 func_800B4264(s32, s32);
extern u8 D_800D0FC0[];

s32 func_8003C354(Menu3C354 *m, s32 *out) {
    s32 a;
    s32 b;
    s32 d;
    s32 flag;

    a = D_800D0FC0[2];
    b = D_800D0FC0[3];
    if (m->mode == 3) {
        d = func_8003C648(m, a);
        if (d == 0) {
            d = func_8003C648(m, b);
        }
        *out = d;
    } else {
        d = func_8003C5BC(m, a);
        if (d == 0) {
            d = func_8003C5BC(m, b);
        }
    }
    flag = 0;
    if (func_800B4264(a, 0x8000) != 0 || func_800B4264(b, 0x8000) != 0) {
        flag = 1;
    }
    if (flag) {
        m->unk246 = 1;
        return m->sel;
    }
    if (d != 0) {
        if (m->sel >= 0) {
            m->ent[m->sel].state = 1;
        }
        m->sel += d;
        if (m->sel < 0) {
            m->sel = m->count - 1;
        } else {
            m->sel = m->sel % (s8)m->count;
        }
        while (m->ent[m->sel].state == 3) {
            m->sel += d;
            if (m->sel < 0) {
                m->sel = m->count - 1;
            } else {
                m->sel = m->sel % (s8)m->count;
            }
        }
        m->ent[m->sel].state = 2;
    }
    return 0;
}
