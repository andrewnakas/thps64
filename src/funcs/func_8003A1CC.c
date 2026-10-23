#include "common.h"

void func_800A9B98(void *, s32, u8);
extern s32 D_800EA9C0;

void func_8003A1CC(f32 arg0) {
    s32 i;
    u8 v;
    u32 t;
    f32 f;
    f32 c;
    f32 g;
    s32 m;

    f = arg0 * 255.0f;
    c = 2147483648.0f;
    if (!(f >= c)) { t = (s32)f; } else { g = f - c; m = 0x80000000; t = (s32)g | m; }
    v = t;
    i = 0;
    do {
        func_800A9B98(&D_800EA9C0, i, v);
        i++;
    } while (i < 0x9F);
}
