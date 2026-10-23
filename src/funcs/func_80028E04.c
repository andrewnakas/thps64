#include "common.h"

typedef struct {
    u8 pad0[0x48];
    u16 unk48;
} Sk;

void func_800286FC(Sk *);
void func_800287BC(Sk *);
void func_80028BC0(Sk *, s32, s32);
void func_80039E60(s32, s32, s32);
s32 func_800B4264(s32, s32);
extern u8 D_800D0FC0[];

s32 func_80028E04(Sk *arg0) {
    s32 ret;
    s32 hit;
    s32 hit2;
    s32 b;
    s32 a;

    ret = 0;
    a = D_800D0FC0[2];
    b = D_800D0FC0[3];
    func_80028BC0(arg0, a, b);
    hit = 0;
    if (func_800B4264(a, 0x8000) != 0 || func_800B4264(b, 0x8000) != 0) {
        hit = 1;
    }
    if (hit != 0 && arg0->unk48 == 0x67) {
        func_80039E60(0x93, 10000, 0);
        ret = 0x18;
    }
    hit2 = 0;
    if (func_800B4264(a, 0x4000) != 0 || func_800B4264(b, 0x4000) != 0) {
        hit2 = 1;
    }
    if (hit2 != 0) {
        func_80039E60(0x93, 10000, 0);
        ret = 0x18;
    }
    func_800286FC(arg0);
    func_800287BC(arg0);
    return ret;
}
