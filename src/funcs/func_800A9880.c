/* cflags: -O2 */
#include "common.h"

s32 func_800A9D64();                                /* extern */

s32 func_800A9880(void *arg0, s32 arg1, s32 arg2) {
    s32 temp_v1;
    void *temp_v0;
    void *temp_v1_2;

    if (func_800A9D64() != 0) {
        temp_v1 = (*(s32 *)((u8 *)arg0 + 0x48));
        if (arg2 >= temp_v1) {
            if ((arg2 < 0xC8) && (arg1 < temp_v1)) {
                temp_v1_2 = arg0 + (arg2 * 0x24);
                temp_v0 = arg0 + (arg1 * 0x24);
                (*(s32 *)((u8 *)temp_v1_2 + 0x538)) = 0;
                (*(s32 *)((u8 *)temp_v1_2 + 0x534)) = arg1;
                (*(s32 *)((u8 *)temp_v1_2 + 0x53C)) = (s32) (*(s32 *)((u8 *)temp_v0 + 0x53C));
                (*(s32 *)((u8 *)temp_v1_2 + 0x540)) = (s32) (*(s32 *)((u8 *)temp_v0 + 0x540));
                (*(u8 *)((u8 *)temp_v1_2 + 0x549)) = (u8) (*(u8 *)((u8 *)temp_v0 + 0x549));
                (*(f32 *)((u8 *)temp_v1_2 + 0x54C)) = (f32) (*(f32 *)((u8 *)temp_v0 + 0x54C));
                (*(f32 *)((u8 *)temp_v1_2 + 0x550)) = (f32) (*(f32 *)((u8 *)temp_v0 + 0x550));
                (*(u8 *)((u8 *)temp_v1_2 + 0x548)) = (u8) (*(u8 *)((u8 *)temp_v0 + 0x548));
                (*(u8 *)((u8 *)temp_v1_2 + 0x54A)) = (u8) (*(u8 *)((u8 *)temp_v0 + 0x54A));
                (*(s32 *)((u8 *)temp_v1_2 + 0x544)) = (s32) (*(s32 *)((u8 *)temp_v0 + 0x544));
                return 1;
            }
            /* Duplicate return node #6. Try simplifying control flow for better match */
            return 0;
        }
    }
    return 0;
}
