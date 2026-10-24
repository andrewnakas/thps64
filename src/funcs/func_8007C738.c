/* cflags: -O2 -fno-schedule-insns2 */
#include "common.h"

s32 func_8005EA48(void *, s32);                         /* extern */
extern u8 D_8001E388;
extern s32 D_800DE520;

void func_8007C738(void *arg0, s32 arg1) {
    s32 temp_a1;

    (*(u8 **)((u8 *)arg0 + 0x44)) = &D_8001E388;
    temp_a1 = arg1 & 1;
    D_800DE520 -= 1;
    if (temp_a1 != 0) {
        func_8005EA48(arg0, temp_a1);
    }
}
