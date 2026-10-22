#include "common.h"
typedef struct {
    u8 pad_000[0x528];
    s32 field_528;
    u8 pad_52C[9];
    u8 field_535[4];
    u8 field_539[4];
    u8 pad_53D[0x13];
    s32 field_550;
    s32 field_554;
} State80087E3C;
typedef struct { u8 pad_000[0x110]; s32 field_110; s32 field_114; s32 field_118; s32 field_11C; u8 field_120[16]; } Entry80087E3C;
extern u8 D_800D0FC0[];
extern u8 D_800DC3F8[];
void func_80087E3C(State80087E3C *state) {
    u8 *table = D_800DC3F8;
    u8 *context = D_800D0FC0;
    u32 index;
    u8 value;
    index = context[0x16] * 0x10;
    value = ((Entry80087E3C *)(index + (u32)table))->field_120[3];
    state->field_539[0] = value;
    state->field_535[0] = value;
    index = context[0x16] * 0x10;
    value = ((Entry80087E3C *)(index + (u32)table))->field_120[7];
    state->field_539[1] = value;
    state->field_535[1] = value;
    index = context[0x16] * 0x10;
    value = ((Entry80087E3C *)(index + (u32)table))->field_120[11];
    state->field_539[2] = value;
    state->field_535[2] = value;
    index = context[0x16] * 0x10;
    value = ((Entry80087E3C *)(index + (u32)table))->field_120[15];
    state->field_539[3] = value;
    state->field_535[3] = value;
    index = context[0x16] * 4;
    state->field_550 = ((Entry80087E3C *)(index + (u32)table))->field_118;
    index = context[0x16] * 4;
    state->field_554 = ((Entry80087E3C *)(index + (u32)table))->field_110;
}
