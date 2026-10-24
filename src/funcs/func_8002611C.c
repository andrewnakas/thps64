/* cflags: -Wa,-O0 */
#include "common.h"

s32 func_800B379C(s32, f32, f32);            /* extern */
extern u8 D_800D0FC2;
extern s32 D_800DC618;
extern s32 D_800DC6D8;
extern s32 D_800DE7A0;
extern s32 D_800DF37C;
extern f32 D_800F5668;

void func_8002611C(void) {
    if ((D_800DE7A0 != 7) && (D_800DE7A0 != 5) && (D_800DE7A0 != 8) && (D_800DF37C != 0) && (D_800DC618 != 2) && (D_800DC6D8 != 2)) {
        func_800B379C(D_800D0FC2, D_800F5668 * 4.0f, 0.8f);
    }
}
