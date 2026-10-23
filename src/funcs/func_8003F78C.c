#include "common.h"

typedef struct {
    u8 pad0[0x3C];
    s32 unk3C;
    u8 pad40[0x68 - 0x40];
    s32 unk68;
} Obj8003F78C;

void func_80039E60(s32, s32, s32);
void func_8003E9FC(Obj8003F78C *);
void func_8003F8C8(Obj8003F78C *);
void func_8003FC04(Obj8003F78C *);
void func_8003FD30(Obj8003F78C *);
s32 func_8003FEF4(s32);
s32 func_8003FF2C(s32);
s32 func_800B4264(s32, s32);
extern u8 D_800D0FC2;

s32 func_8003F78C(Obj8003F78C *arg0) {
    s32 ret;
    s32 v;
    s32 c;
    s32 one;
    s32 m1;

    ret = 0;
    c = D_800D0FC2;
    if (func_8003FF2C(c) == (one = 1)) {
        arg0->unk3C = 1;
        func_8003FC04(arg0);
    } else if (func_8003FF2C(c) == (m1 = -1)) {
        arg0->unk3C = 2;
        func_8003FC04(arg0);
    } else if ((v = func_8003FEF4(c)) == one || (v = func_8003FEF4(c)) == m1) {
        arg0->unk3C = v;
        func_8003F8C8(arg0);
    }
    if (func_800B4264(c, 0x9000) != 0) {
        if (arg0->unk68 != 0) {
            func_80039E60(0x91, 0x2710, 0);
            ret = 0xE;
        } else {
            func_80039E60(0x92, 0x2710, 0);
        }
    } else if (func_800B4264(c, 0x4000) != 0) {
        func_80039E60(0x93, 0x2710, 0);
        ret = 6;
    }
    func_8003FD30(arg0);
    func_8003E9FC(arg0);
    return ret;
}
