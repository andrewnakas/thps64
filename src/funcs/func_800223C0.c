#include "common.h"

typedef struct {
    f32 m[16];
    f32 v[3];
} Xform223C0;

void func_80041EC0(void *, void *);
void func_80041F80(void *);
void func_8009D3F0(void *, f32);

void func_800223C0(s32 arg0, s32 *arg1) {
    Xform223C0 x;
    f32 ang;
    f32 k;
    f32 a;
    f32 b;
    f32 c;

    k = -0.00153396f;
    ang = arg0 * k;
    a = (f32) arg1[5] * 0.00024414062f;
    b = (f32) arg1[6] * 0.00024414062f;
    c = (f32) arg1[7] * 0.00024414062f;
    x.v[0] = a;
    x.v[1] = b;
    x.v[2] = c;
    func_80041F80(&x);
    func_8009D3F0(&x, ang);
    func_80041EC0(arg1, &x);
    arg1[5] = (s32) (x.v[0] * 4096.0f);
    arg1[6] = (s32) (x.v[1] * 4096.0f);
    arg1[7] = (s32) (x.v[2] * 4096.0f);
}
