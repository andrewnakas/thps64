#include "common.h"

typedef struct {
    f32 field_000, field_004, field_008;
    union { s32 word; u8 bytes[4]; } field_00C;
} State80087620;

f64 func_800872F0(f64, f64);

void func_80087620(State80087620 *arg0, u8 *arg1) {
    f32 divisor;
    f32 reciprocal;
    f64 step;
    f32 scale;
    f32 bias;
    s32 value;
    s32 index;
    u8 *output;

    divisor = arg0->field_000;
    if (divisor == 0.0f) {
        reciprocal = 0.0f;
    } else {
        reciprocal = 1.0f / divisor;
    }
    index = 0;
    step = 0.00392156862745098;
    scale = 255.0f;
    bias = 0.5f;
    while (1) {
        if (index >= 0x100) {
            break;
        }
        value = (s32) ((((f32) func_800872F0((f64) index * step, (f64) reciprocal) * arg0->field_008) + arg0->field_004) * scale + bias);
        output = arg1 + index;
        if (value >= 0) {
            if (arg0->field_00C.word < value) {
                value = arg0->field_00C.bytes[3];
            }
            *output = value;
        } else {
            *output = 0;
        }
        index++;
    }
}
