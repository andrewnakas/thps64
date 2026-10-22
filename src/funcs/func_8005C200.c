#include "common.h"

s32 func_8004D398(void *, s32);             /* extern */

void func_8005C200(void *arg0) {
    s32 temp_a1;
    s32 var_a0;
    s32 var_v1;

    if (((*(s32 *)((u8 *)(arg0) + 0x450)) == 0) && (((*(s32 *)((u8 *)(arg0) + 0x454)) != 0) || ((*(s32 *)((u8 *)(arg0) + 0x818)) != 0))) {
        temp_a1 = (*(s32 *)((u8 *)(arg0) + 0x460));
        var_v1 = 0;
        if (temp_a1 & 0x2000) {
            var_v1 = (u8) (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x964))) + 0x10)) > 0U;
        }
        var_a0 = 0;
        if (temp_a1 & 0x4000) {
            var_a0 = (u8) (*(u8 *)((u8 *)((*(void **)((u8 *)(arg0) + 0x964))) + 0x20)) > 0U;
        }
        var_v1 |= var_a0;
        var_v1 |= ((*(s32 *)((u8 *)(arg0) + 0x458)) == 0);
        if ((*(s32 *)((u8 *)(arg0) + 0x818)) != 0) {
            if ((*(s32 *)((u8 *)(arg0) + 0x820)) > 0) {
                if (((*(s32 *)((u8 *)(arg0) + 0x81C)) & 0xFFF) < 0xED4) {
                    var_v1 = 1;
                }
            } else if (((*(s32 *)((u8 *)(arg0) + 0x81C)) & 0xFFF) >= 0x12D) {
                var_v1 = 1;
            }
        }
        if (var_v1 != 0) {
            func_8004D398(arg0, 0);
            (*(s32 *)((u8 *)(arg0) + 0x318)) = (s32) ((*(s32 *)((u8 *)(arg0) + 0x318)) + 1);
        }
    }
}
