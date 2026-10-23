#include "common.h"

extern u8 D_800D0FC0[];
s32 func_8003E054(s32);
s32 func_80027644(s32, s32, s32, f32);
void func_80030120(u8 *, s32, s32, s32, s32);
void func_800306C8(u8 *, s32, s32);
void func_800305C8(u8 *, s32 *, s32, s32);
void func_800304F8(u8 *);
void func_80030428(u8 *);
void func_8002F220(u8 *);

#define W(o) (*(s32 *)(arg0 + (o)))

s32 func_8002FF34(u8 *arg0) {
    s32 ret;
    u8 *g;
    s32 p1;
    s32 p2;
    s32 a;
    s32 b;
    s32 c;
    s32 t;
    f32 k;

    ret = 0;
    g = D_800D0FC0;
    p1 = g[2];
    p2 = g[3];
    a = func_8003E054(p1);
    b = func_8003E054(p2);
    if (W(0x7A8) != 0) {
        a = 0;
    }
    if (W(0x7AC) != 0) {
        b = 0;
    }
    k = 100.0f;
    a = func_80027644(W(0x7B0), a, 1, k);
    c = func_80027644(W(0x7B4), b, 1, k);
    if (a != 0) {
        W(0x784) = 1;
    }
    if (c != 0) {
        W(0x788) = 1;
    }
    if (a != 0 || c != 0) {
        t = W(0x78C);
        t += a;
        W(0x78C) = (t + W(0x794)) % W(0x794);
        t = W(0x790);
        t += c;
        W(0x790) = (t + W(0x794)) % W(0x794);
        func_80030120(arg0, W(0x7B0), W(0x7B4), W(0x78C), W(0x790));
        func_80027644(W(0x7B0), 0, 0, k);
        func_80027644(W(0x7B4), 0, 0, k);
    }
    func_800306C8(arg0, p1, p2);
    func_800305C8(arg0, &ret, p1, p2);
    func_800304F8(arg0);
    func_80030428(arg0);
    func_8002F220(arg0);
    return ret;
}
