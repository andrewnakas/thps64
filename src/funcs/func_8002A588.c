#include "common.h"

void func_8002A054(void *);
s32 func_8002A348(void *);
void func_8002A73C(void *);
void func_8002A904(void *);
void func_80039E60(s32, s32, s32);
void func_800A9220(void *, s32, s32);
s32 func_800B4264(s32, s32);
void func_800BE3D8(void);
void func_800BE5A4(void);
void func_800BEF70(s32, s32, s32);
extern u8 D_800D0FC0[];
extern s32 D_800D3100;
extern s32 D_800EA9C0;
extern f32 D_800F5668;

typedef struct {
    u8 pad0[0x2C0];
    f32 unk2C0;
    u8 pad2C4[0x2EC - 0x2C4];
    s32 unk2EC;
    u8 pad2F0[0x300 - 0x2F0];
    s32 unk300;
} Obj2A588;

s32 func_8002A588(Obj2A588 *arg0) {
    s32 ret;
    s32 hit;
    s32 hit2;
    s32 c2;
    s32 c3;

    ret = 0;
    if (arg0->unk2EC == 2) {
        return func_8002A348(arg0);
    }
    c2 = D_800D0FC0[2];
    c3 = D_800D0FC0[3];
    arg0->unk2C0 += D_800F5668;
    func_8002A73C(arg0);
    if (arg0->unk2C0 > 6.0f) {
        if (D_800D3100 != 0) {
            D_800D3100 = 0;
            func_800A9220(&D_800EA9C0, 2, 0);
        }
    }
    if (arg0->unk2C0 > 6.0f && (hit = (func_800B4264(c2, 0x1000) != 0 || func_800B4264(c3, 0x1000) != 0))) {
        func_80039E60(0x91, 0x2710, 0);
        ret = 3;
    } else if ((hit2 = (func_800B4264(c2, 0x8000) != 0 || func_800B4264(c2, 0x8000) != 0))) {
        func_8002A904(arg0);
    }
    if (arg0->unk2C0 > 36.0f) {
        arg0->unk300 = 0;
        arg0->unk2EC = 2;
    }
    func_800BE3D8();
    func_800BEF70(0, 0, 0);
    func_8002A054(arg0);
    func_800BE5A4();
    return ret;
}
