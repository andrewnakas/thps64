#include "common.h"

void func_800A8480(void *, s32, f32 *, s32);                     /* extern */

s32 func_800871A8(u8 *arg0, s32 arg1, s32 arg2) {
    f32 sp10;
    s32 temp_s0;

    sp10 = 0.0f;
    temp_s0 = arg2 * 0x240;
    func_800A8480(arg0 + (temp_s0 + 0x188), arg1, &sp10, 0);
    return (s32) (sp10 / *(f32 *) (arg0 + temp_s0 + 0x188));
}
