#include "common.h"

typedef struct {
    s32 a[6];
    u8 pad18[0x50];
    s32 hit;
    s32 pad6C;
    s32 result;
    u8 pad74[6];
    s16 ny;
    u8 pad7C[0xC];
    s8 flag;
    u8 pad89[0x77];
} Ray_Q2;

void func_8005CCD8(Ray_Q2 *, s32);
void func_8005DF8C(Ray_Q2 *, s32);

s32 func_80048DCC(s32 *arg0, s32 arg1, s32 arg2) {
    Ray_Q2 r;
    Ray_Q2 *p;
    s32 t;

    p = &r;

    r.a[0] = arg0[0];
    r.a[1] = arg0[1] - (arg1 << 12);
    r.a[2] = arg0[2];
    r.a[3] = arg0[0];
    arg2 <<= 12;
    t = arg0[1];
    t += arg2;
    r.a[4] = t;
    r.a[5] = arg0[2];
    func_8005CCD8(p, 0);
    r.flag = 0;
    func_8005DF8C(p, 1);
    if (r.hit != 0 && r.ny < -0xBFF) {
        return r.result;
    }
    return -1;
}
