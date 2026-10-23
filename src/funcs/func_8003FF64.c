#include "common.h"

void func_800B1AC4(void *, f32, f32, f32, f32);

void func_8003FF64(u8 *arg0) {
    s32 i;
    s32 x;

    x = 0x194;
    for (i = 0; i < arg0[0x66]; i++) {
        func_800B1AC4(arg0 + 0x304, x, 217.0f, 1.0f, 1.0f);
        x += 0xE;
    }
}
