#include "common.h"

typedef struct {
    f32 unk0;
    s32 unk4;
    u8 unk8[1];
} Obj80039360;

void func_800A602C(void *);
void func_800BE7D0(s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 D_800F3294;
extern s32 D_800F3298;
extern f32 D_800F5668;

s32 func_80039360(Obj80039360 *arg0) {
    f32 zero;
    f32 k;
    f32 v;
    f32 t;
    f32 d;
    s32 a;

    if ((v = arg0->unk0) == (zero = 0.0f)) {
        return arg0->unk4 = -1;
    }
    arg0->unk4 = 0;
    k = 3.0f;
    t = arg0->unk0;
    if (t < zero) {
        arg0->unk0 = t + D_800F5668 * k;
        if (arg0->unk0 > zero) {
            arg0->unk0 = zero;
            arg0->unk4 = 1;
        }
        a = (arg0->unk0 + 1.0f) * 255.0f;
    } else {
        d = D_800F5668;
        arg0->unk0 = t - d * k;
        if (arg0->unk0 < zero) {
            arg0->unk0 = zero;
            arg0->unk4 = 2;
        }
        a = arg0->unk0 * 255.0f;
    }
    if (a < 0) {
        a = 0;
    } else if (a >= 0x100) {
        a = 0xFF;
    }
    if (a != 0) {
        func_800A602C(arg0->unk8);
        func_800BE7D0(0, D_800F3294, 0, D_800F3298, 0, 0, 0, a & 0xFF);
    }
    return arg0->unk4;
}
