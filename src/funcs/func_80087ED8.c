#include "common.h"
void func_800A773C(void *, f32, f32);
void func_800A7AF8(void *, s32, s32, s32, s32);
void func_800A7B10(void *, s32, s32, s32, s32);
void func_800A8678(void *, void *, f32, f32, s32, s32, f32, s32, s32, s32, s32, f32, s32, s32);
extern u8 D_8001EF70[];
extern u8 D_8001EF7C[];
extern u8 D_8001EF88[];
extern u8 D_8001EF9C[];
#define D_8001EFAC (*(const f32 *)0x8001EFAC)
#define D_8001EFB0 (*(const f32 *)0x8001EFB0)
#define D_8001EFB4 (*(const f32 *)0x8001EFB4)
#define D_8001EFB8 (*(const f32 *)0x8001EFB8)
#define D_8001EFBC (*(const f32 *)0x8001EFBC)
#define D_8001EFC0 (*(const f32 *)0x8001EFC0)
#define D_8001EFC4 (*(const f32 *)0x8001EFC4)
#define D_8001EFC8 (*(const f32 *)0x8001EFC8)
typedef struct {
    u8 pad_000[0x4F0];
    s8 field_4F0;
    u8 pad_4F1[3];
    f32 field_4F4, field_4F8, field_4FC, field_500;
    u16 field_504[8], field_514[8];
    u8 pad_524[0x11];
    s8 field_535[4];
    u8 pad_539[7];
    void *field_540[4];
} State80087ED8;
void func_80087ED8(State80087ED8 *state) {
    void *object;
    void *text;

    if (state->field_4F0 == 0) {
        func_800A7AF8(((u8 *)state + 0x70), 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A7B10(((u8 *)state + 0x70), 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A773C(((u8 *)state + 0x70), state->field_4FC, state->field_500);
    } else {
        func_800A7AF8(((u8 *)state + 0x70), 0x87, 0xC2, 0xF3, 0xFF);
        func_800A7B10(((u8 *)state + 0x70), 0x87, 0xC2, 0xF3, 0xFF);
        func_800A773C(((u8 *)state + 0x70), state->field_4F4, state->field_4F8);
    }
    object = (u8 *)state + 0x70;
    func_800A8678(object, (state->field_540[state->field_535[0]]), (f32) state->field_504[0], (f32) state->field_514[0], 2, 0, D_8001EFAC, 0xAA, 0x50, 1, 0, 0, 0, 0);
    if (state->field_4F0 == 1) {
        func_800A7AF8(object, 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A7B10(object, 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A773C(object, state->field_4FC, state->field_500);
    } else {
        func_800A7AF8(object, 0x87, 0xC2, 0xF3, 0xFF);
        func_800A7B10(object, 0x87, 0xC2, 0xF3, 0xFF);
        func_800A773C(object, state->field_4F4, state->field_4F8);
    }
    object = (u8 *)state + 0x70;
    func_800A8678(object, (state->field_540[state->field_535[1]]), (f32) state->field_504[1], (f32) state->field_514[1], 2, 0, D_8001EFB0, 0xAA, 0x50, 1, 0, 0, 0, 0);
    if (state->field_4F0 == 2) {
        func_800A7AF8(object, 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A7B10(object, 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A773C(object, state->field_4FC, state->field_500);
    } else {
        func_800A7AF8(object, 0x87, 0xC2, 0xF3, 0xFF);
        func_800A7B10(object, 0x87, 0xC2, 0xF3, 0xFF);
        func_800A773C(object, state->field_4F4, state->field_4F8);
    }
    object = (u8 *)state + 0x70;
    func_800A8678(object, (state->field_540[state->field_535[2]]), (f32) state->field_504[2], (f32) state->field_514[2], 2, 0, D_8001EFB4, 0xAA, 0x50, 1, 0, 0, 0, 0);
    if (state->field_4F0 == 3) {
        func_800A7AF8(object, 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A7B10(object, 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A773C(object, state->field_4FC, state->field_500);
    } else {
        func_800A7AF8(object, 0x87, 0xC2, 0xF3, 0xFF);
        func_800A7B10(object, 0x87, 0xC2, 0xF3, 0xFF);
        func_800A773C(object, state->field_4F4, state->field_4F8);
    }
    object = (u8 *)state + 0x70;
    func_800A8678(object, (state->field_540[state->field_535[3]]), (f32) state->field_504[3], (f32) state->field_514[3], 2, 0, D_8001EFB8, 0xAA, 0x50, 1, 0, 0, 0, 0);
    if (state->field_4F0 == 4) {
        func_800A7AF8(object, 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A7B10(object, 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A773C(object, state->field_4FC, state->field_500);
    } else {
        func_800A7AF8(object, 0x87, 0xC2, 0xF3, 0xFF);
        func_800A7B10(object, 0x87, 0xC2, 0xF3, 0xFF);
        func_800A773C(object, state->field_4F4, state->field_4F8);
    }
    object = (u8 *)state + 0x70;
    text = D_8001EF70;
    func_800A8678(object, text, (f32) state->field_504[4], (f32) state->field_514[4], 2, 0, D_8001EFBC, 0xAA, 0x50, 1, 0, 0, 0, 0);
    if (state->field_4F0 == 5) {
        func_800A7AF8(object, 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A7B10(object, 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A773C(object, state->field_4FC, state->field_500);
    } else {
        func_800A7AF8(object, 0x87, 0xC2, 0xF3, 0xFF);
        func_800A7B10(object, 0x87, 0xC2, 0xF3, 0xFF);
        func_800A773C(object, state->field_4F4, state->field_4F8);
    }
    object = (u8 *)state + 0x70;
    text = D_8001EF7C;
    func_800A8678(object, text, (f32) state->field_504[5], (f32) state->field_514[5], 2, 0, D_8001EFC0, 0xAA, 0x50, 1, 0, 0, 0, 0);
    if (state->field_4F0 == 6) {
        func_800A7AF8(object, 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A7B10(object, 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A773C(object, state->field_4FC, state->field_500);
    } else {
        func_800A7AF8(object, 0x87, 0xC2, 0xF3, 0xFF);
        func_800A7B10(object, 0x87, 0xC2, 0xF3, 0xFF);
        func_800A773C(object, state->field_4F4, state->field_4F8);
    }
    object = (u8 *)state + 0x70;
    text = D_8001EF88;
    func_800A8678(object, text, (f32) state->field_504[6], (f32) state->field_514[6], 2, 0, D_8001EFC4, 0xAA, 0x50, 1, 0, 0, 0, 0);
    if (state->field_4F0 == 7) {
        func_800A7AF8(object, 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A7B10(object, 0xFC, 0xC2, 0x6B, 0xFF);
        func_800A773C(object, state->field_4FC, state->field_500);
    } else {
        func_800A7AF8(object, 0x87, 0xC2, 0xF3, 0xFF);
        func_800A7B10(object, 0x87, 0xC2, 0xF3, 0xFF);
        func_800A773C(object, state->field_4F4, state->field_4F8);
    }
    text = D_8001EF9C;
    func_800A8678((u8 *)state + 0x70, text, (f32) state->field_504[7], (f32) state->field_514[7], 2, 0, D_8001EFC8, 0xAA, 0x50, 1, 0, 0, 0, 0);
}
