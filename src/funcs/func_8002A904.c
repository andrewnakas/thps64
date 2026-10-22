#include "common.h"

s32 func_80039E60(s32, s32, s32);   /* extern */

void func_8002A904(void *arg0) {
    f32 temp_f0;
    f32 temp_f2;
    f32 var_f0;

    temp_f0 = (*(f32 *)((u8 *)(arg0) + 0x2C0));
    if (!(temp_f0 < 6.0f)) {
        if ((6.0f <= temp_f0) && (temp_f0 < 16.0f)) {
            (*(f32 *)((u8 *)(arg0) + 0x2C0)) = (f32) 16.0f;
        } else {
            temp_f2 = (*(f32 *)((u8 *)(arg0) + 0x2C0));
            if (16.0f <= temp_f2) {
                var_f0 = 26.0f;
                if (!(temp_f2 < var_f0)) {
                    goto block_7;
                }
                goto block_9;
            }
block_7:
            if (26.0f <= (*(f32 *)((u8 *)(arg0) + 0x2C0))) {
                var_f0 = 36.0f;
                if ((*(f32 *)((u8 *)(arg0) + 0x2C0)) < var_f0) {
block_9:
                    (*(f32 *)((u8 *)(arg0) + 0x2C0)) = var_f0;
                }
            }
        }
        func_80039E60(0x91, 0x2710, 0);
    }
}
