#include "common.h"

s32 func_80034C44(s32, f32, f32, s32, f32, s32); /* extern */

void func_800823FC(void *arg0) {
    s32 temp_v0;
    s32 temp_v1;

    (*(s32 *)((u8 *)arg0 + 0x214)) = (s32) ((*(s32 *)((u8 *)arg0 + 0x214)) + 1);
    if ((*(s32 *)((u8 *)arg0 + 0x238)) != 0) {
        temp_v0 = (*(s32 *)((u8 *)arg0 + 0x230)) + 1;
        (*(s32 *)((u8 *)arg0 + 0x230)) = temp_v0;
        if (temp_v0 >= (s32) (*(u16 *)((u8 *)arg0 + 0x240))) {
            (*(s32 *)((u8 *)arg0 + 0x238)) = 0;
        }
    } else {
        temp_v1 = (*(s32 *)((u8 *)arg0 + 0x230)) - 1;
        (*(s32 *)((u8 *)arg0 + 0x230)) = temp_v1;
        if (-(s32) (*(u16 *)((u8 *)arg0 + 0x240)) >= temp_v1) {
            (*(s32 *)((u8 *)arg0 + 0x238)) = 1;
        }
    }
    func_80034C44((*(s32 *)((u8 *)arg0 + 0x224)), (f32) (*(s32 *)((u8 *)arg0 + 0x228)), (f32) ((*(s32 *)((u8 *)arg0 + 0x22C)) + (*(s32 *)((u8 *)arg0 + 0x230))), (*(s32 *)((u8 *)arg0 + 0x234)), 1.0f, 0);
}
