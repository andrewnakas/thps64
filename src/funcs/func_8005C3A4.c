#include "common.h"

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 pad;
} SVec3;

s32 func_80022E14(s32, s32);
s32 func_80022E54(s32 *, s32 *);

void func_8005C3A4(s32 *arg0, SVec3 v) {
    s32 t[3];
    s32 m;
    s32 a;
    s32 b;
    s32 c;

    a = v.x;
    b = v.y;
    c = v.z;
    t[0] = a;
    t[1] = b;
    t[2] = c;
    m = func_80022E54(arg0, t);
    arg0[0] -= func_80022E14(m, v.x);
    arg0[1] -= func_80022E14(m, v.y);
    arg0[2] -= func_80022E14(m, v.z);
}
