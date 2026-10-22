#include "common.h"

s32 func_80039E60(s32, s32, s32);   /* extern */
s32 func_8003C8DC(s32, s32);                    /* extern */

void func_8003B8D4(void *arg0) {
    s32 temp_s0;

    temp_s0 = arg0 + 0x2C0;
    if (func_8003C8DC(temp_s0, 3) != 0) {
        func_80039E60(0x91, 0x2710, 0);
        (*(s32 *)((u8 *)(arg0) + 0x34)) = (s32) ((*(s32 *)((u8 *)(arg0) + 0x34)) == 0);
        return;
    }
    if (func_8003C8DC(temp_s0, 4) != 0) {
        func_80039E60(0x91, 0x2710, 0);
        (*(s32 *)((u8 *)(arg0) + 0x38)) = (s32) ((*(s32 *)((u8 *)(arg0) + 0x38)) == 0);
    }
}
