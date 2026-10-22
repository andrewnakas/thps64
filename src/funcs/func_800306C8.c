#include "common.h"

s32 func_80039E60(s32, s32, s32);   /* extern */
s32 func_800B4264(s32, s32);                /* extern */

void func_800306C8(void *arg0, s32 arg1, s32 arg2) {
    if (func_800B4264(arg1, 0x9000) != 0) {
        if (((*(s32 *)((u8 *)(arg0) + 0x7AC)) != 0) && ((*(s32 *)((u8 *)(arg0) + 0x78C)) == (*(s32 *)((u8 *)(arg0) + 0x790)))) {
            func_80039E60(0x92, 0x2710, 0);
        } else {
            if ((*(s32 *)((u8 *)(arg0) + 0x7A8)) == 0) {
                func_80039E60(0x91, 0x2710, 0);
            }
            (*(s32 *)((u8 *)(arg0) + 0x7A8)) = 1;
        }
    }
    if (func_800B4264(arg2, 0x9000) != 0) {
        if (((*(s32 *)((u8 *)(arg0) + 0x7A8)) != 0) && ((*(s32 *)((u8 *)(arg0) + 0x790)) == (*(s32 *)((u8 *)(arg0) + 0x78C)))) {
            func_80039E60(0x92, 0x2710, 0);
            return;
        }
        if ((*(s32 *)((u8 *)(arg0) + 0x7AC)) == 0) {
            func_80039E60(0x91, 0x2710, 0);
        }
        (*(s32 *)((u8 *)(arg0) + 0x7AC)) = 1;
    }
}
