#include "common.h"

extern u8 D_800EAEF3;
extern void func_8003A1CC(f32);
extern void func_8003A2B0(f32);

void func_8003A734(u8 *arg0) {
    f32 z;

    if (arg0[0x10A] != 0) {
        z = 0.0f;
        func_8003A1CC(z);
        func_8003A2B0(z);
        D_800EAEF3 = 1;
        arg0[0x10A] = 0;
    }
}
