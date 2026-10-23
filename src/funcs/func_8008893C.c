#include "common.h"

typedef struct {
    u8 pad_000[0x4F0];
    u8 field_4F0;
    u8 pad_4F1[0x33];
    s32 field_524;
    u8 pad_528[4];
    u16 field_52C, field_52E, field_530, field_532;
    u8 field_534;
    u8 pad_535[0x23];
    f32 field_558;
    s32 field_55C;
} State8008893C;

void func_80039E60(s32, s32, s32);
s32 func_8003FEF4(u8);
s32 func_8003FF2C(u8);
void func_80087B8C(void *);
void func_80087ED8(void *);
void func_80088744(void *);
void func_80088B88(void *, s32);
s32 func_80088C50(void *);
void func_800B1AC4(void *, f32, f32, f32, f32);
s32 func_800B4264(u8, s32);
void func_800BE3D8();
void func_800BE5A4();
void func_800BEF70(s32, s32, s32);
extern f32 D_800F5668;

s32 func_8008893C(State8008893C *arg0) {
    s32 raw;
    s32 step;
    s32 result;
    f32 phase;
    f64 phase64;
    f32 shared_value;
    s32 first;
    s32 second;

    result = 0;
    raw = func_8003FF2C(arg0->field_534);
    if (raw == -1) {
        func_80088B88(arg0, -1);
    } else if (raw == 1) {
        func_80088B88(arg0, 1);
    }
    step = func_8003FEF4(arg0->field_534);
    if (step == -1) {
        func_80039E60(0x90, 0x2710, 0);
        arg0->field_4F0--;
        if ((s8) arg0->field_4F0 < 0) {
            arg0->field_4F0 = 7;
        }
    } else if (step == 1) {
        func_80039E60(0x90, 0x2710, 0);
        arg0->field_4F0++;
        if ((s8) arg0->field_4F0 >= 8) {
            arg0->field_4F0 = 0;
        }
    }
    if (func_800B4264(arg0->field_534, 0x8000) != 0) {
        result = func_80088C50(arg0);
    }
    if (func_800B4264(arg0->field_534, 0x4000) != 0) {
        func_80039E60(0x93, 0x2710, 0);
        result = 0x18;
    }
    phase = arg0->field_558 + D_800F5668;
    arg0->field_558 = phase;
    phase64 = (f64) phase;
    if (0.5 < phase64) {
        arg0->field_558 = (f32) (phase64 - 0.5);
        arg0->field_55C = (s32) (arg0->field_55C == 0);
    }
    func_80087B8C(arg0);
    func_800BE3D8();
    func_800BEF70(0, 0, 0);
    func_800B1AC4((u8 *)arg0 + 0x34, 34.0f, 0.0f, 0.925f, 2.0f);
    func_80087ED8(arg0);
    func_80088744(arg0);
    if ((arg0->field_524 != 0) && (arg0->field_55C != 0)) {
        first = arg0->field_52C;
        second = arg0->field_52E;
        shared_value = 0.7f;
        func_800B1AC4((u8 *)arg0 + 0x48, (f32) first, (f32) second, shared_value, shared_value);
        func_800B1AC4((u8 *)arg0 + 0x5C, (f32) arg0->field_530, (f32) arg0->field_532, shared_value, shared_value);
    }
    func_800BE5A4();
    return result;
}
