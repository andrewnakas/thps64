#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec3_5C8CC;

Vec3_5C8CC func_80046E04(Vec3_5C8CC *, s32 *);
s32 func_800474C8(Vec3_5C8CC *);
extern Vec3_5C8CC D_800D6FDC;
extern Vec3_5C8CC D_800D6FE8;

void func_8005C8CC(Vec3_5C8CC *arg0) {
    Vec3_5C8CC t;
    s32 n;
    Vec3_5C8CC *p;
    Vec3_5C8CC *q;

    p = &D_800D6FDC;
    D_800D6FDC = *arg0;
    q = &D_800D6FE8;
    n = -func_800474C8(p);
    t = func_80046E04(p, &n);
    *q = t;
}
