#include "common.h"

extern s16 D_800D48BC;
extern s16 D_800D48A4[3];
extern s32 D_800D48AC[3];

void func_80043448(void) {
    s32 s;
    s16 *v;
    s32 *o;
    s32 t;
    s32 x;
    s32 y;
    s32 z;

    s = D_800D48BC;
    v = D_800D48A4;
    t = s * v[0];
    x = t >> 12;
    t = s * v[1];
    y = t >> 12;
    t = s * v[2];
    z = t >> 12;
    o = D_800D48AC;
    o[0] = x;
    v[0] = x;
    o[1] = y;
    v[1] = y;
    o[2] = z;
    v[2] = z;
}
