#include "common.h"

s32 func_800463E8(void *, s32);             /* extern */
s32 func_8005C444();                            /* extern */
s32 func_8006A16C(s32);                             /* extern */
extern s32 D_800DE7A0;

void func_8004C9E8(void *arg0) {
    s32 temp_a0;
    s32 temp_v1;
    s32 var_v0_2;
    s32 var_v1;
    void *var_a0;
    void *var_v0;

    temp_v1 = (*(s32 *)((u8 *)(arg0) + 0x82C));
    if ((temp_v1 != 5) && ((*(s32 *)((u8 *)(arg0) + 0x428)) != 0)) {
        (*(s32 *)((u8 *)(arg0) + 0x858)) = 1;
        (*(s32 *)((u8 *)(arg0) + 0x2F8)) = 0;
        (*(s32 *)((u8 *)(arg0) + 0x2F4)) = 0xF;
        if (temp_v1 != 2) {
            func_8005C444();
        }
        (*(s32 *)((u8 *)(arg0) + 0x444)) = 0;
        temp_a0 = (*(s32 *)((u8 *)(arg0) + 0x510));
        if ((temp_a0 != 0) && ((*(s32 *)((u8 *)(arg0) + 0x514)) != 0)) {
            (*(s32 *)((u8 *)(arg0) + 0x444)) = func_8006A16C(temp_a0);
        }
        (*(s32 *)((u8 *)(arg0) + 0x380)) = 0;
        (*(s32 *)((u8 *)(arg0) + 0x37C)) = 0;
        func_800463E8(arg0, 0);
        var_v1 = 0x4F;
        var_v0 = arg0 + 0x13C;
        do {
            (*(s32 *)((u8 *)(var_v0) + 0x660)) = 0;
            var_v1 -= 1;
            var_v0 -= 4;
        } while (var_v1 >= 0);
        if (D_800DE7A0 == 2) {
            var_v0_2 = 0x4F;
            var_a0 = arg0 + 0x13C;
            do {
                (*(s32 *)((u8 *)(var_a0) + 0x520)) = 0;
                var_v0_2 -= 1;
                var_a0 -= 4;
            } while (var_v0_2 >= 0);
        }
    }
}
