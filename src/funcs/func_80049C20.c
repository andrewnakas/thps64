#include "common.h"

s32 func_800233B8(s32);
void func_80043264(s32 *);
void func_80043288(void);
void func_800433E4(s32 *);

void func_80049C20(s32 *arg0, s32 *arg1) {
    s32 v[3];
    s32 *p;
    s32 x;
    s32 y;
    s32 z;
    s32 d;

    x = arg1[0] >> 12;
    y = arg1[1] >> 12;
    z = arg1[2] >> 12;
    p = v;
    v[0] = x;
    v[1] = y;
    v[2] = z;
    func_800433E4(p);
    func_80043288();
    func_80043264(p);
    d = func_800233B8(v[0] + v[1] + v[2]);
    if (d != 0) {
        arg0[0] = arg1[0] / d;
        arg0[1] = arg1[1] / d;
        arg0[2] = arg1[2] / d;
    } else {
        arg0[0] = 0;
        arg0[1] = 0;
        arg0[2] = 0;
    }
}
