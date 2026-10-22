#include "common.h"

typedef struct {
    s32 x, y, z;
} Vec800492F8;

typedef struct {
    Vec800492F8 a;
    Vec800492F8 b;
    u8 pad18[0x68 - 0x18];
    s32 unk68;
} Ray800492F8;

s32 func_8005CA90(Vec800492F8 *, Vec800492F8 *, void *, s32, s32);
void func_8005CCD0(s32, Ray800492F8 *);
void func_8005CCD8(Ray800492F8 *, s32);
extern s32 D_800D6180;
extern s32 D_800D7240;
extern Ray800492F8 D_800D724C;

s32 func_800492F8(Vec800492F8 *arg0, Vec800492F8 *arg1, s32 arg2) {
    s32 sp18[4];
    s32 v;
    Ray800492F8 *r;
    s32 x, y, z;
    s32 x2, y2, z2;

    v = func_8005CA90(arg0, arg1, sp18, arg2, 0);
    if (v == 0) {
        x = arg0->x;
        y = arg0->y;
        z = arg0->z;
        r = &D_800D724C;
        r->a.x = x;
        r->a.y = y;
        r->a.z = z;
        x2 = arg1->x;
        y2 = arg1->y;
        z2 = arg1->z;
        r->b.x = x2;
        r->b.y = y2;
        r->b.z = z2;
        func_8005CCD8(r, 0);
        D_800D7240 = 1;
        func_8005CCD0(D_800D6180, r);
        D_800D7240 = 0;
        v = r->unk68;
    }
    return v;
}
