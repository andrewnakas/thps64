/* cflags: -O2 */
#include "common.h"

s32 func_800BA840(void *, s32, s32);        /* extern */

void func_800BA8A4(void *arg0, s32 arg1) {
    s32 var_s0;
    s32 var_s0_2;
    u8 temp_v1;

    temp_v1 = (*(u8 *)((u8 *)arg0 + 0x3E));
    switch (temp_v1) {                              /* irregular */
    case 0:
        var_s0 = 0;
        if (((u16) (*(u16 *)((u8 *)arg0 + 0x64)) >> 1) != 0) {
            do {
                func_800BA840(arg0, (*(s32 *)((u8 *)arg0 + 0x58)) + (var_s0 * 2), arg1);
                var_s0 += 1;
            } while (var_s0 < (s32) ((u16) (*(u16 *)((u8 *)arg0 + 0x64)) >> 1));
            return;
        }
        return;
    case 2:
        var_s0_2 = 0;
        if ((*(u8 *)((u8 *)arg0 + 0x40)) != 0) {
            do {
                func_800BA840(arg0, (*(s32 *)((u8 *)arg0 + 0x54)) + (var_s0_2 * 2), arg1);
                var_s0_2 += 1;
            } while (var_s0_2 < (s32) (*(u8 *)((u8 *)arg0 + 0x40)));
        }
        break;
    }
}
