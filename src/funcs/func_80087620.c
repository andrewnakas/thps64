#include "common.h"

typedef struct {
    f32 field_000, field_004, field_008;
    union { s32 word; u8 bytes[4]; } field_00C;
} State80087620;

f64 func_800872F0(f64, f64);
#define D_8001EE80 (*(const f32 *)0x8001EE80)
#define D_8001EE88 (*(const f64 *)0x8001EE88)
#define D_8001EE90 (*(const f32 *)0x8001EE90)
#define D_8001EE94 (*(const f32 *)0x8001EE94)

void func_80087620(State80087620 *arg0, u8 *arg1) {
    f32 divisor;
    f32 bias;
    f32 scale;
    f32 reciprocal;
    register f64 step __asm__("$f22");
    s32 value;
    s32 index;
    State80087620 *state;
    u8 *output;

    state = arg0;
    divisor = state->field_000;
    if (divisor == 0.0f) {
        reciprocal = 0.0f;
    } else {
        reciprocal = D_8001EE80 / divisor;
    }
    index = 0;
    step = D_8001EE88;
    scale = D_8001EE90;
    bias = D_8001EE94;
next_value:
    if (index < 0x100) {
        value = (s32) (((((f32) func_800872F0((f64) index * step, (f64) reciprocal) * state->field_008) + state->field_004) * scale) + bias);
        output = arg1 + index;
        if (value >= 0) {
            if (state->field_00C.word < value) {
                value = state->field_00C.bytes[3];
            }
            *output = (u8)value;
        } else {
            *output = 0;
        }
        index += 1;
        goto next_value;
    }
}
