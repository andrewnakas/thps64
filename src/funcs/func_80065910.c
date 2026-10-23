#include "common.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

Vec3 func_80046E04(Vec3 *, f32 *);
Vec3 func_80046FBC(Vec3 *, Vec3 *);
s32 func_8004706C(Vec3 *);

void func_80065910(u8 *arg0, Vec3 *arg1, f32 arg2) {
    Vec3 *p;
    Vec3 r;
    Vec3 d;

    p = (Vec3 *)(arg0 + 0x2FC);
    if (func_8004706C(p) != 0) {
        *p = *arg1;
        d = func_80046FBC(p, (Vec3 *)(arg0 + 4));
        r = func_80046E04(&d, &arg2);
        *(Vec3 *)(arg0 + 0x84) = r;
        *(s32 *)(arg0 + 0x2A4) |= 1;
    }
}
