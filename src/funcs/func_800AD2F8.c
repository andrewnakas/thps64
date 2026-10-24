/* cflags: -O2 */
#include "common.h"

typedef struct {
    u8 pad0[0xC];
    u32 now;
    u8 pad10[0x40 - 0x10];
    u32 start;
    u8 pad44[0x54 - 0x44];
    u32 relStart;
    f32 atkScale;
    f32 decScale;
    f32 relScale;
    u32 rate;
    u8 pad68[0xBF - 0x68];
    u8 period;
    u8 base;
    u8 peak;
    u8 sustain;
    u8 phase;
    u8 level;
    u8 timer;
    u8 atkTime;
    u8 decTime;
    u8 relTime;
    u8 padC9[4];
    u8 relLevel;
} Env800AD2F8;

extern s32 D_800ECC24;

void func_800AD2F8(Env800AD2F8 *arg0) {
    s32 t;

    if (arg0->now >= arg0->relStart && arg0->phase < 4) {
        arg0->phase = 4;
        arg0->timer = 1;
        arg0->relLevel = arg0->level;
    }
    D_800ECC24 = arg0->timer;
    if ((u8)--arg0->timer != 0) {
        return;
    }
    arg0->timer = arg0->period;
    switch (arg0->phase) {
        case 1:
            t = (((arg0->now - arg0->start) >> 8) * arg0->rate) >> 10;
            if (t < arg0->atkTime) {
                arg0->level = arg0->base + (s32)(arg0->atkScale * t);
            } else {
                arg0->phase = 2;
                arg0->level = arg0->peak;
            }
            break;
        case 2:
            t = ((((arg0->now - arg0->start) >> 8) - arg0->atkTime) * arg0->rate) >> 10;
            if (t < arg0->decTime) {
                arg0->level = arg0->peak + (s32)(arg0->decScale * t);
            } else {
                arg0->phase = 3;
                arg0->level = arg0->sustain;
            }
            break;
        case 3:
            break;
        case 4:
            t = (((arg0->now - arg0->relStart) >> 8) * arg0->rate) >> 10;
            if (t < arg0->relTime) {
                arg0->level = arg0->relLevel - (s32)(arg0->relScale * t * arg0->relLevel);
            } else {
                arg0->phase = 5;
                arg0->level = 0;
            }
            break;
    }
}
