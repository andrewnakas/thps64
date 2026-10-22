#include "common.h"

extern s32 D_800DA56C;
extern s32 D_800DA570;
extern u32 D_800DA574;
extern u32 D_800DA578;

void func_8005E6B4(s32 arg0, s32 arg1) {
    u32 x;
    u32 y;

    D_800DA56C = arg0;
    D_800DA570 = arg1;
    x = arg0 * 3;
    y = arg1 * 4;
    if (y < x) {
        D_800DA574 = 0x1000;
        D_800DA578 = (x << 12) / y;
    } else {
        D_800DA574 = ((u32) arg1 << 14) / x;
        D_800DA578 = 0x1000;
    }
}
