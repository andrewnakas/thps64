#include "common.h"

typedef union {
    s16 m[16];
    s32 w[8];
} Mtx16;

s32 func_80023190(s32, s32);
void func_800223C0(s32, Mtx16 *);

void func_8006CE48(Mtx16 *src, s16 *out) {
    Mtx16 m;
    s32 a;
    s32 b;
    s32 c;

    m = *src;
    m.m[1] = -m.m[1];
    m.m[4] = -m.m[4];
    m.m[7] = -m.m[7];
    a = func_80023190(m.m[2], m.m[8]) & 0xFFF;
    func_800223C0(-a, &m);
    b = func_80023190(-m.m[5], m.m[8]) & 0xFFF;
    func_800223C0(-b, &m);
    c = func_80023190(m.m[3], m.m[4]) & 0xFFF;
    out[0] = b;
    out[1] = a;
    out[2] = c;
}
