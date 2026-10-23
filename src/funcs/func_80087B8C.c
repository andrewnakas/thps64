#include "common.h"
typedef struct { u8 pad_000[0x4F0]; s8 field_4F0; u8 pad_4F1[0x33]; s32 field_524; u8 pad_528[4]; s16 field_52C, field_52E, field_530, field_532; } State80087B8C;
void func_80087B8C(State80087B8C *state) {
    s32 selection = state->field_4F0;
    s32 one;
    if (selection == 0) {
        state->field_52C = 0x159;
        state->field_52E = 0x44;
        state->field_530 = 0x23C;
        state->field_532 = 0x44;
        state->field_524 = 1;
        return;
    }
    one = 1;
    if (selection == 1) {
        state->field_52C = 0x6f;
        state->field_52E = 0x65;
        state->field_530 = 0x14d;
        state->field_532 = 0x65;
        state->field_524 = one;
        return;
    }
    if (selection == 2) {
        state->field_52C = 0x160;
        state->field_52E = 0xd3;
        state->field_530 = 0x244;
        state->field_532 = 0xd3;
        state->field_524 = one;
        return;
    }
    if (selection == 3) {
        state->field_52C = 0x89;
        state->field_52E = 0xf3;
        state->field_530 = 0x16e;
        state->field_532 = 0xf3;
        state->field_524 = one;
        return;
    }
    if (selection == 4) {
        state->field_52C = 0xb8;
        state->field_52E = 0x127;
        state->field_530 = 0x1e8;
        state->field_532 = 0x127;
        state->field_524 = one;
        return;
    }
    if (selection == 5) {
        state->field_52C = 0xc8;
        state->field_52E = 0x148;
        state->field_530 = 0x1e8;
        state->field_532 = 0x148;
        state->field_524 = one;
        return;
    }
    if (selection == 6) {
        state->field_52C = 0xa0;
        state->field_52E = 0x164;
        state->field_530 = 0x1e8;
        state->field_532 = 0x164;
        state->field_524 = one;
        return;
    }
    if (selection == 7) {
        state->field_52C = 0xa3;
        state->field_52E = 0x184;
        state->field_530 = 0x1e8;
        state->field_532 = 0x184;
        state->field_524 = one;
        return;
    }
}
