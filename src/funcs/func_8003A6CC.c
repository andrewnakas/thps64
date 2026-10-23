#include "common.h"

extern char D_800D0FC0[];
extern u8 D_800EAEF3;
extern void func_8003A1CC(f32);
extern void func_8003A2B0(f32);

void func_8003A6CC(u8 *a0) {
    u8 *p;

    if (a0[0x10A] != 1) {
        p = (u8 *)D_800D0FC0;
        func_8003A1CC(*(f32 *)(p + 0x2C));
        func_8003A2B0(*(f32 *)(p + 0x30));
        D_800EAEF3 = 0;
        a0[0x10A] = 1;
    }
}
