#include "common.h"

void func_8006F178(s32, s32, s32, s32, s32, s32);
void func_8006F1A8(s32, s32, s32, s32);
s32 func_8006F204(void);
void func_8006F23C(s32);
void func_8006F274(s32);
extern s32 D_800DC618;
extern s32 D_800DE7C4;
extern s32 D_800DE820;
extern s32 D_800E9038;
typedef union { u32 word; u16 half[2]; } Word80089040;
typedef struct { u8 pad_000[0x90]; s32 field_090; s32 field_094; s32 field_098; s32 field_09C; Word80089040 field_0A0; } State80089040;
extern State80089040 D_800FC0D0;

void func_80089040(void) {
    State80089040 *state = &D_800FC0D0;
    s32 scale;
    s32 offset;
    u32 remaining;
    u32 difference;

    offset = 0x28;
    if ((D_800E9038 == 0) && (D_800DE820 == 0) && (D_800DE7C4 == 0) && (D_800DC618 != 2) && (state->field_090 != 0)) {
        difference = (0x12C - state->field_0A0.half[1]) & 0xFFFF;
        if (difference < 0x14U) {
            offset = difference * 2;
        }
        if ((u32) state->field_0A0.word < 0x14U) {
            offset = state->field_0A0.word * 2;
        }
        func_8006F274(1);
        func_8006F1A8(0x80, 0x80, 0, 0);
        func_8006F23C(0xB4);
        offset = offset & 0xFFFF;
        /* Initialize the shared scale in the first call and reuse it below. */
        func_8006F178(offset, 0x64, state->field_090, 0, 0, (scale = 0x100));
        if (state->field_094 != 0) {
            func_8006F178(offset, (func_8006F204() / 9) + 0x64, state->field_094, 0, 0, scale);
        }
        if (state->field_098 != 0) {
            func_8006F178(offset, ((func_8006F204() / 9) * 2) + 0x64, state->field_098, 0, 0, scale);
        }
        if (state->field_09C != 0) {
            func_8006F178(offset, ((func_8006F204() / 9) * 3) + 0x64, state->field_09C, 0, 0, scale);
        }
        remaining = state->field_0A0.word - 1;
        state->field_0A0.word = remaining;
        if (remaining == 0) {
            state->field_09C = 0;
            state->field_098 = 0;
            state->field_094 = 0;
            state->field_090 = 0;
        }
    }
}
