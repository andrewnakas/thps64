#include "common.h"

typedef struct {
    u8 on;
    s8 started;
    u8 pad2[2];
    s32 held;
    s32 released;
    s32 ticks;
} Btn80043EF0;

void func_80022E0C(void);
extern s32 D_800D49C4;

void func_80043EF0(Btn80043EF0 *arg0, s32 arg1) {
    arg0->ticks++;
    if (arg0->on == 0 && arg1 != 0) {
        arg0->started = 1;
        arg0->ticks = 0;
    }
    if (arg1 != 0) {
        D_800D49C4 = 0;
        func_80022E0C();
        arg0->on = 1;
    } else {
        arg0->on = 0;
    }
    if (arg0->on != 0) {
        arg0->held++;
        arg0->released = 0;
    } else {
        arg0->held = 0;
        arg0->released++;
    }
}
