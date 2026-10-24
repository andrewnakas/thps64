/* cflags: -O2 -fno-schedule-insns -fno-schedule-insns2 -Wa,-no-m4100 -Wa,-O0 */
#include "common.h"

s32 func_800B379C(s32, f32, f32);               /* extern */
extern s32 D_800DC618;
extern s32 D_800DC6D8;
extern s32 D_800DE7A0;
extern s32 D_800DE9C4;
typedef struct { u8 pad[0x988]; s32 arr[1]; } S_DE9F4;
extern S_DE9F4 D_800DE9F4;
extern f32 D_800F5668;
extern f32 D_8001BD7C;

void func_8005C690(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 var_f2;
    f32 f;
    s32 var_a0;

    var_a0 = (*(s32 *)((u8 *)(arg0) + 0x968));
    if (D_800DE7A0 == 7) {
        var_a0 ^= D_800DE9C4;
    }
    if ((D_800DE9F4.arr[var_a0] != 0) && (D_800DC618 != 2) && (D_800DC6D8 != 2)) {
        f = D_800F5668 * (f32) arg1;
        if (arg2 == 1) {
            var_f2 = (f32) (arg3 / 255);
        } else {
            var_f2 = 0.8f;
        }
        func_800B379C(var_a0, f, var_f2);
    }
}
