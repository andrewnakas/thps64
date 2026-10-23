/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 */
#include "common.h"

typedef struct {
    u8 pad0[0x21C];
    s16 pos;
    u16 unk21E;
    u8 mode;
    s8 dir;
    s8 target;
    s8 unk223;
    u16 frac;
    u8 count;
    u8 flag;
    s32 speed;
} A8004A314;

void func_8004A204(A8004A314 *, s32, s32, s32, s32);
extern s32 D_800DE99C;

void func_8004A314(A8004A314 *arg0) {
    s32 v;
    s32 d;
    s32 one;
    s32 neg;
    s32 dir;

    if (arg0->mode == 0) {
        s32 dir = arg0->dir;
        if ((dir == 1 && arg0->pos >= arg0->target) || (dir == -1 && arg0->pos <= arg0->target)) {
            if (arg0->unk223 <= 0) {
                arg0->flag = 1;
            }
        }
    }
    d = (arg0->speed * D_800DE99C) >> 8;
    v = (arg0->pos << 16) | arg0->frac;
    {
        s32 dir = arg0->dir;
        if (dir == (one = 1)) {
            v += d;
        }
        if (dir == (neg = -1)) {
            v -= d;
        }
    }
    arg0->pos = v >> 16;
    arg0->frac = v;
    switch (arg0->mode) {
    case 0:
        dir = arg0->dir;
        if ((dir == one && arg0->pos >= arg0->target) || (dir == neg && arg0->pos <= arg0->target)) {
            if (arg0->unk223 > 0) {
                func_8004A204(arg0, arg0->unk21E, arg0->target, arg0->unk223, -1);
            } else {
                arg0->pos = arg0->target;
            }
        }
        break;
    case 1:
        if (arg0->pos >= arg0->count) {
            arg0->pos = 0;
        }
        if (arg0->pos < 0) {
            arg0->pos = arg0->count - 1;
        }
        break;
    }
}
